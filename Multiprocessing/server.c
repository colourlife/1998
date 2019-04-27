#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <error.h>
#include <sys/wait.h>

typedef struct sockaddr_in sockaddr_in;
typedef struct sockaddr sockaddr;

void wait_child(int signo)
{
	while(waitpid(0,NULL,WNOHANG)> 0)
	{
	}
}

int main()
{
	int lfd,cfd;
	pid_t pid;
	char buff[1024] = {0};
	int n,i;
	//创建套接字
	lfd = socket(AF_INET,SOCK_STREAM,0);
	if(lfd < 0)
	{
		perror("socket");
		exit(1);
	}
	//绑定端口号
	sockaddr_in serv_addr;
	sockaddr_in clie_addr;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(6666);
	inet_pton(AF_INET,"192.168.43.150",&serv_addr.sin_addr.s_addr);
	int b = bind(lfd,(sockaddr*)&serv_addr,sizeof(serv_addr));
	if(b < 0)
	{
		perror("bind");
		exit(1);
	}
	//监听 指定最大链接数
	int l = listen(lfd,128);
	//接受参数
	socklen_t clie_len = sizeof(clie_addr);
	while(1)
	{
		cfd = accept(lfd,(sockaddr*)&clie_addr,&clie_len );
		if(cfd < 0)
		{
			perror("accept");
			exit(1);
		}
		pid = fork();
		if(pid < 0)
		{
			perror("fork");
			exit(1);
		}
		else if(pid == 0)
		{
			//子进程跳出循环进行下面的数据处理
			close(lfd);
			break;
		}
		else
		{
			close(cfd);	
			signal(SIGCHLD,wait_child);
		}
	}
	while(1)
	{
		n = read(cfd,buff,sizeof(buff));
		if(n <= 0)
		{
			close(cfd);
			return 0;
		}
		else if(n == -1)
		{
			perror("read");
			exit(1);
		}
		else
		{
			for(i=0;i<n;++i)
			{
				buff[i] = toupper(buff[i]);
			}
			write(cfd,buff,n);
		}
	}
	return 0;
}
