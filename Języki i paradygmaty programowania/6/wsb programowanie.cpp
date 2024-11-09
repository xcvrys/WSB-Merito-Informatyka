
// Zadanie 1
// a. #include - służy do dołączania plików nagłówkowych do programu.
// b. #ifdef, #ifndef, #endif - służą do warunkowego kompilowania kodu.
// c. #pragma - służy do specyficznych dla kompilatora instrukcji.
// d. #undef - służy do usuwania definicji makra.

// Zadanie 2
// #define - służy do definiowania makr, które są zastępowane przez preprocesor.
// constexpr - służy do definiowania stałych wyrażonych w czasie kompilacji.

#include <cmath>
#include <iostream>
#include <list>
#include <stdexcept>

// Zadanie 3
#ifndef MOJE_FUNKCJE_H
#define MOJE_FUNKCJE_H

void powitanie();           // Deklaracja funkcji powitanie
int mnozenie(int a, int b); // Deklaracja funkcji mnozenie

#endif

#include "moje_funkcje.h"

void powitanie() {
  std::cout << "Witaj w moich nowych funkcjach!" << std::endl;
}

int mnozenie(int a, int b) { return a * b; }

// Zadanie 4
void funkcjaZWyjatkiem() {
  throw std::runtime_error("To jest przykładowy wyjątek!");
}

// Zadanie 5
class Zwierze {
public:
  std::string gatunek;

  Zwierze(std::string g) : gatunek(g) {}

  virtual void wyswietlInformacje() const {
    std::cout << "Gatunek: " << gatunek << std::endl;
  }
};

class Pies : public Zwierze {
public:
  std::string rasa;

  Pies(std::string g, std::string r) : Zwierze(g), rasa(r) {}

  void wyswietlInformacje() const override {
    std::cout << "Gatunek: " << gatunek << ", Rasa: " << rasa << std::endl;
  }

  void szczekaj() const { std::cout << "Hau hau!" << std::endl; }
};

// Zadanie 6
// Klasa bazowa
class Figura {
public:
  virtual double obliczPole() const = 0;  // Metoda abstrakcyjna
  virtual double obliczObwod() const = 0; // Metoda abstrakcyjna
  virtual ~Figura() {}                    // Wirtualny destruktor
};

// Klasa pochodna - Trojkat
class Trojkat : public Figura {
private:
  double a, b, c; // Pola

public:
  Trojkat(double sideA, double sideB, double sideC)
      : a(sideA), b(sideB), c(sideC) {} // Konstruktor

  double obliczPole() const override {
    // Wzór Herona
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
  }

  double obliczObwod() const override { return a + b + c; }
};

// Klasa pochodna - Kolo
class Kolo : public Figura {
private:
  double promien; // Pole

public:
  Kolo(double r) : promien(r) {} // Konstruktor

  double obliczPole() const override { return 3.14 * promien * promien; }

  double obliczObwod() const override { return 2 * 3.14 * promien; }
};

// Klasa pochodna - Prostokat
class Prostokat : public Figura {
private:
  double dlugosc, szerokosc; // Pola

public:
  Prostokat(double l, double s) : dlugosc(l), szerokosc(s) {} // Konstruktor

  double obliczPole() const override { return dlugosc * szerokosc; }

  double obliczObwod() const override { return 2 * (dlugosc + szerokosc); }
};

int main() {
  // Zadanie 3
  powitanie();
  int wynikMnozenia = mnozenie(5, 3);
  std::cout << "Wynik mnozenia: " << wynikMnozenia << std::endl;

  // Zadanie 4
  try {
    funkcjaZWyjatkiem();
  } catch (const std::exception &e) {
    std::cerr << "Złapany wyjątek: " << e.what() << std::endl;
  }

  // Zadanie 5
  Pies mojPies("Ssak", "Labrador");
  mojPies.wyswietlInformacje();
  mojPies.szczekaj();

  // Zadanie 6

  std::list<Figura *> listaFigur; // Lista wskaźników do obiektów klasy Figura

  listaFigur.push_back(new Kolo(3.0));
  listaFigur.push_back(new Trojkat(4.0, 5.0, 6.0));
  listaFigur.push_back(new Prostokat(2.0, 4.0));
  // Tu można dodać więcej figur do listy

  for (const auto &figura : listaFigur) {
    std::cout << "Pole: " << figura->obliczPole()
              << ", Obwod: " << figura->obliczObwod() << std::endl;
  }

  // Zwolnienie pamięci zaalokowanej na obiekty
  for (const auto &figura : listaFigur) {
    delete figura;
  }

  return 0;

  return 0;
}

// Zadanie 7
// Klasy: Zwierze, Pies, Figura, Trojkat, Kolo, Prostokat
// Pola: gatunek, rasa, a, b, c, promien, dlugosc, szerokosc
// Metody: wyswietlInformacje, szczekaj, obliczPole, obliczObwod
// Dziedziczenie: Pies dziedziczy po Zwierze, Trojkat, Kolo, Prostokat
// dziedziczą po Figura Polimorfizm: Metody obliczPole i obliczObwod są
// wirtualne i nadpisywane w klasach pochodnych
