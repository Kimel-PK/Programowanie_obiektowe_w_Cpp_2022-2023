#include <array>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
T dot_product(const vector<T> &a, const vector<T> &b) {
	if (a.size() != b.size()) {
		throw invalid_argument("Vectors must have the same size");
	}
	
	T result = T();
	for (size_t i = 0; i < a.size(); ++i) {
		result += a[i] * b[i];
	}
	return result;
}

main () {
	vector<int> vect1 {1, 2, 3};
	vector<int> vect2 {4, 5, 6};
	
	cout << dot_product(vect1, vect2) << endl;
}