#include <memory>
#include <iostream>
#include "smart_ptr.h"

struct foo{

	foo(): data{10}
	{
		std::cout << "Into constructor of baz" << '\n'; 
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
		std::cout << "Into constructor of baz" << '\n'; 
	}

	~baz()
	{
		std::cout << "Into destructor of baz" << '\n';
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
	
//	std::function<void()> l = [=](){ std::cout<< " Lambda function" << '\n'; }; 
	std::function<void(void)> func = [&](){ std::cout<< " Lambda function" << '\n'; }; 

	//smart_ptr<foo, sp_deleter< std::function<void(void)> > > f_delete(new foo, func);

//	std::shared_ptr<foo> f_shared_ptr(new foo,  [](){ std::cout << "Into shared_ptr destructor" << std::endl;} ) ;
	{
	std::shared_ptr<foo> sh5(new foo, [](auto p) {
			           std::cout << "Call delete from lambda...\n";
								            delete p;
														        });
	}

	smart_ptr<foo, decltype(func) > f_del(new foo, func );

}

