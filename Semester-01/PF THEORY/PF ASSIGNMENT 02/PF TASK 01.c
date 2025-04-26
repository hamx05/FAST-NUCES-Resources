#include <stdio.h>
int main () {
	
	int i, j, total_batsman, total_innings, score[5][5], total_score, avg_score, max_score=0, half_century_count, century_count;
	
	printf("Enter the number of batsman and innings: ");
	scanf("%d%d", &total_batsman ,&total_innings);

	for (i=0; i<total_batsman; i++) {	
		for (j=0; j<total_innings; j++) {
			printf("Enter the performance of batsman %d in inning %d: ", i+1, j+1);
			scanf("%d", &score[i][j]);
		}
	}
	
	printf("\n");
	printf("=========================================\n");
	for (i=0; i<total_batsman; i++) {
		printf("\tStatistics for Batsman #%d:-\n\n", i+1);		
		total_score = 0;
		max_score = 0;
		century_count = 0;
		half_century_count = 0;
		for (j=0; j<total_innings; j++) {
			total_score += score[i][j];
			printf("Score in inning %d: %d \n", j+1, score[i][j]);
			if (max_score < score[i][j]) {
				max_score = score[i][j];			
			}
			if (score[i][j] >= 100) {
			century_count++;			
			}
			if (score[i][j] >= 50 && score[i][j] < 100) {
			half_century_count++;			
			}
			
		}
		avg_score = total_score / total_innings;
		printf("Total runs scored: %d\n", total_score);
		printf("Average score per inning: %d\n", avg_score);
		printf("Highest score in a single inning: %d\n", max_score);
		printf("Number of centuries: %d\n", century_count);
		printf("Number of half-centuries: %d\n", half_century_count);	
		printf("=========================================\n");
	}
	
	
	
	return 0;
}
