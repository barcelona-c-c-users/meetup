#include <algorithm>
#include <list>

int main(){
	std::list<int> l{ 1,3,5,7,9,7,5,3,1};
	std::sort(std::begin(l), std::end(l) );

	return 0;
}

