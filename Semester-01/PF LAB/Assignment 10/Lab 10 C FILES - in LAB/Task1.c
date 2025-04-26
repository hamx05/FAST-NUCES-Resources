#include <stdio.h>

int main () {
	int i;
	char arr[6]={'a','b','c','d','e','f'};
	char* ptr1;
	char** ptr2;
	ptr1 = &arr;
	ptr2 = &ptr1;
	*(*ptr2+2)='X';
	for(i=0;i<6;i++)
	{
		printf("%c\n",*(*ptr2+i));
	}	
}
