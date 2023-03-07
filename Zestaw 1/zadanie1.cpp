#include <iostream>
using namespace std;

template <class arg>
arg maksimum(arg arg1, arg arg2) {
	return (arg1 > arg2) ? arg1 : arg2;
}

int main () {
	cout << maksimum (1, 2) << endl;
	cout << maksimum (35.2, 32.3) << endl;
}