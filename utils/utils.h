#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <functional>
#include <sstream>
#include <vector>

using namespace std;

int readInt();
void readNLines(int n, const function<void(const string&)>& processLine);
vector<int> transformLineToIntVector(const string& line);

#endif
