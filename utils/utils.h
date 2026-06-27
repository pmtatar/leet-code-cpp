#ifndef UTILS_H
#define UTILS_H

#include <functional>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

/**
 * Read an integer from the standard input.
 *
 * Example:
 * Input: "5"
 * Output: 5
 */
int readInt();

/**
 * Read n lines from the standard input.
 */
void readNLines(int n, const function<void(const string&)>& processLine);

/**
 * Split a line into substrings at each occurrence of the delimiter.
 * Leading and trailing whitespace is trimmed from each part.
 *
 * Example:
 * Input: "[1, 2, 3, 4, 5]; [1, 2, 7]", ';'
 * Output: vector<string> with items ["[1, 2, 3, 4, 5]", "[1, 2, 7]"]
 */
vector<string> splitLine(const string& line, char delimiter);

/**
 * Transform a line of text into a vector of integers.
 *
 * Example:
 * Input: "[1, 2, 3, 4, 5]"
 * Output: vector<int> with items [1, 2, 3, 4, 5]
 */
vector<int> transformLineToIntVector(const string& line);

/**
 * Transform a line of text into a 2D matrix of integers.
 *
 * Example:
 * Input: "[[1, 2, 3], [4, 5, 6], [7, 8, 9]]"
 * Output: vector<vector<int>> with rows [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
 */
vector<vector<int>> transformLineTo2DIntMatrix(const string& line);

/**
 * Transform a line of text into a vector of characters.
 *
 * If the line looks like a JSON-style array of quoted single-character strings,
 * each quoted segment becomes one char (same parsing as transformLineToStringVector).
 * Example:
 * Input: "[\"h\", \"e\", \"l\", \"l\", \"o\"]"
 * Output: vector<char> with items ['h', 'e', 'l', 'l', 'o']
 *
 * Otherwise (no [...] array), every character in the line is stored in order
 * (legacy behaviour for a plain string with no brackets).
 */
vector<char> transformLineToCharVector(const string& line);

/**
 * Transform a line of text into a vector of strings.
 *
 * Example:
 * Input: "[\"flower\", \"flow\", \"fly\", \"flight\" ]"
 * Output: vector<string> with items ["flower","flow","fly","flight"]
 */
vector<string> transformLineToStringVector(const string& line);

/**
 * Print a vector of characters.
 *
 * Example: ['h', 'e', 'l', 'l', 'o']
 */
void printCharVector(const vector<char>& v);

/**
 * Print a vector of integers.
 *
 * Example: [1, 2, 3, 4, 5]
 */
void printIntVector(const vector<int>& v);

/**
 * Print a 2D matrix of integers, one row per line.
 *
 * Example:
 * [[1, 2, 3], [4, 5, 6], [7, 8, 9]] prints as:
 * [1, 2, 3]
 * [4, 5, 6]
 * [7, 8, 9]
 */
void print2DIntVector(const vector<vector<int>>& matrix);

/**
 * Print a vector of strings.
 *
 * Example: ["flower", "flow", "fly", "flight"]
 */
void printStringVector(const vector<string>& v);

#endif
