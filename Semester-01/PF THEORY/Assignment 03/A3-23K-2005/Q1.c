#include<stdio.h>

void matriceTWO() {
    int i, j;
    int matrice[2][2];
    printf("Enter the elements of 2x2 matrice:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            scanf("%d", & matrice[i][j]);
        }
    }
    printf("\n");
    int max = matrice[0][1];
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d\t", matrice[i][j]);
            if (max < matrice[i][j]) {
                max = matrice[i][j];
            }
        }
        printf("\n");
    }
    printf("Output: %d\n\n", max);
}
void matriceFOUR() {
    int i, j;
    int matrice[4][4];
    int sub1[2][2], sub2[2][2], sub3[2][2], sub4[2][2], sub5[2][2], sub6[2][2], sub7[2][2], sub8[2][2], sub9[2][2], sub10[2][2], sub11[2][2], sub12[2][2], sub13[2][2], sub14[2][2], sub15[2][2], sub16[2][2];
    printf("Enter the elements of 4x4 matrice:\n");
    for (i=0; i<4; i++) {
        for (j=0; j<4; j++) {
            scanf("%d", & matrice[i][j]);
        }
    }
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            sub1[i][j] = matrice[i][j];
        }
    }
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            sub2[i][j] = matrice[i][j + 2];
        }
    }
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            sub3[i][j] = matrice[i + 2][j];
        }
    }
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            sub4[i][j] = matrice[i + 2][j + 2];
        }
    }
    int max1 = sub1[0][0], max2 = sub2[0][0], max3 = sub3[0][0], max4 = sub4[0][0];
    for (i=0; i<2; i++) {
        for (j=0; j<2; j++) {
            printf("%d\t", sub1[i][j]);
            if (max1 < sub1[i][j]) {
                max1 = sub1[i][j];
            }
        }
        printf("\n");
    }
    printf("\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d\t", sub2[i][j]);
            if (max2 < sub2[i][j]) {
                max2 = sub2[i][j];
            }
        }
        printf("\n");
    }
    printf("\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d\t", sub3[i][j]);
            if (max3 < sub3[i][j]) {
                max3 = sub3[i][j];
            }
        }
        printf("\n");
    }
    printf("\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d\t", sub4[i][j]);
            if (max4 < sub4[i][j]) {
                max4 = sub4[i][j];
            }
        }
        printf("\n");
    }
    printf("\n");
    int output[2][2] = {{max1,max2},{max3,max4}};
    printf("Output:\n");
    for (i=0; i<2; i++) {
        for (j=0; j<2; j++) {
            printf("%d\t", output[i][j]);
        }
        printf("\n");
    }
}

