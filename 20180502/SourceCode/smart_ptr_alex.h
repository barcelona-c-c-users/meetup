template <class T>
class DefaultSPStorage
{
	protected:
		typedef T* StoredType;
		//the type of the pointee_ object
		typedef T* PointerType;
		//type returned by operator->
		typedef T& ReferenceType; //type returned by operator*
	public:
		DefaultSPStorage() : pointee_(Default())
	{}
		DefaultSPStorage(const StoredType& p): pointee_(p) {}
		PointerType operator->() const { return pointee_; }
		ReferenceType operator*() const { return *pointee_; }
		friend inline PointerType GetImpl(const DefaultSPStorage& sp)
		{ return sp.pointee_; }
		friend inline const StoredType& GetImplRef(
				const DefaultSPStorage& sp)
		{ return sp.pointee_; }
		friend inline StoredType& GetImplRef(DefaultSPStorage& sp)
		{ return sp.pointee_; }
	protected:
		void Destroy()
		{ delete pointee_; }
		static StoredType Default()
		{ return 0; }
	private:
		StoredType pointee_;
};



template
<
typename T,
template <class> class OwnershipPolicy = RefCounted,
class ConversionPolicy = DisallowConversion,
template <class> class CheckingPolicy = AssertCheck,
template <class> class StoragePolicy = DefaultSPStorage
>
class SmartPtr;





