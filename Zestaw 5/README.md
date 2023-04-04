# Zestaw 5

## Zadanie 1

Zaimplementuj szablon `is_class` służący do sprawdzania czy dany typ jest klasą.

## Zadanie 2

Napisz szablon, który sprawdza czy jego parametr posiada typ stowarzyszony `value_type`, np.: `has_value_type<std::vector<int> >::yes` powinno mieć wartość `true`, a `has_value_type<int>::yes` wartość false.

## Zadanie 3

Zaimplementuj szablon klasy `Is_convertible` za pomocą którego możliwe jest stwierdzenie czy jeden z typów można rzutować na drugi.

## Zadanie 4

Zdefiniuj szablon `Strip`, który jako funkcja typów dokonuje operacji usunięcia jednego lub obydwu kwalifikatorów (`const` oraz `&`) i uzyskanie gołego typu podstawowego.

## Zadanie 5

Zmodyfikuj szablon operatora `+` którym dodajemy dwa wektory:

```cpp
template<typename T,typename U> std::vector<T>
operator+(const std::vector<T> &a, const std::vector<U> &b)
```

Modyfikacja polegać powinna na implementacji klasy cech `Promote` (będącą funkcją typów), która będzie określała typ wyniku na podstawie typu składników. Wybierzemy następującą strategię: jeśli typy mają różny rozmiar to wybieramy typ większy, jeżeli mają ten sam rozmiar to liczymy na specjalizacje. Dla identycznych typów wynik jest jasny (choć jak przekonuje nas przykład 5.1 typ sumy nie musi być typem składników). Resztę musimy definiować ręcznie korzystając ze specjalizacji pełnych. Specjalizację proszę sobie uprościć definiując odpowiednie makro `MK_PROMOTE(T1,T2,Tr)`.

## Zadanie 6

Napisz funkcje zwracające: długość listy typów, typ dla określonego indeksu listy typów oraz taką, która sprawdza czy dany typ jest wymieniony w podanej liście typów.
