## Wejście:
W pierwszej linii wejścia program otrzymuje liczbę n oznaczającą liczbę operacji na bazie kaset a następnie n opisów operacji z poniższej listy

d – dodanie do bazy nowej kasety, w przypadku tej operacji w kolejnych dwóch liniach znajdowała się będzie nazwa zespołu i tytuł kasety.
w – wypisanie w osobnych liniach tytułów kaset podanego zespołu. Nazwa zespołu zostanie podana w kolejnej linii wejścia. Zespołu należy wypisywać w kolejności ich dodawania do bazy.
z– wypisanie w osobnych liniach zespołów, które nagrały kasetę o podanym tytule. Nazwa zespołu zostanie podana w kolejnej linii. Nazwy zespołów należy wypisywać w kolejności dodawania kaset o podanym tytule do bazy.
UWAGA: w zestawach mogą pojawić się linie, które nie pasują do powyższego wzorca (zamiast jednoznakowego symbolu polecenia mogą pojawić się dłuższe linie). Takie linie program powinien ignorować.

1<=n<=100000

## Wyjście:
Na standardowym wyjściu program powinien wypisać efekty działania operacji w i z. W przypadku gdy w bazie nie ma zespołu o podanej nazwie (operacja w) lub kasety o podanym tytule (operacja z) program nie powinien niczego wypisać.
```
Przykładowe wejście:
5
d
Defekt muzgó
Wszyscy jedziemy...
d
Zielone żabki
Lekcja historii
d
Defekt muzgó
Lekcja historii
w 
Defekt muzgó
z
Lekcja historii
z
Wszyscy pokutujemy
Przykładowe wyjście:
Wszyscy jedziemy...
Lekcja historii
Zielone żabki
Defekt muzgó
```
Uwaga:
Zadanie ma zostać rozwiązane przy pomocy samodzielnie zaimplementowanych drzew splay.
