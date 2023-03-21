#include <iostream>
#include <set>

using namespace std;

template <typename Iter>
void ReverseSort(Iter a, Iter b) {
    while (a != b) {
        cout << *a << " ";
        ++a;
    }
}

int main() {
	set<int, greater<>> s;

	s.insert(13);
	s.insert(37);
	s.insert(21);

	ReverseSort(s.begin(), s.end());
}