#include <iostream>

#include "../utils/utils.h"

using namespace std;

/**
 * This function calculates the square root of a number using the Newton-Raphson method.
 * @param n The number to calculate the square root of
 * @return The square root of the number
 */
double fastSquareRoot(unsigned int n) {
  double x = n;
  double root = 0;
  while (true) {
    root = 0.5 * (x + (n / x));
    if (abs(root - x) < 1e-7) {
      break;
    }
    x = root;
  }
  return root;
}

/**
 * This function calculates the square root of a number using the Babylonian method.
 * @param n The number to calculate the square root of
 * @return The square root of the number
 */
unsigned int binarySearchSquareRoot(unsigned int n) {
  unsigned int left = 0;
  unsigned int right = n;
  unsigned int mid = 0;
  while (left <= right) {
    mid = (left + right) / 2;
    unsigned int product = mid * mid;
    if (product == n) {
      return mid;
    }
    if (product < n) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return mid;
}

int main() {
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [](const string& line) {
    unsigned int num = stoi(line);
    cout << num << " ^ 1/2 = " << fastSquareRoot(num) << "\n";
    cout << num << " binary search ^ 1/2 = " << binarySearchSquareRoot(num) << "\n";
  });
  return 0;
}
