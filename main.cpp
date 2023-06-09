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
const int ROW = 3;
const int COL = 3;


int main()
{
    bool playMore;

    do {
    SelectPlayers ();
    playMore = Continue ();
    } while (playMore == true);

}

void SelectPlayers ()
{
    int numberOfPlayers;
    bool invalid = true;

    cout << "How many players are playing? 1 or 2? "
    << "Number of Players: ";

    cin >> numberOfPlayers;

    if (numberOfPlayers == 1)
    {
        CreateBoard();
        PlayGame();
    }
    else if (numberOfPlayers == 2)
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
    for (int i = 0; i < COL; i ++)
    {
        for (int j = 0; i < ROW; j++)
             {
                 cout << "__|";
             }
        cout << endl;
    }
                            
    for (int a = 3; a < COL; a ++)
    {
        for (int j = 0; j < ROW; j++)
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

/*
Testing Code

#include <iostream>

using namespace std;

void CreateBoard();

const int COL = 3;
const int ROW = 3;

int main()
{
    CreateBoard();
}

void CreateBoard()
{
    int placement[COL][ROW] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

    for (int i = 0; i < COL; i++)
    {
        for (int j = 0; j < ROW; j++)
        {
            cout << "|" 
            cout << placement[i][j] << "|";
        }
        cout << "__";
        cout << endl;
    }
}
*/
