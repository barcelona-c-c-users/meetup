namespace bcn_meetup
{

template <typename T>
class smart_ptr{
	public:
		smart_ptr(T* pointer) : pointee_(pointer){
		}

		~smart_ptr()
		{
			delete pointee_;
		}	

		T??? operator->(){
		 	return pointee_;
		}

		T??? operator*(){
			return *pointee_;
		}

	private:
	T* pointee_;
};

}
