#include <stdio.h>
#include <conio.h>

int main () {
		
	float scale;
	
	printf("Enter the Richter scale number = ");
	scanf("%f",&scale);
	
	if (scale<5.0){
		printf("Little or no damage.");
	}
	else if (scale>=5.0 && scale<5.5) {
		printf("Some damage");
	}
	else if (scale>=5.5 && scale<6.5) {
		printf("Serious damage: Walls may break or crack.");
		}		
	else if (scale>=6.5 && scale<7.5) {
		printf("Disaster: House and buildings may collapse.");
		}
	else if (scale>7.5) {
		printf("Catastroph: Most buildings destroyed.");
		}

return 0;
}


