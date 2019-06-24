#include <unordered_map>
#include "tcp_server.hpp"


// void Handler(std::string& req, std::string* resp) {
//   auto it = dict.find(req);
//   if(it == dict.end()) {
//     *resp = "未找到";
//   } else {
//     *resp = it->second;
//   }



int main() {
  std::unordered_map<std::string,std::string> dict;

  dict.insert(std::make_pair<std::string,std::string> ("hello", "你好"));
  dict.insert(std::make_pair<std::string,std::string> ("world", "世界"));
  dict.insert(std::make_pair<std::string,std::string> ("bit", "比特"));
  dict.insert(std::make_pair<std::string,std::string> ("byte", "字节"));
  TcpServer server;
  server.Start("0.0.0.0", 9090, [&dict](const std::string& req, std::string *resp){
    auto it = dict.find(req);
    if(it == dict.end()) {
      *resp = "未找到";
    } else {
      *resp = it->second;
    } 
  });

  return 0;
}

//[&dict](std::string& req, std::string*resp){
//auto it = dict.find(req);
//if(it == dict.end()) {
//*resp = "未找到";
//} else {
//*resp = it->second;
//} 

