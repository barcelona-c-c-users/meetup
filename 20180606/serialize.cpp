#include <iostream>
#include <type_traits>


/*     
//this goes in some header so you can use it everywhere
template<typename T>
struct TypeSink{
    using Type = void;
};

template<typename T>
using TypeSinkT = typename TypeSink<T>::Type;
     
//use case
template<typename T, typename=void>
struct HasBarOfTypeInt : std::false_type{};

template<typename T>
struct HasBarOfTypeInt<T, TypeSinkT<decltype(std::declval<T&>().*(&T::bar))>> 
		: std::is_same<typename std::decay<decltype(std::declval<T&>().*(&T::bar))>::type,int>{};
     
struct S{
   int bar;
};

struct K{
  
};
     
template<typename T, typename = TypeSinkT<decltype(&T::bar)>>
void print(T){
	std::cout << "has bar" << std::endl;
}
void print(...){
	std::cout << "no bar" << std::endl;
}
     
int main(){
    print(S{});
    print(K{});
    std::cout << "bar is int: " << HasBarOfTypeInt<S>::value << std::endl;
}
*/
#include <iostream>
#include <type_traits>
#include <string>

template <class T>
struct hasSerialize
{
    // For the compile time comparison.
    typedef char yes[1];
    typedef yes no[2];

    // This helper struct permits us to check that serialize is truly a method.
    // The second argument must be of the type of the first.
    // For instance reallyHas<int, 10> would be substituted by reallyHas<int, int 10> and works!
    // reallyHas<int, &C::serialize> would be substituted by reallyHas<int, int &C::serialize> and fail!
    // Note: It only works with integral constants and pointers (so function pointers work).
    // In our case we check that &C::serialize has the same signature as the first argument!
    // reallyHas<std::string (C::*)(), &C::serialize> should be substituted by 
    // reallyHas<std::string (C::*)(), std::string (C::*)() &C::serialize> and work!
    template <typename U, U u> struct reallyHas;

    // Two overloads for yes: one for the signature of a normal method, one is for the signature of a const method.
    // We accept a pointer to our helper struct, in order to avoid to instantiate a real instance of this type.
    // std::string (C::*)() is function pointer declaration.
   // template <typename C> static yes& test(reallyHas<std::string (C::*)(), &C::serialize>* /*unused*/) { }
    template <typename C> static yes& test(reallyHas<std::string (C::*)() const, &C::serialize>* /*unused*/) { }

    // The famous C++ sink-hole.
    // Note that sink-hole must be templated too as we are testing test<T>(0).
    // If the method serialize isn't available, we will end up in this method.
    template <typename> static no& test(...) { /* dark matter */ }

    // The constant used as a return value for the test.
    // The test is actually done here, thanks to the sizeof compile-time evaluation.
    static const bool value = sizeof(test<T>(0)) == sizeof(yes);
};

struct A{
	std::string to_string() const{
		return "Hello from A";
	}

};

struct B{

	std::string serialize() const{
		return "Hello from B";
	}
};


template <class T> 
typename std::enable_if<hasSerialize<T>::value, std::string>::type serialize(const T& obj)
{
    return obj.serialize();
}

template <class T> 
typename std::enable_if<!hasSerialize<T>::value, std::string>::type serialize(const T& obj)
{
    return obj.to_string();
}


int main(){
	std::cout << hasSerialize<A>::value << std::endl;
	std::cout << hasSerialize<B>::value << std::endl;
	A a;
	B b;
	std::cout << serialize(a) << '\n'; 	
	std::cout << serialize(b) << '\n'; 	
	
//				std::cout << hasSerialize<C>::value << std::endl;
}

