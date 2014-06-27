#include <iostream>
#ifndef ClassTemplate_HH
#define ClassTemplate_HH

using std::cout;
using std::endl;
//define template class
template <typename T1,typename T2>
class myClass{
    private:
        T1 I;
        T2 J;
    public:
        myClass(T1 a,T2 b);
        void show();
};

//This is construct function
//Notice this formate
template <typename T1, typename T2>
myClass<T1,T2>::myClass(T1 a,T2 b):I(a),J(b){}
//This is void show();

template <typename T1,typename T2>
void myClass<T1,T2>::show()
{
    cout<<"I="<<I<<",J="<<J<<endl;
}
#endif


