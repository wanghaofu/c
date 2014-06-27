#include "ctest.h"

int main()
{
    ctest tst;
    tst.createthread();

    while(1)
    {
        sleep(1);
    }
    return 0;
}
