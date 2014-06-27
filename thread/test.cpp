test::test();
{}
test::~test()
{}
void *threadFunction();
{
    printf("This is a Thread");
    for(;;);
}
void test::createThread()
{
    pthread_t threadID;
    pthread_create(&threadID,NULL,threadFunction,NULL);
}

