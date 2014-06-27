#include <stdio.h>  
#include <stdlib.h>  
#include <errno.h>  
#include <string.h>  
#include <netdb.h>  
#include <sys/types.h>  
#include <netinet/in.h>  
#include <sys/socket.h>  
#include <string.h>


#define SERVERIP "127.0.0.1"
#define SERVPORT 3333 /* the port client will be connecting to */ 

#define MAXDATASIZE 1024 /* max number of bytes we can get at once */ 
#define FILE_NAME_MAX_SIZE 512


int main(int argc, char *argv[]) 
{ 
	int sockfd, recvbytes;  
	char buf[MAXDATASIZE]; 
	struct hostent *host; 
	struct sockaddr_in serv_addr; /* connector's address information */ 

	if (argc != 2) { 
		printf("uSAGE:./%s ServerIpAddress\n",agrv[0]);
		exit(1); 
	} 
	// get the host info 
	if((host=gethostbyname(argv[1]))==NULL)
	{
		herror("gethostbyname error!");
		exit(1);
	}



	//create socket 
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1 )
	{
		perror("socket create error!");
	}

	//create connect 
	serv_addr.sin_family = AF_INET; /* host byte order */ 
	serv_addr.sin_port = htons(SERVPORT); /* short, network byte order */ 
	serv_addr.sin_addr = *((struct in_addr *)host->h_addr); 
	bzero(&(serv_addr.sin_zero), 8); /* zero the rest of the struct */ 

	if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr)) == -1 )
	{
		perror("connect error!");
		exit(1);
	}
	
	 printf("send:");
	 
	 if( send(sockfd, "I am is a player!", 17,0) == -1)
     {
          perror("send error!");
          return 1;
    }

	

	//recv data
	if((recvbytes = recv(sockfd,buf,MAXDATASIZE,0)) ==-1 )
	{
		perror("recv error!" );
		exit(1);
	}

	if( recvbytes )
	{
		buf[recvbytes] = '\0';
		printf("received:%s\n",buf);
	}

	close(sockfd); 
	return 0;
} 

