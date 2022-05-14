# Feedback

## README

Har laget en README, med litt innhold. 
Forventer bedre beskrivelse av innholdet samt et enkelt UML diagram som viser sammenheng mellom klassene i endelig innlevering.

## Git

`.gitignore` lagt inn, og inneholder det som er vesentlig for dette prosjektet.

## CMake

Ikke så mye å her. Litt tips:

* Putt public headere i en folder `include` (interface til biblioteket ditt).
* Putt private headere (filer du vil .cpp skal ha tilgang på, men ingen andre) og .cpp filer som hører til biblioteket i en folder `src`.
* Lag en egen folder for tester, e.g., `tests`.
* Put kode som fører til en executable som skal distribueres e.g, i en folder `tool`.
* Kjørbar eksempelkode som viser bruk putter du f.eks i en folder `examples`. 

Hold bibliotket, testkode, eksempelkode og kode for executable (main og tilhørende funksjoner) separert.
Lag en `CMakeLists.txt` for hver folder og bruk `add_subdirectory` i topp-nivå `CMakeLists.txt`.

## Kode

Prosjektet har ikke en definert formaterings stil (e.g., `.clang-format`). Hva skjer om noen andre jobber på koden og kjører formatering?

### Person.h/cpp

`#include <vector>` -> Brukes ikke, fjern.

`using namespace std;` -> Du drar ikke nytte av denne og det er uansett best å skrive `std::` slik som du gjør. Fjern.

Trenger du egentlig default constructor?

Vurder enn annet type enn `bool` for gender. Ute av kontekst sier f.eks. `true` oss ingenting om hva det betyr. Kanskje du får forespørsel øsnker å legge alternative valg? Da må du skrive om store deler av programmet. Sjekk ut `enum`!

Accessorene dine er `const`. Bra.

Kunne være lurt å legge til en metode `std::string getFullName() const`.

### Node.h/cpp

Først og fremst, template klasses er veldig dårlige kandidater for å splitte i .hpp/.cpp. Vil anbefale å unngå dette på det aller høyeste.

`Node(const T& data,Node<T>* leftPtr,Node<T>* rightPtr);` -> Tror ikke du får bruk for denne. Fjern.

For i implementere et tre, trenger du også en parent. Det du har nå ligner på en singly-linkedlist som går to forskjellige veier. 

Fint å se at du konstruerer en node for å representere datastrukturen for seg selv. 
Kunne ha blitt fristen til å putte lgikken inn i en person, men da mister man gjenbrukbarhet og får en mer kompleks person klasse.

`T getData(const T& data);` -> Har du glemt å fjerne argumentet fra metoden? Merk at du nå returnerer by-value. Objektet klienten får er altså en kopi. Kanskje du ønsker å returnere by reference? Kan kjøre const reference om du ikke ønsker at klienten skal kunne kalle metoder som kan mutere. Altså view-only.

```cpp
bool hasSpace();
bool isLeaf();
```

Disse kan (og bør) merkes `const` . Alle metoder i en klasse som ikke muterer skal markeres `const`.

```cpp
void setRightPtr(Node<T> *rightPtr);
void setLeftPtr(Node<T> *leftPtr);
```

Kan det være en ide å ta inn `T` som argument og heller konstruere en `Node` som en del av metoden? Da får du full kontroll på levetiden.

### BinaryTree.h/cpp

Igjen, templates er ikke en god kandidat for å splitte koden. Grunnen er at kompilatoren må ha tilgang på implementasjonen. Man kan komme rundt problemet, men vil ikke anbefale det.

I teorien er ikke denne klasses nødvendig siden klassen `Node` i seg selv kan sees på som et fullverdig tre. Med det sagt, så kunne denne klasses bli brukt til å skjule tilstedeværelsen av typen `Node`. Altså at klassen er en del av implementasjonsdetaljen til `BinaryTree` og skjules fra public API. Tenk litt på det.  

`BinaryTree();` -> Default konstruktør har ikke et formål her. Fjern.

`Node<T>* root;` -> Trenger vi egentlig å bruke peker?

```cpp
template<class T>
BinaryTree<T>::BinaryTree(Node<T>* root){}
```
Du har glemt å assigne argumentet `root` i konstruktøren til feltet `root`.

### main.cpp

Ser ut som noe som løser laben vi hadde tidligere. 
Oppgaven din blir da å tilpase dette til å bruke en tre datastruktur for å modellere familetreet i stedet for en liste.

```cpp
Person createPerson() { // Function to create person
    Person person{};
    ...
}
```

Hvorfor ikke kalle konstrøktøren med flere argument i stedet for å kalle settere etterhvert? Hva om du skulle glemme en setter f.eks (på generell basis)?
Da kan du også fjerne settere om disse ikke er nødvendige videre i programmet. Jo mindre som kan mutere jo bedre.


## Unit tests

Ingen tester så langt. Ha alltid i hodet å designe koden slik at den enkelt kan bli testet.
Dvs. klasser og funksjoner med klare formål som ikke gjør for mye på engang.

Bruk gjerne Catch2 rammeverket som vi har brukt i klassen.
Se f.eks https://github.com/AIS1002-OOP/Pathfinding/tree/master/tests

## Continuous integration (CI)

Ingen CI oppsett lagt inn.

---

Disclaimer: Tilbakemeldingen er ikke nødvendigvis komplett og kan ikke brukes som fasit. Bruk skjønn.
