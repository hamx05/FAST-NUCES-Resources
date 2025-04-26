#include <stdio.h>

int main() {
    
    int LI;
    
    printf("Enter the light intensity: ");
    scanf("%d", &LI);
    
    
    if (LI>=0 && LI<100)
        printf("Evening");
        
    else if (LI>=100 && LI<=500)
        printf("Lightning");
        
    else if (LI>500) {
        printf("Sunshine");
    }
    
        
    else { }

    return 0;
}
