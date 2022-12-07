#include "AllDays.h"
#include "Util.h"

void RunDay7() {
    std::string fileName = "Day7.txt";
    std::vector<std::string> lines;
    readFile(fileName, lines);

    int totalSpace = 70000000;
    std::map<std::string, int> dirs;
    std::string currentDirectory;
    for (std::string line : lines) {
        if (line.rfind("$ cd ", 0) == 0) { 
            std::string moveTo = line.substr(5, line.length());
            if (moveTo == "..") {
                currentDirectory = currentDirectory.substr(0, currentDirectory.substr(0,currentDirectory.length()-2).find_last_of('/')+1);
            }
            else {
                if(moveTo.find('/') != std::string::npos){
                    currentDirectory += moveTo;
                }
                else {
                    currentDirectory += (moveTo + "/");
                }
            }
        }
        else if (isdigit(line[0])) {
            std::string numm = line.substr(0, line.find_first_of(' '));
            int size = stoi(numm);
            std::map<std::string, int>::iterator itr;
            std::string tDirectory = currentDirectory;

            itr = dirs.find(currentDirectory);

            if (itr != dirs.end())
                itr->second += size;
            else
                dirs.insert(std::pair<std::string, int>(currentDirectory, size));

            //CD ..
            tDirectory = tDirectory.substr(0, tDirectory.substr(0, tDirectory.length() - 2).find_last_of('/') + 1);
            while (tDirectory != "/") {
                itr = dirs.find(tDirectory);

                if (itr != dirs.end())
                    itr->second += size;
                else
                    dirs.insert(std::pair<std::string, int>(tDirectory, size));


                tDirectory = tDirectory.substr(0, tDirectory.substr(0, tDirectory.length() - 2).find_last_of('/') + 1);
            }
            if (tDirectory == "/" && currentDirectory != "/") {
                itr = dirs.find(tDirectory);

                if (itr != dirs.end())
                    itr->second += size;
                else
                    dirs.insert(std::pair<std::string, int>(tDirectory, size));


                tDirectory = tDirectory.substr(0, tDirectory.substr(0, tDirectory.length() - 2).find_last_of('/') + 1);
            }
        }
    }

    //Part 1
    int total = 0;
    for (const auto& kv : dirs) {
        std::cout << kv.first << " has value " << kv.second << std::endl;

        if (kv.second <= 100000) {
            total += kv.second;
        }

    }


    std::cout << "Part 1:" << total << std::endl;

    //Part 2
    std::map<std::string, int>::iterator itr;
    int remainingSpace;
    itr = dirs.find("/");

    if (itr != dirs.end())
        remainingSpace = (totalSpace - itr->second);

    int needToDelete = 30000000 - remainingSpace;
    std::string dirToDelete;
    int currentDeleteSize = totalSpace;
    for (const auto& kv : dirs) {
        if (kv.second >= needToDelete && kv.second < currentDeleteSize) {
            dirToDelete = kv.first;            
            currentDeleteSize = kv.second;
        }
    }

    std::cout << "Part 2:" << currentDeleteSize << std::endl;
}