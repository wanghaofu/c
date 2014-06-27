/*
 * File: Thread.h
 * Author: kNull
 * Blog: http://hi.baidu.com/hetaoos
 * Created on 2008年7月30日, 上午10:13
 */

/*
 * 在编译的时候记得加上参数：-lpthread
 * 
 */

#ifndef _THREAD_H
#define _THREAD_H


#include <pthread.h>
#include <unistd.h>

class Thread
{
private:
    //当前线程的线程ID
    pthread_t tid;
    //线程的状态
    int threadStatus;
    //获取执行方法的指针
    static void* run0(void* pVoid);
    //内部执行方法
    void* run1();
public:
    //线程的状态－新建
    static const int THREAD_STATUS_NEW = 0;
    //线程的状态－正在运行
    static const int THREAD_STATUS_RUNNING = 1;
    //线程的状态－运行结束
    static const int THREAD_STATUS_EXIT = -1;
    //构造函数
    Thread();
    //线程的运行实体
    virtual void run() = 0;
    //开始执行线程
    bool start();
    //获取线程ID
    pthread_t getThreadID();
    //获取线程状态
    int getState();
    //等待线程直至退出
    void join();
    //等待线程退出或者超时
    void join(unsigned long millisTime);
};

#endif /* _THREAD_H */

void* Thread::run0(void* pVoid)
{
    Thread* p = (Thread*) pVoid;
    p->run1();
    return p;
}

void* Thread::run1()
{

    threadStatus = THREAD_STATUS_RUNNING;
    tid = pthread_self();
    run();
    threadStatus = THREAD_STATUS_EXIT;
    tid = 0;
    pthread_exit(NULL);
}

Thread::Thread()
{
    tid = 0;
    threadStatus = THREAD_STATUS_NEW;
}

bool Thread::start()
{
    return pthread_create(&tid, NULL, run0, this) == 0;
}

pthread_t Thread::getThreadID()
{
    return tid;
}

int Thread::getState()
{
    return threadStatus;
}

void Thread::join()
{
    if (tid > 0)
    {
        pthread_join(tid, NULL);
    }
}

void Thread::join(unsigned long millisTime)
{

    if (tid == 0)
    {
        return;
    }
    if (millisTime == 0)
    {
        join();
    }else
    {
        unsigned long k = 0;
        while (threadStatus != THREAD_STATUS_EXIT && k <= millisTime)
        {
            usleep(100);
            k++;
        }
    }
}

