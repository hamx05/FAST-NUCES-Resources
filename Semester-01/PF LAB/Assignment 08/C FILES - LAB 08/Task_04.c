#include <stdio.h>
#include <string.h>

int main () {
	
	char password[50], saved[]="Secure123";
	
	printf("enter the password: ");
	gets(password);
	
	if (strlen(password) >= 8) {
		if (strcmp(password,saved) == 0){
			printf("Login successful.");
		}
		else {
			printf("Password does not match. Login failed.");
		}
	}
	
	else {
		printf("Login failed due to insufficient characters.");
	}
	
	
	return 0;
}
