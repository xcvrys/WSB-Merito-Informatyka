
#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

// Zadanie 1: Funkcja wyświetlająca "Hello, World!"
void helloWorld(int times = 1) {
  for (int i = 0; i < times; ++i) {
    std::cout << "Hello, World!" << std::endl;
  }
}

// Zadanie 2: Funkcja sortująca tablicę
void sortArray(int arr[], int size) { std::sort(arr, arr + size); }

// Zadanie 3: Funkcje liczące silnię
// a) Używając pętli
int factorialLoop(int n) {
  int result = 1;
  for (int i = 1; i <= n; ++i) {
    result *= i;
  }
  return result;
}

// b) Używając rekurencji
int factorialRecursion(int n) {
  if (n <= 1) {
    return 1;
  }
  return n * factorialRecursion(n - 1);
}

// Zadanie 4: Funkcja inline
inline int multiply(int a, int b) { return a * b; }
// Funkcja inline różni się od innych funkcji tym, że kompilator może wstawić
// jej kod bezpośrednio w miejsce wywołania, co może przyspieszyć działanie
// programu.

// Zadanie 5: Funkcja odwracająca kolejność elementów tablicy
void reverseArray(int arr[], int size) { std::reverse(arr, arr + size); }

// Zadanie 6: Funkcja obliczająca sumę, średnią, minimum, maksimum oraz medianę
// tablicy
void arrayStatistics(int arr[], int size) {
  int sum = std::accumulate(arr, arr + size, 0);
  double average = static_cast<double>(sum) / size;
  int min = *std::min_element(arr, arr + size);
  int max = *std::max_element(arr, arr + size);

  std::vector<int> sortedArr(arr, arr + size);
  std::sort(sortedArr.begin(), sortedArr.end());
  double median = (size % 2 == 0)
                      ? (sortedArr[size / 2 - 1] + sortedArr[size / 2]) / 2.0
                      : sortedArr[size / 2];

  std::cout << "Sum: " << sum << std::endl;
  std::cout << "Average: " << average << std::endl;
  std::cout << "Min: " << min << std::endl;
  std::cout << "Max: " << max << std::endl;
  std::cout << "Median: " << median << std::endl;
}

// Zadanie 7: Przeciążanie funkcji
void print(int x) { std::cout << "Integer: " << x << std::endl; }

void print(double x) { std::cout << "Double: " << x << std::endl; }

// Zadanie 8: Funkcje obliczające wartość n-tego elementu ciągu Fibonacciego
// a) Używając pętli
int fibonacciLoop(int n) {
  if (n <= 1)
    return n;
  int a = 0, b = 1, c;
  for (int i = 2; i <= n; ++i) {
    c = a + b;
    a = b;
    b = c;
  }
  return c;
}

// b) Używając rekurencji
int fibonacciRecursion(int n) {
  if (n <= 1)
    return n;
  return fibonacciRecursion(n - 1) + fibonacciRecursion(n - 2);
}

int main() {
  // Testowanie funkcji z zadania 1
  helloWorld();
  helloWorld(3);

  // Testowanie funkcji z zadania 2
  int arr1[] = {5, 3, 8, 1, 2};
  int size1 = sizeof(arr1) / sizeof(arr1[0]);
  sortArray(arr1, size1);
  std::cout << "Sorted array: ";
  for (int i = 0; i < size1; ++i) {
    std::cout << arr1[i] << " ";
  }
  std::cout << std::endl;

  // Testowanie funkcji z zadania 3
  std::cout << "Factorial (loop) of 5: " << factorialLoop(5) << std::endl;
  std::cout << "Factorial (recursion) of 5: " << factorialRecursion(5)
            << std::endl;

  // Testowanie funkcji z zadania 4
  std::cout << "Multiply 3 and 4: " << multiply(3, 4) << std::endl;

  // Testowanie funkcji z zadania 5
  int arr2[] = {1, 2, 3, 4, 5};
  int size2 = sizeof(arr2) / sizeof(arr2[0]);
  reverseArray(arr2, size2);
  std::cout << "Reversed array: ";
  for (int i = 0; i < size2; ++i) {
    std::cout << arr2[i] << " ";
  }
  std::cout << std::endl;

  // Testowanie funkcji z zadania 6
  int arr3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int size3 = sizeof(arr3) / sizeof(arr3[0]);
  arrayStatistics(arr3, size3);

  // Testowanie funkcji z zadania 7
  print(42);
  print(3.14);

  // Testowanie funkcji z zadania 8
  std::cout << "Fibonacci (loop) of 10: " << fibonacciLoop(10) << std::endl;
  std::cout << "Fibonacci (recursion) of 10: " << fibonacciRecursion(10)
            << std::endl;

  return 0;
}
