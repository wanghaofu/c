#include <stdio.h>  
#include <stdlib.h>  
#include <errno.h>  
#include <string.h>  
#include <netdb.h>  
#include <sys/types.h>  
#include <netinet/in.h>  
#include <sys/socket.h>  

#define DEST_IP "10.246.131.142" 
#define DEST_PORT 45678 

int main(int argc, char *argv[])
{
	int sockfd, port = 45678; 
	struct sockaddr_in my_addr;
	struct sockaddr_in dest_addr; /* will hold the destination addr */

	//检查socket是否连通
	if((sockfd=socket(AF_INET, SOCK_STREAM, 0)) == -1) 
	{ 
		printf("Socket Error, %d\n", errno); 
		exit(1); 
	} 

	//绑定socket
	my_addr.sin_family = AF_INET; /* host byte order */ 
	my_addr.sin_port = htons(port); /* see man htons for more information */ 
	my_addr.sin_addr.s_addr = htonl(INADDR_ANY); /* get our address */ 
	bzero(&(my_addr.sin_zero), 8); /* zero out the rest of the space */ 

	if(bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr)) == -1)
	{ 
		printf("Bind Error, %d\n", errno); 
		close(sockfd); 
		exit(1); 
	} 

	//远程连接
	dest_addr.sin_family = AF_INET; /* host byte order */ 
	dest_addr.sin_port = htons(DEST_PORT); /* short, network byte order */
	dest_addr.sin_addr.s_addr = inet_addr(DEST_IP); 
	bzero(&(dest_addr.sin_zero), 8); /* zero the rest of the struct */ 

	if(connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(struct sockaddr)) == -1)
	{
		printf("Connection Error, %d\n", errno); 
		close(sockfd); 
		exit(1); 
	}

	//发送
	char *msg = "'花果山','--','2级','性能告警','#559944'"; 
	int len, send_msg, bytes_sent; 
	len = strlen(msg); 
	bytes_sent = send(sockfd, msg, len, 0); 

	//关闭
	close(sockfd);
}

