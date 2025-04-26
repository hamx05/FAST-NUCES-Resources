#include <stdio.h>
#include <conio.h>

int main () {
    
    int burger=200, fries=50, pizza=500, sandwiches=150, total_snacks, quantity_first, quantity_second, price=0, price1=0, price2=0, total_quantity;
    char  first_snack, second_snack;
	
	// MENU: 
	printf("\t\tABC Restaurant Online Order Placement\n\t\t\tWelcome\n\n");
	printf("Please select from the following Menu\n");
	printf("B = Burger\t\t(Rs 200)\n");
	printf("F = French Fries\t(Rs 50)\n");
	printf("P = Pizza\t\t(Rs 500)\n");
	printf("S = Sandwiches\t\t(Rs 150)\n\n");
	
	
	// TAKING ORDER FROM CUSTOMER:
	printf("How many types of snack do you want to order: ");
	scanf("%d", &total_snacks);

	printf("Enter the first snack you want to order: ");
	scanf(" %c", &first_snack);
	
	switch (first_snack) {
	
	case 'B':
	        printf("Please provide quantity: ");
	        scanf("%d", &quantity_first);
	        price1 = burger * quantity_first;
	        break;
	    
    case 'F':
	        printf("Please provide quantity: ");
	        scanf("%d", &quantity_first); 
	        price1 = fries * quantity_first;
	        break;
	    
	case 'P':
	        printf("Please provide quantity: ");
	        scanf("%d", &quantity_first); 
	        price1 = pizza * quantity_first;
	        break;
	    
    case 'S':
	        printf("Please provide quantity: ");
	        scanf("%d", &quantity_first); 
	        price1 = sandwiches * quantity_first;
	        break;
	    
    default:
        printf("Invalid item.\n");
        break; }
        

    printf("Enter the second snack you want to order: ");
	scanf(" %c", &second_snack);
	
	switch (second_snack) {
	
	case 'B':
	        printf("Please provide quantity: ");
	        scanf("%d", &quantity_second);
	        price2 = burger * quantity_second;
	        break;
	    
    case 'F':
	        printf("Please provide quantity: ");
	        scanf("%d", &quantity_second); 
	        price2 = fries * quantity_second;
	        break;
	    
	case 'P':
	        printf("Please provide quantity: ");
	        scanf("%d", &quantity_second); 
	        price2 = pizza * quantity_second;
	        break;
	    
    case 'S':
	        printf("Please provide quantity: ");
	        scanf("%d", &quantity_second); 
	        price2 = sandwiches * quantity_second;
	        break;
	    
    default:
        printf("Invalid item.\n");
        break; }
        
    
	
	printf("-------------------------------------------------------------------\n");
	total_quantity = quantity_first + quantity_second;
	printf("You have ordered %d items!\n", total_quantity);
	printf("%d %c (s) value %d\n", quantity_first, first_snack, price1);
	printf("%d %c (s) value %d\n", quantity_second, second_snack, price2);
	price = price1 + price2;
    printf("Total: %d PKR\n", price);
    printf("Thank you for your order. Have a nice day!");
	
	
    return 0;
    }

