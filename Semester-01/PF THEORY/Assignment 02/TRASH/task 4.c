#include <stdio.h>

int main () {
	
	int i,j,k;
	
	char maze[5][5] = {
        {'S', 'O', 'O', 'W', 'W'},
        {'O', 'W', 'O', 'O', 'W'},
        {'O', 'O', 'O', 'W', 'O'},
        {'W', 'W', 'O', 'W', 'O'},
        {'W', 'W', 'O', 'E', 'W'}
    };	
		
	for (i=0;i<5;i++) {
//		for (j=0; j<5; j++) {
//			for (k=0; k<5; k++) {
				if (maze[i][j] == 'O' && maze[i][k] =='O') {
					printf("(%d,%d), ", i,i+1);
					
				}
			
				if (maze[i][j] == 'O' && maze[i][k] =='O') {
					printf("(%d,%d), ", i,i+1);
				}
//		}
			
//		}
	}
	
	return 0;
}
