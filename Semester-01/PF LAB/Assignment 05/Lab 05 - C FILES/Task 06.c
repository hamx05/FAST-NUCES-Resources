#include <stdio.h>

int main() {
    
    float time_mins=0, time_hr=0;
    char type, is_manual, cup_size;
    
    printf("Enter the coffee type (B/W): ");
    scanf(" %c", &type);
   
    
    printf("Is the coffee manual: ");
    scanf(" %c", &is_manual);
    if (is_manual=='Y') {
        printf("Coffee is manual\n\n");
    }
    else {
        printf("Coffee is not manual\n\n"); }
    
    printf("Enter the size of the cup (small=s, double=d): ");
    scanf(" %c", &cup_size);
    
    
    
    
    switch (type) {
         case 'W':
             printf("Put water\n");
             time_mins += 15;
             printf("Add sugar\n");
             time_mins += 15;
             printf("Mix well\n");
             time_mins += 20;
             printf("Add coffee\n");
             time_mins += 2;
             printf("Add milk\n");
             time_mins += 4;
             printf("Mix well\n");
             time_mins += 20;
             time_hr = time_mins / 60;
             if (cup_size=='d') {
                 time_mins *= 1.5;
                 time_hr = time_mins / 60;}
             printf("Total expected time: %.2f minute(s) or %.2f hour(s)", time_mins, time_hr);
             break;
         
         case 'B':
             printf("Put water\n");
             time_mins += 20;
             printf("Add sugar\n");
             time_mins += 20;
             printf("Mix well\n");
             time_mins += 25;
             printf("Add coffee\n");
             time_mins += 15;
             printf("Add milk\n");
             printf("Mix well\n");
             time_mins += 25;
             time_hr = time_mins / 60;
             if (cup_size=='d') {
                 time_mins *= 1.5; 
                 time_hr = time_mins / 60; }
             printf("Total expected time: %.2f minute(s) or %.2f hour(s)", time_mins, time_hr);
             break;
           }

    return 0;
}

