#include <atomic>
#include <algorithm>
#include <cstddef>

namespace bcn_meetup
{
template <typename T>
class smart_ptr{
	public:
		explicit smart_ptr(T* pointer) : pointee_(pointer), 
																		elements_(new std::atomic<size_t>(1))
		{
		
		}

		~smart_ptr() noexcept 
		{
			--*elements_;
			if(*elements_ == 0){
				delete pointee_;
				delete elements_;
			}
		}	

		smart_ptr(const smart_ptr& rhs )
		{
			pointee_ = rhs.pointee_;
			elements_ = rhs.elements_;
			++*elements_;
		}

		smart_ptr& operator=(smart_ptr const& rhs)
		{
			if(rhs != *this){
				smart_ptr<T> temp(rhs);
				std::swap(*this,temp);
			}
			return *this;
		}	

		T* operator->(){
		 	return pointee_;
		}

		T&  operator*(){
			return *pointee_;
		}

	private:
	T* pointee_;
	std::atomic<std::size_t>* elements_;
};

}
