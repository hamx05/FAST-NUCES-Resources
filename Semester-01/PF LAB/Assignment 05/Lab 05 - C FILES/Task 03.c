#include <stdio.h>
#include <conio.h>

int main () {
	float fsc=0,nts=0;
	
	printf("Enter your FSc percentage = ");
	scanf("%f", &fsc);
	printf("Enter your NTs percentage = ");
	scanf("%f", &nts);
	
	if (fsc>70 && nts>70) {
		printf("\nCongratulations! You been selected for IT in Oxford.\n");
	}
	
	else if (fsc>70 && nts>60){
		printf("\nCongratulations! You been selected for Electronics in Oxford.\n");
	}
	
	else if (fsc>70 && nts>50){
		printf("\nCongratulations! You been selected for Telecommunications in Oxford.\n");
	}

	else if (fsc>=60 && fsc<70 && nts>=50) {
		printf("\nCongratulations! You been selected for IT in MIT.");
	}
	
	else if (fsc>=50 && fsc<=59 && nts>=50){
		printf("\nCongratulations! You been selected for Chemical in MIT.");
	}
	
	else if (fsc>40 && fsc<50 && nts>=50){
		printf("\nCongratulations! You been selected for Computer in MIT.");
	}
	else {
		printf("No seats available at this percentage.");
	}
	
	
	return 0;	
}
	
