#include <iostream>
#include <vector>

using namespace std;

template <typename T, int N = 100, typename R = T *>
class Stack;

template <typename T, int N>
class Stack<T, N, T *> {
public:
    Stack() = default;

    void push(const T &t) { s.push_back(t); }

    T pop() {
        T t = s.back();
        s.pop_back();
        return t;
    }

    T top() const { return s.back(); }

    bool empty() const { return s.empty(); }

    size_t size() const { return s.size(); }

private:
    vector<T> s;
};

template <typename T, int N>
class Stack<T, N, vector<T>> {
public:
    Stack() = default;

    void push(const T &t) {
		s.push_back(t);
	}

    T pop() {
        T t = s.back();
        s.pop_back();
        return t;
    }

    T top() const { return s.back(); }

    bool empty() const { return s.empty(); }

    size_t size() const { return s.size(); }

private:
    vector<T> s;
};

template <typename T, int N>
class Stack<T, N, vector<T> &> {
public:
    Stack() = default;

    void push(const T &t) {
		s.push_back(t);
	}

    T pop() {
        T t = s.back();
        s.pop_back();
        return t;
    }

    T top() const { return s.back(); }

    bool empty() const { return s.empty(); }

    size_t size() const { return s.size(); }

private:
    vector<T> &s;
};

int main() {
	Stack<int, 100> stack;
	Stack<int, 0, vector<int>> stack2;
	
	stack.push(1);
	stack.push(2);
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;

	stack2.push(7);
	stack2.push(3);
	cout << stack2.pop() << endl;
	cout << stack2.pop() << endl;
}