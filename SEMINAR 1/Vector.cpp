#include <iostream>
#include <initializer_list>

template<typename T> class DynamicArray {
protected:
    T* data;
    int size;
public:
    DynamicArray() {
        this->size = 0;
        this->data = nullptr;
    }

    DynamicArray(int size) {
        this->size = size;
        this->data = new T[size];
    }

    ~DynamicArray() {
        delete[] data;
    }

    int getSize() {
        return this->size;
    }

    T& operator[](int index) {
        if (index < 0 || index >= this->size) {
            throw "Index out of range";
        }
        return this->data[index];
    }

    void resize(int newSize) {
        T* newData = new T[newSize];
        int copySize = (newSize > this->size) ? this->size : newSize;
        for (int i = 0; i < copySize; i++) {
            newData[i] = this->data[i];
        }
        delete[] this->data;
        this->data = newData;
        this->size = newSize;
    }
};

template <typename T, unsigned defsize = 0> class Vector : DynamicArray<T*> {
protected:
	T* v;
	unsigned len;
	static const unsigned _defsize = defsize;
public:
	explicit Vector(unsigned N = _defsize) : v(nullptr), len(0) {
		if (N > 0) v = new T[N];
		if (v) len = N;
		std::cout << "base: " << N << std::endl << std::flush;
	}
	~Vector () {};
	//................
};

/*template <> class Vector<bool> {
protected:
	unsigned char* v;
	unsigned len;
	static const unsigned _defsize = 16;
	bool getbit(unsigned msb, unsigned char byte) { return byte & (0x80 >> msb); }

public:
	explicit Vector(unsigned N = _defsize) : v(nullptr), len(0) {
		if (N > 0) v = new unsigned char[N/8];
		if (v) len = N;
	}
	Vector(std::initializer_list <T> l) : {
	    cout << "Constructed with initializer list" << endl;
	}
	bool operator[] (unsigned i) {
		unsigned char b = v[i / 8];
		return getbit(i % 8, b) == 0 ? false : true;
	}
	//.............
};*/

/*template <typename T, unsigned _defsize> class Vector<T*, _defsize>  : Vector<void*> {
public:
	// Конструктор
	Vector(unsigned N = _defsize) : Vector<void*>(N) { std::cout << "!!!" << N << "!!!" << std::endl << std::flush;	}
	
	//.............
	T* operator[] (unsigned i) {
		return (T*)v[i];
	}
};*/

int main(void)
{
    Vector<double>    dv(100);
    //Vector<double,10> ddv;

    //Vector<char>      cv(10);   

    //Vector<const char*> pv(20);
    //Vector<int*>        pv1(200);
    //Vector<double*,300> pv2;

    //Vector<Vector<double,10>,10> mat;

    //Vector<bool> bv(1000);
}

