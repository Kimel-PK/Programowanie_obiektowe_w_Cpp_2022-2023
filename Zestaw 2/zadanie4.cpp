#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class SequenceGen {
public:
    SequenceGen(int start, int step) : _current(start), _step(step) {}

    int operator() () {
        return _current += _step;
    }

private:
    int _current;
    int _step;
};

int main() {
    vector<int> vec(20);
    generate_n(vec.begin(), vec.size(), SequenceGen(1, 2));
    
    vector<int>::iterator it = find_if(vec.begin(), vec.end(), bind(greater<int>(), placeholders::_1, 4));
    if (it != vec.end())
        cout << *it << " is greater than 4" << endl;
    else
        cout << "No element greater than 4 found" << endl;

    return 0;
}
