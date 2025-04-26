#include <stdio.h>
int main() {

	 int i = 0;   
	 for(i=0;i<7;i++)
{
    if(i%2==0)
    {
        printf("%d\t%d\t%d\t%d",i,i,i,i);
    }
    else
    printf("\t%d\t%d",i,i);
    
     printf("\n",i);
}
    return 0;
}
