#include "Day1.h"
#include "Util.h"

void RunDay2() {
    std::string fileName = "Day2.txt";
    std::vector<std::string> lines;
    readFile(fileName, lines);

    std::vector<int> score;

    //Rock: A|X|1 ; Paper: B|Y|2 ; Scissor: C|Z|3
    std::vector<char> oppVect{ 'A','B','C' };
    std::vector<char> meVect{ 'X','Y','Z' };
    for (std::string line : lines) {
        
        char opp = line[0];
        char me = line[2];

        int winlosedraw = 0;

        int oppIndex = getIndexChar(oppVect, opp);
        int meIndex = getIndexChar(meVect, me);

        int shape = meIndex+1;

        if (oppIndex==meIndex) {
            winlosedraw = 3;
        }
        int winnerIndex = oppIndex + 1;
        if (winnerIndex == 3) { winnerIndex = 0; }
        if (winnerIndex == meIndex) {winlosedraw = 6;}


        score.push_back(winlosedraw + shape);
    }


    std::cout << "Part 1: " << std::accumulate(score.begin(), score.end(), 0) << '\n';
    score.clear();

    for (std::string line : lines) {

        char opp = line[0];
        char me = line[2];

        int oppIndex = getIndexChar(oppVect, opp);
        int meIndex = getIndexChar(meVect, me);

        int winnerIndex = oppIndex + 1;
        if (winnerIndex == 3) { winnerIndex = 0; }
        int loserIndex = oppIndex - 1;
        if (loserIndex == -1) { loserIndex = 2; }
        int shape = oppIndex + 1;
        //have to lose
        if (meIndex == 0) {
            shape = loserIndex + 1;
        }
        //have to win
        else if (meIndex == 2) {
            shape = winnerIndex + 1;
        }
        

        int winlosedraw = meIndex*3;

        score.push_back(winlosedraw + shape);
    }

    std::cout << "Part 2: " << std::accumulate(score.begin(), score.end(), 0) << '\n';
}