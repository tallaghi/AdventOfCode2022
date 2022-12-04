#include "Day3.h"
#include "Util.h"

void RunDay3() {
    std::string fileName = "Day3.txt";
    std::vector<std::string> lines;
    std::vector<int> priorities;
    readFile(fileName, lines);
    int score = 0;
    for (std::string line : lines) {
        std::string compartment1 = line.substr(0, line.length() / 2);
        std::string compartment2 = line.substr(line.length() / 2);

        for (int i = 0; i < compartment1.length(); i++) {
            if (compartment2.find(compartment1[i]) != std::string::npos) {
                score += (compartment1[i] < 'a') ? (compartment1[i] - 'A' + 27) : (compartment1[i] - '`');
                break;
            }
        }
    }

    std::cout << "Part 1: " << score << '\n';
    score = 0;

    for (int i = 0; i < lines.size(); i += 3) {
        std::string str1 = lines[i];
        std::string str2 = lines[i+1];
        std::string str3 = lines[i+2];

        for (int i = 0; i < str1.length(); i++) {
            if (str2.find(str1[i]) != std::string::npos && str3.find(str1[i]) != std::string::npos) {
                score += (str1[i] < 'a') ? (str1[i] - 'A' + 27) : (str1[i] - '`');
                break;
            }
        }
    }

    std::cout << "Part 2: " << score << '\n';
}