#include <iostream>
using namespace std;

class ChessPiece {
    string name;
    string color;
    char symbol; // small letters for white, capital letters for black

    public:
        ChessPiece () { // Default constructor
            name = "Pawn";
            color = "White";
            symbol = 'p';
        }

        ChessPiece (string name, string color, char symbol) { // Parameterized constructor
            this->name = name;
            this->color = color;
            this->symbol = symbol;
        }
        
        // Setter functions
        void setName (string name) {
            this->name = name;
        }

        void setColor (string color) {
            this->color = color;
        }

        void setSymbol (char symbol) {
            this->symbol = symbol;
        }

        // Getter functions
        string getName () { return name; }
        string getColor () { return color; }
        char getSymbol () { return symbol; }

        

};

class ChessBoard {
private:
    ChessPiece* board[8][8];

public:
    char white[16] = {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'};


    ChessBoard() { // Constructor - Initialize the board with null pointers
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
                    cout << board[i][j]->getSymbol() << " ";
                } else {
                    cout << "- ";
                }
            }
            cout << endl;
        }
    }

    // Move a piece from one position to another
    void movePiece(int startX, int startY, int endX, int endY) {
        if (isValidPosition(startX, startY) && isValidPosition(endX, endY)) {
            board[endX][endY] = board[startX][startY];
            board[startX][startY] = nullptr;
        } else {
            cout << "Invalid move!" << endl;
        }
    }

private:
    // Check if the position is within the board's bounds
    bool isValidPosition(int x, int y) const {
        return x >= 0 && x < 8 && y >= 0 && y < 8;
    }
};



int main () {


    return 0;
}