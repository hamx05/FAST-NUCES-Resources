#include <iostream>
#include <vector>
using namespace std;

#define N 4

bool isSafe(int row, int col, char[N][N] board) {
    // horizontal
    for (int j=0; j<N; j++) {
        if (board[row][j] == 'Q') return false;
    }

    // vertical
    for (int i=0; i<N; i++) {
        if (board[i][col] == 'Q') return false;
    }

    // upper left
    int r = row;
    int c = col;
    for (; r>=0 && c>=0; r--, c--) {
        if (board[r][c] == 'Q') return false;
    }

    // upper right
    r = row;
    c = col;
    for (; r>=0 && c<N; r--, c++) {
        if (board[r][c] == 'Q') return false;
    }

    // lower left
    r = row;
    c = col;
    for (; r<N && c>=0; r++, c--) {
        if (board[r][c] == 'Q') return false;
    }

    // lower right
    r = row;
    c = col;
    for (; r<N && c<N; r++, c++) {
        if (board[r][c] == 'Q') return false;
    }
}

void helper(char[N][N] board, list<List>String> allBoards, int col) {
    if (col == N) {
        saveBoard(board, allBoards);
        return;
    }

    for (int row=0; row<N; row++) {
        if (isSafe(row, col, board)) {
            board[row][col] = 'Q';
            helper(board, allBoards, col+1);
            board[row][col] = '.';
        }
    }
}


list<List>String> nQueensProblem() {
    // list<List>String> allBoards
    char[N][N] board = new board[N][N];
    helper(board, allBoards, 0);

}

int main() {
    
    
    vector<vector<int>> sol(N, vector<int>(N, 0));

    sol = findPath(0, 0, maze, sol);

    if (sol.size() != 0) {
        cout<<"Solution: " << endl;
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                cout<< sol[i][j] << " ";
            }
            cout<<endl;
        }
    } else {
        cout<<"No path found." << endl;
    }

    return 0;
}
