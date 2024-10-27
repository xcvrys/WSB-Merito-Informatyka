#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
namespace fs = filesystem;

void displayMenu() {
  cout << "\n--- Menu ---\n";
  cout << "1. Funkcje replace i inne\n";
  cout << "2. Różnice między get, getline, read i >>\n";
  cout << "3. Analiza kodu z filestream\n";
  cout << "4. Wczytywanie liczb i obliczanie średniej i sumy\n";
  cout << "5. Liczenie znaków, słów i linii\n";
  cout << "6. Wczytywanie liczb i sprawdzanie parzystości\n";
  cout << "7. Sortowanie tablic (Bubble Sort i Quick Sort)\n";
  cout << "8. Wypisywanie zawartości plików\n";
  cout << "9. Operacje na katalogach i plikach\n";
  cout << "10. Szyfrowanie Cezarem\n";
  cout << "11. Deszyfrowanie cezarem\n";
  cout << "0. Wyjście\n";
}

int zad1() {
  // Przykład użycia funkcji replace
  string str = "Hello, World!";
  cout << "Oryginalny string: " << str << endl;

  // Zastąpienie "World" na "C++"
  str.replace(7, 5, "C++");
  cout << "Po użyciu replace: " << str << endl;

  // Opis działania funkcji replace:
  // string& replace (size_t pos, size_t len, const string& str);
  // Zastępuje fragment stringa zaczynając od pozycji 'pos' i o długości 'len'
  // na string 'str'.

  // Przykład użycia funkcji insert
  string str2 = "C++ World!";
  cout << "\nOryginalny string: " << str2 << endl;

  // Wstawienie "Hello, " na początku
  str2.insert(0, "Hello, ");
  cout << "Po użyciu insert: " << str2 << endl;

  // Opis działania funkcji insert:
  // string& insert (size_t pos, const string& str);
  // Wstawia string 'str' na pozycji 'pos'.

  // Przykład użycia funkcji erase
  string str3 = "Hello, C++ World!";
  cout << "\nOryginalny string: " << str3 << endl;

  // Usunięcie 5 znaków zaczynając od pozycji 7
  str3.erase(7, 5);
  cout << "Po użyciu erase: " << str3 << endl;

  // Opis działania funkcji erase:
  // string& erase (size_t pos, size_t len);
  // Usuwa fragment stringa zaczynając od pozycji 'pos' i o długości 'len'.

  return 0;
}

int zad2() {
  // Tworzenie przykładowego pliku do testów
  {
    ofstream outFile("example.txt");
    outFile << "Pierwsza linia\nDruga linia\nTrzecia linia\n";
    outFile.close();
  }

  // Otwieranie pliku do odczytu
  ifstream inFile("example.txt");
  if (!inFile) {
    cerr << "Nie można otworzyć pliku." << endl;
    return 1;
  }

  // 1. Wczytywanie z użyciem get()
  char ch;
  cout << "Użycie get(): ";
  while (inFile.get(ch) && ch != '\n') { // Wczytuje do napotkania nowej linii
    cout << ch;
  }
  cout << endl;

  // Resetowanie strumienia do początku pliku
  inFile.clear();  // Czyści flagi błędów
  inFile.seekg(0); // Ustawia wskaźnik na początek pliku

  // 2. Wczytywanie z użyciem getline()
  string line;
  cout << "Użycie getline(): ";
  if (getline(inFile, line)) { // Wczytuje całą linię
    cout << line;
  }
  cout << endl;

  // Resetowanie strumienia do początku pliku
  inFile.clear();
  inFile.seekg(0);

  // 3. Wczytywanie z użyciem read()
  char buffer[20];
  cout << "Użycie read(): ";
  inFile.read(buffer, sizeof(buffer) - 1); // Wczytuje maksymalnie 19 znaków
  buffer[inFile.gcount()] = '\0';          // Ustawia null-terminator
  cout << buffer;
  cout << endl;

  // Resetowanie strumienia do początku pliku
  inFile.clear();
  inFile.seekg(0);

  // 4. Wczytywanie z użyciem operatora >>
  string word;
  cout << "Użycie operatora >>: ";
  while (inFile >> word) { // Wczytuje słowa oddzielone spacjami
    cout << word << " ";
  }
  cout << endl;

  // Zamknięcie pliku
  inFile.close();
  return 0;
}

