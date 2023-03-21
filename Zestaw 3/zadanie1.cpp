#include <string>
#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
T Max(T a, T b) {
    return a > b ? a : b;
}

template <typename T>
T *Max(T *a, T *b) {
    return *a > *b ? a : b;
}

template <typename T>
T Max(T *data_size, size_t n) {
    T Max = data_size[0];
    for (size_t i = 1; i < n; ++i) {
        if (data_size[i] > Max)
            Max = data_size[i];
    }
    return Max;
}

template <>
char *Max(char *a, char *b) {
    return strcmp(a, b) > 0 ? a : b;
}

template <>
const char *Max(const char *a, const char *b) {
    return strcmp(a, b) > 0 ? a : b;
}

template <typename T>
const T *Max(T *a, const T *b) {
    return *a > *b ? a : const_cast<T *>(b);
}

template <>
const char *Max(char *a, const char *b) {
    return strcmp(a, b) > 0 ? a : b;
}

int main() {
	int i, j = 7;

    double x[5] = {3, 9, 1, 7, 0};

    char *p1 = new char[6];
    char *p2 = new char[6];

    strncpy(p1, "domek", 6);
    strncpy(p2, "romek", 6);
	
    cout << Max(i, j) << endl; // T Max(T a, T b)
    cout << *Max(&i, &j) << endl; // T *Max(T *a, T *b)
    cout << Max(x, 5) << endl; // T Max(T *data, size_t n)
    cout << Max("domek", "romek") << endl; // const char *Max(const char *a, const char *b)
    cout << Max(p1, p2) << endl; // char *Max(char *a, char *b)
    cout << Max(p1, "domek") << endl; // const T *Max(char *a, const char *b)
}