void matriceEIGHT() {
	int i, j;
    int matrice[4][4];
    int sub1[2][2], sub2[2][2], sub3[2][2], sub4[2][2], sub5[2][2], sub6[2][2], sub7[2][2], sub8[2][2];
    int sub9[2][2], sub10[2][2], sub11[2][2], sub12[2][2], sub13[2][2], sub14[2][2], sub15[2][2], sub16[2][2];
    printf("Enter the elements of 8x8 matrice:\n");
    for (i=0; i<4; i++) {
        for (j=0; j<4; j++) {
            scanf("%d", & matrice[i][j]);
        }
    }
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            sub1[i][j] = matrice[i][j];
        }
    }
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            sub2[i][j] = matrice[i][j + 2];
        }
    }
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            sub3[i][j] = matrice[i + 2][j];
        }
    }
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            sub4[i][j] = matrice[i + 2][j + 2];
        }
    }
	for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            sub5[i][j] = matrice[i + 2][j];
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            sub6[i][j] = matrice[i + 2][j + 2];
    	}
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            sub7[i][j] = matrice[i + 2][j + 4];
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            sub8[i][j] = matrice[i + 2][j + 6];
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            sub9[i][j] = matrice[i + 4][j];
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            sub10[i][j] = matrice[i + 4][j + 2];
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            sub11[i][j] = matrice[i + 4][j + 4];
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            sub12[i][j] = matrice[i + 4][j + 6];
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            sub13[i][j] = matrice[i + 6][j];
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            sub14[i][j] = matrice[i + 6][j + 2];
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            sub15[i][j] = matrice[i + 6][j + 4];
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            sub16[i][j] = matrice[i + 6][j + 6];
        }
    }
    
	int max1 = sub1[0][0], max2 = sub2[0][0], max3 = sub3[0][0], max4 = sub4[0][0], max5 = sub5[0][0], max6 = sub6[0][0], max7 = sub7[0][0], max8 = sub8[0][0], max9 = sub9[0][0], max10 = sub10[0][0], max11 = sub11[0][0], max12 = sub12[0][0], max13 = sub13[0][0], max14 = sub14[0][0], max15 = sub15[0][0], max16 = sub16[0][0];
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d\t", sub1[i][j]);
            if (max1 < sub1[i][j]) {
                max1 = sub1[i][j];
            }
        }
        printf("\n");
    }
    printf("\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d\t", sub2[i][j]);
            if (max2 < sub2[i][j]) {
                max2 = sub2[i][j];
            }
        }
        printf("\n");
    }
		printf("\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d\t", sub3[i][j]);
            if (max3 < sub3[i][j]) {
                max3 = sub3[i][j];
        	}
        }
        printf("\n");
    }
        printf("\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d\t", sub4[i][j]);
            if (max4 < sub4[i][j]) {
                max4 = sub4[i][j];
        	}
    	}
            printf("\n");
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d\t", sub5[i][j]);
            if (max5 < sub5[i][j]) {
                max5 = sub5[i][j];
            }
       	}
        printf("\n");
    }
        printf("\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d\t", sub6[i][j]);
            if (max6 < sub6[i][j]) {
                max6 = sub6[i][j];
            }
        }
        printf("\n");
    }
    printf("\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d\t", sub7[i][j]);
            if (max7 < sub7[i][j]) {
                max7 = sub7[i][j];
            }
        }
        printf("\n");
    }
        printf("\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d\t", sub8[i][j]);
            if (max8 < sub8[i][j]) {
                max8 = sub8[i][j];
            }
        }
        printf("\n");
    }
    printf("\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d\t", sub9[i][j]);
            if (max9 < sub9[i][j]) {
                max9 = sub9[i][j];
            }
        }
        printf("\n");
    }
        printf("\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d\t", sub10[i][j]);
            if (max10 < sub10[i][j]) {
                max10 = sub10[i][j];
            }
        }
        printf("\n");
    }
    printf("\n");
	for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d\t", sub11[i][j]);
            if (max11 < sub11[i][j]) {
                max11 = sub11[i][j];
            }
    	}
        printf("\n");
    }
    printf("\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d\t", sub12[i][j]);
            if (max12 < sub12[i][j]) {
                max12 = sub12[i][j];
            }
        }
        printf("\n");
    }
    printf("\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d\t", sub13[i][j]);
            if (max13 < sub13[i][j]) {
                max13 = sub13[i][j];
            }
    	}
        printf("\n");
	}
    printf("\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d\t", sub14[i][j]);
            if (max14 < sub14[i][j]) {
                max14 = sub14[i][j];
            }
        }
        printf("\n");
}
    printf("\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d\t", sub15[i][j]);
            if (max15 < sub15[i][j]) {
                max15 = sub15[i][j];
            }
        }
        printf("\n");
    }
    printf("\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d\t", sub16[i][j]);
            if (max16 < sub16[i][j]) {
                max16 = sub16[i][j];
            }
        }
        printf("\n");
    }
    printf("\n");
    
    int output[4][4] = {{max1,max2,max3,max4},{max5, max6,max7,max8},{max9,max10,max11,max12},{max13,max14,max15,max16}};
    printf("Output:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d\t", output[i][j]);
        }
        printf("\n");
    }
        printf("\n");
}

int main() {
        printf("Muhammad Hammad (23K-2005)\n");
        
		int choice;
        printf("1) 2x2 matrice\n2) 4x4 matrice\n3) 8x8 matrice\n4) Exit\n");
        printf("choose a matrix to continue: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
        case 1:
            matriceTWO();
            break;
        case 2:
            matriceFOUR();
            break;
        case 3:
            matriceEIGHT();
            break;
        case 4:
            printf("The program has exited.\n");
            break;
        default:
            printf("Invalid input. Please select from the above.\n");
        }

	if (choice>=4 || choice <=0 || choice>='a') {
		exit(1);
	}
	main ();
    return 0;
}
    


    
