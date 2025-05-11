#include <iostream>
#include <vector>
using namespace std;

#define N 5

// logic fixed by gpt

vector<vector<int>> findPath(int x, int y, int maze[N][N], vector<vector<int>>& sol) {
    
    // base condition, when reached at meat
    if (x == N-1 && y == N-1 && maze[x][y] == 1) {
        sol[x][y] = 1;
        return sol;
    }

    // check if current position is valid
    if ((x >= 0 && x < N) && (y >= 0 && y < N) && maze[x][y] == 1) {
        // mark x, y as part of solution path
        sol[x][y] = 1;

        // Move downward
        if (x + 1 < N) {
            if (findPath(x+1, y, maze, sol).size() != 0) {
                return sol;
            }
        }

        // Move right
        if (y + 1 < N) {
            if (findPath(x, y+1, maze, sol).size() != 0) {
                return sol;
            }
        }
        
        // backtrack, and unmark x, y as part of solution path
        sol[x][y] = 0;
    }

    return {};
}

int main() {
    
    int maze[N][N]= {{1, 0, 1, 0, 1},
                     {1, 1, 1, 1, 1},
                     {0, 1, 0, 1, 1},
                     {1, 0, 0, 1, 1},
                     {1, 1, 1, 0, 1}};
    
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
