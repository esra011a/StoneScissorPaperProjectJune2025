// StoneScissorPaperProjectJune2025.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>
#include <ctime>  
enum enValue { Stone = 1, Paper = 2, Scissor = 3 };
enum enResult { Player = 1, Computer = 2, NoWinner = 3 };
int RandomNumber(int From, int To)//generic function Random
{
    int  randnum = rand() % (To - From + 1) + From;
    return randnum;
}
unsigned int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;

}

void  GameoverHeader()
{
    cout << "\n\n _______________________________________________________________________\n\n";
    cout << "\t\t\t+++ G a m e  O v e r +++\t\t\t";
    cout << "\n\n _______________________________________________________________________\n\n";
    cout << "\n\n _______________[ Game Results ]___________________\n\n";

}
void getRounds(int NumberOfRounds, int PlayerCounter, int ComputerCounter, int NoWinnerCounter)
{
    string FinalWinner = "aa";
    if (PlayerCounter > ComputerCounter && PlayerCounter > NoWinnerCounter)
    {
        FinalWinner = "Player";
    }
    else if (ComputerCounter > PlayerCounter && ComputerCounter > NoWinnerCounter)
    {
        FinalWinner = "Computer";
    }
    else
    {
        FinalWinner = "No Winner";
    }
    cout << "Game Rounds:        " << NumberOfRounds << endl;
    cout << "Player won times:   " << PlayerCounter << endl;
    cout << "Computer won times: " << ComputerCounter << endl;
    cout << "Draw times:         " << NoWinnerCounter << endl;
    cout << "Final Winner:       " << FinalWinner << endl;
    cout << "\n\n _________________________________________________\n\n";
}
enResult  GetRound(int i, int UserChoiceNumber, int NumberOfRounds)
{
    enResult Winner;

    string StringcomputerChoice, StringPlayerChoice, StringWinner;
    enValue ComputerChoice = (enValue)RandomNumber(1, 3);
    enValue PlayerChoice = (enValue)UserChoiceNumber;
    if (ComputerChoice == enValue::Paper && PlayerChoice == enValue::Scissor)
    {
        Winner = enResult::Player;
        system("color 2F");
    }
    else if (ComputerChoice == enValue::Scissor && PlayerChoice == enValue::Paper)
    {
        Winner = enResult::Computer;
        cout << '\a';
        system("color 4F");

    }
    else if (ComputerChoice == enValue::Stone && PlayerChoice == enValue::Scissor)
    {
        Winner = enResult::Computer;
        cout << '\a';
        system("color 4F");

    }
    else if (ComputerChoice == enValue::Scissor && PlayerChoice == enValue::Stone)
    {
        Winner = enResult::Player;
        system("color 2F");
    }
    else if (ComputerChoice == enValue::Stone && PlayerChoice == enValue::Paper)
    {
        Winner = enResult::Player;
        system("color 2F");
    }
    else if (ComputerChoice == enValue::Paper && PlayerChoice == enValue::Stone)
    {
        Winner = enResult::Computer;
        cout << '\a';
        system("color 4F");

    }
    else if (ComputerChoice == PlayerChoice)
    {
        Winner = enResult::NoWinner;
        system("color 6F");
    }

    if (ComputerChoice == enValue::Scissor) StringcomputerChoice = "Scissor";
    else if (ComputerChoice == enValue::Paper) StringcomputerChoice = "Paper";
    else if (ComputerChoice == enValue::Stone) StringcomputerChoice = "Stone";

    if (PlayerChoice == enValue::Scissor) StringPlayerChoice = "Scissor";
    else if (PlayerChoice == enValue::Paper) StringPlayerChoice = "Paper";
    else if (PlayerChoice == enValue::Stone) StringPlayerChoice = "Stone";


    if (Winner == enResult::Computer) StringWinner = "Computer";
    else if (Winner == enResult::Player) StringWinner = "Player";
    else if (Winner == enResult::NoWinner) StringWinner = "No Winner";

    cout << "\n\n_____________Round [" << i << "]________________\n\n";
    cout << "Player1  Choice: " << StringPlayerChoice << endl;
    cout << "Computer Choice: " << StringcomputerChoice << endl;
    cout << "Round Winner   : " << StringWinner << endl;
    cout << "\n\n________________________________\n\n";

    return Winner;
}
void StartRounds()
{

    char PlayAgain = 'y';
    do {
        int NumberOfRounds = ReadPositiveNumber("Enter number of rounds?");
        short UserChoiceNumber;
        int PlayerCounter = 0;
        int ComputerCounter = 0;
        int NoWinnerCounter = 0;
        int i = 1;
        for (i = 1; i <= NumberOfRounds; i++)
        {
            cout << "Round [" << i << "] begins: \n";
            cout << "Your Choice: [1]Stone, [2]Paper, [3]Scissor ?";
            cin >> UserChoiceNumber;
            enResult Winner = GetRound(i, UserChoiceNumber, NumberOfRounds);
            if (Winner == enResult::Computer)
                ComputerCounter++;
            else if (Winner == enResult::Player)
                PlayerCounter++;
            else if (Winner == enResult::NoWinner)
                NoWinnerCounter++;
            if (i == NumberOfRounds) {
                GameoverHeader();
                getRounds(NumberOfRounds, PlayerCounter, ComputerCounter, NoWinnerCounter);
            }
        }

        cout << "do you want to play again?y/N?";
        cin >> PlayAgain;
        system("cls");
        system("color 07");


    } while (PlayAgain != 'N' && PlayAgain != 'n');

}
int main()
{
    srand((unsigned)time(NULL));

    StartRounds();
    return 0;
}