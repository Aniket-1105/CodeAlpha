#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

const int SIZE = 9;

// Function to print the Sudoku board
void printBoard(const vector<vector<int>>& board) {
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            cout << board[row][col] << " ";
        }
        cout << endl;
    }
}

// Function to check if placing a number is valid
bool isSafe(const vector<vector<int>>& board, int row, int col, int num) {
    for (int x = 0; x < SIZE; ++x) {
        if (board[row][x] == num || board[x][col] == num) {
            return false;
        }
    }
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }
    return true;
}

// Backtracking algorithm to solve Sudoku
bool solveSudoku(vector<vector<int>>& board) {
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= SIZE; ++num) {
                    if (isSafe(board, row, col, num)) {
                        board[row][col] = num;
                        if (solveSudoku(board)) {
                            return true;
                        }
                        board[row][col] = 0; // Backtrack
                    }
                }
                return false; // No number is valid
            }
        }
    }
    return true; // Solved
}

// Initialize predefined puzzles based on difficulty
vector<vector<int>> initializePuzzle(const string& difficulty) {
    if (difficulty == "easy") {
        return {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}
        };
    } else if (difficulty == "moderate") {
        return {
            {0, 0, 0, 6, 0, 0, 4, 0, 0},
            {7, 0, 0, 0, 0, 3, 6, 0, 0},
            {0, 0, 0, 0, 9, 1, 0, 8, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 5, 0, 1, 8, 0, 0, 0, 3},
            {0, 0, 0, 3, 0, 6, 0, 4, 5},
            {0, 4, 0, 2, 0, 0, 0, 6, 0},
            {9, 0, 3, 0, 0, 0, 0, 0, 0},
            {0, 2, 0, 0, 0, 0, 1, 0, 0}
        };
    } else if (difficulty == "hard") {
        return {
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 3, 0, 8, 5},
            {0, 0, 1, 0, 2, 0, 0, 0, 0},
            {0, 0, 0, 5, 0, 7, 0, 0, 0},
            {0, 0, 4, 0, 0, 0, 1, 0, 0},
            {0, 9, 0, 0, 0, 0, 0, 0, 0},
            {5, 0, 0, 0, 0, 0, 0, 7, 3},
            {0, 0, 2, 0, 1, 0, 0, 0, 0},
            {0, 0, 0, 0, 4, 0, 0, 0, 9}
        };
    } else {
        throw invalid_argument("Invalid difficulty level");
    }
}

// Function to get Sudoku input from the user
void getUserInput(vector<vector<int>>& board) {
    cout << "Enter the Sudoku puzzle row by row (use 0 for empty cells):" << endl;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cin >> board[i][j];
        }
    }
}

int main() {
    vector<vector<int>> board;
    string mode;

    cout << "Choose mode: (user/easy/moderate/hard): ";
    cin >> mode;

    if (mode == "user") {
        board.resize(SIZE, vector<int>(SIZE, 0));
        getUserInput(board);
    } else {
        try {
            board = initializePuzzle(mode);
        } catch (const invalid_argument& e) {
            cout << e.what() << endl;
            return 1;
        }
    }

    cout << "\nInitial Sudoku Puzzle:" << endl;
    printBoard(board);

    if (solveSudoku(board)) {
        cout << "\nSolved Sudoku Puzzle:" << endl;
        printBoard(board);
    } else {
        cout << "\nNo solution exists for the given Sudoku puzzle." << endl;
    }

    return 0;
}
