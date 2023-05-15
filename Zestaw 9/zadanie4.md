# Zadanie 4

## Pierwsza specjalizacja

```cpp
template<class T, class... Args> unique_ptr<T> make_unique (Args&&... args);
```

Wywołuje skontruktor o danych argumentach, rezerwując miejsce w pamięci na 1 obiekt danego typu

## Druga specjalizacja

```cpp
template<class T> unique_ptr<T> make_unique (std::size_t size);
```

Rezerwuje miejsce w pamięci na tablicy obiektów danego typu o rozmiarze `size`
