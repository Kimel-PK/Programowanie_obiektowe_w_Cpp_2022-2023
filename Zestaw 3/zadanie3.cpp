#include <iostream>

using namespace std;

template <typename T, int N = 100>
class Stack {
public:
    Stack() = default;
};

template <typename T>
class Stack<T, 666> {
public:
    Stack() = default;
};

template <typename T, int N>
class Stack<T *, N> {
public:
    Stack() = default;
};

template <int N>
class Stack<double, N> {
public:
    Stack() = default;
};

template <int N>
class Stack<int *, N> {
public:
    Stack() = default;
};

template <>
class Stack<double, 666> {
public:
    Stack() = default;
};

template <>
class Stack<double *, 44> {
public:
    Stack() = default;
};

int main() {
	cout << typeid(Stack<int, 666>).name() << endl;
	cout << typeid(Stack<float *, 25>).name() << endl;
	cout << typeid(Stack<double, 33>).name() << endl;
	cout << typeid(Stack<int *, 66>).name() << endl;
	cout << typeid(Stack<double, 666>).name() << endl;
	cout << typeid(Stack<double *, 44>).name() << endl;
}