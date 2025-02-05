/**
 * test.cpp
 * Project UID 24b93ce4a6274610f4c3f3e31fe17277t
 *
 * <#Name#>
 * Daniel Bao
 * <#Uniqname#>
 * danbao
 *
 * EECS 183: Project 2
 * Winter 2025
 *
 * Testing functions for your rps.cpp implementation.
 * Holds the definitions of required testing functions.
 * We have stubbed all required functions for you.
 */

#include <iostream>
#include <string>

using namespace std;


//************************************************************************
// You should have implemented the following functions in rps.cpp
//************************************************************************
string getName(int playerNumber);
int getMenuChoice();
bool isMoveGood(char move);
char getMove(string playerName);
bool isRoundWinner(char move, char opponentMove);
void announceRoundWinner(string winnerName);
int doRound(string p1Name, string p2Name);
void announceWinner(string winnerName);
string doGame(string p1Name, string p2Name, int gameType);

//************************************************************************
// The following functions were already implemented for you in rps.cpp
//************************************************************************
void printInitialHeader();
void printMenu();
void printErrorMessage(int errorNumber);
void printCloser();

//************************************************************************
// Testing function declarations. Function definition is below main.
//************************************************************************
void test_isMoveGood();
void test_isRoundWinner();
void test_announceRoundWinner();
void test_announceWinner();


void startTests() {
    cout << "\nExecuting your test cases\n";

    test_isMoveGood();
    test_isRoundWinner();
    test_announceRoundWinner();
    test_announceWinner();

    return;
}

//************************************************************************
// Put all your test function implementations below here.
// We have stubbed all required functions for you
// to recieve full points when submitting test.cpp
// NOTE: We will only grade your tests for the following functions
//       * isMoveGood
//       * isRoundWinner
//       * announceRoundWinner()
//       * announceWinner()
//************************************************************************

void test_isMoveGood() {
    cout << "Now testing function isMoveGood()\n";
    cout << "'r': Expected: 1, Actual: " << isMoveGood('r') << endl;
    cout << "'q': Expected: 0, Actual: " << isMoveGood('q') << endl;
    cout << "'s': Expected: 1, Actual: " << isMoveGood('s') << endl;
    cout << "'p': Expected: 1, Actual: " << isMoveGood('p') << endl;
    cout << "'R': Expected: 1, Actual: " << isMoveGood('R') << endl;
    cout << "'p': Expected: 1, Actual: " << isMoveGood('p') << endl;

    return;
}

void test_isRoundWinner() {
    cout << "\nNow testing function isRoundWinner()\n";
    cout << "r vs p: Expected: 0, Actual: " << isRoundWinner('r', 'p') << endl;
    cout << "r vs r: Expected: 0, Actual: " << isRoundWinner('r', 'r') << endl;
    cout << "p vs s: Expected: 0, Actual: " << isRoundWinner('p', 's') << endl;
    cout << "r vs c: Expected: 0, Actual: " << isRoundWinner('r', 'c') << endl;
    cout << "c vs p: Expected: 0, Actual: " << isRoundWinner('c', 'p') << endl;
    cout << "r vs s: Expected: 1, Actual: " << isRoundWinner('r', 's') << endl;
}

void test_announceRoundWinner() {
    cout << "\nNow testing function announceRoundWinner()\n";
    cout << "Player1: Expected: Player1 wins round, Actual: ";
    announceRoundWinner("Player1");
    cout << endl;

    cout << "Player2: Expected: Player2 wins round, Actual: "; 
    announceRoundWinner("Player2");
    cout << endl;

    cout << "none: Expected: no one wins round, Actual: ";
    announceRoundWinner("");
    cout << endl;
}

void test_announceWinner() {
    cout << "\nNow testing function announceWinner()\n";
    cout << "Player1: Expected: Player1 wins, Actual: ";
    announceWinner("Player1");
    cout << endl;

    cout << "Player2: Expected: Player2 wins, Actual: "; 
    announceWinner("Player2");
    cout << endl;

    cout << "none: Expected: no one wins, Actual: ";
    announceRoundWinner("");
    cout << endl;
}
