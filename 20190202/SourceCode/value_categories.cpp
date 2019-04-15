#include <iostream>
#include <string>

namespace detail {
	template <class T> struct value_category      { static constexpr char const* value = "prvalue"; };
	template <class T> struct value_category<T&>  { static constexpr char const* value = "lvalue"; };
	template <class T> struct value_category<T&&> { static constexpr char const* value = "xvalue"; };
}

#define PRINT_VALUE_CAT(expr) std::cout << #expr << " is a " << ::detail::value_category<decltype((expr))>::value << '\n'

struct S { int i; };

int&& foo_ref(){return 10;};
int foo(){return 10;};

int main()
{
	PRINT_VALUE_CAT(4); // prvalue
	PRINT_VALUE_CAT('a'); // prvalue
	const char* str = "Hello";

	PRINT_VALUE_CAT(str); // lvalue
	PRINT_VALUE_CAT("Hello"); // lvalue

	int32_t a{0};
	PRINT_VALUE_CAT(a); // lvalue

	int&& r = 42;
	PRINT_VALUE_CAT(r); // lvalue
	PRINT_VALUE_CAT(std::move(r)); // xvalue
	PRINT_VALUE_CAT(foo_ref()); // xvalue
	PRINT_VALUE_CAT(foo()); // xvalue

	int32_t i{0};
	PRINT_VALUE_CAT(++i); // lvalue 
	PRINT_VALUE_CAT(i++); // prvalue

	PRINT_VALUE_CAT(S{0}); // prvalue
	PRINT_VALUE_CAT(S{0}.i); // gcc prvalue clang xvalue ???
}
