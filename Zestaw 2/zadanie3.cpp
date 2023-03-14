#include <iostream>
#include <vector>

using namespace std;

template <typename Iterator, typename T>
T accumulate(Iterator first, Iterator last) {
    T sum = (T)0;
    for (; first != last; ++first)
        sum += *first;
    return sum;
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    int result = accumulate<vector<int>::iterator, int>(v.begin(), v.end());
    cout << "Sum: " << result << endl;
    return 0;
}