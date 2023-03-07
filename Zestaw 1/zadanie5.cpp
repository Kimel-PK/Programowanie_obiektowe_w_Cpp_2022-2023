#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stack {
private:
	vector<T> vect;

public:
	typedef T value_type;
	
	void push(const T &x) {
		vect.push_back(x);
	}
	
	T pop() {
		T x = vect.back();
		vect.pop_back();
		return x;
	}

	T top() {
		return vect.back();
	}

	bool empty() {
		return vect.size() == 0;
	}
};

template <typename T>
decltype(auto) sum(T t) {
	typename T::value_type sum = 0;
	while (!t.empty()) {
		sum += t.pop();
	}
	return sum;
}

int main() {
	Stack<int> stack;
	stack.push(1);
	stack.push(3);
	stack.push(3);
	stack.push(7);
	
	cout << sum(stack) << endl;
}