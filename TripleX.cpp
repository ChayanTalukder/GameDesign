#include <iostream>
#include <ctime>
using namespace std;

void PrintIntroduction(int Difficulty){
    // Printing welcome message to the terminal
    cout << endl;
    cout << "Hello there, fellow spy. Breaking and entering the level " << Difficulty << " " <<"server room? It won't be that easy!" << endl;
    cout << "One must solve and enter the correct codes to continue. This is the only was forward...or you can turn back anytime, hehehehe." << endl;
}


bool PlayGame(int Difficulty) {

     PrintIntroduction(Difficulty);
    
    // Initializing & declaring the three numbers
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA+CodeB+CodeC;
    const int CodeProduct = CodeA*CodeB*CodeC;

    // Printing the sum & product of the three numbers to the terminal
    cout << endl;
    cout << "> There are three numbers in the puzzle... " << endl;
    cout << "> The numbers add upto: " << CodeSum << endl;
    cout << "> The numbers multiply to: " << CodeProduct << endl;

    // Storing player guess
    int GuessA, GuessB, GuessC; 
    cout << "\nEnter your guess spymaster:" << endl;
    cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA+GuessB+GuessC;
    int GuessProduct = GuessA*GuessB*GuessC;
    
    // Checking if player guess correct or not 
    if (CodeSum==GuessSum && CodeProduct==GuessProduct){
        cout << "\n*** Well done spymaster! You have extracted a file! Keep going ***" << endl;
        return true;
    }
    else {
        cout << "\n*** You entered the wrong codes! Careful now.....and try again! ***" <<  endl;
        return false;
    }
}

// Our main fucntion
int main() {

    srand(time(NULL));                                      // Creates new random sequence based on time of the day

    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;
    
    while (LevelDifficulty <= MaxDifficulty){               // Loops the game until all levels are completed

        bool blevelComplete = PlayGame(LevelDifficulty);
        cin.clear();                                        // Clears errors
        cin.ignore();                                       // Discards the buffers

        if (blevelComplete){
            
            ++LevelDifficulty;                              // Increases the difficulty level
        }
    }
    
    cout << "\n*** Great work Spymaster! Finally, you extracted all the files! Now it's time to get out of here! ***" << endl;
    return 0;
}
