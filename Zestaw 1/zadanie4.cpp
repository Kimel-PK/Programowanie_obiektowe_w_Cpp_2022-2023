#include <iostream>
using namespace std;

template <template <int N> class T, int K>
void function(T<K> t) {
	cout << K << endl;
}

template <int N>
class Class {};

int main() {
	function(Class<7>());
	function(Class<15>());
	function(Class<-3>());
}