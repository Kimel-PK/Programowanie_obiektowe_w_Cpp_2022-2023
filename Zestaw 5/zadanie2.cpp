#include <iostream>
#include <vector>
#include <type_traits>

template <typename T>
struct has_value_type {
private:
    template<typename C>
    static std::true_type test(typename C::value_type*);
    template<typename C>
    static std::false_type test(...);
public:
    static constexpr bool value = decltype(test<T>(nullptr))::value;
};

int main() {
    std::cout << std::boolalpha;
    std::cout << has_value_type<std::vector<int>>::value << std::endl; // true
    std::cout << has_value_type<int>::value << std::endl; // false
    std::cout << has_value_type<double*>::value << std::endl; // false
    std::cout << has_value_type<std::string>::value << std::endl; // true
    return 0;
}