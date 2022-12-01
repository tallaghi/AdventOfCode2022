#include "Util.h"

void readFile(std::string fileName, std::list<std::string>& lines)
{
    lines.clear();
    std::ifstream file(fileName);
    std::string s;
    while (std::getline(file, s))
        lines.push_back(s);
}