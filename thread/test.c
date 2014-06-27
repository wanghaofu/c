#include <stdio.h>
#include <pthread.h>
int i;
pthread_mutex_t mutex;
pthread_cond_t cond;
unsigned count;
struct timespec delay;

void thread(void)
{
    while(1)
    {pthread_mutex_lock(&mutex);
    while(i <10 )
    {
        pthread_cond_wait(&cond,&mutex);
    }
    i = i+3;
      printf("This is a pthread %d.\n",i);
      pthread_mutex_unlock(&mutex);
       usleep(3000000);
    }
}
void squence(void)
{ 
    while(1)
    {
     pthread_mutex_lock(&mutex);
      if(i >10)
        pthread_cond_signal(&cond);
        i=i+1;
        printf("sssssssssssssssssssssssssssssssssssssssssssssssssssss %d\n",i);
        pthread_mutex_unlock(&mutex);
        usleep(2000000);
    }
}
void task(void)
{
    while(1)
    {
        i=i+1;
    printf("ttttttttttt%d\n",i);
    usleep(1000000);
    }
}
int main(void)
{
    pthread_t id1,id2,id3;
    int ret;
    pthread_mutex_init(&mutex,NULL);
    ret=pthread_create(&id1,NULL,(void *) thread,NULL);
     ret=pthread_create(&id2,NULL,(void *) squence,NULL);
      ret=pthread_create(&id3,NULL,(void *) task,NULL);
    // pthread_join(id,NULL);
    //for(i=0;i<1000;i++)
     // printf("This is the main process.\n");
     sleep(1000);
     while(1)
     {}
    return (0);
}

