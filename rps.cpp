/**
 * rps.cpp
 * Project UID 24b93ce4a6274610f4c3f3e31fe17277c
 *
 * <#Name#>
 * Daniel Bao
 * <#Uniqname#>
 * danbao
 *
 * EECS 183: Project 2
 * Winter 2025
 *
 * <#description#>
 * List of functions used in start.cpp and test.cpp for doing
 * rock paper scissors game.
 */

#include <iostream>
#include <string>

const int MAX_ROUNDS = 3;

using namespace std;

//************************************************************************
// The following four functions have already been implemented for you.
// You should use them when writing the other functions, but do not edit
// their implementations.
//************************************************************************

/**
 * Requires: nothing
 * Modifies: cout
 * Effects:  Prints a pretty header to introduce the user to the game.
 */
void printInitialHeader();

/**
 * Requires: nothing
 * Modifies: cout
 * Effects:  Prints the menu.
 * Prompts:  "1) Play rock, paper, scissors"
 *           "2) Play rock, paper, scissors, lizard, spock"
 *           "3) Quit"
 *           "Choice --> "
 */
void printMenu();

/**
 * Requires: errorNumber be either 1 or 2
 * Modifies: cout
 * Effects:  If errorNumber is 1, prints an error message indicating
 *           an illegal name was entered.
 *           If errorNumber is 2, prints an error message indicating
 *           an illegal move was entered.
 */
void printErrorMessage(int errorNumber);

/**
 * Requires: nothing
 * Modifies: cout
 * Effects:  Prints out the final greeting for the program.
 */
void printCloser();

//************************************************************************
// You must implement all of the following functions. Add your 
// implementations below rps() as indicated.
//************************************************************************

/**
 * Requires: nothing
 * Modifies: nothing
 * Effects:  Utilizes the other functions in this file to play 
 *           the game Rock Paper Scissors.
 *
 *           Starter algorithm pseudocode: 
 *           1. Print the header
 *           2. Get player 1 name
 *           3. Get player 2 name
 *           4. Repeat the following until the user quits the program:
 *              * Get the menu choice
 *              * Play the game and announce the winner, 
 *                or quit the program (according to user's menu choice)
 *           5. Print the closing message 
 */
void rps();

/**
 * Requires: playerNumber is either 1 or 2
 * Modifies: cout, cin
 * Effects:  Prompts the user to enter their name. Names entered may
 *           have spaces within them.
 *               Example: "Kermit the frog"
 *
 *           If an empty name is given, this is invalid input, so print
 *           error message 1, and return a default name.
 *           For player 1, the default name is: Rocky
 *           For player 2, the default name is: Creed
 *           Otherwise, return name entered by user.
 *              
 * Prompt:   Player [playerNumber], enter your name:
 */
string getName(int playerNumber);


/**
 * Requires: nothing
 * Modifies: cout, cin
 * Effects:  Prints the menu, and reads the input from the user.
 *           Checks to make sure the input is within range for the menu.
 *           If it is not, prints "Invalid menu choice". Continues to print 
 *           the menu and read in input until a valid choice is entered,
 *           then returns the user's choice of menu options. You can assume
 *           a user will enter an integer, and nothing else, as their choice.
 *
 * Prompt:   Invalid menu choice
 */
int getMenuChoice();


/**
 * Requires: nothing
 * Modifies: nothing
 * Effects:  Returns true if and only if move represents a valid move character
 *           one of 'R', 'r', 'P', 'p', 'S', 's'. Returns false otherwise.
 */
bool isMoveGood(char move);


/**
 * Requires: playerName is the name of the player being prompted for their
 *           move.
 * Modifies: cout, cin
 * Effects:  Prompts the player for their move and returns it.
 *           This function should accept the first non-whitespace character as
 *           the move. If an illegal character is entered for their move, print
 *           error message 2 and return rock as a default. 
 *           You can assume a user will enter a single character, 
 *           and nothing else, as their move.
 *
 * Prompt:   [playerName], enter your move:
 */
char getMove(string playerName);


