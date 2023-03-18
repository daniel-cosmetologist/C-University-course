#include <algorithm>
using namespace std;

class A {
	int* p;
	unsigned dim;
public:
	int operator [](int i) { return p[i];  }
};

template <typename T>
class F {
	T a;
public:
	F() : a(1.0) {}
	T operator() (T x, T y) { return x + y + a; }
	T operator() (T x, T y, T z) { return x + y + z; }
};

template <typename T>
class cmp {
public:
	bool operator() (const T& x, const T& y) { return x + 1 < y; }
};


void ff(double dif) {
	F<double> fun;
	double res1 = fun(1.5, 2.5);
	double res2 = fun(1.0, 2.0, 3.0);

	double A[] = {1,5,3,4,2};
	double a{2};

	sort(begin(A), end(A), cmp<double>());

	{
		sort(begin(A), end(A), [](double x, double y) {return x < y;});
		sort(begin(A), end(A), [=](double x, double y) {return x + dif < y;});
		sort(begin(A), end(A), [&](double x, double y) {return x + (--dif) < y;});
		sort(begin(A), end(A), [&, a](double x, double y) {return x + (--dif) * a < y;});
		sort(begin(A), end(A), [=, &dif](double x, double y) {return x + (--dif) * a < y;});
	}
}