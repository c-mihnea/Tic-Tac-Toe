#include "Board.hpp"

void Board::printMap()
{
    system("clear");
    for(int row = MIN_NUMBER_OF_ROWS; row < MAX_NUMBER_OF_ROWS; row ++)
    {
        for(int column = MIN_NUMBER_OF_COLUMNS; column < MAX_NUMBER_OF_COLUMNS; column ++)
        {
            if(column != LAST_ELEMENT_OF_ROWS_AND_COLUMNS)
            {
                std::cout << matrix[row][column] << "|" ;
            }
            else
            {
                std::cout << matrix[row][column];
            }
        }

        if(row != LAST_ELEMENT_OF_ROWS_AND_COLUMNS)
        {
            std::cout << std::endl;
            std::cout << "======";
            std::cout << std::endl;
        }
        else
        {
            std::cout << std::endl;
        }
    }
}

void Board::updateMap(int positionToBeUpdated, bool user)
{
    for(int row = MIN_NUMBER_OF_ROWS; row < MAX_NUMBER_OF_ROWS; row ++)
    {
        for(int column = MIN_NUMBER_OF_COLUMNS; column < MAX_NUMBER_OF_COLUMNS; column ++)
        {
            if(matrix[row][column] == std::to_string(positionToBeUpdated))
            {
                if(user)
                {
                    matrix[row][column] = "X";
                }
                else
                {
                    matrix[row][column] = "O";
                }
            }
        }
    }
}

void Board::readUserInput(bool user)
{
    int position;
    std::cout << "Enter your position: ";
    std::cin >> position;

    updateMap(position, user);
    printMap();
}

bool Board::verifyColumns()
{
    for(int column = MIN_NUMBER_OF_COLUMNS; column < MAX_NUMBER_OF_COLUMNS; column ++)
    {
        if(matrix[0][column] == matrix[1][column] && matrix[1][column] == matrix[2][column])
        {
            return true;
        }
    }
    return false;
}

bool Board::verifyRows()
{
    for(int row = MIN_NUMBER_OF_ROWS; row < MAX_NUMBER_OF_ROWS; row ++)
    {
        if(matrix[row][0] == matrix[row][1] && matrix[row][1] == matrix[row][2])
        {
            return true;
        }
    }
    return false;
}

bool Board::verifyDiagonally()
{
    if(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
    {
        return true;
    }
    if(matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
    {
        return true;
    }
    return false;
}

bool Board::someoneWon()
{
    if(verifyColumns() || verifyRows() || verifyDiagonally())
    {
        std::cout << "someone won";
        return true;
    }
    return false;
}