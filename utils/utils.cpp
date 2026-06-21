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

vector<string> transformLineToStringVector(const string& line) {
  vector<string> parsed_items;
  string_view line_view = line;

  // 1. Locate the boundaries of the array
  auto start_bracket = line_view.find('[');
  auto end_bracket = line_view.rfind(']');

  // Validate bounds
  if (start_bracket == string_view::npos || end_bracket == string_view::npos || start_bracket >= end_bracket) {
    return parsed_items;
  }

  // 2. Isolate the contents inside the brackets
  string_view content = line_view.substr(start_bracket + 1, end_bracket - start_bracket - 1);

  // 3. Extract items enclosed in quotes
  size_t current_pos = 0;
  while (current_pos < content.size()) {
    auto first_quote = content.find('"', current_pos);
    if (first_quote == string_view::npos) {
      break;
    }

    auto second_quote = content.find('"', first_quote + 1);
    if (second_quote == string_view::npos) {
      break;
    }

    // Construct the string and add to the vector
    parsed_items.emplace_back(content.substr(first_quote + 1, second_quote - first_quote - 1));

    // Advance search position past the closing quote
    current_pos = second_quote + 1;
  }

  return parsed_items;
}

vector<char> transformLineToCharVector(const string& line) {
  size_t start_bracket = line.find('[');
  size_t end_bracket = line.rfind(']');
  if (start_bracket != string::npos && end_bracket != string::npos && start_bracket < end_bracket) {
    vector<string> parts = transformLineToStringVector(line);
    vector<char> v;
    v.reserve(parts.size());
    for (const string& s : parts) {
      if (s.size() == 1) {
        v.push_back(s[0]);
      }
    }
    return v;
  }
  vector<char> v;
  for (char c : line) {
    v.push_back(c);
  }
  return v;
}

void printCharVector(const vector<char>& v) {
  cout << "[";
  for (int i = 0; i < v.size(); ++i) {
    cout << "'" << v[i] << "'";
    if (i < v.size() - 1) {
      cout << ", ";
    }
  }
  cout << "]";
  cout << "\n";
}

void printIntVector(const vector<int>& v) {
  cout << "[";
  for (int i = 0; i < v.size(); ++i) {
    cout << v[i];
    if (i < v.size() - 1) {
      cout << ", ";
    }
  }
  cout << "]";
  cout << "\n";
}

void printStringVector(const vector<string>& v) {
  cout << "[";
  for (int i = 0; i < v.size(); ++i) {
    cout << "\"" << v[i] << "\"";
    if (i < v.size() - 1) {
      cout << ", ";
    }
  }
  cout << "]";
  cout << "\n";
}
