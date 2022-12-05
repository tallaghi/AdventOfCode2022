#include "AllDays.h"
#include "Util.h"

void RunDay5() {
    std::string fileName = "Day5.txt";
    std::vector<std::string> lines;
    readFile(fileName, lines);
    
    auto pos = std::distance(lines.begin(),std::find(lines.begin(), lines.end(), ""));
    std::vector<std::stack<std::string>> stackVec;
    for (int i = 0; i < 9; i++) {
        std::stack<std::string> stack;
        stackVec.push_back(stack);
    }

    for (int i = (pos - 2); i >= 0; i--)
    {
        for (int j = 0; j <= lines[i].size(); j += 4) 
        {
            if (lines[i].substr(j, 3).find_first_not_of(' ') != std::string::npos)
            {
                int stackLoc = 0;
                if (j != 0) {
                    stackLoc = j / 4;
                }
                stackVec[stackLoc].push(lines[i].substr(j, 3));
            }
        }
    }

    std::vector<std::stack<std::string>> stackVecPart2 = stackVec;

    
    for (int i = pos + 1; i < lines.size(); i++) 
    {
        std::vector<std::string> directions = splitString(lines[i]," ");
        int moveNum = stoi(directions[1]);
        int moveStart = stoi(directions[3])-1;
        int moveEnd = stoi(directions[5])-1;

        std::vector<std::string> cratesToMove;

        //PART 1
        for (int j = 0; j < moveNum; j++) 
        {
            stackVec[moveEnd].push(stackVec[moveStart].top());
            stackVec[moveStart].pop();
        }

        // PART 2
        for (int j = 0; j < moveNum; j++)
        {
            cratesToMove.push_back(stackVecPart2[moveStart].top());
            stackVecPart2[moveStart].pop();
        }

        for (int j = moveNum - 1; j >= 0; j--)
        {
            stackVecPart2[moveEnd].push(cratesToMove[j]);
        }

    }

    std::cout << "Part 1: ";
    for (std::stack<std::string> stack : stackVec) 
    {
        std::cout << stack.top();
    }

    std::cout << "Part 2: ";
    for (std::stack<std::string> stack : stackVecPart2)
    {
        std::cout << stack.top();
    }


    //std::cout << "Part 2: " << part2Total << '\n';
}