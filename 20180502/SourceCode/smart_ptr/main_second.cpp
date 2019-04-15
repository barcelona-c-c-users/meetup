#include "smart_ptr_first.h"
#include <iostream>

using namespace bcn_meetup;

struct foo{
	foo(){
		std::cout << "into foo constructor\n";
	}

	~foo(){
		std::cout << "into foo destructor\n";
	}

	int data;
};

int main()
{
	smart_ptr<foo> f(new foo);
	
	f->data=10;
	std::cout << "f data val = " << (*f).data << '\n';

	return 0;	
}

