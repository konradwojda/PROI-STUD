# Szyfr nihilistów
## Dane autora
Imię i nazwisko: Konrad Wojda  
## Opis zadania
Zadaniem było zaimplementowanie funkcji pozwalających na wygenerowanie kwadratu Polibiusza oraz na jego podstawie na szyfrowanie i odszyfrowanie wiadomości w szyfrze nihilistów.
Rozwiązanie zostało podzielone na podproblemy implementowane w kolejnych funkcjach. 
* removeDuplicate - usuwanie powtórzeń ze stringa
* replaceJ - podstawianie litery "j" na "i"
* checkString - sprawdzenie czy w stringu znajduje się podana litera
* getLabels - losowanie wartości od 1 do 1000 i tworzenie tablicy
* getCells - uzupełnianie szachownicy Polibiusza zgodnie z przyjętym wymaganiem
* generateSquare - generowanie struktury kwadratu Polibiusza 
* przeciążenie operatora << tak aby wyświetlał szachownicę
* przeciążenie operatora >> tak aby tworzył kwadrat Polibiusza z zadanego klucza
* findIndex (1) - szukanie indeksu danej litery w komórkach kwadratu Polibiusza
* cipherLetter - szyfrowanie pojedyńczej litery
* cipherMessage - szyfrowanie ciągu znaków 
* validateKey - sprawdzanie czy klucz jest poprawny (tylko litery a-z)
* encrypt - szyfrowanie całej wiadomości 
* findIndex (2) - szukanie indeksu podanej liczby w nazwach kolumn/wierszy 
* decryptLetter - odszyfrowanie pojedyńczej litery
* predecrypt - jedynie odejmuje po kolei wartości zaszyfrowanego klucza od zaszyfrowanej wiadomości
* decrypt - odszyfrowanie danej wiadomości 
## Informacje o środowisku
Używane środowisko to Visual Studio 2019.
## Sposób testowania
Użyłem natywnych testów jednostkowych zawartych w Visual Studio. Przetestowałem napisane funkcje. Wszystkie testy zakończyły się pomyślnie. Dodatkowo w funkcji main() zaprezentowane jest przykładowe działanie programu, który najpierw szyfruje daną wiadomość, a potem ją odszyfrowuje. Wszystko wyświetlane jest za pomocą std::cout. 
