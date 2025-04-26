#include<stdio.h>
#include<string.h>
#include<stdlib.h>
   struct customerinfo{
   	char name[20];
   	int address;
   }; 
   struct car{
   	float price;
   	int model;
   	char brand[20];
   	int  manufacturingdate;
   	char countryoforigin[30];
   	struct customerinfo ci;
   };
   savebillinfo(){
   	  struct car c;
   	printf("Enter Name: ");
   	scanf("%s",&c.ci.name);
   	printf("Enter Address in integer: ");
   	scanf("%d",&c.ci.address);\
   	printf("Enter Price: ");
   	scanf("%f",&c.price);
   	printf("Enter Model: ");
   	scanf("%d",&c.model);
   	printf("Enter Brand: ");
   	scanf("%s",&c.brand);
   	printf("Enter Manufacturing Date: ");
    scanf("%d",&c.manufacturingdate);
	printf("Enter Country of Origin: ");
    scanf("%s",&c.countryoforigin);
    FILE *ptr=fopen("bill.txt","a");
	if(ptr==NULL){
    printf("\nError in opening file");
	}else{
    fwrite(&c,sizeof(struct car),1,ptr);
    fclose(ptr);
   }
}
int main(){
	savebillinfo();
}
