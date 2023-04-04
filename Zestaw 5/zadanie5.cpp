#include <vector>
#include <iostream>
#include <type_traits>

template<typename T, typename U>
struct Promote {
private:
    template<typename T1, typename U1>
    static auto check(T1 t, U1 u) -> decltype(t + u);
    static void check(...);
public:
    using type = decltype(check(std::declval<T>(), std::declval<U>()));
};

#define MK_PROMOTE(T1, T2, Tr) \
template<> struct Promote<T1, T2> { using type = Tr; }; \
template<> struct Promote<T2, T1> { using type = Tr; };

MK_PROMOTE(int, double, double)
MK_PROMOTE(unsigned int, float, float)
MK_PROMOTE(long, long long, long long)

template<typename T, typename U>
std::vector<typename Promote<T, U>::type>
operator+(const std::vector<T> &a, const std::vector<U> &b) {
    using V = typename Promote<T, U>::type;
    std::vector<V> result(std::max(a.size(), b.size()));
    for (std::size_t i = 0; i < result.size(); ++i) {
        V sum = 0;
        if (i < a.size()) {
            sum += a[i];
        }
        if (i < b.size()) {
            sum += b[i];
        }
        result[i] = sum;
    }
    return result;
}

int main() {
    std::vector<int> a = {1, 2, 3};
    std::vector<double> b = {2.5, 3.5, 4.5};

    auto c = a + b;

    for (const auto &elem : c) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}