int zad3(int argc, char *argv[]) {
  // Ustawienie lokalizacji globalnej na domyślną lokalizację systemową.
  locale::global(locale(""));

  // Sprawdzanie, czy podano odpowiednią liczbę argumentów wiersza poleceń.
  if (argc != 3) {
    cout << "Użycie: " << argv[0] << " <katalog> <plik>" << endl;
    return 1; // Zwraca kod błędu 1, gdy argumenty są niepoprawne.
  }

  // Pobieranie nazw katalogu i pliku z argumentów wiersza poleceń
  fs::path directoryPath = argv[1]; // Katalog
  fs::path filePath = argv[2];      // Plik

  // Sprawdzenie, czy katalog istnieje
  if (!fs::exists(directoryPath)) {
    // Jeśli katalog nie istnieje, spróbuj go utworzyć
    if (fs::create_directory(directoryPath)) {
      cout << "Utworzono katalog: " << directoryPath
           << endl; // Informacja o utworzeniu katalogu
    } else {
      cout << "Nie udało się utworzyć katalogu." << endl; // Komunikat o błędzie
      return 1;                                           // Zwraca kod błędu 1
    }
  } else {
    cout << "Katalog już istnieje." << endl; // Informacja o istnieniu katalogu
  }

  // Tworzenie pliku i zapisywanie do niego treści
  ofstream outputFile(filePath); // Otwiera plik do zapisu
  if (outputFile.is_open()) {
    outputFile << "To jest zawartość pliku." << endl; // Zapisuje treść do pliku
    outputFile.close();                               // Zamyka plik
    cout << "Utworzono plik: " << filePath
         << endl; // Informacja o utworzeniu pliku
  } else {
    cout << "Nie udało się utworzyć pliku." << endl; // Komunikat o błędzie
    return 1;                                        // Zwraca kod błędu 1
  }

  // Tworzenie ścieżki do skopiowanego pliku
  fs::path copiedFilePath =
      directoryPath / "skopiowany_plik.txt"; // Tworzy ścieżkę do nowego pliku

  // Próba skopiowania pliku
  try {
    fs::copy_file(filePath, copiedFilePath,
                  fs::copy_options::overwrite_existing); // Kopiuje plik
    cout << "Skopiowano plik do: " << copiedFilePath
         << endl; // Informacja o skopiowaniu pliku
  } catch (const fs::filesystem_error &e) {
    cout << "Błąd podczas kopiowania pliku: " << e.what()
         << endl; // Komunikat o błędzie
    return 1;     // Zwraca kod błędu 1
  }

  // Wyświetlanie zawartości katalogu
  cout << "Zawartość katalogu:" << endl;
  for (const auto &entry : fs::directory_iterator(directoryPath)) {
    cout << entry.path().filename()
         << endl; // Wyświetla nazwę każdego pliku w katalogu
  }

  // Wyświetlanie atrybutów pliku
  cout << "Atrybuty pliku " << filePath << ":" << endl;
  if (fs::exists(filePath)) {
    cout << "Rozmiar: " << fs::file_size(filePath) << " bajtów"
         << endl; // Wyświetla rozmiar pliku
    cout << "Czas ostatniej modyfikacji: "
         << fs::last_write_time(filePath).time_since_epoch().count()
         << endl; // Wyświetla czas ostatniej modyfikacji
  } else {
    cout << "Plik nie istnieje." << endl; // Komunikat o nieistnieniu pliku
  }

  return 0; // Zwraca kod błędu 0 (sukces)
}

