#ifndef UTIL_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define UTIL_H

#include <iostream>
#include <fstream>
#include <string>
#include <list>

void readFile(std::string fileName, std::list<std::string>& lines);

#endif
