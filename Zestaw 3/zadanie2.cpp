#include <string>
#include <iostream>

using namespace std;

template <typename T, typename U>
T convert(U u) {
    try {
        return static_cast<T>(u);
    } catch (const exception &e) {
        cerr << "Exception: " << e.what() << endl;
        return T();
    }
}

template <>
string convert<string>(double d) {
    return to_string(d);
}

template <>
int convert<int, double>(double u) {
    return static_cast<int>(u);
}

template <>
double convert<double, int>(int u) {
    return static_cast<double>(u);
}

int main() {
	
    cout << convert<int>(13.37) << endl;
    cout << convert<double>(12) << endl;
    cout << convert<string>(21.37) << endl;
}