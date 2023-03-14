# Zadanie 1

## Polimorfizm dynamiczny

Możliwość wykonywania różnych wersji metod w zależności od typu obiektu. Do jednej zmiennej możemy przypisać wiele różnych obiektów różnych typów. W momencie wywołania metody na tym obiekcie ustalana jest odpowiednia wersja. Nie jesteśmy w stanie określić wersji metody na poziomie kompilacji - nie wiemy co zostanie przypisane do naszej zmiennej.

## Polimorfizm statyczny

Mechanizmy dziedziczenia, które można ustalić na poziomie kompilacji. Przykładowo przeciążenie operatorów. Z góry wiemy, którą wersję operatora należy wywołać.

## Klasa abstrakcyjna

Klasa, która nie może mieć instancji i posiada abstrakcyjne metody (bez implementacji). Służy jako szablon nakładający wymóg zaimplementowania wszystkich metod rodzica przez jego dzieci.

## Funkcja wirtualna

Funkcja abstrakycjna lub zwykła, która jest nadpisywana w klasach pochodnych.
