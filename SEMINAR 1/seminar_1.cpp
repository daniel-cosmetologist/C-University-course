template <typename T> T add(T a, T b) {
    return a + b;
}

int x = add(3, 5);

float f = add<float>(3.0, 7.0);

template<typename T> void mysort(T arr[], unsigned size)
{
    for (unsigned i = 0; i < size; i++)
    {
        for (unsigned k = i + 1; k < size; k++)
        {
            if (arr[k] < arr[i]) {
                T tmp(arr[i]);
                arr[i] = arr[k];
                arr[k] = tmp;
            }
        }
    }
}

int main() {
//.........
int iarr[] = { 8, 1, 3, 4, 9, 0, 2, 7, 6, 5 };
mysort(iarr, sizeof(iarr) / sizeof(iarr[0]));

//.........
double darr[10] = { 8.1, 1.2, 3.3, 4.9, 9.5, 0.4, 2.6, 7.7, 6.8, 5.0 };
mysort<double>(darr, sizeof(darr) / sizeof(darr[0]));

}

/*
Задание 02. Написать шаблонный класс deque с возможностью быстрой вставки и 
удаления элементов в начало или в конец коллекции. Также надо реализовать методы 
взятия/изменения элемента по индексу и написать тестовую программу.
*/