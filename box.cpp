#include <iostream>

// Declatation of the Box class
class Box
{
	private:
		int height, width, depth;
	public:
		Box(int, int, int);
		~Box();
		int volume();
};

// Definition of the Box class

//The constructor function
Box::Box(int ht, int wd, int dp)
{
	height = ht;
	width = wd;
	depth = dp;
}

//The destructor function
Box::~Box()
{
	// does nothing
}

// Member function to computer the Box's volume.
int Box::volume()
{
	return height * width * depth;
}

// The main() function 

int main()
{
	//Construct a box object
	Box thisbox(7, 8, 9);

	// Computer and display the object's volume.
	int volume = thisbox.volume();
	std::cout << volume;

	return 0;
}
