#include<stdio.h>

struct product{
	int productid;
	char productname[30];
	int quantity;
	float price;
};
  void addproduct(FILE *ifile){
  	struct product newproduct;
  	printf("Enter product id:");
  	scanf("%d",&newproduct.productid);
  	printf("Enter product Name: ");
  	scanf("%s",&newproduct.productname);
  	printf("Enter Quantity: ");
  	scanf("%d",&newproduct.quantity);
  	printf("Enter Price: ");
  	scanf("%f",&newproduct.price);
  	fwrite(&newproduct,sizeof(struct product),1,ifile);
  	printf("Product Added Successfully.");
  }
  
  void displayin(FILE *ptr){
  	struct product display;
  	printf("\nInventory\n");
    printf("------------------------------------------------\n");
    printf("ID\tName\t\tQuantity\tPrice per Unit\n");
    printf("------------------------------------------------\n");
    while(fread(&display,sizeof(struct product),1,ptr)==1){
    	printf("%d\t%s\t\t%d\t%.2f\n",display.productid,display.productname,display.quantity,display.price);  	
	}
  }
  
  
  float ctotal(FILE *ptr){
  	struct product cal;
  	
  	float value=0.0;
  	while(fread(&cal,sizeof(struct product),1,ptr)==1){
  		value+=cal.price * cal.quantity;
	  }
	  return value;
  }
  
  void update(FILE *ptr,int productid,int quantity){
  	struct product update;
  	rewind(ptr);
  	while(fread(&update,sizeof(struct product),1,ptr)==1){
  		if(update.productid==productid){
  			update.quantity+=quantity;
  			fseek(ptr,-sizeof(struct product),SEEK_CUR);
  			fwrite(&update,sizeof(struct product),1,ptr);
  			 printf("Stock updated successfully.\n");
  			 return;
		  }
	  }
  }  
int main(){
	FILE *ifile=fopen("inventory.txt","a+");
	if(ifile==NULL){
		printf("Error in opening the file.");
	}
	int choice;
	printf("\nInventory Management System\n");
        printf("1. Add Product\n");
        printf("2. Display Inventory\n");
        printf("3. Calculate Total Value\n");
        printf("4. Update Stock\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

      switch(choice){
      	
      	case 1:
          addproduct(ifile);
		  break;
		  
		case 2:
		displayin(ifile);
		break; 
		
		case 3:
		printf("Total Value is : %.2f",ctotal(ifile)); 
		break;
		
		case 4:
			{	
		int productid, quantity;
		printf("Enter Product ID: ");
		scanf("%d",&productid);
		printf("Enter Quantity: ");
		scanf("%d",&quantity);
		update(ifile,productid,quantity); 	
	}
		break;
		
		case 5:
		printf("Exiting program!.");
		break;
		default:
		printf("Invalid Input.");	 
	  }
  fclose(ifile);


}
