ctest::ctest(){}
ctest::~ctest(){}

void* fnThreadFun(void *para)
{
    return ((void *)0);
}

void ctest::createthread()
{
    pthread_t ntid;
    err = pthread_create(&ntid,NULL,fnThreadFun,NULL);
    if(err != 0 )
    {
        printf("can't create thread: %s\n",strerror(err));
        return 1;
    }
}
