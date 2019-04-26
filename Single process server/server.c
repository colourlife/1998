#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <error.h>
#include <ctype.h>
#include <arpa/inet.h>

typedef struct sockaddr_in sockaddr_in;
typedef struct sockaddr sockaddr;

#define IP "192.168.43.150"
#define PORT 6666
int main()
{
	int fd;
	sockaddr_in addr;
	sockaddr_in clie;

	//创建套接字 
	fd = socket(AF_INET,SOCK_STREAM,0);
	if(fd <0)
	{
		perror("socket");
		return 0;
	}
	
	
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	char* ip = IP;
	inet_pton(AF_INET,ip, &addr.sin_addr.s_addr);

	//绑定端口号 
	int b =	bind(fd,(sockaddr*)&addr,sizeof(sockaddr_in));
	if(b<0)
	{
		perror("bind");
		return 0;
	}

	//监听 设置连接数 
	int l = listen(fd,32);
	if(l<0)
	{
		perror("listen");
		return 0;
	}

	
	//接收连接 
	socklen_t len;
	len = sizeof(clie);
	int cfd = accept(fd,(sockaddr*)&clie,&len);
	if(cfd <0)
	{
		perror("accept");
		return 0;
	}
	
	//数据处理 
	while(1)
	{
		char buff[1024];
		int n = read(cfd,buff,sizeof(buff));
		int i=0;
		for(i=0;i<n;++i)
		{
			buff[i] = toupper(buff[i]);
		}
		write(cfd,buff,n);
	}
	close(fd);
	close(cfd);
}
