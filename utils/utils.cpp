#include <functional>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int readInt() {
  int x = -1;
  cin >> x;
  cin.ignore();
  return x;
}

void readNLines(int n, const function<void(const string&)>& processLine) {
  for (int i = 0; i < n; i++) {
    string line;
    getline(cin, line);
    processLine(line);
  }
}

vector<int> transformLineToIntVector(const string& line) {
  vector<int> v;
  stringstream ss(line);
  int token = -1;
  while (ss >> token) {
    v.push_back(token);
  }
  return v;
}
