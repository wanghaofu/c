//#include "stdafx.h"
#include <iostream>

template <typename T, typename T2> //加法模板函数
T Add(T x,T2 y)
{
    return x+y;
}
template <typename T>
T Add(T x,T y,T z)
{
    return x+y*z;
}
template <typename S>
S haha(S n, S m, int i)
{
    S g;
    g= n+m+i;
    return g;
}

int main()
{
    std::cout<<Add(10,20,30);
    int n=20, m=50;
    std::cout<<haha(n,m,10)<<std::endl;

    double x=10.2 ;
    int y=10;
    std::cout<<Add(x,y)<<std::endl;


    double x1=10.10,y1=10.11;
    std::cout<<Add(x1,y1)<<std::endl;

    long x2=999, y2=9999;
    std::cout<<Add(x2,y2)<<std::endl;

    return 0;
}
