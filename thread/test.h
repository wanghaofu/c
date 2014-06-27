#ifndef TEST_H
#define TEST_H

class test
{
    public:
        test();
        ~test();
        void createThread();
    private:
        void *createfunction();
};
#endif
