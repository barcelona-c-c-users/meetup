#include <algorithm>
#include <iostream>
#include <utility>

template<typename T>
class my_basic_string
{
 T* data_;
 size_t size_;

	public:

	my_basic_string(T* data, size_t size) : data_(new T[size]), size_{size} 
	{
		std::copy(data, data + size, data_ );
	};
	
	~my_basic_string()
	{
		if(data_ != nullptr)
			delete[] data_;
		size_ = 0;
	}

	my_basic_string(const my_basic_string& s)  : data_{new T[s.size_]}, size_{s.size_}
	{
	  std::copy(s.data_, s.data_ + s.size_, data_ );
	}

	my_basic_string& operator=(const my_basic_string& s)
	{
//		if(this != &s){
			delete[] data_;
			data_ = new T[s.size_];
			size_ = s.size_;
			std::copy(s.data_, s.data_ + s.size_, data_ );
//		}
		return *this;
	}

	my_basic_string(my_basic_string&& s) noexcept  : data_{std::exchange(s.data_,nullptr)}, size_{std::exchange(s.size_,0)}
	{
	}

	my_basic_string& operator=(my_basic_string&& s) noexcept
	{
//		if(this != &s){
			data_ = std::exchange(s.data_, nullptr); 
			size_ = std::exchange(s.size_,0);
//		}
		return *this;
	}
	
};

using my_string = my_basic_string<char>;

