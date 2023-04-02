#include <iostream>

using namespace std;

template <typename T>
struct sum_traits;

template <>
struct sum_traits<char> {
	typedef string sum_type;
};

template <>
struct sum_traits<int> {
	typedef int sum_type;
};

template <>
struct sum_traits<float> {
	typedef float sum_type;
};

template <>
struct sum_traits<double> {
	typedef double sum_type;
};

template<typename T>
typename sum_traits<T>::sum_type sum(T* begin, T* end) {
	typename sum_traits<T>::sum_type total = typename sum_traits<T>::sum_type();
	while (begin != end) {
		total += *begin;
		++begin;
	}
	return total;
}

int main() {
	char arr1[] = "abcd";
	int arr2[] = { 1, 2, 3, 4 };
	float arr3[] = { 1.0, 2.0, 3.0, 4.0 };
	double arr4[] = { 1.0, 2.0, 3.0, 4.0 };
	
	cout << sum(arr1 + 1, arr1 + 3) << endl;
	cout << sum(arr2, arr2 + 2) << endl;
	cout << sum(arr3 + 1, arr3 + 3) << endl;
	cout << sum(arr4 + 2, arr4 + 4) << endl;
	
	return 0;
}