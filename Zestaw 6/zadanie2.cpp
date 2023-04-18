#include <iostream>

using namespace std;

class No_checking_policy {
public:
	static void check_push(size_t, size_t) {}
	static void check_pop(size_t) {}
	static void check_top(size_t) {}
};

class Abort_on_error_policy {
public:
	static void check_push(size_t top, size_t N) {
		if (top == N - 1) {
			cerr << "Stack overflow!" << endl;
			exit(1);
		}
	}
	
	static void check_pop(size_t top) {
		if (top == 0) {
			cerr << "Stack underflow!" << endl;
			exit(1);
		}
	}
	
	static void check_top(size_t top) {
		if (top == 0) {
			cerr << "Stack is empty!" << endl;
			exit(1);
		}
	}
};

template<typename T = int , size_t N = 100,
typename Checking_policy = No_checking_policy > class Stack {
private:
	T _rep[N];
	size_t _top;
public:
	explicit Stack(size_t n = N) : _top(0){};

    void push(const T &val)
    {
        Checking_policy::check_push(_top, N);
        _rep[_top++] = val;
    }

    void pop()
    {
        Checking_policy::check_pop(_top);
        --_top;
    }

    T top() const
    {
        Checking_policy::check_top(_top);
        return &_rep[_top - 1];
    }

    T &top()
    {
        Checking_policy::check_top(_top);
        return _rep[_top - 1];
    }

    bool is_empty() { return !_top; }
};

int main () {
	Stack<int, 100, No_checking_policy> stack;
	Stack<int, 100, Abort_on_error_policy> stack2;
	
	stack.pop();
	cout << "ok" << endl;
	
	stack2.pop();
	cout << "Error" << endl;
}