#include <stdio.h>


int main() {
	int i,j,s=4,counta,countp;
    int a[] = { 25, 15, 30, 20};  
    int p[] = {200, 300, 500, 400}; 
 //     for age
    for (i=0;i<s;i++) {
        for (j=i+1;j<s;j++) {
            if(a[i] < a[j]) {
                counta = a[i];
                a[i] = a[j];
                  a[j] = counta;
          }
      }
      }
      printf("Age in accending order\n");
      for(i=s-1;i>=0;i--){
      	printf("Age = %d\n" ,a[i]);
	  }
      //         for price
               for (i=0;i<s;i++) {
                  for (j=i+1;j<s;j++) {
                if(p[i]>p[j]){
				 countp = p[i];
                p[i]= p[j];
                p[j] = countp;
          }
       }
    
}
    printf("\nprice in decending order\n");
    for(i=s-1;i>=0;i--){
      	printf("\nprice = %d" ,p[i]);
      }
   printf("\nThe Age in accending order and price in decending order:\n");
   for (i=s-1;i>=0;i--) {
     printf("\nAge= %d, Price:=%d\n", a[i], p[i]);
}
    
    return 0;
}



