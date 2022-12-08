#include "AllDays.h"
#include "Util.h"

void RunDay8() {
    std::string fileName = "Day8.txt";
    std::vector<std::string> lines;
    readFile(fileName, lines);
    const int ySize = lines.size();
    const int xSize = lines[0].length();

    int visibleTrees = (((ySize - 2) * 2) + (xSize * 2));
    int maxScore = 0;

    //allocate the array
    int** matrix = new int* [ySize];
    for (int i = 0; i < ySize; i++)
        matrix[i] = new int[xSize];

    for (int i = 0; i < ySize; i++) {
        for (int j = 0; j < xSize; j++) {
            matrix[i][j] = static_cast<int>(lines[i][j]) - '0';
        }
    }
    
    for (int i = 1; i < (ySize - 1); i++) {
        for (int j = 1; j < (xSize-1); j++) {
            int treeInQuestion = matrix[i][j];
            bool visibleFromNorth = true;
            bool visibleFromSouth = true;
            bool visibleFromWest = true;
            bool visibleFromEast = true;
            int distanceFromNorth = i;
            int distanceFromSouth = ySize - i;
            int distanceFromWest = j;
            int distanceFromEast = xSize - j;

            int northScore = 1;
            int southScore = 1;
            int westScore = 1;
            int eastScore = 1;

            //NORTH
            for (int iter = (i - 1); iter >= 0; iter--) {
                if (matrix[iter][j] >= treeInQuestion){
                    visibleFromNorth = false;
                    northScore += ((i - 1) - iter);
                    break;
                }
            }

            if (visibleFromNorth) {
                northScore += (i - 1);
            }

            //SOUTH
            for (int iter = (i + 1); iter < ySize; iter++) {
                if (matrix[iter][j] >= treeInQuestion){
                    visibleFromSouth = false;
                    southScore += (iter - (i + 1));
                    break;
                }
            }

            if (visibleFromSouth) {
                southScore += ySize - 1 - (i + 1);
            }

            //WEST
            for (int iter = (j - 1); iter >= 0; iter--) {
                if (matrix[i][iter] >= treeInQuestion){
                    visibleFromWest = false;
                    westScore += ((j - 1) - iter);
                    break;
                }
            }

            if (visibleFromWest) {
                westScore += (j - 1);
            }

            //EAST
            for (int iter = (j + 1); iter < xSize; iter++) {
                if (matrix[i][iter] >= treeInQuestion){
                    visibleFromEast = false;
                    eastScore += (iter - (j + 1));
                    break;
                }
            }

            if (visibleFromEast) {
                eastScore += xSize - 1 - (j + 1);
            }

            //PART 1
            if (visibleFromNorth || visibleFromSouth || visibleFromEast || visibleFromWest)
                visibleTrees++;

            //PART 2
            if ((northScore * southScore * eastScore * westScore) > maxScore) {
                maxScore = (northScore * southScore * eastScore * westScore);
                std::cout << "Max Score is now " << maxScore << " tree is " << treeInQuestion << " i is " << i << " j is " << j << std::endl;
                std::cout << "NorthScore " << northScore << " SouthScore " << southScore << " WestScore " << westScore << " EastScore " << eastScore << std::endl;
            }
        }
    }

    std::cout << "Part 1:" << visibleTrees << std::endl;
    std::cout << "Part 2:" << maxScore << std::endl;

    //deallocate the array
    for (int i = 0; i < ySize; i++)
        delete[] matrix[i];
    delete[] matrix;
}