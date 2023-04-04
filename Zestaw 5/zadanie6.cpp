#include <iostream>
#include <string>

using namespace std;

template <typename H, typename T> struct Typy {
    typedef H Head;
    typedef T Tail;
};

class NullType {};
struct EmptyList {};

template <typename T> struct Dlugosc;
template <> struct Dlugosc<NullType> {
    enum { Result = 0 };
};

template<typename H, typename T> struct Dlugosc<Typy<H, T> > {
    enum { Result = 1 + Dlugosc<T>::Result };
};

template <int N, typename T> struct Typ {
    typedef typename Typ<N-1, typename T::Tail>::Result Result;
};

template <typename H, typename T> struct Typ<1, Typy<H, T> > {
    typedef H Result;
};

template <int N> struct Typ<N, NullType> {
    typedef EmptyList Result;
};

template <typename T, typename TL> struct Wymieniony {
    enum { Result = Wymieniony<T, typename TL::Tail>::Result };
};

template <typename T, typename Tail> struct Wymieniony<T, Typy<T, Tail> > {
    enum { Result = 1 };
};

template <typename T> struct Wymieniony<T, NullType> {
    enum { Result = 0 };
};

int main() 
{
    typedef Typy<int, NullType> T1;
    typedef Typy<double, T1> T2;
    typedef Typy<float, T2> T3;
    typedef Typy<string, T3> T4;

    cout << Dlugosc<T4>::Result << endl;
    cout << Dlugosc<T3>::Result << endl;
    cout << Dlugosc<T2>::Result << endl;
    cout << Dlugosc<T1>::Result << endl;

    typedef Typ<1, T4>::Result T;

    // test funkcja Wymieniony
    cout << Wymieniony<int, T4>::Result << endl;
}