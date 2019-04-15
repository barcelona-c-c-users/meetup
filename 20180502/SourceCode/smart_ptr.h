#include <atomic>
#include <algorithm>
#include <iostream>

template <typename T>
struct Deleter{
	public:
				Deleter(){	}

		//	int operator()(int y) const { return y; }
		/*	int mikel(int x){

					std::cout << "deleter called" << '\n';
				return 0;
			}

	*/
			void operator(){	std::cout << "deleter called" << '\n'; }

};



template <typename T, typename D = Deleter<T> >
class smart_ptr
{
	T* pointee_;
	D d;
	std::atomic<size_t>* elements_;

	public:
	explicit smart_ptr(T* pointer) : pointee_(pointer), elements_(new std::atomic<size_t>(1)) 
	{

	}

	~smart_ptr() noexcept
	{
		std::cout << "Into destructor of smart_ptr pointee_ =" << pointee_->data << '\n';
		if( !--*elements_){
			delete pointee_;
			delete elements_;
		}
		d(12);
	}

	smart_ptr(smart_ptr const& rhs)
	{
		pointee_ = rhs.pointee_;
		elements_ = rhs.elements_ ;	
		++*elements_;
	}

	smart_ptr& operator=(smart_ptr const& rhs)
	{
		smart_ptr temp(rhs);
		std::swap(*this,temp);
		return *this;
	}

	smart_ptr(smart_ptr&& rhs)
	{
		pointee_ = std::move(rhs.pointee_);
		elements_ = rhs.elements_;	
	}

	smart_ptr& operator=(smart_ptr&& rhs)
	{
		smart_ptr temp(std::forward(rhs));
		std::swap(*this,temp);
		return *this;
	}

	size_t use_count() const noexcept
	{
		return *elements_;
	}

	T& operator*() const noexcept 
	{
		return *pointee_;
	} 

	T* operator->() const noexcept
	{
		return pointee_;
	}

};

