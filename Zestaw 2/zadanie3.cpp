#include <iostream>
#include <vector>

using namespace std;

template <typename Iterator>
int accumulate(Iterator first, Iterator last) {
    int sum = 0;
    for (; first != last; ++first)
        sum += 1;
    return sum;
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    int result = accumulate(v.begin(), v.end());
    cout << "Sum: " << result << endl;
    return 0;
}