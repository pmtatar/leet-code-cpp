#include <iostream>

#include "../utils/utils.h"

using namespace std;

/**
 * This function calculates the power of a number using fast exponentiation.
 * It uses the property that (a * b) % c = ((a % c) * (b % c)) % c.
 * This is useful because it allows us to calculate the power of a number in O(log n) time.
 * @param base The base number
 * @param power The power to calculate
 * @return The result of base^power
 */
const int MOD = 1e9 + 7; // 10^9 + 7 is a prime number that is used to avoid overflow
long long fastPower(unsigned int base, unsigned int power) {
  long long result = 1;
  while (power > 0) {
    if ((power & 1) == 1) {
      result = (result * base) % MOD;
    }
    base = (base * base) % MOD;
    power >>= 1;
  }
  return result;
}

int main() {
  int n = readInt();
  cout << n << "\n";
  readNLines(n, [](const string& line) {
    vector<int> v = transformLineToIntVector(line);
    cout << v[0] << " ^ " << v[1] << " = " << fastPower(v[0], v[1]) << "\n";
  });
  return 0;
}
