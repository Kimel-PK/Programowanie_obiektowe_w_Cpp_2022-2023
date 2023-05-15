#include <iostream>
#include <memory>

using namespace std;

int main () {
	unique_ptr<int> u_ptr = make_unique<int> (5);
	int* ptr = new int(5);
	
	cout << sizeof (u_ptr) << " == " << sizeof (ptr) << endl;
}