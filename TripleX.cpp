#include <iostream>
#include <ctime>

void PlayIntro(int Difficulty)
{
    // Prints the intro message
    std::cout << "\nYou are trapped inside a level " << Difficulty << " escape room!\n";
    std::cout << "You will need to enter the codes to escape from this escape room..\n";
}

bool PlayGame(int Difficulty)
{
    PlayIntro(Difficulty);

    // initialises three variables
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;    
    
    std::cout << "\nThere are three numbers in the code";
    std::cout << "\nThe codes add up to:" << CodeSum;
    std::cout << "\nThe codes multiply to:" << CodeProduct << std::endl;

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // check if the guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nYou're a genius! You have escaped level " << Difficulty << " room!\n";
        return true;
    }
    else 
    {
        std::cout << "\nYou're a loser! You're still stuck in level " << Difficulty << " room! Please try again :(\n";
        return false;
    }
}

int main()
{
    srand(time(NULL));
    
    int LevelDifficulty = 1;
    const int MaxLevel = 5;

    while (LevelDifficulty <= MaxLevel) // loop the game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }

    std::cout << "\nCongratulations! You have managed to escape all the rooms! Well done!";

    return 0;
}