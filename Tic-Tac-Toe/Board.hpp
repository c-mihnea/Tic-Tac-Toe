#include <iostream>
#include <string>

#define MAX_NUMBER_OF_ROWS 3
#define MIN_NUMBER_OF_ROWS 0
#define MAX_NUMBER_OF_COLUMNS 3
#define MIN_NUMBER_OF_COLUMNS 0
#define LAST_ELEMENT_OF_ROWS_AND_COLUMNS 2

class Board
{
public:
    void printMap();
    void readUserInput(bool user);
    bool someoneWon();
private:
    void updateMap(int positionToBeUpdated, bool user);
    bool verifyColumns();
    bool verifyRows();
    bool verifyDiagonally();
    std::string matrix[3][3] = {"1", "2", "3",
                                "4", "5", "6",
                                "7", "8", "9"};
};