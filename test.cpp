#include <iostream>
using namespace std;

//函数模板
template<typename  iname>
int setName()
{
}

template <class T>
void setname(T name)
{
    cout << "hello";
}



int main()
{
	int numberOfLanguages;
	cout << "Hello reader .\n"
		<< "Welcome c++.\n";
	cout << "How many programming languages have you userd?";
	cin >> numberOfLanguages;

	if (numberOfLanguages < 1)
		cout << "Read thr preface. You may prefer\n"
			  << "a more elementary book by the same author.\n";
	else
		cout << "Enjoy the book.\n";
	return 0;

}
