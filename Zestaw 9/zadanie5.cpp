#include <iostream>
#include <memory>

using namespace std;

class Test {
	public:
	~Test () {
		cout << "del" << endl;
	}
};

int main () {
	
	shared_ptr<Test> a = make_shared<Test> ();
	shared_ptr<Test> b (a);
	{
		shared_ptr<Test> c (a);
	}
}