#include <iostream>

/* Здесь мы объявляем базовый класс Array с шаблонным параметром Т. 
Массив имеет два приватных элемента: size - длину массива, и data - 
указатель на массив. Конструктор Array позволяет создавать массив 
нужной длины, конструктор копирования копирует массив другого объекта. 
Оператор [] позволяет получать доступ к элементам массива, а операторы 
+=, -= и *= позволяют сложить, вычесть или умножить на константу другой массив. */

template <typename T>
class Array {
  protected:
    int size;
    T* data;
  
  public:
    Array(int size);
    virtual ~Array();
    Array(const Array<T>& other);
    T& operator[](int index) const;
    void operator+=(const Array<T>& other);
    void operator-=(const Array<T>& other);
    void operator*=(const T& value);
};

/* Этот класс matrix наследует класс Array<Array<T>> и представляет матрицу размера 3х3.
Конструктор по умолчанию создает единичную матрицу, а конструктор копирования 
инициализирует матрицу из другой матрицы или массива. Кроме того, определены операции 
транспонирования, нахождения определителя, нахождения обратной матрицы и основные 
операции матричного умножения и сложения/вычитания. */

template <typename T>
class matrix : public Array<Array<T>> {
  public:
    matrix() : Array<Array<T>>(3) {}
    matrix(const matrix<T>& other) : Array<Array<T>>(other) {}
    matrix(const Array<Array<T>>& other) : Array<Array<T>>(other) {}
    matrix(T a11, T a12, T a13, T a21, T a22, T a23, T a31, T a32, T a33);
    matrix<T> transpose() const;
    T determinant() const;
    matrix<T> inverse() const;
    matrix<T> operator+(const matrix<T>& other) const;
    matrix<T> operator-(const matrix<T>& other) const;
    matrix<T> operator*(const matrix<T>& other) const;
    matrix<T> operator*(const T& value) const;
};

&&
/* Определение конструктора matrix: */
template <typename T>
matrix<T>::matrix(T a11, T a12, T a13, T a21, T a22, T a23, T a31, T a32, T a33) : Array<Array<T>>(3) {
    this->data[0][0] = a11;
    this->data[0][1] = a12;
    this->data[0][2] = a13;
    this->data[1][0] = a21;
    this->data[1][1] = a22;
    this->data[1][2] = a23;
    this->data[2][0] = a31;
    this->data[2][1] = a32;
    this->data[2][2] = a33;
}

/* Определение операции транспонирования: */
template <typename T>
matrix<T> matrix<T>::transpose() const {
    matrix<T> result(*this);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < i; ++j) {
            std::swap(result.data[i][j], result.data[j][i]);
        }
    }
    return result;
}

/* Определение операции нахождения определителя: */
template <typename T>
T matrix<T>::determinant() const {
    return data[0][0] * data[1][1] * data[2][2] + data[0][1] * data[1][2] * data[2][0] + data[0][2] * data[1][0] * data[2][1]
         - data[2][0] * data[1][1] * data[0][2] - data[1][0] * data[0][1] * data[2][2] - data[0][0] * data[1][2] * data[2][1];
}

/* Определение операции нахождения обратной матрицы: */
template <typename T>
matrix<T> matrix<T>::inverse() const {
    T det = determinant();
    if (det == 0) {
        std::cerr << "Matrix is singular" << std::endl;
        return matrix();
    }
    matrix<T> result;
    result[0][0] = (data[1][1] * data[2][2] - data[1][2] * data[2][1]) / det;
    result[0][1] = (data[0][2] * data[2][1] - data[0][1] * data[2][2]) / det;
    result[0][2] = (data[0][1] * data[1][2] - data[0][2] * data[1][1]) / det;
    result[1][0] = (data[1][2] * data[2][0] - data[1][0] * data[2][2]) / det;
    result[1][1] = (data[0][0] * data[2][2] - data[0][2] * data[2][0]) / det;
    result[1][2] = (data[1][0] * data[0][2] - data[0][0] * data[1][2]) / det;
    result[2][0] = (data[1][0] * data[2][1] - data[2][0] * data[1][1]) / det;
    result[2][1] = (data[2][0] * data[0][1] - data[0][0] * data[2][1]) / det;
    result[2][2] = (data[0][0] * data[1][1] - data[1][0] * data[0][1]) / det;
    return result;
}

/* Определение операции сложения: */
template <typename T>
matrix<T> matrix<T>::operator+(const matrix<T>& other) const {
    matrix<T> result(*this);
    result += other;
    return result;
}

/* Определение операции вычитания: */
template <typename T>
matrix<T> matrix<T>::operator-(const matrix<T>& other) const {
    matrix<T> result(*this);
    result -= other;
    return result;
}

/* Определение операции умножения на константу: */
template <typename T>
matrix<T> matrix<T>::operator*(const T& value) const {
    matrix<T> result(*this);
    result *= value;
    return result;
}

/* Определение операции умножения матриц: */
template <typename T>
matrix<T> matrix<T>::operator*(const matrix<T>& other) const {
    matrix<T> result;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                result[i][j] += data[i][k] * other[k][j];
            }
        }
    }
    return result;
}

/* Вот как можно перегрузить операторы ввода/вывода: */
template <typename T>
std::ostream& operator<<(std::ostream& os, const matrix<T>& mat) {
    for (int i = 0; i < 3; ++i) {
        os << mat[i][0] << " " << mat[i][1] << " " << mat[i][2] << std::endl;
    }
    return os;
}

template <typename T>
std::istream& operator>>(std::istream& is, matrix<T>& mat) {
    T a11, a12, a13, a21, a22, a23, a31, a32, a33;
    is >> a11 >> a12 >> a13 >> a21 >> a22 >> a23 >> a31 >> a32 >> a33;
    mat = matrix<T>(a11, a12, a13, a21, a22, a23, a31, a32, a33);
    return is;
}

/* И вот как можно перегрузить оператор () для доступа к элементам матрицы по индексам: */
template <typename T>
T& matrix<T>::operator()(int i, int j) {
    return data[i][j];
}

template <typename T>
const T& matrix<T>::operator()(int i, int j) const {
    return data[i][j];
}

/* Наконец, код базового класса Array выглядит следующим образом: */
template <typename T>
Array<T>::Array(int size) : size(size), data(new T[size]) {}

template <typename T>
Array<T>::~Array() {
    delete[] data;
}

template <typename T>
Array<T>::Array(const Array<T>& other) : size(other.size), data(new T[other.size]) {
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

template <typename T>
T& Array<T>::operator[](int index) const {
    return data[index];
}

template <typename T>
void Array<T>::operator+=(const Array<T>& other) {
    for (int i = 0; i < size; ++i) {
        data[i] += other.data[i];
    }
}

template <typename T>
void Array<T>::operator-=(const Array<T>& other) {
    for (int i = 0; i < size; ++i) {
        data[i] -= other.data[i];
    }
}

template <typename T>
void Array<T>::operator*=(const T& value) {
    for (int i = 0; i < size; ++i) {
        data[i] *= value;
    }
}