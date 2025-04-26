#include <stdio.h>
#include <string.h>


	
	int i, n;
	
	typedef struct GameStructure {
		char name[80];
		float healthPoint;
		float attackPoint;
		float defensePoint;
	} GameStructure;
	
	GameStructure GS[10];

void createCharacter(int *number) {
		
		int count=0;
		while (count != 1) {
			printf("Enter the character's name: ");
			scanf("%s", GS[i].name);
			if (strlen(GS[i].name) > 8) {
				printf("Name cannot be more than 8 characters. Re-enter the name.\n");
				continue;
			} else {
				count++;
			}
		}
	
		while (count!=3) {
			count=0;
			printf("Enter %s's health point: ", GS[i].name);
			scanf("%f", &GS[i].healthPoint);
			if (GS[i].healthPoint > 5 || GS[i].healthPoint < 0) {
				printf("Health points invalid. Re-enter all the fields.\n");
				continue;
			} else {
				count++;
			}
			
			
			printf("Enter %s's attack point: ", GS[i].name);
			scanf("%f", &GS[i].attackPoint);
			if (GS[i].attackPoint > 5 || GS[i].attackPoint < 0 || GS[i].attackPoint == GS[i].healthPoint) {
				printf("Attack points invalid. Re-enter all the fields.\n");
				continue;
			} else {
				count++;
			}
			
			
			printf("Enter %s's defense point: ", GS[i].name);
			scanf("%f", &GS[i].defensePoint);
			if (GS[i].defensePoint > 5 || GS[i].defensePoint < 0 || GS[i].defensePoint == GS[i].healthPoint || GS[i].defensePoint == GS[i].attackPoint || GS[i].defensePoint != 10 - GS[i].healthPoint - GS[i].attackPoint) {
				printf("Defense points invalid. Re-enter all the fields.\n");
				continue;
			} else {
				count++;
			}
		}
		number++;
}

void displayCharacter (int *number) {
	printf("The details of all the characters are shown below:\n");
	
	for (i=0; i<number; i++) {
		printf("Information of character %d:", i+1);
		printf("Name: ", GS[i].name);
		printf("Health points: ", GS[i].healthPoint);
		printf("Attack points: ", GS[i].attackPoint);
		printf("Defense points: ", GS[i].defensePoint);
	}
	
	
}
			
	
int main () {
	int choice, number;
	
	do {
		printf("Enter the choice: \n");
		printf("1. Create character\n");
		printf("2. Display character\n");
		scanf("%d", &choice);
		
		switch (choice) {
			case 1:
				createCharacter(number);
				break;
			case 2:
				displayCharacter(number);
				break;
			default:
				printf("Invalid choice.");
				break;
		}
	}
		
	while (number!=0);
	
	
	return 0;
}

	
