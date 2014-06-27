#include <iostream>
using std::cout;
using std::endl;

#include "Date.h"

int main()
{
    Date date1(7, 4, 2012);
    Date date2; // date2 defaults to 1/1/2000

    cout << "date1 = " ;
    date1.print();

    cout << "\ndate2 = ";
    date2.print();

    date2 = date1; //default memberwise assignment

    cout << "\n\nAfter default memberwise assignment , date2 = ";
    date2.print();

    cout <<  endl;
    return 0;
} // end main
