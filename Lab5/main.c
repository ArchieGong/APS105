#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

//Full Name: Jiawei Gong
//Student Number: 1007249951
//This program will draw a pascal triangle
//The input is the number of rows

//this function can calculate the factorial of a given number
int factorial (int n){
	int fv = 1;
	for(int i=1; i<=n; i++){
		fv=fv*i;
	}
	return fv;
}

//this function can printf the correct space of a specific row with considering the total rows
void space (int totalrows, int whichrow){
	for(int i=1; i<=(3*(totalrows-1)-3*(whichrow-1)); i++){
	printf(" ");
	}
	return;
}

//ths function can calculate and printf the correct numbers in a specifc row with considering the total rows
void number (int whatrow){
	if(whatrow==1){
		printf("1");
	}
	else{
	for(int i=whatrow; i>=2; i=i-1){
		int trinumber = factorial(whatrow-1)/(factorial(i-1)*factorial(whatrow-1-(i-1)));
		printf("%d", trinumber);
		
		int m = 0;
		while(trinumber>0){
			trinumber = trinumber/10;
			m = m+1;
		}
		
		for(int k=1; k<=(6-m); k++){
			printf(" ");
		}
		
	}
	printf("1");
	}
	return;
}


int main()
{
	int row = 0;
	printf("Enter the number of rows: ");
	scanf("%d", &row);
	
	while(row>=0){
		for(int i=1; i<=row; i++){
			space(row, i);
			number(i);
            printf("     ");
			printf("\n");
		}
		
		row=0;
		printf("Enter the number of rows: ");
		scanf("%d", &row);
	}
	

	return 0;
}
