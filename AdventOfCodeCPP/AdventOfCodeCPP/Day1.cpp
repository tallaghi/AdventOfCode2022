#include "Day1.h"
#include "Util.h"

void RunDay() {
    std::string fileName = "Day1.txt";
    std::list<std::string> lines;
    readFile(fileName, lines);

    std::list<int> listOfLists;
    std::list<int> currentList;
    std::list<std::string>::const_iterator i;

    for (i = lines.begin(); i != lines.end(); i++) {
        std::string line = i->c_str();
        if (line != "") {
            int lineNum = stoi(line);
            currentList.push_back(lineNum);
        }
        else {
            listOfLists.push_back(std::accumulate(begin(currentList), end(currentList), 0));
            currentList.clear();
        }
    }

    listOfLists.sort(std::greater<int>());
    auto lol_front = listOfLists.begin();

    std::cout << "Part 1: " << *lol_front << '\n';

    int sumOfAll = 0;
    sumOfAll += *lol_front;
    advance(lol_front, 1);
    sumOfAll += *lol_front;
    advance(lol_front, 1);
    sumOfAll += *lol_front;

    std::cout << "Part 2: " << sumOfAll << '\n';
}