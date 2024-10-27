#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Zadanie 1: Funkcja „Hello, World!”
void helloWorld(int times = 1) {
    for (int i = 0; i < times; ++i) {
        cout << "Hello, World!" << endl;
    }
}

// Zadanie 2: Funkcja sortująca tablicę
void sortArray(int arr[], int size) {
    sort(arr, arr + size);
    cout << "Posortowana tablica: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Zadanie 3: Funkcje liczące silnię
int factorialLoop(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int factorialRecursive(int n) {
    return (n <= 1) ? 1 : n * factorialRecursive(n - 1);
}

// Zadanie 4: Funkcja inline
inline int square(int x) {
    return x * x;
}

// Zadanie 5: Funkcja odwracająca kolejność elementów tablicy
void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; ++i) {
        swap(arr[i], arr[size - i - 1]);
    }
    cout << "Odwrócona tablica: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Zadanie 6: Funkcja statystyk
void stats(const int arr[], int size) {
    int sum = 0, min = arr[0], max = arr[0];
    vector<int> vec(arr, arr + size);

    for (int i = 0; i < size; ++i) {
        sum += arr[i];
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    double avg = static_cast<double>(sum) / size;
    sort(vec.begin(), vec.end());
    double median = (size % 2 == 0) ? (vec[size / 2 - 1] + vec[size / 2]) / 2.0 : vec[size / 2];

    cout << "Suma: " << sum << ", Średnia: " << avg << ", Min: " << min
              << ", Max: " << max << ", Mediana: " << median << endl;
}

// Zadanie 7: Przeciążanie funkcji
int multiply(int a, int b) {
    return a * b;
}

double multiply(double a, double b) {
    return a * b;
}

// Zadanie 8: Ciąg Fibonacciego
int fibonacciLoop(int n) {
    int a = 0, b = 1, temp;
    for (int i = 2; i <= n; ++i) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return (n == 0) ? 0 : b;
}

int fibonacciRecursive(int n) {
    return (n <= 1) ? n : fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

void showMenu() {
    cout << "\nWybierz numer zadania:\n";
    cout << "1. Hello World\n";
    cout << "2. Sortowanie tablicy\n";
    cout << "3. Silnia (pętla i rekurencja)\n";
    cout << "4. Funkcja inline (kwadrat liczby)\n";
    cout << "5. Odwrócenie tablicy\n";
    cout << "6. Statystyki tablicy\n";
    cout << "7. Przeciążanie funkcji (mnożenie int i double)\n";
    cout << "8. Ciąg Fibonacciego (pętla i rekurencja)\n";
    cout << "0. Wyjście\n";
    cout << "Twój wybór: ";
}

int main() {
    int choice;
    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                helloWorld();
                helloWorld(3);
                break;
            case 2: {
                int arr[] = {5, 3, 8, 1, 2};
                int size = sizeof(arr) / sizeof(arr[0]);
                sortArray(arr, size);
                break;
            }
            case 3: {
                int number = 5;
                cout << "Silnia (pętla): " << factorialLoop(number) << endl;
                cout << "Silnia (rekurencja): " << factorialRecursive(number) << endl;
                break;
            }
            case 4:
                cout << "Kwadrat liczby 4 to: " << square(4) << endl;
                break;
            case 5: {
                int arr[] = {1, 2, 3, 4, 5};
                int size = sizeof(arr) / sizeof(arr[0]);
                reverseArray(arr, size);
                break;
            }
            case 6: {
                int arr[] = {5, 3, 8, 1, 2};
                int size = sizeof(arr) / sizeof(arr[0]);
                stats(arr, size);
                break;
            }
            case 7: // 🔥
                cout << "Int: " << multiply(3, 4) << endl;
                cout << "Double: " << multiply(3.5, 4.2) << endl;
                break;
            case 8: {
                int n = 5;
                cout << "Fibonacci (pętla): " << fibonacciLoop(n) << endl;
                cout << "Fibonacci (rekurencja): " << fibonacciRecursive(n) << endl;
                break;
            }
            case 0:
                cout << "Zakończono program." << endl;
                return 0;
            default:
                cout << "Niepoprawny wybór. Spróbuj ponownie." << endl;
        }
    }
}
