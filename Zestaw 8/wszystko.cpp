#include <cmath>
#include <iostream>
#include <cmath>

using namespace std;

// Zadanie 1

template <typename T>
class square {
public:
	T operator()(T x) {
		return x * x;
	};
};

template<typename Func>
double integrate(Func f, double start, double stop, double step) {
	double integral = 0.0;

	for (double x = start; x < stop; x += step) {
		integral += f(x);
	}

	return integral * step;
}

// Zadanie 2

template <typename T>
class Variable {
public:
	T operator()(T x) {
		return x;
	};
};

template <typename T>
class Constant {
private:
	double constant;
public:
	Constant(T c) : constant(c) {};
	T operator()(T x) {
		return constant;
	};
	T operator()(T,T) {
		return constant;
	}
};

// Zadanie 5

template<typename T, typename R = Variable<T>> class Expr {
	R _rep;
public:
	Expr() {};
	Expr(R rep): _rep(rep) {};
	T operator()(T x) {
		return _rep(x);
	}
	R rep() const {
		return _rep;
	};
};

// Zadanie 3

template<typename T, typename LHS, typename RHS >
class AddExpr {
private:
	LHS _lhs;
	RHS _rhs;
public:
	AddExpr(const LHS &l, const RHS &r) : _lhs(l), _rhs(r) {};

	T operator()(T x) {
		return _rhs(x) + _lhs(x);
	}
	T operator()(T x, T y) {
		return _lhs(x, y) + _rhs(x, y);
	}
};

template<typename T,typename LHS,typename RHS>
Expr<T, AddExpr<T, LHS, RHS>> operator+(const Expr<T, LHS> &l, const Expr<T, RHS> &r) {
	return Expr<T, AddExpr<T, LHS, RHS>>(AddExpr<T, LHS, RHS> (l.rep(),r.rep()));
};

template<typename T,typename LHS>
Expr<T,AddExpr<T,LHS,Constant<T>>>
operator+(const Expr<T,LHS> &l, T r) {
	return Expr<T ,AddExpr<T ,LHS , Constant<T>>>(AddExpr<T ,LHS ,Constant<T>>(l.rep() ,Constant<T>(r)));
};

template<typename T, typename LHS>
Expr<T, AddExpr<T, Constant<T>, LHS>> operator+(T r, const Expr<T, LHS> &l) {
	return Expr<T, AddExpr<T, Constant<T>, LHS>>(AddExpr<T,Constant<T>,LHS>(Constant<T>(r),l.rep()));
};

// Zadanie 4

template<typename LHS, typename RHS>
class DivExpr {
private:
	LHS _lhs;
	RHS _rhs;
public:
	DivExpr(const LHS &l,const RHS &r) : _lhs(l), _rhs(r) {};

	double operator()(double x) {
		return _rhs(x) / _lhs(x);
	}
};

template<typename LHS, typename RHS>
DivExpr<LHS, RHS> operator/(const LHS &l, const RHS &r) {
	return DivExpr<LHS,RHS>(l,r);
};

template<typename LHS>
DivExpr<LHS,Constant<double>> operator/(const LHS &l, double r) {
	return DivExpr<LHS, Constant<double>>(l,Constant<double>(r));
};

template<typename RHS>
DivExpr<Constant<double>, RHS> operator/(double l, const RHS &r) {
	return DivExpr<Constant<double>, RHS>(Constant<double>(l), r);
};

template<typename Func>
class SinExpr {
private:
	Func f;
public:
	SinExpr(Func a) : f(a) {};
	double operator()(double x) {return sin(f(x));};
};

template<typename Arg>
SinExpr<Arg> sin(const Arg&a) {
	return SinExpr<Arg>(a);
}

// Zadanie 6

class First {
public:
	double operator()(double x) {
		return x;
	}
	double operator()(double x,double) {
		return x;
	}
};

class Second {
public:
	double operator()(double,double y) {
		return y;
	}
};

int main () {
	// Oczekiwany wynik = 14
	cout << integrate(square<double>(), 0, 4, 1) << endl;

	// Oczekiwany wynik = 4
	cout << integrate(Constant<double>(1.0), 0, 4, 1) << endl;

	// Oczekiwany wynik = 6
	Expr<double,Variable<double>> x;
	Expr<double,square<double>> sqr;
	cout << integrate(x, 0, 4, 1) << endl;

	// Oczekiwany wynik = 20
	cout << integrate(x + sqr, 0, 4, 1) << endl;

	// Oczekiwany wynik = 22
	cout << integrate(x + 2.0, 0, 4, 1) << endl;

	// Oczekiwany wynik = 1.047 (nie zgadza sie pewnie przez sposob integracji)
	cout << integrate(1.0 / sin(x + 1.0), 0, 1, 0.001) << endl;

	return 0;
}