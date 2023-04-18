# Zestaw 6

## Zadanie 1

Przeanalizuj przykład zaczynający się od pliku `glowny.cpp`. Zamienia on nazwy zrozumiałe dla człowieka ("czarny", "zielony") na strukturki ze składowymi RGB, wykorzystując do tego celu fabrykę kolorów. Domyślną reakcją fabryki na przekazanie nieznanej nazwy koloru powinno być rzucenie wyjątkiem, ale chcemy zachować możliwość zmiany tej defaultowej reakcji; wprowadzono więc klasę wytycznych.

Zwróć uwagę na podział tego projektu na poszczególne pliki źródłowe. Zaimplementuj w odrębnym pliku (albo plikach) alternatywną politykę, która zamiast wyjątku zwraca pewien ustalony kolor domyślny. Przerób ją następnie z klasy na szablon klasy tak, aby można było zadawać kolor domyślny jako trzy parametry tego szablonu.

## Zadanie 2

Zmodyfikuj prosty szablon stosu:

```cpp
template<typename T = int , size_t N = 100> class Stack {
```

przez dodanie nowego parametru, który będzie określał klasę wytyczną do sprawdzenia zakresu pamięci:

```cpp
template<typename T = int , size_t N = 100,
    typename Checking_policy = No_checking_policy > class Stack {
private:
        T _rep[N];
        size_t _top; ….
```

Klasa wytycznych powinna posiadać minimum 3 funkcje składowe: `check_push(size_t, size_t)`, `check_pop(size_t)` oraz `check_top(size_t)`. Zaimplementuj przykłady klasy wytycznych dla strategii: braku sprawdzania (`No_checking_policy`) oraz przerywania działania (`Abort_on_error_policy`).

## Zadanie 3

W celu zaimplementowania różnych strategii przydziału pamięci dodajemy dodatkowy parametr szablonu, który sam będzie szablonem:

```cpp
template<typename T = int , size_t N = 100,
    typename Checking_policy = No_checking_policy,
    template<typename U,size_t M> class Allocator_policy
    = Static_table_allocator > class Stack;
```

Szablon typu `Allocator_policy` posiada jeden typ stowarzyszony i szereg funkcji. Na przykład szablon ze statyczną tablicą w pamięci:

```cpp
template<typename T,size_t N = 0> struct Static_table_allocator {
    typedef T rep_type[N];
    void init(rep_type &,size_t) {};
    void expand_if_needed(rep_type &,size_t) {};
    void shrink_if_needed(rep_type &,size_t) {};
    void dealocate(rep_type &){};
    static size_t size() {return N;};
};
```

Zaimplementuj szablon stosu wykorzystujący dodatkowy parametr do alokacji oraz przykład klasy `Dynamic_table_allocator`.

## Zadanie 4

Wykorzystując prywatne dziedziczenie wykonaj modyfikację i przenieś zmienną `_rep` (dane ze stosu) z klasy `Stack` do klasy wytycznej, która dokonuje alokacji. Zmodyfikuj odpowiednio klasę `Stack`.
