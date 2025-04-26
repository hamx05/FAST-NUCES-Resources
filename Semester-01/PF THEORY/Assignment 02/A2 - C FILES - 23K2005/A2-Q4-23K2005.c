#include <stdio.h>

int i, ROW = 5, COL = 5;

int path[5 * 5][2];  // To store the path
int path_index = 0;  // Index to keep track of the path

void printPath() {
    for (i = 0; i < path_index; i++) {
        printf("%d,%d   ", path[i][0], path[i][1]);
    }
    printf("\n");
}

int findPath(char ch[5][5], int x, int y) {
    if (x < 0 || x >= ROW || y < 0 || y >= COL || ch[x][y] == 'W' || ch[x][y] == 'V') {
        return 0;
    }

    path[path_index][0] = x;
    path[path_index][1] = y;
    path_index++;

    if (ch[x][y] == 'E') {
        printPath();
        return 1;
    }

    ch[x][y] = 'V';

    if (findPath(ch, x, y + 1) || findPath(ch, x + 1, y)) {
        return 1;
    }

    path_index--;
    return 0;
}

int main() {
printf("Student ID: 23K-2005\n");
printf("Student Name: Muhammad Hammad\n\n");
    char ch[5][5] = {
        {'S', 'O', 'O', 'W', 'W'},
        {'O', 'W', 'O', 'O', 'W'},
        {'O', 'O', 'O', 'W', 'O'},
        {'W', 'W', 'O', 'W', 'O'},
        {'W', 'W', 'O', 'E', 'W'}
    };

    printf("Output Maze after traversal:\n");

    findPath(ch, 0, 0);

    return 0;
}
