#include <atomic>
#include <algorithm>
#include <iostream>

struct normal_deleter{
		void operator()(){
			std::cout << "into operator () normal \n";
		}
};

struct special_deleter{
		void operator()(){
			std::cout << "into operator () special \n";
		}
};

template<typename T>
class default_deleter : T 
{
	public:
		void operator()(){
			  T::operator()();
		}
};

template <typename T, typename Deleter = default_deleter<normal_deleter> >
class smart_ptr : Deleter
{
	T* pointee_;
	std::atomic<size_t>* elements_;
	Deleter d_;
	public:
	explicit smart_ptr(T* pointer) : pointee_(pointer), elements_(new std::atomic<size_t>(1)) 
	{
	}
	
	smart_ptr(T* pointer, Deleter d) : pointee_(pointer), elements_(new std::atomic<size_t>(1)), d_(d)  
	{
			
	}


	~smart_ptr() noexcept
	{

		std::cout << "Into destructor of smart_ptr pointee_ =" << pointee_->data << '\n';
		if( !--*elements_){
		
			delete pointee_;
			//Deleter::operator()();
			d_();
		}
	}

	smart_ptr(smart_ptr const & rhs)
	{
		pointee_ = rhs.pointee_;
		elements_ = rhs.elements_;	
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

