#include<stdio.h>
 int main(){
 	FILE *first=fopen("file1.txt","w");
 	fprintf(first,"Text in 1 file.\n Another text ");
 	fprintf(first,"some more text in 1 ");
 	fclose(first);
 	
 	FILE *second=fopen("file2.txt","w");
 	fprintf(second,"Text in Second file");
 	fclose(second);
 	
 	
 	first=fopen("file1.txt","r");
    second=fopen("file2.txt","r");
    
 	FILE *merge=fopen("merge.txt","w");
 	
 	int ch;
	 while((ch=fgetc(first))!=EOF){
	 	fputc(ch,merge);
	 }
	 while((ch=fgetc(second))!=EOF){
	 	fputc(ch,merge);
	 }
	 
	 fclose(first);
     fclose(second);
	 fclose(merge); 
 }
