/*
Вариант 23. Базовый класс - массив чисел, производный класс - матрица размерности 3х3, сумма всех 
элементов которой равна нулю. Должны поддерживаться операции сложения
и умножения на другие матрицы по правилам линейной алгебры.
Определите в нём конструктор, деструктор, оператор копирования. Переопределите операции доступа к
элементу матрицы, +=, -= и *=.
*/

#include <iostream>
#include <initializer_list>

/* template <typename T>
class Array {
protected:
    int size;
    T* arr;
public:
    Array(int s) {
        size = s;
        arr = new double[size];
    }
    virtual ~Array() {
        delete []arr;
    }
    Array(const Array<T>& a) {
        size = a.size;
        arr = new double[size];
        for (int i = 0; i < size; i++) {
            arr[i] = a.arr[i];
        }
    }
    T& operator[](int i) const {
        return arr[i];
    }
};*/

/*-------------------------------------------------------------------*/
//using namespace std;

template<typename T> class Array {
private:
    T *arr;
    int size;
public:
    Array() : arr(nullptr), size(0) {}
    Array(int s) : arr(new T[s]), size(s) {}
    Array(std::initializer_list<T> lst) : arr(new T[lst.size()]), size(lst.size()) {
        std::copy(lst.begin(), lst.end(), arr);
    }
    Array(const Array<T>& rhs) : arr(new T[rhs.size]), size(rhs.size) {
        for (int i = 0; i < size; ++i) {
            arr[i] = rhs.arr[i];
        }
    }
    Array(Array<T>&& rhs) : arr(rhs.arr), size(rhs.size) {
        rhs.arr = nullptr;
        rhs.size = 0;
    }
    virtual ~Array() {
        delete[] arr;
    }
    virtual T& operator[](int i) {
        return arr[i];
    }
    virtual void insert(T val, int pos) {
        T* temp = new T[size+1];
        for (int i = 0, j = 0; i <= size; ++i) {
            if (i == pos) {
                temp[i] = val;
            }
            else {
                temp[i] = arr[j];
                ++j;
            }
        }
        delete[] arr;
        arr = temp;
        ++size;
    }
    virtual void erase(int pos) {
        T* temp = new T[size-1];
        for (int i = 0, j = 0; i < size; ++i) {
            if (i != pos) {
                temp[j] = arr[i];
                ++j;
            }
        }
        delete[] arr;
        arr = temp;
        --size;
    }
    virtual Array<T>& operator=(const Array<T>& rhs) {
        if (this == &rhs) {
            return *this;
        }
        delete[] arr;
        arr = new T[rhs.size];
        size = rhs.size;
        for (int i = 0; i < size; ++i) {
            arr[i] = rhs.arr[i];
        }
        return *this;
    }
    virtual Array<T>& operator=(Array<T>&& rhs) {
        if (this == &rhs) {
            return *this;
        }
        delete[] arr;
        arr = rhs.arr;
        size = rhs.size;
        rhs.arr = nullptr;
        rhs.size = 0;
        return *this;
    }
    /*virtual*/ friend std::ostream& operator<<(std::ostream& out, const Array<T>& a) {
        out << "[ ";
        for (int i = 0; i < a.size; ++i) {
            out << a.arr[i] << " ";
        }
        out << "]";
        return out;
    }
    /*virtual*/ friend std::istream& operator>>(std::istream& in, Array<T>& a) {
        for (int i = 0; i < a.size; ++i) {
            in >> a.arr[i];
        }
        return in;
    }
    virtual Array<T> operator&&(const Array<T>& rhs) {
        Array<T> arr(rhs.size + size);
        int i = 0, j = 0, k = 0;
        while (i < size && j < rhs.size) {
            if (arr[i] < rhs.arr[j]) {
                arr.arr[k] = arr[i];
                ++i;
            }
            else {
                arr.arr[k] = rhs.arr[j];
                ++j;
            }
            ++k;
        }
        while (i < size) {
            arr.arr[k] = arr[i];
            ++i;
            ++k;
        }
        while (j < rhs.size) {
            arr.arr[k] = rhs.arr[j];
            ++j;
            ++k;
        }
        return arr;
    }
};

int main() {
    Array<int> a1{1, 5, 3};
    Array<int> a2{2, 6, 4};
    Array<int> a3;
    a3 = a1 && a2;
    std::cout << a3 << std::endl;
    a1.insert(4, 1);
    std::cout << a1 << std::endl;
    a2.erase(0);
    std::cout << a2 << std::endl;
    return 0;
}
/*-------------------------------------------------------------------*/

/*class Matrix: public Array<Array<double>> {
public:
    Matrix(): Array(9) {}
    Matrix(int a[3][3]) : Array(9) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                arr[i * 3 + j] = a[i][j];
            }
        }
    }
    Matrix(const Matrix &m) : Array(m) {
        
    }
    int sum() {
        int s = 0;
        for (int i = 0; i < size; i++) {
            s += arr[i];
        }
        return s;
    }
    Matrix &operator+=(const Matrix &m) {
        for (int i = 0; i < size; i++) {
            arr[i] += m.arr[i];
        }
        return *this;
    }    
    Matrix &operator-=(const Matrix &m) {
        for (int i = 0; i < size; i++) {
            arr[i] -= m.arr[i];
        }
        return *this;
    }
    Matrix &operator*=(const Matrix &m) {
        int tmp[3][3];
        int sum;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                sum = 0;
                for(int k = 0; k < 3; k++) {
                    sum += arr[i * 3 + k] * m.arr[k * 3 + j];
                }
                tmp[i][j] = sum;
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                arr[i * 3 + j] = tmp[i][j];
            }
        }
        return *this;
    }
};

int main() {
    int a[3][3] = {{1,2,3}, {4,-6,7}, {8,-9,0}};
    Matrix m(a);
    std::cout << m.sum() << std::endl;
    Matrix m2;
    std::cout << m2.sum() << std::endl;
    m2 = m;
    std::cout << m2.sum() << std::endl;
    int a2[3][3] = {{1,2,-1}, {-2,3,-4}, {0,1,2}};
    Matrix m3(a2);
    m *= m3;
    std::cout << m.sum() << std::endl;    
    return 0;
}*/