#include "my_basic_string.h"
#include <chrono>
#include <string.h>
#include <vector>

int main()
{
	char text[] = "Hello from Barcelonas best meetup";  
	my_string str(text,  strlen(text) + 1 );	

	std::vector<my_string> vec(1000,str);

	auto start = std::chrono::high_resolution_clock::now();

	auto it = std::cbegin(vec);
	vec.insert(it,str);

	auto elapsed = std::chrono::high_resolution_clock::now() - start;
	long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
	std::cout << "This code took " << microseconds << " microseconds to execute." << std::endl;
	return 0;
}
