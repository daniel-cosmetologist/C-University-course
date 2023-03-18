#include <iostream>
using namespace std;

class Complex 
{
protected:
	double a, b;
public:
	explicit Complex(double na = 0, double nb = 0) : a(na), b(nb) {};
	Complex(const Complex& src) : a(src.a), b(src.b) {};
	~Complex() { cout << "RIP: (" << a << ", " << b << ")" << endl << flush; };

	Complex& operator= (const Complex& src) { a = src.a; b = src.b; return *this; };
	Complex& operator+= (const Complex& src) { a += src.a; b += src.b; return *this; };
	Complex& operator-= (const Complex& src) { a -= src.a; b -= src.b; return *this; };

	Complex operator+ (const Complex& src2) const {	Complex res(*this);	res += src2; return res; }
	Complex operator- (const Complex& src2) const {	Complex res(*this);	res -= src2; return res; }
	Complex operator* (const Complex& src2) const {	Complex t(*this); Complex res; 
													res.a = t.a * src2.a - t.b * src2.b;
													res.b = t.b * src2.a + t.a * src2.b;
													return res;	}
	Complex operator/ (const Complex& src2) const {
		Complex t(*this);
		Complex res;
		res.a = (t.a * src2.a + t.b * src2.b) / (src2.a * src2.a + src2.b * src2.b);
		res.b = (t.b * src2.a - t.a * src2.b) / (src2.a * src2.a + src2.b * src2.b);
		return res;
	};

	double Re() const { return a; };
	double Im() const { return b; };
};


ostream& operator<<(ostream& os, const Complex& src) {
	os << "(" << src.Re() << ", " << src.Im() << ")" << flush;
	return os;
}

istream& operator>> (istream& is, Complex& r) {
	double na, nb = 0;
	is >> na;
	char c; 
	is >> c;
	if (c == '/') is >> nb;
	r = Complex(na, nb);
	return is;
}

class Array {
protected:
	Complex* arr;
	int len;
public:
	Array(int N = 0) : arr(0), len(0) {
		if (N > 0) arr = new Complex[N];
		if (arr) len = N;
	}
	Array(const Array& t) : arr(0), len(0) {
		if (t.len > 0) arr = new Complex[t.len];
		if (arr) {
			len = t.len;
			for (int i = 0; i < len; i++) {
				arr[i] = t.arr[i];
			}
		}
	}

	int size() const { return len; }

	Complex& operator[](int ind) {
		return arr[ind];
	}
	Complex operator[](int ind) const{
		return arr[ind];
	}

	~Array() { delete[] arr; }

	void insert(Complex x, int index) {
		Array t = *this;
		delete[] arr;
		arr = new Complex[len + 1];
		len = len + 1;
		for (int i = 0; i < len; i++) {
			if (i < index) {
				arr[i] = t[i];
			}
			if (i == index) {
				arr[i] = x;
			}
			if (i > index) {
				arr[i] = t[i - 1];
			}
		}

	}

	void erase(int index) {
		Array t = *this;
		delete[] arr;
		arr = new Complex[len - 1];
		len = len - 1;
		for (int i = 0; i < len; i++) {
			if (i < index) {
				arr[i] = t[i];
			}
			if (i >= index) {
				arr[i] = t[i + 1];
			}
		}
	}

};

ostream& operator<<(ostream& os, const Array& src) {
	for (int i = 0; i < src.size(); i++) {
		os << src[i] << endl;
	}
	return os;
}

int main() {
	Complex A0;
	Complex a(1);
	Complex b(2, 4);
	Complex c(6, 7);
	Array p(3);
	p[0] = a;
	p[1] = b;
	p[2] = c;
	cout << p << endl;
	Array PL;
	cout << PL;
	Complex d(0, 1.5);
	p.insert(d, 2);
	cout << p << endl;
}