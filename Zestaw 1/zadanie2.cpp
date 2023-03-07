#include <iostream>
#include <string>
using namespace std;

template <typename T, typename U>
T convert(U u) {
	try	{
		return static_cast<T>(u);
	} catch (const exception &e) {
		cerr << "Error: " << e.what() << endl;
		return T();
	}
}

template <>
string convert<std::string> (double d) {
	return to_string(d);
}

int main() {
	cout << convert<string>(13.37) << endl;
	cout << convert<double>(5) << endl;
	cout << convert<int>(21.37) << endl;
}