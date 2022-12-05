#include "Util.h"

void readFile(std::string fileName, std::vector<std::string>& lines)
{
    lines.clear();
    std::ifstream file(fileName);
    std::string s;
    while (std::getline(file, s))
        lines.push_back(s);
}

int getIndexInt(std::vector<int> v, int K) 
{
    auto it = find(v.begin(), v.end(), K);

    // If element was found
    if (it != v.end())
    {

        // calculating the index
        // of K
        int index = it - v.begin();
        return index;
    }
    else {
        // If the element is not
        // present in the vector
        return -1;
    }
}

int getIndexChar(std::vector<char> v, char K) 
{
    auto it = find(v.begin(), v.end(), K);

    // If element was found
    if (it != v.end())
    {

        // calculating the index
        // of K
        int index = it - v.begin();
        return index;
    }
    else {
        // If the element is not
        // present in the vector
        return -1;
    }
}

int getIndexString(std::vector<std::string> v, std::string K)
{
    auto it = find(v.begin(), v.end(), K);

    // If element was found
    if (it != v.end())
    {

        // calculating the index
        // of K
        int index = it - v.begin();
        return index;
    }
    else {
        // If the element is not
        // present in the vector
        return -1;
    }
}

std::vector<std::string> splitString(std::string str, std::string delimiter = " ")
{
    int start = 0;
    int end = str.find(delimiter);
    std::vector<std::string> vec;
    while (end != -1) {
        vec.push_back(str.substr(start, end - start));
        start = end + delimiter.size();
        end = str.find(delimiter, start);
    }
    vec.push_back(str.substr(start, end - start));
    return vec;
}