/**
 * Requires: move is the move of the player being checked for a win.
 *           opponentMove is the move of the opponent.
 *           both move and opponentMove are valid moves.
 * Modifies: nothing
 * Effects:  Returns true if and only if the player who made move won
 *           according to the rules to rock-paper-scissors. Returns false
 *           otherwise.
 */
bool isRoundWinner(char move, char opponentMove);


/**
 * Requires: winnerName is the name of the player who won the round.
 * Modifies: cout
 * Effects:  If winnerName is the empty string, i.e., "",
 *           prints a message indicating the round is a draw. 
 *           Otherwise, prints a congratulatory message to the winner.
 * Prompt:   This round is a draw!
 *           ------------- OR -------------
 *           [winner_name] wins the round!
 */
void announceRoundWinner(string winnerName);


/**
 * Requires: p1Name and p2Name are the names of the respective players
 * Modifies: nothing
 * Effects:  Simulates a complete round of rock-paper-scissors, which
 *           consists of three steps:
 *             1. Get player1 move
 *             2. Get player2 move
 *             3. Return 0 if the round was a draw; 1 if player 1 won;
 *                2 if player 2 won.
 */
int doRound(string p1Name, string p2Name);


/**
 * Requires: winnerName is the name of the player who won the game.
 * Modifies: cout
 * Effects:  If winnerName is the empty string, i.e., "", 
 *           prints that the game was a draw.
 *           Otherwise, prints a congratulatory message to the winner.
 * Prompt:   No winner!
 *           ------------- OR -------------
 *           Congratulations [winnerName]!
 *           You won EECS 183 Rock-Paper-Scissors!
 */
void announceWinner(string winnerName);


/**
 * Requires: p1Name and p2Name are the names of the respective players,
 *           gameType can be 1 for regular rock-paper-scissors
 *           or 2 for rock-paper-scissors-lizard-spock
 * Modifies: cout
 *
 * Base Project:
 * Effects:  If gameType is 2, prints "Under Construction" to indicate that the
 *           s'more has not been implemented. Returns empty string.
 *           Otherwise, plays exactly three rounds of rock-paper-scissors while
 *           keeping track of the number of round wins for each player.
 *           When a round results in a draw, neither player is the winner,
 *           so neither player is awarded a point.
 *           After each round is played, the round winner (or draw) is
 *           announced. 
 *           Returns the name of the game winner, or "" in event of a draw.
 * Prompt:   Under Construction
 *
 * S'more Version:
 * Effects:  Has same functionality as base project, but also handles a
 *           gameType of 2. When game_type is 2, plays exactly three rounds of
 *           rock-paper-scissors-lizard-spock. Keeps track of round wins for
 *           each player and announces round winners in the same fashion as 
 *           described above.
 */
string doGame(string p1Name, string p2Name, int gameType);

//************************************************************************
// Implement the functions below this line.
//************************************************************************

void rps() {
    printInitialHeader();
    
    string player1Name = getName(1);
    string player2Name = getName(2);

    int menuChoice = getMenuChoice();

    //Checks if user chose a gamemode or quit
    while (menuChoice != 3){
        if (menuChoice == 1){
            announceWinner(doGame(player1Name, player2Name, 1));
        } 

        else if (menuChoice == 2){
            cout << "Under Construction\n";
            announceWinner("");
        }

        menuChoice = getMenuChoice();
    }

    printCloser();
}

string getName(int playerNumber) {
    string name;
    cout << "Player " << playerNumber << " , enter your name: ";
    getline(cin, name);        
    cout << "\n";

    //Default names if empty name is input
    if (playerNumber == 1 && name == ""){
        name = "Rocky";
        printErrorMessage(1);
    }
    else if (playerNumber == 2 && name == ""){
        name = "Creed";
        printErrorMessage(1);
    }

    return name;
}


int getMenuChoice() {
    printMenu();

    int choice;
    cin >> choice;

    //Checks if choice is 1, 2, or 3
    while (choice > 3 || choice < 1){
        cout << "\nInvalid menu choice\n";
        printMenu();
        cin >> choice;
        cout << endl;
    }
    return choice;
}


