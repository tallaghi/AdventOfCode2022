#include "Day1.h"
#include "Util.h"

void RunDay1() {
    std::string fileName = "Day1.txt";
    std::vector<std::string> lines;
    readFile(fileName, lines);

    std::vector<int> listOfLists;
    std::vector<int> currentList;

    for (std::string i : lines) {
        std::string line = i;
        if (line != "") {
            int lineNum = stoi(line);
            currentList.push_back(lineNum);
        }
        else {
            listOfLists.push_back(std::accumulate(begin(currentList), end(currentList), 0));
            currentList.clear();
        }
    }

    std::sort(listOfLists.begin(), listOfLists.end(), std::greater<int>());
    auto lol_front = listOfLists.begin();

    std::cout << "Part 1: " << listOfLists[0] << '\n';

    int sumOfAll = 0;
    sumOfAll += listOfLists[0];
    sumOfAll += listOfLists[1];
    sumOfAll += listOfLists[2];

    std::cout << "Part 2: " << sumOfAll << '\n';
}