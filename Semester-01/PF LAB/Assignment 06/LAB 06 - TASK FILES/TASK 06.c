#include <stdio.h>

int main () {

      int total = 21, comp;

printf("Total matches: %d", total);

while(total >= 0) {
int choice;
if (total==1) {
    printf("Oops! You lost!");
    break; 
}

    printf("\nPick 1, 2, 3, or 4 sticks: ", choice);
    scanf("%d", &choice);
    if (choice>4 || choice<1) {
    printf("Invalid choice!");
    return 1;
    break; }
    
    total -= choice;
    printf("\nMatches left: %d", total);
    
    if (total == 5 || total == 10 || total == 15)
    comp = 4;
    else if (total == 4 || total == 9 || total == 14)
    comp = 3;
    else if (total == 3 || total == 8 || total == 13)
    comp = 2;
    else 
    comp = 1;
    
    printf("\nComputer picked: %d matches",comp);
    total -= comp;
    printf("\nMatches left: %d\n\n", total);
}

return 0;

}
    

