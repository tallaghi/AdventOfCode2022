#ifndef UTIL_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define UTIL_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void readFile(std::string fileName, std::vector<std::string>& lines);
int getIndexInt(std::vector<int> v, int K);
int getIndexChar(std::vector<char> v, char K);
int getIndexString(std::vector<std::string> v, std::string K);
std::vector<std::string> splitString(std::string str, std::string delimiter);

#endif
