#include <stdio.h>

int main()
{
    float item1, item2, item3, item4, item5,item_total,gst,profit, grand_total;

    printf("Input the price of item 1 = ");
    scanf("%f", &item1);
    printf("Input the price of item 2 = ");
    scanf("%f", &item2);
    printf("Input the price of item 3 = ");
    scanf("%f", &item3);
    printf("Input the price of item 4 = ");
    scanf("%f", &item4);
    printf("Input the price of item 5 = ");
    scanf("%f", &item5);
    
    item_total = item1 + item2 + item3 + item4 + item5; 
    profit = (item_total *15) / 100;
    gst = (item_total *18) / 100;
    grand_total = item_total + ((item_total *18) / 100);
    
    
    printf("\n\n\t\tSalman Grocery Store\n\n--------------------------------------------------\n\n");
    printf("Description\t\t|\tPrice\n\n--------------------------------------------------\n\n");
    printf("Item 1\t\t\t|\t%.2f\nItem 2\t\t\t|\t%.2f\nItem 3\t\t\t|\t%.2f\nItem 4\t\t\t|\t%.2f\nItem 5\t\t\t|\t%.2f\n",item1,item2,item3,item4,item5);
    printf("\n--------------------------------------------------\n\n");
    printf("Item total\t\t|\t%.2f\n\nGST\t\t\t|\t%.2f",item_total, gst);
    printf("\n--------------------------------------------------\n\n");
    printf("Grand Total\t\t|\t%.2f\n\n\nTotal Profit Earned\t|\t%.2f",grand_total, profit);
  

    
    return 0;
}
