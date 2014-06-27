#include "stdio.h"
main()
{
	int i;
	for(i=1;i<=100;i++)
	{
		if( ( i%3==0) && (i%5==0) )
		 printf("%10s","fizzBuzz");
		else if(i%3==0)
		 printf("%10s","Fizz");
		else if(i%5==0) 
		 printf("%10s","Buzz");
		else
		 printf("%10d",i);
		if(i%5==0 )
		 printf("\n");
	}
    printf("this end haha ");
    printf("only output to screen");
    printf("how to write");
    printf("output to file");
	return(0);
}