void zad4() {
  int choice;
  string path;

  while (true) {
    cout << "Wybierz operację:\n";
    cout << "1. Sprawdź istnienie pliku\n";
    cout << "2. Utwórz katalog\n";
    cout << "3. Wyświetl zawartość katalogu\n";
    cout << "0. Wyjście\n";
    cout << "Wprowadź swój wybór: ";
    cin >> choice;

    switch (choice) {
    case 1: // Sprawdź istnienie pliku
      cout << "Podaj ścieżkę do pliku: ";
      cin >> path;
      if (fs::exists(path)) {
        cout << path << " istnieje." << endl;
      } else {
        cout << path << " nie istnieje." << endl;
      }
      break;

    case 2: // Utwórz katalog
      cout << "Podaj nazwę katalogu do utworzenia: ";
      cin >> path;
      if (fs::create_directory(path)) {
        cout << "Utworzono katalog: " << path << endl;
      } else {
        cout << "Nie udało się utworzyć katalogu lub katalog już istnieje."
             << endl;
      }
      break;

    case 3: // Wyświetl zawartość katalogu
      cout << "Podaj ścieżkę do katalogu: ";
      cin >> path;
      if (fs::exists(path) && fs::is_directory(path)) {
        cout << "Zawartość katalogu " << path << ":" << endl;
        for (const auto &entry : fs::directory_iterator(path)) {
          cout << entry.path().filename() << endl;
        }
      } else {
        cout << "Podana ścieżka nie jest katalogiem lub nie istnieje." << endl;
      }
      break;

    case 0: // Wyjście
      cout << "Zamykam program." << endl;
      return;

    default:
      cout << "Nieprawidłowy wybór. Spróbuj ponownie." << endl;
    }
  }
}

int zad5(int argc, char *argv[]) {
  // Sprawdzanie, czy podano co najmniej jeden argument
  if (argc < 2) {
    cout << "Użycie: " << argv[0] << " <nazwa_pliku1> <nazwa_pliku2> ..."
         << endl;
    return 1; // Zwrócenie błędu, gdy brak argumentów
  }

  // Iteracja przez wszystkie argumenty podane w linii poleceń
  for (int i = 1; i < argc; ++i) {
    ifstream file(argv[i]); // Otwieranie pliku

    // Sprawdzanie, czy plik został poprawnie otwarty
    if (!file.is_open()) {
      cout << "Nie można otworzyć pliku: " << argv[i] << endl;
      continue; // Kontynuacja do następnego pliku
    }

    cout << "Zawartość pliku " << argv[i] << ":\n";

    string line;
    // Wczytywanie i wypisywanie linii z pliku
    while (getline(file, line)) {
      cout << line << endl; // Wypisanie linii
    }

    file.close(); // Zamknięcie pliku
    cout << endl; // Nowa linia dla lepszej czytelności
  }

  return 0; // Zwrócenie sukcesu
}

int zad6(int argc, char *argv[]) {
  // Sprawdzanie, czy podano nazwę pliku jako argument
  if (argc != 2) {
    cout << "Użycie: " << argv[0] << " <nazwa_pliku>" << endl;
    return 1; // Zwrócenie błędu, gdy brak argumentu
  }

  ifstream file(argv[1]); // Otwieranie pliku
  if (!file.is_open()) {
    cout << "Nie można otworzyć pliku: " << argv[1] << endl;
    return 1; // Zwrócenie błędu, gdy nie udało się otworzyć pliku
  }

  vector<double> numbers; // Wektor do przechowywania liczb
  double number;

  // Wczytywanie liczb z pliku
  while (file >> number) {
    numbers.push_back(number); // Dodawanie liczby do wektora
  }

  file.close(); // Zamknięcie pliku

  // Sprawdzanie, czy wczytano jakiekolwiek liczby
  if (numbers.empty()) {
    cout << "Brak liczb w pliku." << endl;
    return 0; // Zwrócenie sukcesu, gdy brak liczb
  }

  double sum = 0.0; // Zmienna do przechowywania sumy
  // Obliczanie sumy liczb
  for (double num : numbers) {
    sum += num;
  }

  double average = sum / numbers.size(); // Obliczanie średniej

  // Wypisywanie wyników
  cout << "Suma: " << sum << endl;
  cout << "Średnia: " << average << endl;

  return 0; // Zwrócenie sukcesu
}

