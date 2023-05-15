#include <iostream>
#include <memory>

using namespace std;

weak_ptr<int> w_ptr;

void observe() {
	cout << "w_ptr.use_count() == " << w_ptr.use_count() << "; ";
	
	if (shared_ptr<int> s_ptr = w_ptr.lock()) {
		cout << "*s_ptr == " << *s_ptr << endl;
	} else {
		cout << "w_ptr is expired" << endl;
	}
}

int main() {
	{
		auto sp = make_shared<int>(42);
		w_ptr = sp;
 
		observe();
	}
 
	observe();
}