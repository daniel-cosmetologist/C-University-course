template<class T>
constexpr T pi = T(3.1415926535897932385L);  // variable template

template<class T>
T circular_area(T r) // function template
{
    return pi<T> *r * r; // pi<T> is a variable template instantiation
}

constexpr double square(double x) {
    return x * x;
}

const double four = square(2.0);

constexpr int factorial(int n)
{
    return n <= 1 ? 1 : (n * factorial(n - 1));
}

// C++14 constexpr functions may use local variables and loops
constexpr int factorial_cxx14(int n)
{
    int res = 1;
    while (n > 1)
        res *= n--;
    return res;
}

void main2() {
    int i = 3;
    constexpr int x = factorial(3);
}