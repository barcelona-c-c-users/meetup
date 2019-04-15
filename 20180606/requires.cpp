#include <algorithm>
#include <list>
#include <type_traits>
#include <utility>
#include <vector>

using namespace std;

template<typename T, typename U>
constexpr bool Convertible()
{
	return std::is_convertible<T, U>::value;
}


template<typename T>
constexpr bool CopyConstructible()
{
  return  std::is_copy_constructible<T>::value;
}

template<typename T>
concept bool
  CopyAssignable()
{
	return requires(T a, T b){
	{ a = b } -> void;
	};
}


template<typename T>
concept bool
   Destructible()
{
	return requires(T a){
	{ a.~T() } -> void;
	};
}

template<typename T, typename U>
concept bool
Equality_comparable()
{
  return requires (T a, U b) {
      {a == b} -> bool; // a can be compared to b using ==
                       // and returns something 
                       // convertible to bool
     {a != b} -> bool;
		 {b == a} -> bool;
		 {b != a} -> bool;
  };
};

template<typename It>
concept bool Iterator()
{

 return requires (It a, It b) {
		 CopyConstructible<It>;
		 CopyAssignable<It>;
		 Destructible<It>;
    *a;
    {++a} -> It&

  };
};

template<Iterator It>
It find_mikel(It first, It second){

	return first;
};

/*
ForwardIterator

template<typename It>
concept bool ForwardIterator = requires(It i)
{
    requires InputIterator<It>;
    requires DefaultConstructible<It>;

    requires crab::Switch()
        .Case(OutputIterator<It, detail::value_type<It>>)
           .Then(Same<detail::value_type<It>&, detail::reference<It>>)
        .Default()
           .Then(Same<const detail::value_type<It>&, detail::reference<It>>)
    ();

    {i++} -> It;
    {*i++} -> detail::reference<It>;
};
*/



template<typename T>
concept bool Iterable = requires()
{
    typename T::iterator;                    // T tiene tipo miembro "iterator"
    typename std::iterator_traits<T>;        // Instancia de std::iterator_traits es válida
    requires Iterator<typename T::iterator>; // T::iterator satisface el concepto "Iterator"
};


class foo{
private:
	int value;

public:
	friend
	bool operator==(foo const& lhs, foo const& rhs) = delete;
//{
	//	return lhs.value == rhs.value;
//	}

	friend
	bool operator!=(foo const& lhs, foo const& rhs) = delete;
//	{
//		return !(lhs == rhs);
//	}
};

template<typename T>
requires false
class Bar
{

};

int main()
{
	//	foo a;
	std::list<int> l;
	l.emplace(std::begin(l), 0);
	l.emplace(std::begin(l), 1);
	//std::sort(std::begin(l), std::end(l) );
	//	sort_mikel(l);
	std::vector<int> v_int;
	v_int.emplace_back(0);
	auto retIt = find_mikel(std::begin(v_int), std::end(v_int) );
	//Foo<int> o;
	//	Bar<int> f_bar;
	//	Foo<foo> f;
	return 0;
}
