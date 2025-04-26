#include <stdio.h>

int main() {
    int x,i,j,y;
    int total_runs,half_centuries,centuries,highest_score;
     int score[x][y];
    printf("Enter the number of batsmen: ");
    scanf("%d", &x);
    printf("Enter the number of innings: ");
    scanf("%d", &y);
    
    printf("\n");
    for (i=0;i<x;i++) {
        printf("enter batsman  %d=\n", i+1);
        
        for (j=0;j <y;j++) {
            printf("enter innings run  %d= ", j+1);
            scanf("%d", &score[i][j]);
        }
    }
    
    for (i=0;i<x;i++) {
    	printf("\nBatsman status %d:\n", i+1);
        
         half_centuries= 0;
         centuries  = 0;
         highest_score  = 0;
         total_runs  = 0;
        for(j =0;j<y;j++) {
    
             if (score[i][j] >= 50) {
                half_centuries++;
                printf("Number of half-centuries = %d\n", half_centuries);
            }
           else if (score[i][j] >= 100) {
                centuries++;
                 printf("Number of centuries= %d\n", centuries);
            }
            
            if (score[i][j]> highest_score) {
                highest_score = score[i][j];
                 printf("Highest score in a single inning = %d\n", highest_score);
            }
            total_runs += score[i][j];
            printf("Total runs scored= %d\n", total_runs);
        }
        
        float average = total_runs / y;
         printf("Average runs per inning: %.2f\n", average);
  }
    
    return 0;
}
