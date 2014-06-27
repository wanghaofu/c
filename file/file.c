/**
  A test about syscall of File I/O
Author:supu@TaobaoDBA
supu@taobao.com http://orczhou.com http://www.taobaodba.com
 */

#include   "stdlib.h"           /* for exit */
#include   "unistd.h"           /* for write fdatasync*/
#include    "fcntl.h"           /* for open  */
int main(void){
	int fd;
	if((fd=open("/test.file",O_WRONLY|O_APPEND|O_DSYNC))<0){
		exit(1);
	}
	char buff[]="\nhello wangtao \n";
	if(write(fd,buff,16)!= 16){
		exit(2);
	}
	if(fdatasync(fd)==-1){
		exit(3);
	}
	exit(0);
}

