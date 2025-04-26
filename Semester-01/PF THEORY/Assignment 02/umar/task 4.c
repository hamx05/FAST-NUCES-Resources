#include <stdio.h>

int main() {
    char ch[5][5] = {
        {'S', 'O', 'O', 'W', 'W'},
        {'O', 'W', 'O', 'O', 'W'},
        {'O', 'O', 'O', 'W', 'O'},
        {'W', 'W', 'O', 'W', 'O'},
        {'W', 'W', 'O', 'E', 'W'}
    };

    int x =0, y =0 ,i,j; 

    printf("Output Maze after traversal:\n");

       for(i=0;i<4;i++){
        printf("(%d,%d) ",x,y);
        if ( ch[x][y+1] == 'O'){
		
            y++;
        }
     else  if (ch[x][y]== 'O') {
            x++;
              
      }
     }


    return 0;
}
