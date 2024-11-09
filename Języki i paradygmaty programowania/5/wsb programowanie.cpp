#include <algorithm>
#include <iomanip>
#include <iostream>
#include <locale>
#include <numeric>
#include <vector>

using namespace std;

void potegaPrzezZmienna(int x) {
  x = x * x; // Podnosi wartość x do kwadratu
  cout << "Wynik (przez zmienną): " << x << endl; // Wyświetla wynik
  // Funkcja przyjmuje argument przez wartość, co oznacza, że zmiany dokonane na
  // zmiennej x wewnątrz funkcji nie wpływają na oryginalną zmienną przekazaną
  // do funkcji.
}

void potegaPrzezReferencje(int &x) {
  x = x * x; // Podnosi wartość x do kwadratu
  cout << "Wynik (przez referencję): " << x << endl; // Wyświetla wynik
  // Funkcja przyjmuje argument przez referencję, co oznacza, że zmiany dokonane
  // na zmiennej x wewnątrz funkcji wpływają na oryginalną zmienną przekazaną do
  // funkcji.
}

void potegaPrzezWskaznik(int *x) {
  *x = (*x) * (*x); // Podnosi wartość x do kwadratu
  cout << "Wynik (przez wskaźnik): " << *x << endl; // Wyświetla wynik
  // Funkcja przyjmuje argument przez wskaźnik, co oznacza, że zmiany dokonane
  // na zmiennej wskazywanej przez wskaźnik x wewnątrz funkcji wpływają na
  // oryginalną zmienną przekazaną do funkcji.
}

int zad1() {
  std::locale::global(std::locale(""));
  int liczba = 5;

  cout << "Początkowa wartość: " << liczba << endl;
  potegaPrzezZmienna(liczba);
  cout << "Wartość po funkcji: " << liczba << endl << endl;

  liczba = 5;
  cout << "Początkowa wartość: " << liczba << endl;
  potegaPrzezReferencje(liczba);
  cout << "Wartość po funkcji: " << liczba << endl << endl;

  liczba = 5;
  cout << "Początkowa wartość: " << liczba << endl;
  potegaPrzezWskaznik(&liczba);
  cout << "Wartość po funkcji: " << liczba << endl;

  return 0;
}

// Zadanie 2

int zad2() {
  std::locale::global(std::locale(""));
  int tablica[] = {10, 20, 30, 40, 50};
  int *ptr = tablica;

  cout << "Wartość: " << *ptr << endl; // Wyświetla pierwszą wartość tablicy

  ptr++;
  cout << "Wartość po przesunięciu: " << *ptr
       << endl; // Wyświetla drugą wartość tablicy

  ptr += 2;
  cout << "Wartość po przesunięciu: " << *ptr
       << endl; // Wyświetla czwartą wartość tablicy

  --ptr;
  cout << "Wartość po przesunięciu: " << *ptr
       << endl; // Wyświetla trzecią wartość tablicy

  cout << "Wartość: " << *(ptr + 2) << endl; // Wyświetla piątą wartość tablicy

  cout << "Wartość: " << *ptr << endl; // Wyświetla trzecią wartość tablicy

  return 0;
}

// Zadanie 3
void zamienWskazniki(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void zamienReferencje(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

int zad3() {
  int x = 5, y = 10;
  cout << "Przed zamianą: x = " << x << ", y = " << y << endl;
  zamienWskazniki(&x, &y);
  cout << "Po zamianie wskaźników: x = " << x << ", y = " << y << endl;

  zamienReferencje(x, y);
  cout << "Po zamianie referencji: x = " << x << ", y = " << y << endl;

  return 0;
}

// Zadanie 4
// Alokacja statyczna: Pamięć jest przydzielana podczas kompilacji i nie może
// być zmieniona w trakcie działania programu. Alokacja dynamiczna: Pamięć jest
// przydzielana w trakcie działania programu, co pozwala na większą
// elastyczność, ale wymaga ręcznego zarządzania pamięcią.

// Zadanie 5

int zad5(int argc, char *argv[]) {
  std::locale::global(std::locale(""));
  int n;

  if (argc > 1) {
    n = atoi(argv[1]);
  } else {
    cout << "Podaj rozmiar tablicy: ";
    cin >> n;
  }

  vector<int> tablica(n);
  srand(time(0));

  for (int i = 0; i < n; ++i) {
    tablica[i] = rand() % 100;
  }

  sort(tablica.begin(), tablica.end());

  int suma = accumulate(tablica.begin(), tablica.end(), 0);
  double srednia = static_cast<double>(suma) / n;
  double mediana = (n % 2 == 0) ? (tablica[n / 2 - 1] + tablica[n / 2]) / 2.0
                                : tablica[n / 2];

  cout << "Tablica: ";
  for (int val : tablica) {
    cout << val << " ";
  }
  cout << endl;

  cout << "Suma: " << suma << endl;
  cout << "Średnia: " << srednia << endl;
  cout << "Mediana: " << mediana << endl;

  return 0;
}

// Zadanie 6

struct Osoba {
  string imie;
  int wiek;

  Osoba(string i, int w) : imie(i), wiek(w) {}
};

int zad6() {
  // Statyczna alokacja
  Osoba osoba1("Jan", 30);
  cout << "Osoba 1: " << osoba1.imie << ", wiek: " << osoba1.wiek << endl;

  // Dynamiczna alokacja
  Osoba *osoba2 = new Osoba("Anna", 25);
  cout << "Osoba 2: " << osoba2->imie << ", wiek: " << osoba2->wiek << endl;

  delete osoba2;

  return 0;
}

// Zadanie 7

enum Kolor { CZERWONY, ZIELONY, NIEBIESKI };

union Wartosc {
  int wartosc_int;
  float wartosc_float;
  double wartosc_double;
};

int zad7() {
  Kolor mojKolor = CZERWONY;
  Wartosc mojaWartosc;

  mojaWartosc.wartosc_int = 10;
  cout << "Wartosc int: " << mojaWartosc.wartosc_int << endl;

  mojaWartosc.wartosc_float = 3.14f;
  cout << "Wartosc float: " << mojaWartosc.wartosc_float << endl;

  mojaWartosc.wartosc_double = 2.718281828459;
  cout << "Wartosc double: " << setprecision(15) << mojaWartosc.wartosc_double
       << endl;

  return 0;
}

int main(int argc, char *argv[]) {
  zad1();
  zad2();
  zad3();
  zad5(argc, argv);
  zad6();
  zad7();

  return 0;
}
