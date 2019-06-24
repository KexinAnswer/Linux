#pragma 

#include <functional>
#include "tcp_socket.hpp"

#define CHECK_RET(exp) if(!(exp)){ \
  return false; \
}

typedef std::function<void(const std::string& req, std::string* resp)> Handler;

class TcpProcessServer {
public:
  TcpProcessServer() {

      } 

  ~TcpProcessServer() {
    listen_sock_.Close();
  }

  bool Start(const std::string& ip, uint16_t port,Handler handler) {
    // 1. 创建socket  
    CHECK_RET(listen_sock_.Socket());
    // 2. 绑定端口号
    CHECK_RET(listen_sock_.Bind(ip,port));
    // 3. 监听
    CHECK_RET(listen_sock_.Listen());
    // 4. 进入主循环
    while(true) {
      // 5. 调用 Accept
      TcpSocket client_sock;
      std::string peer_ip;
      uint16_t peer_port;
      bool ret = listen_sock_.Accept(&client_sock, &peer_ip, &peer_port);
      if(!ret) {
        continue;
      }
      printf("[%s:%d]客户端建立连接!\n",peer_ip.c_str(),peer_port);
      // 6. 创建子进程，让子进程区处理客户端的请求
      //  父进程继续调用 Accept
      ProcessConnect(client_sock, handler, peer_ip, peer_port);
    }
  }
private:
  TcpSocket listen_sock_;

  void ProcessConnect(TcpSocket& client_sock, Handler handler, const std::string& ip, uint16_t port) {
    // 1. 创建子进程
    pid_t ret = fork();
    // 2. 父进程直接结束这个函数
    if(ret > 0) {
      // 父进程
      // 父进程也需要关闭这个 Socket 
      // 否则就会出现文件描述符泄露
      client_sock.Close();
      return;
    }
    // 3. 子进程循环的做已下事情
    //    a) 读取客户端请求
    while(1) {
      std::string req;
      int r = client_sock.Recv(&req);
      if(r < 0) {
        continue;
      }
      if(ret == 0) {
        printf("[%s:%d]客户端断开连接!\n",ip.c_str(),port);
        break;
      } 
      printf("[%s:%d]客户端发送了: %s\n",ip.c_str(),port,req.c_str());
      //    b) 根据请求计算响应
      std::string resp;
      handler(req,&resp);
      //    c) 把响应写回给客户端
      client_sock.Send(resp);
     
    }
   // 子进程的收尾工作
   // 1. 关闭 Socket
   client_sock.Close();
   // 2. 结束进程
   exit(0);
  }
};

// 进程创建失败的原因
// 1. 内存不够
// 2. 进程不太多
// 实际工作中创建进程失败可能性非常小
