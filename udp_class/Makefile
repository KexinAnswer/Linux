.PHONY:all
all:echo_server echo_client

echo_server:echo_server.cc udp_server.hpp udp_socket.hpp
	g++ echo_server.cc -o echo_server -std=c++11

echo_client:echo_client.cc udp_client.hpp udp_socket.hpp
	g++ echo_client.cc -o echo_client -std=c++11

.PHONY:clean
clean:
	rm echo_client echo_server
