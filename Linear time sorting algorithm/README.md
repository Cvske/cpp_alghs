## Wejście
Na wejściu program otrzymuje liczbę n, a następnie n opisów dokumentów. Opis każdego z dokumentów składa się z unikalnego numeru, priorytetu, losowego kodu, liczby m kodów tematów dotyczących danego dokumentu (z zakresu od 1 do 4) a następnie m liczb z zakreso do 0 do 255. Na końcu program otrzyma liczby 1, 2, 3 i 4 odpowiadające kolejno numerom, priorytetom, kodom dokumentów oraz kodom tematów uporządkowane względem ich wagi przy sortowaniu.

1<=n<=2000000
## Wyjście
Na standardowym wyjściu program powinien wypisać sumę losowych kodów poszczególnych dokumentow pomnożonych przez finalny indeks elementu w posortowanej tablicy. Wynik powinien zostać wypisany modulo 100000007.


## Wejście
```
5
2 10 145 2 0 1
4 2 1119 4 255 0 1 2
1 10 0 2 0 1
3 5 2 4 255 0 1 2
5 10 99999 1 24
4 2 3 1
```
## Wyjście
```203508```
## Wejście
```
5
2 10 145 2 0 1
4 2 1119 4 255 0 1 2
1 10 0 2 0 1
3 5 2 4 255 0 1 2
5 10 99999 1 24 
4 3 2 1
```
## Wyjście
```204625```
## Wejście
```
1
1 10 0 2 0 1
1 2 3 4
```
## Wyjście
```
0
```
