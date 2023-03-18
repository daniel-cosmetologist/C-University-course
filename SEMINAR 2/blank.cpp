#include <iostream>

using namespace std;

int main()
{
    cout << "Hello, world!!" << endl;
}
// ИТЕРАТОР ШАБЛОННЫХ ОБЬЕКТОВ
int f();
//int zz = f();
auto zz = f();

void g()
{
    vector<int> v;
    //for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
      //  *it = 0;
    //for (auto it = v.begin(); it != v.end(); it++)
    for (auto ii = v[0]; ii != 100; ii++)
    {
        ii += 10;

    }

    for (auto& it = v[0]; it != 100; it++)
    {
        cout << *it;
    }

    // вместо использования итератора, используем range(синтаксически сахар)
    // в питоне не прибито гвоздем, как в си++
    for (auto val : v)
    {
        cout << val;
        // if cin >> val, auto&
    }
    // we can use for-each (looks like in python, but it is an algorithm)
    // it canw be optimized better then val : v...
}

// Циклы с диапазоном

void g(){
    for(auto it = v.begin(); it != v.end(); it++)
}

vector<int> v(10); // can't intialise
// v{1, 2, 3, 4}
int A[10] = {1, 2, 3, 4};
// we want similarity in initialising

// массив - однотипные объекты, лежащие в смежной ...
// tuple may have different types
// struct - class without protecting(private methods and objects)

template <class T>
struct S {
    vector<T> v;
    S() {  };
    S(intialiser_list<T> l) : v(l) {
        cout << "constructed with a " << l.size() << "-element list\n";
        for(auto i = l.begin(), i != l.end(); i++)
        {
            
        }
    }
}

void init_lists()
{
    S<int> s = {1, 2, 3, 4, 5}; // copy list
    S<int> s2{10, 11}; // it's allowed for usual constructors too (no difference between {} and ())
    // S<int> ss(1, 2, 3);
    // with (1, 11.2) would be typecasting, ok
} // explicit is not allowing typecasting
// можно убрать конструктор по умолчанию если = delete

int zero2{};
int* p{};
char c{ 9 };
 s.append({ 6, 7, 8});

 for (int x : {-1, -2, -3})

 templated_fn<initializer_list<int>>({ 1, 2, 3 })
 templated_fn({1, 2, 3}) // compiler error, it has no type
// дальше идет объявление класса Vec
 // при возвращении и передаче в функцию вызывается конструктор копирования
 Vec(Vec&& src) {
    p = src.p;
    dim = src.dim;
    src.p = nullptr;
    src.dim = 0; // data from src removed to our object
 };

 void ff() {
    Vec x(10);
    Vec x2(x);
 }

 //Контейнер шаблона дополнить конструктором перемещения и снабдить конструктором копирования