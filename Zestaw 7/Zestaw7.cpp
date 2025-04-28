#include <print>
#include <string>
#include <numbers>

#pragma region Task1
template <int n>
constexpr double factorial()  {
	return n * factorial<n - 1>();
}

template <>
constexpr double factorial<0>() {
	return 1;
}

void Task1()
{
	constexpr double result = factorial<5>();
	std::print("Factorial of 5 is: {}\n", result);
}
#pragma endregion

#pragma region Task2
template <int x, int base>
constexpr int power() {
	if constexpr (base == 0) 
		return 1;
	else
		return x * power<x, base - 1>();
}

void Task2()
{
	constexpr int result = power<2, 10>();
	std::print("2^10 is: {}\n", result);
}
#pragma endregion

#pragma region Task3
template <int n>
constexpr inline int quickPow(double x) {
	return x * quickPow<n - 1>(x);
}

template <>
constexpr inline int quickPow<0>(double x) {
	return 1;
}

void Task3()
{
	constexpr int result = quickPow<5>(5);
	std::print("Quick Power of 5^5 is: {}\n", result);
}
#pragma endregion

#pragma region Task4
template <int n>
std::string GetFirstSinXDigits(double x) {
	const long double num = sin(x);
	std::string asStr = std::format("{:.{}f}", num, n);
	return asStr.substr(0, n);
}

void Task4() {
	constexpr int digits = 10;
	constexpr double x = std::numbers::pi / 4;
	const std::string result = GetFirstSinXDigits<digits>(x);
	std::print("First {} digits of sin({}) is: {}\n", digits, x, result);
}
#pragma endregion

#pragma region Task56
template<size_t N, typename T> 
T dot(T* x, T* y) {
	T result = 0;
	for (size_t i = 0; i < N; ++i) {
		result += x[i] * y[i];
	}
	return result;
}

void Task56() {
	constexpr size_t N = 3;
	int x[N] = { 1, 2, 3 };
	int y[N] = { 4, 5, 6 };
	int result = dot<N>(x, y);
	std::print("Dot product of x and y is: {}\n", result);
}
#pragma endregion

int main()
{
	Task1();
	Task2();
	Task3();
	Task4();
	Task56();
}
