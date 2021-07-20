## Wejście
Na wejściu program otrzymuje pięć liczb n,s,d,l,m oznaczające kolejno liczbę analizowanych mediów (media numerujemy od 0 do n-1), medium, które jako pierwsze otrzymało informację, dzień tygodnia kiedy tą informację opublikowano (dzień tygodnia jest liczbą z zakresu od 0 do 6 oznaczającą numer dnia tygodnia), liczbę dni kiedy informacja rozprzestrzeniała się po mediach oraz liczbę krawędzi w ,,grafie cytowań''. Następnie program otrzyma m czwórek liczb postaci a, b,c,d oznaczających, że gazeta a cytuje w dniu b informacje z gazety c z dnia d.
```
1<=n<=300
0<=m<=2000
1<=l<=100000
```
## Wyjście
Na standardowym wyjściu program powinien wypisać liczbę wszystkich ścieżek w grafie cytowań zaczynających się w wierzchołku s w dniu tygodnia d w których ostatni wierzchołek reprezentuje publikację rozważanej informacji przed końcem d-tego dnia. Wynik powinien zostać wypisany modulo 100000007.

# Przykłady
## Wejście
```
3 1 3 3 5
0 3 1 1
0 4 1 3
2 4 1 3
1 5 2 4
2 5 1 4
```
## Wyjście
```
4
```
## Wejście
```
3 1 3 2 5
0 3 1 1
0 4 1 3
2 4 1 3
1 5 2 4
2 5 1 4
```
## Wyjście
```
3
```
