#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>

#define MAXDATASIZE 1024

#define SERVPORT 3333
#define BACKLOG 10


int main(int argc, char *agrv[])
{		
	
	char buf[MAXDATASIZE];
	struct sockaddr_in serv;
	struct sockaddr_in remote_addr; /* connector 's address information */
	int sin_size;

	int sockfd,  client_fd ,numbytes;  /*listen on sock_fd, new connection on new_fd  */

	//检查socket是否连通
	sockfd = socket(AF_INET, SOCK_STREAM , 0 );
	if( sockfd == -1 )
	{
			perror("socket创建错误!");
			exit(1);
	}else{
		printf("socket is ok\n");
	}
	//bind section
	  serv.sin_family = AF_INET;
	  serv.sin_port = htons(SERVPORT);
	  serv.sin_addr.s_addr = htonl(INADDR_ANY);
	  
	  //serv.sin_addr.s_addr=inet_addr( "192.168.1.1"); 

	  bzero(&(serv.sin_zero), 8);

	if( bind(sockfd ,(struct sockaddr *)&serv, sizeof(struct sockaddr )) == -1 )
	{
		perror("bind error! ");
		exit(1);
	}else{
		printf("bind ok\n");
	}

	//listen
	if(listen(sockfd, BACKLOG) == -1)
	{
		perror("listen error!");
		exit(1);
	}else{
		printf("listen ok!\n");
	}

	//accept
	while(1)
	{
		sin_size = sizeof(struct sockaddr_in);

		if((client_fd = accept(sockfd, (struct sockaddr *)&remote_addr, &sin_size)) == -1 )
		{
			perror("accept error!");
			continue;
		}else{
			printf("accept ok!");
		}
		

		if( send(client_fd, "welcome play game", 17,0) == -1)
		{  
			perror("send error!");
			return 1;
		}

		if(( numbytes = recv(client_fd,buf,MAXDATASIZE,0)) ==-1 )
		{
			perror( "RECV ERROR");
			return 1;
		}

		if( numbytes ) {
			buf[numbytes] = '\0';
			printf("received:%s\n",buf);
			sleep(3);
		}
		printf( "send:hi~~/n");
		if( send(client_fd, "welcome play game!", 17,0) == -1)
		{
			perror("send error");
			return 1;
		}
		close ( client_fd);

		/**	if( !fork() )
		  {
		  if( send(client_fd, "Hello,you are connected!\n", 26, 0) == -1)
		  {
		  error("send error!");
		  }
		  close(client_fd);
		//	exit(0);
		}
		close(client_fd);
		//	  while(waitpid(-1,NULL,WNOHANG) > 0 );
		 **/
	}
	close(sockfd);

}



