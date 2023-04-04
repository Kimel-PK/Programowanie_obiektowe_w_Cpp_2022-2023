#include <iostream>
#include <type_traits>

template<typename From, typename To>
struct Is_convertible {
private:
    static void check(To);
    template<typename F, typename = decltype(check(std::declval<F>()))>
    static std::true_type test(int);
    template<typename>
    static std::false_type test(...);
public:
    static constexpr bool value = decltype(test<From>(0))::value;
};

int main() {
    std::cout << std::boolalpha;
    std::cout << Is_convertible<int, double>::value << std::endl; // true
    std::cout << Is_convertible<int*, double>::value << std::endl; // false
    std::cout << Is_convertible<const int&, int>::value << std::endl; // true
    return 0;
}