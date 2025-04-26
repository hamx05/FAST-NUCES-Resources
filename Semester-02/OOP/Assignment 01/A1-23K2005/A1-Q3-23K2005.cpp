#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ChessPiece {
private:
    string name;
    char color;
    char symbol;

public:
    ChessPiece(string name, char color, char symbol) : name(name), color(color), symbol(symbol) {}

    string getName() const { return name; }
    char getColor() const { return color; }
    char getSymbol() const { return symbol; }
};

class ChessBoard {
private:
    vector<vector<ChessPiece*>> cb;

public:
    ChessBoard() {
        cb.resize(8, vector<ChessPiece*>(8, nullptr));
        initializeWhitePieces();
        initializeBlackPieces();
    }

    void initializeWhitePieces() {
        const char pieces[] = {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'};
        for (int i=0; i<8; ++i)
            cb[0][i] = new ChessPiece(getPieceName(pieces[i]), 'w', pieces[i]);
        for (int i=0; i<8; ++i)
            cb[1][i] = new ChessPiece("p", 'w', 'p');
    }

    void initializeBlackPieces() {
        const char pieces[] = {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'};
        for (int i=0; i<8; ++i)
            cb[7][i] = new ChessPiece(getPieceName(pieces[i]), 'b', pieces[i]);
        for (int i=0; i<8; ++i)
            cb[6][i] = new ChessPiece("P", 'b', 'P');
    }

    string getPieceName(char symbol) const {
        switch (symbol) {
            case 'r': return "Rook";
            case 'n': return "Knight";
            case 'b': return "Bishop";
            case 'q': return "Queen";
            case 'k': return "King";
            default:  return "";
        }
    }

    ~ChessBoard() {
        for (int i=0; i<8; ++i)
            for (int j=0; j<8; ++j)
                delete cb[i][j];
    }

    void display() const {
        cout<<"The chessboard is displayed below."<<endl;
        cout << "  a b c d e f g h" << endl;
        for (int i=0; i<8; ++i) {
            cout<< 8 - i << " ";
            for (int j=0; j<8; ++j) {
                if (cb[i][j] != nullptr)
                    cout<<cb[i][j]->getSymbol()<<" ";
                else
                    cout<<". ";
            }
            cout<< 8 - i << endl;
        }
        cout<< "  a b c d e f g h" << endl;
    }

    bool movePiece(string source, string destination) {
        int currRow = 8 - (source[1] - '0');
        int currCol = source[0] - 'a';
        int targetRow = 8 - (destination[1] - '0');
        int targetCol = destination[0] - 'a';

        if (currRow < 0 || currRow > 7 || currCol < 0 || currCol > 7 ||
            targetRow < 0 || targetRow > 7 || targetCol < 0 || targetCol > 7) {
            cout<<"The current or targetted position is invalid. Please try again."<<endl;
            return false;
        }

        if (cb[currRow][currCol] == nullptr) {
            cout<<"The targetted position has no piece. Please try again."<<endl;
            return false;
        }

        char pieceSymbol = cb[currRow][currCol]->getSymbol();
        cout<<"Moving piece with symbol "<<pieceSymbol<<" from "<<source<<" to "<<destination<<endl;

        delete cb[targetRow][targetCol];
        cb[targetRow][targetCol] = cb[currRow][currCol];
        cb[currRow][currCol] = nullptr;
        return true;
    }
};

int main() {
	cout<<"*********************"<<endl;
	cout<<"Name: Muhammad Hammad"<<endl;
	cout<<"Roll no: 23K-2005"<<endl;
	cout<<"*********************"<<endl;
	
    ChessBoard cb;
    cout<<"Initial Game Board"<<endl;
    cb.display();

    cout<<"-----------------------------------------"<<endl;
    cb.movePiece("b8", "a6"); // Knight's move
    cb.display();
    cout<<"\n";

    cout<<"-----------------------------------------"<<endl;
    cb.movePiece("b8", "d7"); // Pawn's move
    cb.display();

    return 0;
}

