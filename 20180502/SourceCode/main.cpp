#include <iostream>
#include "smart_ptr.h"

struct foo{

	foo(): data{10}
	{
		std::cout << "Into constructor" << '\n'; 
	}

	~foo()
	{
		std::cout << "Into destructor of foo" << '\n';
 	}

	int data;
};

struct baz{

	baz(): data{5}
	{
		std::cout << "Into constructor" << '\n'; 
	}

	~baz()
	{
		std::cout << "Into destructor of foo" << '\n';
 	}

	int data;
};

int main()
{
	smart_ptr<foo> f(new foo);	
	std::cout << " 	(*f).data=	" << 	(*f).data	<< '\n'; 
	std::cout << " 	f->data=	" << 	f->data	<< '\n'; 

	auto f2(f);
	std::cout << " 	f2->data=	" << 	f2->data	<< '\n'; 
	auto f3 = f;
	smart_ptr<baz> b(new baz);

	smart_ptr<baz> b2(new baz);

	auto b3 = std::move(b2);

	std::cout << "b3 use_count =	" << 	b3.use_count() 	<< '\n'; 
	std::cout << "b2 use_count =	" << 	b2.use_count() 	<< '\n'; 

	std::cout << "f->data =	" << 	f.use_count() 	<< '\n'; 

}

