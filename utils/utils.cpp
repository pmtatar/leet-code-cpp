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

vector<string> splitLine(const string& line, char delimiter) {
  vector<string> parts;
  stringstream ss(line);
  string part;
  while (getline(ss, part, delimiter)) {
    size_t start = part.find_first_not_of(" \t");
    if (start == string::npos) {
      continue;
    }
    size_t end = part.find_last_not_of(" \t");
    parts.push_back(part.substr(start, end - start + 1));
  }
  return parts;
}

vector<int> transformLineToIntVector(const string& line) {
  vector<int> v;
  size_t start_bracket = line.find('[');
  size_t end_bracket = line.rfind(']');
  if (start_bracket == string::npos || end_bracket == string::npos || start_bracket >= end_bracket) {
    return v;
  }
  string content = line.substr(start_bracket + 1, end_bracket - start_bracket - 1);
  stringstream ss(content);
  int num;
  while (ss >> num) {
    v.push_back(num);
    while (ss.good() && (ss.peek() == ',' || ss.peek() == ' ' || ss.peek() == '\t')) {
      ss.ignore(1);
    }
  }
  return v;
}

vector<vector<int>> transformLineTo2DIntMatrix(const string& line) {
  vector<vector<int>> matrix;
  size_t pos = 0;
  if (!line.empty() && line[0] == '[') {
    pos = 1;
  }
  while (pos < line.size()) {
    size_t start = line.find('[', pos);
    if (start == string::npos) {
      break;
    }
    size_t end = line.find(']', start);
    if (end == string::npos) {
      break;
    }
    matrix.push_back(transformLineToIntVector(line.substr(start, end - start + 1)));
    pos = end + 1;
  }
  return matrix;
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

void print2DIntVector(const vector<vector<int>>& matrix) {
  for (const vector<int>& row : matrix) {
    printIntVector(row);
  }
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
