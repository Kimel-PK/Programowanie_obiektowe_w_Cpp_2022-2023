#include <iostream>
#include <type_traits>

template<typename T>
struct Strip {
    using type = typename std::remove_reference<typename std::remove_const<T>::type>::type;
};

int main() {
    // usunięcie kwalifikatora const
    using T1 = const int;
    using T2 = typename Strip<T1>::type; // T2 to int
    std::cout << std::is_same<T2, int>::value << std::endl; // 1

    // usunięcie kwalifikatora &
    using T3 = int&;
    using T4 = typename Strip<T3>::type; // T4 to int
    std::cout << std::is_same<T4, int>::value << std::endl; // 1

    return 0;
}