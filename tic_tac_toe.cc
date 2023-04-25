#include <iostream>
#include <string>

// Function to display the game board
void displayBoard(char board[]) {
    std::cout << " " << board[0] << " | " << board[1] << " | " << board[2] << " " << std::endl;
    std::cout << "---|---|---" << std::endl;
    std::cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " " << std::endl;
    std::cout << "---|---|---" << std::endl;
    std::cout << " " << board[6] << " | " << board[7] << " | " << board[8] << " " << std::endl;
}

// Function to check if the game has ended
bool isGameOver(char board[]) {
    // Check for tie
    bool isTie = true;
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            isTie = false;
            break;
        }
    }
    if (isTie) {
        return true;
    }
    // Check rows
    for (int i = 0; i < 9; i += 3) {
        if (board[i] == board[i+1] && board[i+1] == board[i+2] && board[i] != ' ') {
            return true;
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[i] == board[i+3] && board[i+3] == board[i+6] && board[i] != ' ') {
            return true;
        }
    }
    // Check diagonals
    if (board[0] == board[4] && board[4] == board[8] && board[0] != ' ') {
        return true;
    }
    if (board[2] == board[4] && board[4] == board[6] && board[2] != ' ') {
        return true;
    }
    return false;
}

// Function to get a valid move from the player
int getMove(char board[], char player) {
    int move;
    while (true) {
        std::cout << "Player " << player << ", enter your move (1-9): ";
        std::string input;
        std::cin >> input;
        bool isNumeric = true;
        for (char c : input) {
            if (!std::isdigit(c)) {
                isNumeric = false;
                break;
            }
        }
        if (input.length() != 1 || !isNumeric) {
            std::cout << "Invalid input. Please enter a number between 1 and 9." << std::endl;
            continue;
        }
        move = input[0] - '0' - 1; // Convert the input to an integer and adjust for 0-based indexing
        if (move < 0 || move > 8 ) {
            std::cout << "Invalid input. Please enter a number between 1 and 9." << std::endl;
            continue;
        }
        if (board[move] != ' ') {
            std::cout << "Cell already occupied. Please choose an empty cell." << std::endl;
            continue;
        }
        break;
    }
    return move;
}

// Function to check if the game is a tie
bool isTie(char board[]) {
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            return false;
        }
    }
    return true;
}


// Function to play the game
void playGame() {
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    bool gameOver = false;
    while (!gameOver) {
        displayBoard(board);
        int move = getMove(board, player);
        board[move] = player;
        if (isGameOver(board)) {
            displayBoard(board);
            if (isTie(board)) {
                std::cout << "Tie game!" << std::endl;
            } else {
                std::cout << "Player " << player << " wins!" << std::endl;
            }
            gameOver = true;
        } else {
            player = (player == 'X') ? 'O' : 'X';
        }
    }
}

// Main function
int main() {
    std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;
    do {
        playGame();
        std::cout << "Play again? (y/n): ";
        std::string choice;
        std::cin >> choice;
        if (choice != "y" && choice != "Y") {
            break;
        }
    } while (true);
    std::cout << "Thanks for playing!" << std::endl;
    return 0;
}