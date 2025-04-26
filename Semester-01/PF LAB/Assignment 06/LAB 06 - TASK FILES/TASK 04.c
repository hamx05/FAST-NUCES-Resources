#include <stdio.h>
int main()
{   
int a,b;
printf("Enter number a: \n");
    scanf(" %d",&a);
printf("Enter number b: \n");
    scanf(" %d",&b);
    
    while(a<=b)
    {
	if(a<=9)
		{
 	switch(a){
 	case 0:
 	printf("Zero, ");
 	break;
 	case 1:
 	printf("One, ");
 	break;
 	case 2:
 	printf("Two, ");
 	break;
 	case 3:
 	printf("Three, ");
 	break;
 	case 4:
 	printf("Four, ");
 	break;
 	case 5:
 	printf("Five, ");
 	break;
 	case 6:
 	printf("Six, ");
 	break;
 	case 7:
 	printf("Seven, ");
 	break;
 	case 8:
 	printf("Eight, ");
  	break;
 	case 9:
 	printf("Nine, ");
 	break;
 	default:
 	printf("Negative Value\n");
	} 
	}
	 
         if(a>9)
		{
   			 if(a%2==0)
   			 printf("Even, ");
  			  else printf("Odd, ");
		}
        
    a++;
    
    }
    return 0;
}
