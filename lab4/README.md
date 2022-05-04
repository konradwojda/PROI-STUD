# Kształty

## Dane autora
Konrad Wojda
## Opis implementacji
### Figures
Zaimplementowano klasę abstrakcyjną Figure oraz dziedziczące po niej Rectangle, Circle, Triangle.  
Każda z klas dziecziczących przyjmuje wymiary, wspiera obliczanie pola i obwodu.  
Zawiera metodę show pozwalającą na wypisanie informacji do podanego strumienia wyjścia.
Każdy obiekt klasy Figure można porównać z innym. Równość liczb typu zmiennopozycyjnego nie ma sensu ze względu na przybliżenie.  
Dlatego porównywana jest wartość bezwzględna różnicy z pewną stałą zapisaną w zmiennej globalnej EPSILON. 
### List
Zaimplementowano listę jednokierunkową, która jest szablonem od podanego typu.  
Klasa Node reprezentuje pojedyńczy węzeł i zawiera dane wskazanego typu i wskaźnik do następnego elementu.
Klasa List zawiera wskaźnik na pierwszy element. Umożliwia iterację po liście do przodu, wstawianie i usuwanie elementu ze wskazanego, przez iterator, miejsca, dodawanie i usuwanie elementu z końca (jako osobne metody).  
Metody dealloc() i copy_elements() zapewniają zwalnianie pamięci i kopiowanie elementów z innej listy.
### FiguresList
Zaimplementowano listę wskaźników do obiektów klasy Figure.  
Umożliwia ona dodawanie i usuwanie elementów, oraz zawiera przeciążony operator wyjścia na strumień, tak aby można było wypisać informację o obiektach przechowywanych przez listę.
