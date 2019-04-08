.PHONY:all
all:tcp_server tcp_client
tcp_server:tcp_server.cc
	g++ -o $@ $^ -lpthread
tcp_client:tcp_client.cc
	g++ -o $@ $^ -lpthread
.PHONY:clean
clean:
	rm -f tcp_server tcp_client
			

