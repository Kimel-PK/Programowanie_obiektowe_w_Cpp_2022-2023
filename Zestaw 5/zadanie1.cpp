#include <iostream>

template<typename T>
struct is_class {
private:
    template<typename C>
    static char test(int C::*);
    template<typename C>
    static int test(...);
public:
    static constexpr bool value = (sizeof(test<T>(0)) == sizeof(char));
};

class Test_class {};
struct Test_struct {};

main () {
	std::cout << std::boolalpha;
    std::cout << is_class<Test_class>::value << std::endl; // true
	std::cout << is_class<Test_struct>::value << std::endl; // true
    std::cout << is_class<int>::value << std::endl; // false
    std::cout << is_class<float>::value << std::endl; // false
    std::cout << is_class<std::string>::value << std::endl; // true
    std::cout << is_class<const char*>::value << std::endl; // false
	
	return 0;
}