#include <iostream>
#include <forward_list>
using namespace std;

void print() {}

// Variadics
template <typename T, typename... Types>
void print(const T& first, const Types&... other) {
	cout << first << endl;
	print(other...); // рекурсия в шаблоне!
	cout << "Done: " << sizeof...(other) << endl;
}

double q(double x) { return x * x;  }

template <typename T>
ostream& operator<<(ostream& os, const forward_list<T>& sl) {
	os << "{ ";
	for (const T& v : sl)
		os << v << " ";
	os << "}";
	return os;
}

int main() {
	forward_list<int> sl {1, 2, 3};

	print(7.5, "hello", q(2.0), sl, 42);
}