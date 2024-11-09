#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

void zadanie1() {
  for (int i = 0; i < 7; i++) {
    cout << "Witaj swiecie!" << endl;
  }
}

void zadanie2() {
  int suma = 0, suma_parzyste = 0;
  for (int i = 1; i <= 10; i++) {
    cout << i << " ";
    suma += i;
    if (i % 2 == 0)
      suma_parzyste += i;
  }
  cout << "\nSuma wszystkich liczb: " << suma << endl;
  cout << "Suma liczb parzystych: " << suma_parzyste << endl;
}

void zadanie3() {
  int i = 0;
  cout << "Petla while: " << endl;
  while (i < 5) {
    cout << "i = " << i << endl;
    i++;
  }

  i = 0;
  cout << "Petla do-while: " << endl;
  do {
    cout << "i = " << i << endl;
    i++;
  } while (i < 5);
}

void zadanie4() {
  cout << "Tabliczka mnozenia:\n";
  for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
      cout << setw(4) << i * j << " | ";
    }
    cout << endl;
  }
}

void zadanie5() {
  float tablica[] = {1.2f, 2.3f, 3.4f, 4.5f, 5.6f, 6.7f, 7.8f, 8.9f, 9.1f};

  cout << "Elementy tablicy od konca:\n";
  for (int i = 8; i >= 0; i--) {
    cout << tablica[i] << " ";
  }
  cout << endl;

  cout << "Co trzeci element tablicy:\n";
  for (int i = 0; i < 9; i += 3) {
    cout << tablica[i] << " ";
  }
  cout << endl;
}

void zadanie6() {
  const int wymiar = 2;
  int tablica[wymiar][wymiar][wymiar][wymiar][wymiar];
  int suma = 0, licznik = 0;

  srand(time(0));

  for (int i = 0; i < wymiar; i++)
    for (int j = 0; j < wymiar; j++)
      for (int k = 0; k < wymiar; k++)
        for (int l = 0; l < wymiar; l++)
          for (int m = 0; m < wymiar; m++) {
            tablica[i][j][k][l][m] = rand() % 100;
            suma += tablica[i][j][k][l][m];
            licznik++;
          }

  double srednia = static_cast<double>(suma) / licznik;

  cout << "Suma elementow tablicy: " << suma << endl;
  cout << "Srednia: " << srednia << endl;
  cout << "Srednia zaokraglona w dol: " << floor(srednia) << endl;
  cout << "Srednia zaokraglona w gore: " << ceil(srednia) << endl;
}

int main() {
  int wybor;
  do {
    cout << "\nWybierz zadanie (1-6) lub 0 aby zakonczyc:\n";
    cout << "1 - Wyswietl napis 'Witaj swiecie!' 7 razy\n";
    cout << "2 - Sumuj liczby od 1 do 10 oraz liczby parzyste\n";
    cout << "3 - Przyklad petli while i do-while\n";
    cout << "4 - Wypisz tabliczke mnozenia\n";
    cout << "5 - Tablica zmiennoprzecinkowa, od konca i co trzeci element\n";
    cout << "6 - Tablica pieciowymiarowa, suma i srednia\n";
    cout << "0 - Zakonczenie programu\n";
    cout << "Twoj wybor: ";
    cin >> wybor;

    switch (wybor) {
    case 1:
      system("cls");
      zadanie1();
      break;
    case 2:
      system("cls");
      zadanie2();
      break;
    case 3:
      system("cls");
      zadanie3();
      break;
    case 4:
      system("cls");
      zadanie4();
      break;
    case 5:
      system("cls");
      zadanie5();
      break;
    case 6:
      system("cls");
      zadanie6();
      break;
    case 0:
      cout << "Zakonczenie programu." << endl;
      break;
    default:
      cout << "Niepoprawny wybor. Sprobuj ponownie." << endl;
    }
  } while (wybor != 0);

  return 0;
}
