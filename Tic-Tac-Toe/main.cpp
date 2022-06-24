#include "Board.hpp"

int main()
{
    Board b;
    bool playWithPC;
    std::cout << "Do you want to play with the pc? (0 - no / 1 - yes): ";
    std::cin >> playWithPC;
    if(playWithPC)
    {

    }
    else
    {
        bool userCurrentlyPlaying = 1;
        int rounds = 0;
        b.printMap();
        do{
            b.readUserInput(userCurrentlyPlaying);
            userCurrentlyPlaying = !userCurrentlyPlaying;
            rounds++;
        }while(!b.someoneWon() && rounds != 9);
    }
    return 0;
}