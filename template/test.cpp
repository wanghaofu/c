#include <iostream>
#include "ClassTemplate.h"
using std::cout;
using std::endl;


template <typename T>
void print(T v)
{
    T::iterator itor;
    for(itor = v.begin();itor!=v.end();++itor)
    {
        cout << *itor <<" ";
    }
    cout << endl;
}



int main()
{
    myClass<int,int> class1(3,5);
    class1.show();

    myClass<int,char> class2(3,'a');
    class2.show();

    myClass<double,int> class3(2.9,10);
    class3.show();

//useing template
    list<int> l;
    
    l.push_back(1);
    l.push_front(2);

    if(!l.empty())
      print(l);

    
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(6);
    if(!vec.empty())
      print(vec);

}
