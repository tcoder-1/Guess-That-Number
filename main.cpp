#include <iostream> // for cout & cin
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include <iomanip> // for output

using namespace std; // to do cout & cin w/o std

//constant variables that won't change throughout the program
const int MIN = 1;
const int MAX = 2;
const int MAX_ATTEMPTS = 8;

/*
generateRandNum function generates a random number bw MAX & MIN. 
rand() generates the random number
% (max - min + 1) makes sure that the number is in the given range
+ min makes the range start an min 
*/
int generateRandNum(int min, int max) {
    return rand() % (max - min + 1) + min;
}

/*
getUserGuess function gets the user's guess and stores it in the variable guess
*/

int getUserGuess() {
    int guess;
    cout << "\nEnter your guess: ";
    cin >> guess;
    return guess;
}

/* 
checkGuess function checks the user's guess 
it compares guess with the target number 
after comparing it tells the user whether their input is high/low/correct
*/
bool checkGuess(int guess, int target) {
    if (guess > target) {
        cout << "   That guess is too HIGH!\n   Try Again.\n";
        return false;
    } 
    else if (guess < target) {
        cout << "   That guess is too LOW!\n   Try Again.\n";
        return false;
    } 
    else {
        cout << "\nGood Job! You correctly guessed the number!\n";
        return true;
    }
}

/*
playGame is the main function for the game
it generates targetNum
attempts tracks how many guesses/input the user makes
isCorrect checks wheather the user guesed correctly
it continues until the user reaches that max attempts allowed
it gets the input using getUserGuess function
it adds 1 to attempts each time 
and checks using checkGuess
if the user runs out of attemps before guessing targetNum it tells the user the correct number
*/
void playGame() {
    // Generate a random number
    int targetNum = generateRandNum(MIN, MAX);
    int attempts = 0;
    bool isCorrect = false;

    cout << "\nWe have selected a number between " << MIN << " and " << MAX << ".\n";
    cout << "You have " << MAX_ATTEMPTS << " attempts to GUESS THAT NUMBER!\n";

    while (attempts < MAX_ATTEMPTS && !isCorrect) {
        int userGuess = getUserGuess();
        attempts++;
        isCorrect = checkGuess(userGuess, targetNum);

        if (!isCorrect && attempts == MAX_ATTEMPTS) {
            cout << "\n               You have used all your attempts.\n";
            cout << "               The correct number was " << targetNum << "!\n";
            cout << "               Better Luck Next Time.\n\n";
        }
    }
}

/*
srand function allows different random numbers to be generated each time
do-while loop makes sure the game runs at least once and until the user says they don't want to play again

srand():- 
    Initializes the random number generator with a seed/starting value, this makes sure that the sequence of random numbers generated is different each time.
    srand:
        This function sets the seed for the rand() function. Without calling srand, rand() would generate the same sequence of numbers each time.
        static_cast<unsigned>(time(0)):
    time(0):- 
        Returns the current time in seconds This value changes each second, which provides a unique seed for the random number generator.
    static_cast<unsigned>:- 
        Converts the time_t value returned by time(0) into an unsigned type, bc srand expects an unsigned argument.
*/
int main() {
    srand(static_cast < unsigned > (time(0))); 
    //rand() % (max - min + 1) + min;

    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout << "***********************************************************************************************************************************************************************************************************************************************************************\n";
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout << setw(148) << "!!!!Welcome to GUESS THAT NUMBER!!!!\n";
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout << "***********************************************************************************************************************************************************************************************************************************************************************\n";
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

    char playAgain;
    do {
        playGame();
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "               Do you want to play GUESS THAT NUMBER again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing! Come back soon!\n";
    return 0;
}
