#include "AllDays.h"
#include "Util.h"

void UniquePosition(std::string onlyLine, int uniqueCharCount) {
    std::string uniqueCharString;
    bool uniqueFourChar = false;
    int finalPos;
    for (int i = 0; i < onlyLine.length(); i++) {
        if (!uniqueFourChar) {
            if (uniqueCharString.length() == uniqueCharCount) {
                uniqueCharString.erase(0, 1);
            }

            uniqueCharString += onlyLine[i];

            if (uniqueCharString.length() == uniqueCharCount) {
                std::string tempString = uniqueCharString;
                std::sort(tempString.begin(), tempString.end());
                int counter = 0;
                for (int j = 0; j < tempString.length(); j++) {
                    if (tempString[j] == tempString[j + 1] && counter < 1) {
                        counter++;
                    }
                }

                if (counter == 0) {
                    uniqueFourChar = true;
                    finalPos = i + 1;
                }
            }
        }
    }

    std::cout << uniqueCharCount << " character unique string position: " << finalPos << '\n';
}

void RunDay6() {
    std::string fileName = "Day6.txt";
    std::vector<std::string> lines;
    readFile(fileName, lines);

    std::string onlyLine = lines[0];
    
    //PART 1
    UniquePosition(onlyLine, 4);
    //PART 2
    UniquePosition(onlyLine, 14);
}