## WEJŚCIE
W pierwszej linii wejścia znajduje się liczba naturalna n, która jest ilością tropów. Następnie program powinien odczytać n wartości wpływów politycznych dla chronologicznie przedstawionych tropów. W kolejnym kroku program powinien odczytać dwie wartości a i b, które są granicami domkniętego przedziału wartości wpływów politycznych dla przesłanek, które warto rozważać. Na koniec program powinien odczytać estymowaną wartość k , która jest wpływem poglądów politycznych na dzisiejsze wydarzenia.
```
0 <= n, k, a, b, wartości wpływów politycznych dla tropów <= 2000000000
```
## WYJŚCIE
```
Na wyjściu program powinien wypisać parę wartości wpływów poglądów politycznych tropów, które spełniałyby wartość k lub “NIE ZNALEZIONO” w przeciwnym wypadku. Wartości pary powinny być wypisane w kolejności niemalejącej.
```
## PRZYKŁADOWE DANE WEJŚCIOWE
```
7                                                                               
15 10 20 8 12 16 25                                                             
9 16                                                                            
25 
```
## PRZYKŁADOWE DANE WYJŚCIOWE
``
10 15
``
## UWAGI
W rozwiązaniu zadania powinna pojawić się implementacja drzew BST, precyzując powinny pojawić się operacje tj. dodawanie nowych węzłów, przycinanie drzewa BST do określonego przedziału oraz wyszukiwanie pary liczb spełniających podaną sumę.
