//通用的 TCP 服务器
#pragma once

#include <functional>
#include "tcp_socket.hpp"

#define CHECK_RET(exp) if(!(exp)) { \
  return false; \
}

typedef std::function<void(const std::string& req, std::string* resp)> Handler;

class TcpServer {
public:
  TcpServer() {

  }

  bool Start(const std::string& ip, uint16_t port, Handler handler) {
    //1. 创建一个 socket 
    CHECK_RET(listen_socket_.Socket());
    //2. 绑定端口号
    CHECK_RET(listen_socket_.Bind(ip,port));
    //bool ret = listen_socket_.Bind(ip,port);
    //3. 进行监听
    CHECK_RET(listen_socket_.Listen());
    printf("Server Start OK! \n");
    //4. 进入主循环
    while(true) {
      TcpSocket client_socket;
      std::string ip;
      uint16_t port;
      bool ret = listen_socket_.Accept(&client_socket,&ip, &port);
      if(!ret) {
        continue;
      }
      printf("[%s:%d] 有客户端连接！\n", ip.c_str(), port);
      //6. 和客户端进行沟通。 一次连接中和客户端多次交互
      while(true) {
        //a) 读取请求
        std::string req;
        int r = client_socket.Recv(&req);
        if(r < 0) {
          continue;
        }
        if(r == 0) {
          //对端关闭了连接
          client_socket.Close(); 
          printf("[%s:%d] 对端关闭了连接！\n", ip.c_str(), port);
          break;
        }
        printf("[%s:%d] 客户端发送了： %s \n", ip.c_str(), port, req.c_str());
        //b) 根据请求计算响应
        std::string resp;
        handler(req,&resp);
        //c)把响应写回客户端
        client_socket.Send(resp);
      }
    }
  }

private:
  //这个 socket 还没有被真正初始化，默认构造值为 -1 ， 并不是一个合理的文件描述符 
  TcpSocket  listen_socket_;
};


// 如何用 scoket api 创建一个 tcp 服务器
// udp服务器比较简单 socket bind recfromv sendto
// tcp服务器 1. scoket 2. bind 3. listen 4. accept  accept之前服务器已经启动完毕 accept要放在循环内部
// 只要listen完成了 服务器就相当于启动完成就绪状态，这个时候随时可以有客户端进行连接
// accept 连接建立好之后 取一个连接 让用户代码进行处理，连接是由内核管的 通过连接发送数据 先把连接通过 accept 接口 获取到用户代码
// 获取到 client_socket 借助 client_socket 完成
