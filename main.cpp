#include <iostream>

using namespace std;

// Fixes: test File, Create Board, PlayGame, PlayComputer, Message, Continue Functions;
// Additions: Another player, extra board, specialization of the game

// Global Prototypes
void SelectPlayers ();
void CreateBoard ();
void PlayGame ();
void PlayComputer ();
void Message ();
bool Continue ();

// Global Variables
const ROW = 3;
const COL = 3;


int main()
{
    bool playMore;

    do {
    SelectPlayers ();
    playMore = Continue ();
    } while (playMore = true);

}

void SelectPlayers ()
{
    int numberOfPlayers;
    bool invalid = true;

    cout << "How many players are playing? 1 or 2? "
    << "Number of Players: ";

    cin >> numberOfPlayers;

    if (numberOfPlayers = 1)
    {
        CreateBoard();
        PlayGame();
    }
    else if (numberOfPlayers = 2)
    {
        CreateBoard();
        PlayComputer();
    }
    else
    {
        while (true)
        {
            cout << "Please enter a valid number of players. How many players are playing? 1 or 2?"
            << "Number of Players: ";
            cin >> numberOfPlayers;
        }
    }

}

void CreateBoard ()
{
    /*
    for (int i = 1; i < COL; i ++)
    {
        for (int j = 0; i < ROW; j++
             {
                 cout << "__|";
             }
        cout << endl;
    }
                            
    for (int a = 3; a < COL; a ++)
    {
        for (int j = 0; i < ROW; j++
             {
                 cout << "__";
             }
        cout << endl;
        }
}

void PlayGame ()
{
    if (gameOver == true)
    {
        Message ();
    }
    else
    {
        
    }
}

void PlayComputer ()
{
    if (gameOver == true)
    {
        Message ();
    }
    else
    {
        
    }
}

void Message (int winner)
{
     cout << "Congradulations on Winning Player" << winner << "!!" << endl;
     return;
     */
}

bool Continue ()
{
    char playMore;

    cout << "Would you like to play again? " << endl;
    cout << "Enter y or Y for yes, and n or N for no" << endl;
    cin >> playMore;

    while (playMore != 'y' || playMore != 'Y' || playMore != 'n' || playMore != 'N')
    {
        cout << "Please enter a valid response. Enter y or Y for yes, and n or N for no " << endl;
        cin >> playMore;
    }
    if (playMore == 'y' || playMore == 'Y')
    {  
        return true;
    }
    if (playMore == 'n' || playMore == 'N')
    {
        return false;
    }

    return false;
}
