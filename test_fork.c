#include <sys/types.h>
#include <unistd.h> //This must include the support is by system
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	pid_t pid;
    cout << "This is c/c++ check"<< endl;
	int a,b;
	a=0;
	b=0;
	printf("test fork() program\n");
	printf("I am the parent process,my pid is %d\n",getpid());
	printf("the address of a is %x\n",&a);
	printf("the address of b is %x\n",&b);
	printf("------------------------------------\n");
	pid=fork();
    cout <<"pid is" << pid<<endl;
	if(pid<0)
	 printf("fork error\n");
	else if(pid==0)
	{
		printf("I am the child process,my pid is %d\n",getpid());
		printf("a=%d\n",a);
		printf("b=%d\n",b);
		printf("the address of a is %x\n",&a);
		printf("the address of b is %x\n",&b);
		a=1;
		printf("a=%d\n",a);
		printf("b=%d\n",b);
		printf("the address of a is %x\n",&a);
		printf("the address of b is %x\n",&b);
	}
	else
	{
		printf("I am the parent process,my pid is %d\n",getpid());
		printf("a=%d\n",a);
		printf("b=%d\n",b);
		printf("the address of a is %x\n",&a);
		printf("the address of b is %x\n",&b);
		b=100;
		printf("a=%d\n",a);
		printf("b=%d\n",b);
		printf("the address of a is %x\n",&a);
		printf("the address of b is %x\n",&b);
	}
	return 0;
 
}


