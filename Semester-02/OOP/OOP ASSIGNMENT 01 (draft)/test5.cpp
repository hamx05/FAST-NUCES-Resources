#include <iostream>
#include <string>

// Forward declaration of ChessPiece class
class ChessPiece;

class ChessBoard {
private:
    ChessPiece* board[8][8];

public:
    // Constructor
    ChessBoard() {
        // Initialize the board with null pointers
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                board[i][j] = nullptr;
            }
        }
    }

    // Display the current state of the board
    void display() const {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i][j] != nullptr) {
                    std::cout << board[i][j]->getSymbol() << " ";
                } else {
                    std::cout << "- ";
                }
            }
            std::cout << std::endl;
        }
    }

    // Move a piece from one position to another
    bool movePiece(std::string source, std::string destination) {
        int startX = source[0] - 'a';
        int startY = 8 - (source[1] - '0');
        int endX = destination[0] - 'a';
        int endY = 8 - (destination[1] - '0');

        if (!isValidPosition(startX, startY) || !isValidPosition(endX, endY)) {
            std::cout << "Invalid move: Position out of bounds!" << std::endl;
            return false;
        }

        if (board[startX][startY] == nullptr) {
            std::cout << "Invalid move: No piece at the source position!" << std::endl;
            return false;
        }

        if (board[endX][endY] != nullptr) {
            std::cout << "Invalid move: Destination position is already occupied!" << std::endl;
            return false;
        }

        // Check if the move is valid for the piece type (Knight or Pawn)
        char symbol = board[startX][startY]->getSymbol();
        if (symbol == 'N' || symbol == 'n' || symbol == 'P' || symbol == 'p') {
            // For simplicity, let's consider only knight and pawn movements for the first turn
            int deltaX = abs(endX - startX);
            int deltaY = abs(endY - startY);
            if ((deltaX == 2 && deltaY == 1) || (deltaX == 1 && deltaY == 2)) {
                board[endX][endY] = board[startX][startY];
                board[startX][startY] = nullptr;
                return true;
            } else {
                std::cout << "Invalid move: Invalid movement for the piece!" << std::endl;
                return false;
            }
        } else {
            std::cout << "Invalid move: Movement not supported for the piece!" << std::endl;
            return false;
        }
    }

private:
    // Check if the position is within the board's bounds
    bool isValidPosition(int x, int y) const {
        return x >= 0 && x < 8 && y >= 0 && y < 8;
    }
};

// ChessPiece class definition
class ChessPiece {
private:
    std::string name;
    std::string color;
    char symbol;

public:
    // Constructor
    ChessPiece(std::string name, std::string color, char symbol)
        : name(name), color(color), symbol(symbol) {}

    // Getter for symbol
    char getSymbol() const {
        return symbol;
    }
};

int main() {
    ChessBoard board;

    // Creating and placing a piece on the board
    ChessPiece whiteKnight("Knight", "white", 'n');
    board.movePiece("b8", "a6"); // Moving a piece to a new position
    board.display();

    // Attempting an invalid move
    board.movePiece("b8", "d7");

    return 0;
}
