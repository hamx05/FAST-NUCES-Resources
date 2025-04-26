#include <stdio.h>

int main () {
	
	int i,n, volume;
	printf("enter the no. of boxes: ");
	scanf("%d", &n);
	
	struct Boxes box[n] { 
		float l;
		float w;
		float h;
	};
	

	for (i=0; i<n; i++) {
	printf("enter the length, width and height of box %d: ", i+1);
	scanf("%f %f %f", &box[i].l, &box[i].w, &box[i].h);
	}
	
	int count=1, block=0;
	for (i=0; i<n; i++) {
		volume = 0;
		if (box[i].h < 41) {
			volume = box[i].l * box[i].w * box[i].h;
			printf("Volume of box %d passed: %d\n", count, volume);
			count++;
		}
		else {
			block++;
		}
	}
	printf("Number of boxes blocked: %d", block);
	
	return 0;
}