int zad7(int argc, char *argv[]) {
  // Sprawdzanie, czy podano nazwę pliku jako argument
  if (argc != 2) {
    cout << "Użycie: " << argv[0] << " <nazwa_pliku>" << endl;
    return 1; // Zwrócenie błędu, gdy brak argumentu
  }

  ifstream file(argv[1]); // Otwieranie pliku
  if (!file.is_open()) {
    cout << "Nie można otworzyć pliku: " << argv[1] << endl;
    return 1; // Zwrócenie błędu, gdy nie udało się otworzyć pliku
  }

  string line;
  size_t charCount = 0; // Liczba znaków
  size_t wordCount = 0; // Liczba słów
  size_t lineCount = 0; // Liczba linii

  // Wczytywanie linii z pliku
  while (getline(file, line)) {
    lineCount++;              // Zwiększanie licznika linii
    charCount += line.size(); // Dodawanie liczby znaków w linii

    // Zliczanie słów w linii
    istringstream iss(line);
    string word;
    while (iss >> word) {
      wordCount++; // Zwiększanie licznika słów
    }
  }

  file.close(); // Zamknięcie pliku

  // Wypisywanie wyników
  cout << "Liczba znaków: " << charCount << endl;
  cout << "Liczba słów: " << wordCount << endl;
  cout << "Liczba linii: " << lineCount << endl;

  return 0; // Zwrócenie sukcesu
}

bool isDivisible(int number, int divisor) {
  return number % divisor ==
         0; // Sprawdzanie, czy liczba jest podzielna przez dany dzielnik
}

int zad8(int argc, char *argv[]) {
  // Sprawdzanie, czy podano nazwę pliku jako argument
  if (argc != 2) {
    cout << "Użycie: " << argv[0] << " <nazwa_pliku>" << endl;
    return 1; // Zwrócenie błędu, gdy brak argumentu
  }

  ifstream file(argv[1]); // Otwieranie pliku
  if (!file.is_open()) {
    cout << "Nie można otworzyć pliku: " << argv[1] << endl;
    return 1; // Zwrócenie błędu, gdy nie udało się otworzyć pliku
  }

  string line;
  // Wczytywanie każdej linii z pliku
  while (getline(file, line)) {
    istringstream iss(line);
    int number;

    // Wczytywanie każdej liczby z linii
    while (iss >> number) {
      cout << "Liczba: " << number << endl;

      // Sprawdzanie parzystości
      if (number % 2 == 0) {
        cout << " - Parzysta";
      } else {
        cout << " - Nieparzysta";
      }

      // Sprawdzanie podzielności
      if (isDivisible(number, 2))
        cout << ", podzielna przez 2";
      if (isDivisible(number, 3))
        cout << ", podzielna przez 3";
      if (isDivisible(number, 5))
        cout << ", podzielna przez 5";
      if (isDivisible(number, 9))
        cout << ", podzielna przez 9";

      cout << endl; // Nowa linia po każdej liczbie
    }
  }

  file.close(); // Zamknięcie pliku
  return 0;     // Zwrócenie sukcesu
}

