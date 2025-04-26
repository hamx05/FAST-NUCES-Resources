#include <stdio.h>
#include <conio.h>

int main () {
	
	int time=0;
	
	printf("Enter the time : ");
	scanf("%d", &time);
	
	if (time>=5 && time<=11) {
		printf("Good morning.");
	}
	
		else if (time >= 12 && time<=18) {
			printf("Good evening.");
		}
		
		else if (time>18 && time<=23 || time == 0) {
			printf("Good night.");
		}
		
		else if (time>=1 && time<5) {
			printf("ERROR");
		}
		
	else {
	}		
		
	return 0;
		
	}
	
	
	

