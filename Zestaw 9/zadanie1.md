# Zadanie 1

Inteligentny wskaźnik to obiekt będący wrapperam na zwykły wskaźnik.
Istnieje on po to, by kiedy obiekt opuści scope, uruchomił destruktor i pamięć została automatycznie wyczyszczona
Sprawa to, że programista nie musi martwić się o memory leak i segmentation fault związane z usuwaniem.

## unique_ptr

Charakteryzuje się tym że może istnieć tylko obiekt wskazujący na daną pozycję w pamięci.
Kiedy spróbujemy stworzyć kolejny to pierwszy zostanie usunięty. Wskaźniki wiedzą o sobie nawzajem, ponieważ przechowują te informacje w tablicy wirtualnej.

## shared_ptr

Może istnieć kilka obiektów pokazujących na to samo miejsce w pamięci. Ma metodę zwracającą ilość inteligentnych wskaźników pokazujących ten sam adres.