// Funkcja do sortowania bąbelkowego (Bubble Sort)
void bubbleSort(vector<int> &arr) {
  int n = arr.size();
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < n - i - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        // Zamiana miejscami
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

// Funkcja do sortowania szybkiego (Quick Sort)
void quickSort(vector<int> &arr, int low, int high) {
  if (low < high) {
    int pivot = arr[high]; // Wybieramy ostatni element jako pivot
    int i = low - 1;       // Indeks mniejszego elementu

    for (int j = low; j < high; ++j) {
      if (arr[j] < pivot) {
        ++i;                  // Zwiększamy indeks mniejszego elementu
        swap(arr[i], arr[j]); // Zamiana miejscami
      }
    }
    swap(arr[i + 1], arr[high]); // Zamiana pivotu na odpowiednią pozycję
    int pi = i + 1;              // Indeks pivotu

    // Rekurencyjne sortowanie elementów przed i po pivot
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

// Funkcja do wczytywania tablicy z pliku
vector<int> readArrayFromFile(const string &filename) {
  ifstream file(filename);
  vector<int> array;
  string line;

  // Wczytywanie każdej linii jako tablicy liczb
  while (getline(file, line)) {
    istringstream iss(line);
    int number;
    while (iss >> number) {
      array.push_back(number);
    }
  }

  file.close();
  return array;
}

// Funkcja do wypisywania tablicy
void printArray(const vector<int> &array) {
  for (const int &num : array) {
    cout << num << " ";
  }
  cout << endl;
}

int zad9(int argc, char *argv[]) {
  if (argc != 2) {
    cout << "Użycie: " << argv[0] << " <nazwa_pliku>" << endl;
    return 1; // Zwrócenie błędu, gdy brak argumentu
  }

  // Wczytanie tablicy z pliku
  vector<int> array = readArrayFromFile(argv[1]);

  // Sortowanie bąbelkowe
  vector<int> bubbleArray =
      array; // Kopiujemy tablicę do sortowania bąbelkowego
  bubbleSort(bubbleArray);
  cout << "Tablica po sortowaniu bąbelkowym: ";
  printArray(bubbleArray);

  // Sortowanie szybkie
  vector<int> quickArray = array; // Kopiujemy tablicę do sortowania szybkiego
  quickSort(quickArray, 0, quickArray.size() - 1);
  cout << "Tablica po sortowaniu szybkim: ";
  printArray(quickArray);

  return 0; // Zwrócenie sukcesu
}

// Funkcja do szyfrowania tekstu przy użyciu szyfru Cezara
string caesarEncrypt(const string &text, int shift) {
  string encryptedText = "";
  // Przechodzimy przez każdy znak tekstu
  for (char c : text) {
    // Sprawdzamy, czy znak jest literą
    if (isalpha(c)) {
      char base =
          islower(c) ? 'a' : 'A'; // Ustalamy bazę (małe lub wielkie litery)
      // Szyfrujemy znak, przesuwając go o wartość 'shift'
      c = (c - base + shift) % 26 + base;
    }
    encryptedText += c; // Dodajemy zaszyfrowany znak do nowego tekstu
  }
  return encryptedText;
}

// Funkcja do odszyfrowywania tekstu przy użyciu szyfru Cezara
string caesarDecrypt(const string &text, int shift) {
  return caesarEncrypt(
      text,
      26 - (shift %
            26)); // Odszyfrowanie to szyfrowanie z przeciwnym przesunięciem
}

int main(int argc, char **argv) {
  while (true) {
    displayMenu();
    int choice;
    cout << "Wybierz zadanie (1-9, 0 aby wyjść): ";
    cin >> choice;

    switch (choice) {
    case 1:
      zad1();
      break;
    case 2:
      zad2();
      break;
    case 4:
      zad4();
      break;
    case 6:
      zad6(argc, argv);
      break;
    case 7:
      zad7(argc, argv);
      break;
    case 8:
      zad8(argc, argv);
      break;
    case 9:
      zad9(argc, argv);
      break;

    case 10:
      cout << caesarDecrypt(
          "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do "
          "eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim "
          "ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut "
          "aliquip ex ea commodo consequat. Duis aute irure dolor in "
          "reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla "
          "pariatur. Excepteur sint occaecat cupidatat non proident, sunt in "
          "culpa qui officia deserunt mollit anim id est laborum.",
          12);
      break;

    case 11:
      cout << caesarEncrypt(
          "Zcfsa wdgia rczcf gwh oash, qcbgsqhshif orwdwgqwbu szwh, gsr rc "
          "swigacr hsadcf wbqwrwribh ih zopcfs sh rczcfs aoubo ozweio. Ih sbwa "
          "or awbwa jsbwoa, eiwg bcghfir slsfqwhohwcb izzoaqc zopcfwg bwgw ih "
          "ozweiwd sl so qcaacrc qcbgseioh. Riwg oihs wfifs rczcf wb "
          "fsdfsvsbrsfwh wb jczidhohs jszwh sggs qwzzia rczcfs si tiuwoh bizzo "
          "dofwohif. Slqsdhsif gwbh cqqosqoh qidwrohoh bcb dfcwrsbh, gibh wb "
          "qizdo eiw cttwqwo rsgsfibh aczzwh obwa wr sgh zopcfia.",
          12);
      break;
    case 0:
      return 0;
    default:
      cout << "Niepoprawny wybór, spróbuj ponownie." << endl;
    }
  }
}
