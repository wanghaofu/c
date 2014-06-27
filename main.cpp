#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define MAX_LINE 40
#define FILENAME "myfile.txt"
//最大客户端数量定义
#define LISTEN_NUM 20
#define BUFLEN 1024

using namespace std;

typedef struct {
    int id;
    float x_coord;
    float y_coord;
    char name[MAX_LINE+1];
} MY_TYPE_T;

#define MAX_OBJECTS 3

/* Initialize an array of three objects */

MY_TYPE_T objects[MAX_OBJECTS]={
    {0,1.5,8.4,"First-object"},
    {1,9.2,7.4,"Second-object"},
    {2,4.1,5.6,"Final-object"},
};

int _log(char * );
int server();
void  _read_log();
int main(int argc , char *argv[] )
{
   server();  

}
int server()
{
    int sock,sock_new;
    int buf_len;
    socklen_t sin_size=sizeof(struct sockaddr);
    int re,se;
    char *buf_r=new char[BUFLEN];
    char *buf_s=new char[BUFLEN];
    struct sockaddr_in my_addr;
    struct sockaddr_in ob_addr;

    sock=socket(AF_INET,SOCK_STREAM,0);
    if(sock==-1) {cout<<"socket error"<<endl;exit(0);}
    else {cout<<sock<<endl;}
    
    my_addr.sin_family=AF_INET; 
    my_addr.sin_port=htons(3490); 
    my_addr.sin_addr.s_addr=INADDR_ANY;
   
    if(bind(sock,(struct sockaddr *)& my_addr,sizeof(struct sockaddr))<0)
    {
        cout<<"bind error"<<endl;
        exit(0);
    }
    cout<<"socket port: "<<ntohs(my_addr.sin_port)<<endl;
    if(listen(sock,LISTEN_NUM)<0)
    {
        cout<<"listen error"<<endl;
        exit(0);
    }
    while(1)
    {
        sock_new=accept(sock,(sockaddr *)&ob_addr,&sin_size); //parent all time to accept the link
        if(sock_new<0)
        {
            cout<<"accept error"<<endl;
            exit(0);
        }
        else
        {
            int p=fork(); //
            if(p==0) //child process 
            {
                cout<<"connect to :"<<inet_ntoa(ob_addr.sin_addr)<<" : "<<htons(ob_addr.sin_port)<<endl;
                int s=fork();
                if(s==0)   //child process
                {
                    do
                    { 
                        memset(buf_r,0,sizeof(buf_r));
                        re=recv(sock_new,buf_r,BUFLEN,0);

                        if(re==-1) 
                        {
                            cout<<"recv error"<<endl;
                            exit(0);
                        }
                        else if(re==0)
                        {
                            cout<<inet_ntoa(ob_addr.sin_addr)<<"connection ended"<<endl;
                            close(sock_new);
                        }
                        else
                        {

                            cout<<inet_ntoa(ob_addr.sin_addr)<<": "<<htons(ob_addr.sin_port) << " -> "<<buf_r<<endl;
                            _log(buf_r);
                        }
                    }while(re>0);
                }
                else
                {
                    do
                    {
                        cout<<"connect from :"<<inet_ntoa(ob_addr.sin_addr)<<" : "<<htons(ob_addr.sin_port)<<endl;
                        cout <<"Input you content:";
                        memset(buf_s,0,sizeof(buf_s));
                        cin.getline(buf_s,BUFLEN);
                        se=send(sock_new,buf_s,BUFLEN,0);
                        if(se==-1)
                        {
                            cout<<"send error"<<endl;
                            exit(0);
                        }
                        else 
                        {
                            cout<<"sended!"<<endl;
                        }
                    }while(1);
                }
            }
        }
    } 
    close(sock);
    return 0;
}



int _log(char *message)
{
    int i;
    FILE *fout;
    int status;
    /* Open the output file*/
    fout = fopen(FILENAME, "a+");
    if(fout==(FILE *)0)
    {
        exit(-1);
    }
    /* Emit each of the objects,one per line*/

    status = fputs(message,fout);
    fclose(fout);
    return status;
}
void _read_log()
{
    int i;
    // read a file
    char str[1024];
    FILE *fin;
    i=0;
    fin = fopen("/var/log/boot.log","r");

    if(fin==(FILE *)0) exit(-1);
    while(false == feof(fin))
    {
        i++;
        fgets(str,1024,fin);
        printf("%d lin The boots file content is :%s",i,str);
    }


    fclose(fin);
}


