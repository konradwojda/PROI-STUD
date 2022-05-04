# Kolejka priorytetowa
## Dane autora
Konrad Wojda
## Opis zaimplementowanej klasy
### Metody i atrybuty prywatne
* size_ - długość kolejki
* Element - struktura reprezentująca element kolejki, posiada:
    * wartość (int zgodnie z założeniem zadania)
    * priorytet
    * konstruktor przypisujący wartości
    * operator != potrzebny do rozróżniania elementów
* queue_ - wektor zawierający elementy
* sort() - funkcja sotrująca elementy według priorytetu
* konstruktor przyjmujący wektor elementów (potrzebny przy przeciążeniu operatora +)
### Metory i atrybuty publiczne
* konstruktor tworzący pustą kolejkę
* size() - getter do pola size_
* push() - funkcja pozwalająca na dodawanie elementów do kolejki
* pop() - funkcja zwracająca element o największym priorytecie i usuwająca go
* operator+ - operator pozwalający na dodawanie dwóch kolejek
* operator+= - operator pozwalający na dodanie dwóch kolejek i przypisanie wyniku do kolejki po lewej stronie operatora
* hash() - funkcja wyliczająca skrót z kolejki
* operator==, operator!= - operatory porównania
* operator[] - operator indeksowania, zwracający wartość elementu na danej pozycji
* przeciążenie operatora wyjścia - wypisuje całą kolejkę razem z priorytetami