bool isMoveGood(char move) {
    //checking if its one of 6 valid char inputs (rock, paper, scissors)
    //including uppercase and lowercase letters
    if (move == 'r' || move == 'R' || move == 'p' || move == 'P' || 
        move == 's' || move == 'S'){
        return true;
    }

    else{
        return false;
    }
}

char getMove(string playerName) {
    cout << endl <<playerName << ", enter your move: ";

    char move;
    cin >> move;

    if (isMoveGood(move)){
        return move;
    }

    //If move isn't good, return a default move of rock
    else{
        printErrorMessage(2);
        return 'r';
    }
}

bool isRoundWinner(char move, char opponentMove) {
    //turning all moves lowercase
    if (move >= 'A' && move <= 'Z'){
        move += 32;
    }

    if (opponentMove >= 'A' && opponentMove<= 'Z'){
        opponentMove += 32;
    }

    //comparing moves to see winner
    if ((move == 'r' && opponentMove == 's') || 
        (move == 's' && opponentMove == 'p' ) ||
        (move == 'p' && opponentMove == 'r')){
        return true;
    }

    else{
        return false;
    }
}


void announceRoundWinner(string winnerName) {
    if (winnerName == ""){
        cout << "\nThis round is a draw!\n";
    }

    else{
        cout << winnerName << " wins the round!\n";
    }
}


int doRound(string p1Name, string p2Name) {
    char p1Move = getMove(p1Name);
    char p2Move = getMove(p2Name);

    cout << endl;

    if (isMoveGood(p1Move) && isMoveGood(p2Move)){
        //If two moves are the same, return tie
        if (isRoundWinner(p1Move, p2Move) == isRoundWinner(p2Move, p1Move)){
            return 0;
        }

        //Returns 1 if player 1 wins
        else if (isRoundWinner(p1Move,p2Move)){
            return 1;
        }

        //Returns 2 if player 2 wins
        else{
            return 2;
        }
        
    }
}


void announceWinner(string winnerName) {
    if (winnerName != ""){
        cout << "\nCongratulations " << winnerName << "!\n";
        cout << "\nYou won EECS 183 Rock-Paper-Scissors!\n";
    }

    else {
        cout << "No winner!\n";
    }
}


string doGame(string p1Name, string p2Name, int gameType) {

    int p1Wins = 0;
    int p2Wins = 0;

    //Does three rounds of game
    for (int i = 0; i < MAX_ROUNDS; i++){

        int winValue = doRound(p1Name, p2Name);

        //Taking game result from announceRoundWinner() function
        if (winValue == 0){
            announceRoundWinner("");
        }

        else if (winValue == 1){
            announceRoundWinner(p1Name);
            p1Wins++;
        }

        else if (winValue == 2){
            announceRoundWinner(p2Name);
            p2Wins++;
        }
    }

    //Checks who won more rounds, or if tied
    if (p1Wins < p2Wins){
        return p2Name;
    }

    else if (p2Wins < p1Wins){
        return p1Name;
    }

    else{
        return ("");
    }
}




//***********************************************************************
// DO NOT modify the four functions below.
//***********************************************************************
void printInitialHeader() {
    cout << "----------------------------------------" << endl;
    cout << "               EECS 183                 " << endl;
    cout << "          Rock-Paper-Scissors           " << endl;
    cout << "----------------------------------------" << endl << endl;
    
    return;
}

void printMenu() {
    cout << endl << endl;
    cout << "Menu Options" << endl
        << "------------" << endl;
    cout << "1) Play rock, paper, scissors" << endl;
    cout << "2) Play rock, paper, scissors, lizard, spock" << endl;
    cout << "3) Quit" << endl << endl;
    
    cout << "Choice -->";
    
    return;
}

void printErrorMessage(int errorNumber) {
    if (errorNumber == 1) {
        cout << endl << "ERROR: Illegal name given, using default" 
            << endl << endl;
    } else if (errorNumber == 2) {
        cout << endl << "ERROR: Illegal move given, using default" << endl;
    } else {
        cout << "This should never print!";
    }
    
    return;
}

void printCloser() {
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "           Thanks for playing           " << endl;
    cout << "          Rock-Paper-Scissors!          " << endl;
    cout << "----------------------------------------" << endl << endl;
    
    return;
}
