#include <iostream>

using namespace std;

// Fixes: test File, Create Board, PlayGame, PlayComputer, Message, Continue Functions;
// Additions: Another player, extra board, specialization of the game

// Global Prototypes
void SelectPlayers();
void CreateBoard();
bool PlayMore();

// Global Variables
const int ROW = 3;
const int COL = 3;

int main()
{
    bool playMore;

    do
    {
        SelectPlayers();
        playMore = PlayMore();
    } while (playMore == true);
}

void SelectPlayers()
{
    int numberOfPlayers;
    bool invalid = true;

    cout << "How many players are playing? 1 or 2? "
         << "Number of Players: ";

    cin >> numberOfPlayers;

    if (numberOfPlayers == 1)
    {
        CreateBoard();
    }
    else if (numberOfPlayers == 2)
    {
        CreateBoard();
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

void CreateBoard()
{
    int board[COL][ROW] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    for (int i = 0; i < ROW; i++)
    {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "  " << endl;
        cout << "-----------" << endl;
    }
}

bool PlayMore()
{
    char playMore;

    cout << "Would you like to play again? " << endl;
    cout << "Enter y or Y for yes, and n or N for no" << endl;
    cin >> playMore;

    if (playMore == 'y' || playMore == 'Y')
    {
        return true;
    }
    if (playMore == 'n' || playMore == 'N')
    {
        return false;
    }
    else
    {
        while (playMore != 'y' || playMore != 'Y' || playMore != 'n' || playMore != 'N')
        {
            cout << "Please enter a valid response. Enter y or Y for yes, and n or N for no " << endl;
            cin >> playMore;
        }
    }

    return false;
}
