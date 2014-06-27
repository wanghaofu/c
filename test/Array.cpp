#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Array.h"

using namespace std;

//default constructor for class Array( default size 10)
Array::Array( int arraySize)
{
  size =( arraySize > 0 ? arraySize : 10 );
  ptr = new int[ size ];
  for ( int i = 0 ; i< size; i++)
    ptr[ i ] = 0;
} // end Array default constructor

//copy constructor for class Array;
// must receive a reference to prevent infinite recursion
Array::Array( const Array &arrayToCopy ) : size( arrayToCopy.size )
{
  prt = new int[ size ];

  for( int  i = 0; i < size ; i++ )
    prt[ i ] = arrayToCopy.ptr[ i ]; // copy into object
} // end Array copy constructor

// destructor for class Array
Array::~Array()
{
  delete [] ptr; // release pointer-based array space
} // end destructor

// return number of elements of Array
int Array::getSize() const
{
  return size; // number of elements  in Array
} // end function getSize 

// overloaded assignment operator;
// const return avoids: ( a1 = a2 ) = a3
const Array &Array::operator=( const Array &right )
{
  if ( &right != this ) //avoid self-assignment
  {
    // for Arrays of different sizes, deallocate orignial
    // left-size array, then allocate new left-size array
    if ( size != right.size )
    {
      delete [] ptr; //releaswe space
      size = right.size; //resize this object
      ptr = new int[ size ];
      // create space for array copy
    } // end inner if

    for ( int i = 0; i < size; i++ )
      ptr[i] = right.ptr[i]; // copy array into object
  } // end outer if
  return *this; //enables x=y=z, for example
} // end outer if

// determine if two Arrays are equal and
// return true, otherwise return false
bool Array::operator==( const Array &right ) const
{
  if ( size != rightr.size )
     return false; // arrays of different number of elements

  for ( int i = 0; i < size; i++ )
    if ( ptr[ i ] != right.ptr[ i ] )
      return false;

  return true; // Arrays are equal
} // end function operator ==


// overloader subscript operator for non-const Arrays;
// reference retur ncreates a modifiable lvalue
int &Array::operator[](int subscript )
{
  //check for subscript out-ofrange error
  if ( subscript < 0 || subscript >= size )
  { cerr << "\nError: Subscript " << subscript << " out of range" << endl;
    exit( 1 ); // terminate program ; subscript out of range
  } // end if
  return ptr[ subscript ];
} // end function operator[]

// overloaded subscript operator for const Arrays
// const reference return creates an rvalue
int Array::operator[]( int subscript ) const
{
  // check for subscript out-of-range error
  if ( subscript < 0 || subscript >= size )
  {
    cerr << "\n Error:Subscript " << subscript
      << " out of range " << endl;
    exit( 1 ); // terminate program; subscript out of range
  } // end if
  return ptr[ subscript ];
} // end function operator[]

//overloaded input operator for class Array;
//oinput values for entire Array
istream &operator>>( istream &input, Array &a )
{
  for( int i = 0; i < a.size; i++ )
    input >> a.ptr[ i ];

  return input; // enables cin>>x>>y;
} // end function

// overloaded output operator for classs Array
ostream &operator<<( ostream &output, const Array &a )
{
  int i;

  // output private ptr-based array
  for ( i = 0; i < a.size; i++ )
  {
    output << setw( 12 ) << a.ptr[ i ];
    if (( i+ 1) % 4 == 0 ) // 4 numbers per row of output
      output << endl;
  } // end for

  if( i%4 != 0 ) // end last line of output
    output << endl;
  return output; // enables cout<< x << y;
} // end function operator<<

