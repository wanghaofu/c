//#include "stdafx.h"
#include <iostream>
#include <string>

template <typename T>
class BinaryOperation
{
    private:
        T x;
        T y;
        char op;
        void add()
        {
            std::cout<<x<<op<<y<<"="<<x+y<<std::endl;
        }
        void sub()
        {
            std::cout<<x<<op<<y<<"="<<x-y<<std::endl;
        }
        void mul();
        void div();
    public:
        BinaryOperation(T x, T y):x(x),y(y)
    {
    }
        void determineOp(char op);
};

//在类外定义成员函数：
//在成员杉树定义之前进行模板声明，
//且在成员函数名之前加上"类名<类型参数>::"
template <typename T>
void BinaryOperation <typename T>::mul()
{
    std::cout<<x<<op<<y<<"="<<x*y<<std::endl;
}

template <typename T>
void BinaryOperation <typename T>::div()
{
    std::cout<<x <<op<<y<<"="<<x/y<<std::endl;
}

template <typename T>
void BinaryOperation <typename T>::determineOp(char op)
{
    this->op = op;
    switch(op)
    {
        case '+':
            add();
            break;
        case '-':
            sub();
            break;
            cat '*':
                mul();
            break;
        case '/':
            div();
            break;
        default:
            break;
    }
}
int main()
{
    BinaryOperation<int> op(10,10);
    op.determineOp('+');
    op.determineOp('-');
    op.determineOp('*');
    op.determineOp('/');

    return 0;
}
