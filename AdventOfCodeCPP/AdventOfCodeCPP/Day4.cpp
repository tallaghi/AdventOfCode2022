#include "Day4.h"
#include "Util.h"

void RunDay4() {
    std::string fileName = "Day4.txt";
    std::vector<std::string> lines;    
    readFile(fileName, lines);
    int part1Total = 0;
    int part2Total = 0;
    for (std::string line : lines) {

        std::string firstRange = line.substr(0, line.find(','));
        std::string secondRange = line.substr(line.find(',')+1);

        int firstFirst = stoi(firstRange.substr(0, firstRange.find('-')));
        int firstSecond = stoi(firstRange.substr(firstRange.find('-') + 1));

        int secondFirst = stoi(secondRange.substr(0, secondRange.find('-')));
        int secondSecond = stoi(secondRange.substr(secondRange.find('-') + 1));
        if (
            (firstFirst >= secondFirst && firstSecond <= secondSecond) ||
            (secondFirst >= firstFirst && secondSecond <= firstSecond)
            ) 
        {
            part1Total++;
        }

        if (
            (firstFirst>=secondFirst && firstFirst<=secondSecond) || 
            (firstSecond >= secondFirst && firstSecond <= secondSecond) ||
            (secondFirst >= firstFirst && secondFirst <= firstSecond) ||
            (secondSecond >= firstFirst && secondSecond <= firstSecond)
            )
        {
            part2Total++;
        }

    }

    std::cout << "Part 1: " << part1Total << '\n';
    
    std::cout << "Part 2: " << part2Total << '\n';
}