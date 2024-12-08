	#include <stdio.h>
	#include <stdbool.h>
	#include <math.h>
	#include <stdlib.h>
//Full Name: Jiawei Gong
//Student Number: 1007249951
//This program will draw a triangle using "*"
//The input is the number of rows

int main()
{
//Declare variable b = the number of rows
	int b;
	printf("Enter the number of rows in the triangle: ");
	scanf("%d", &b);
//Case 1 when b=1
	if(b==1){
		printf("*\n");
	}
//Case 2 when b=2
	else if(b==2){
		printf(" * \n");
		printf("***\n");
	}
	else{
//Case 3 when b>=3
	//row 1 in case 3
		for (int d=1; d<=b-1; d++){
			printf(" ");
		}
		printf("*");
		for (int d=1; d<=b-1-1; d++){
			printf(" ");
		}
		printf(" \n");
	//row 2 to b in case 3
		for (int a=2; a<=b-1; a++){
			for (int c=1; c<=b-a; c++){
				printf(" ");
			}
			printf("*");
			for (int d=1; d<=2*a-3; d++){
				printf(" ");
			}
			printf("*");
			for (int c=1; c<=b-a-1; c++){
				printf(" ");
			}
			printf(" \n");
		}
	//row b in case 3
		for (int d=1; d<=2*b-1; d++){
			printf("*");
		}
		}
	return 0;
}