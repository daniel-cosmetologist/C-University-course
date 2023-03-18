#include <iostream>
#include <string>
#include <tuple>
using namespace std;

typedef tuple<string, int, double> TU;

TU t{"abc",42,3.14};

auto tt = make_tuple("abc",43,2.18);

void f1() {
	cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;

	double x{};
	string s{"Hi!"};
	int j{42};

	tuple<const double&, string&&, int> tpl(x, std::move(s), j);

	// =, ==, < ....
	// a <=> b
	// <<, >> 

	auto nt = std::tie(s, j, x);

	std::tie(s, std::ignore, x) = t;

	cout << tuple_size<TU>::value;

	tuple_element<0, TU>::type ss;

	auto dt = tuple_cat(make_tuple("xyz",2.71), std::tie(s));
}