#include <iostream>
using std::cout;
using std::endl;

void useLocal( void );
void useStaticLocal( void );
void useGlobal (void ) ; 

int x = 1 ; //global variable  declared

int main()
{
    int x= 5; //local variable to main
    cout <<" local x in main's outer scope is " << x <<endl;
    
    {//start new scope
            int x=7;
            cout << "local x in main's inner scope is " << x << endl;
    }
    cout << "local x in main's outer scope is " << x << endl;
    
    useLocal(); // useLocal has local x
    useStaticLocal(); //useStaticLocal has static local x
    useGlobal(); //useGlobal uses global x
    useLocal(); //useLocal reinitializes  its local x
    useStaticLocal(); // static local x retains its prior value
    useGlobal(); //global x also retains its value

    cout << "\nlocal x in main is " << x << endl;
    return 0;
}

void useLocal( void )
{        int x= 25; // initialized cach time useLocal is called
        cout << "\nlocal x is " << x << " on entering useLocal " << endl;
        x++;
        cout << "local x is " << x << " on exiting useLocal " << endl;
}
void useStaticLocal( void )
{
    static int x=50;
    cout << "\nlocal static x is " << x << " on entering useStaticLocal"<<endl;
    x++;
    cout << "local static x is " << x << " on exiting useStaticLocal" << endl;
}

void useGlobal( void )
{
    cout << "\nglobal x is " << x << " on entering useGlobal " << endl;
    x *= 10;
    cout << "global x is " << x << " on exiting useGlobal" << endl;
}


