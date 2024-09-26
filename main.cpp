#include <iostream>
#include <vector>
#include <limits>
#include <algorithm> // Include this for std::count

using namespace std;

// Function Prototypes
void SelectPlayers();
void CreateBoard();
void PlayGame();
void PlayComputer();
void Message(int winner);
bool Continue();
bool CheckWin(char player);
void DisplayBoard();
bool MakeMove(int position, char player);
int Minimax(int depth, bool isMaximizing);
int FindBestMove();

// Global Variables
const int SIZE = 3;
vector<char> board(SIZE * SIZE, ' '); // Represents a 3x3 Tic Tac Toe board

int main() {
    bool playMore;

    do {
        SelectPlayers();
        playMore = Continue();
    } while (playMore == true);

    return 0;
}

void SelectPlayers() {
    int numberOfPlayers;
    cout << "How many players are playing? 1 or 2? Number of Players: ";
    cin >> numberOfPlayers;

    if (numberOfPlayers == 1) {
        CreateBoard();
        PlayComputer();
    } else if (numberOfPlayers == 2) {
        CreateBoard();
        PlayGame();
    } else {
        cout << "Please enter a valid number of players. How many players are playing? 1 or 2? ";
        SelectPlayers(); // Recur to allow re-entry
    }
}

void CreateBoard() {
    board.assign(SIZE * SIZE, ' '); // Reset the board
    DisplayBoard();
}

void DisplayBoard() {
    cout << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << "|" << board[i * SIZE + j];
        }
        cout << "|" << endl;
        cout << "-------" << endl;
    }
}

void PlayGame() {
    char currentPlayer = 'X';
    for (int turn = 0; turn < SIZE * SIZE; turn++) {
        int move;
        while (true) {
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;

            if (move < 1 || move > 9 || !MakeMove(move - 1, currentPlayer)) {
                cout << "Invalid move! Please try again." << endl;
            } else {
                break; // Valid move, exit the loop
            }
        }

        DisplayBoard();
        if (CheckWin(currentPlayer)) {
            Message(currentPlayer == 'X' ? 1 : 2);
            return;
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch players
    }
    cout << "It's a draw!" << endl;
}

void PlayComputer() {
    char currentPlayer = 'X'; // Player is 'X', computer is 'O'
    for (int turn = 0; turn < SIZE * SIZE; turn++) {
        int move;
        if (currentPlayer == 'X') {
            while (true) {
                cout << "Player " << currentPlayer << ", enter your move (1-9): ";
                cin >> move;

                if (move < 1 || move > 9 || !MakeMove(move - 1, currentPlayer)) {
                    cout << "Invalid move! Please try again." << endl;
                } else {
                    break; // Valid move, exit the loop
                }
            }
        } else {
            move = FindBestMove();
            MakeMove(move, currentPlayer);
            cout << "Computer plays at position " << (move + 1) << endl;
        }

        DisplayBoard();
        if (CheckWin(currentPlayer)) {
            Message(currentPlayer == 'X' ? 1 : 0); // 0 for computer
            return;
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch players
    }
    cout << "It's a draw!" << endl;
}

bool MakeMove(int position, char player) {
    if (board[position] == ' ') {
        board[position] = player;
        return true;
    }
    return false;
}

bool CheckWin(char player) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < SIZE; i++) {
        if ((board[i * SIZE] == player && board[i * SIZE + 1] == player && board[i * SIZE + 2] == player) ||
            (board[i] == player && board[i + SIZE] == player && board[i + 2 * SIZE] == player)) {
            return true;
        }
    }
    if ((board[0] == player && board[4] == player && board[8] == player) ||
        (board[2] == player && board[4] == player && board[6] == player)) {
        return true;
    }
    return false;
}

void Message(int winner) {
    if (winner == 0) {
        cout << "Congratulations! The computer won!" << endl;
    } else {
        cout << "Congratulations on winning Player " << winner << "!!" << endl;
    }
}

bool Continue() {
    char playMore;
    cout << "Would you like to play again? Enter y or Y for yes, and n or N for no: ";
    cin >> playMore;

    while (playMore != 'y' && playMore != 'Y' && playMore != 'n' && playMore != 'N') {
        cout << "Please enter a valid response. Enter y or Y for yes, and n or N for no: ";
        cin >> playMore;
    }
    return (playMore == 'y' || playMore == 'Y');
}

// Minimax algorithm to find the best move for the computer
int Minimax(int depth, bool isMaximizing) {
    if (CheckWin('O')) return 10 - depth; // Computer wins
    if (CheckWin('X')) return depth - 10; // Player wins
    if (count(board.begin(), board.end(), ' ') == 0) return 0; // Draw

    if (isMaximizing) {
        int bestScore = numeric_limits<int>::min();
        for (int i = 0; i < board.size(); i++) {
            if (board[i] == ' ') {
                board[i] = 'O'; // Try computer's move
                int score = Minimax(depth + 1, false);
                board[i] = ' '; // Undo move
                bestScore = max(score, bestScore);
            }
        }
        return bestScore;
    } else {
        int bestScore = numeric_limits<int>::max();
        for (int i = 0; i < board.size(); i++) {
            if (board[i] == ' ') {
                board[i] = 'X'; // Try player's move
                int score = Minimax(depth + 1, true);
                board[i] = ' '; // Undo move
                bestScore = min(score, bestScore);
            }
        }
        return bestScore;
    }
}

// Function to find the best move for the computer
int FindBestMove() {
    int bestScore = numeric_limits<int>::min();
    int bestMove = -1;

    for (int i = 0; i < board.size(); i++) {
        if (board[i] == ' ') {
            board[i] = 'O'; // Try computer's move
            int score = Minimax(0, false);
            board[i] = ' '; // Undo move
            if (score > bestScore) {
                bestScore = score;
                bestMove = i;
            }
        }
    }
    return bestMove;
}
