	#include <stdio.h>
	#include <stdbool.h>
	#include <math.h>
	#include <stdlib.h>
	
//Full Name: Jiawei Gong
//Student Number: 1007249951
//This program will make up the cents below 100 cents
//The input is the number of cents

int main(int argc, char **argv)
{
//Declare variables
//The initial number of quarter, dime, nickle, and cent are all 0
	int a;
	int numberofquarter=0;
	int numberofdime=0;
	int numberofnickle=0;
	int numberofcent=0;
//Firstly, the program will ask users to input a number
	printf("Please give an amount in cents less than 100: ");
	scanf("%d", &a);
	printf("%d cents:", a);
//If the first number is between 1 and 100, then the number will go into the first while loop; otherwise, Goodbye
	while(a>1 && a<100){
//Count the number of quarters
			while(a>=25){	
				a=a-25;
				numberofquarter=numberofquarter+1;
			}
//Count the number of dimes
			while(a>=10){
				a=a-10;
				numberofdime=numberofdime+1;
			}
//Count the number of nickels
			while(a>=5){
				a=a-5;
				numberofnickle=numberofnickle+1;
			}
//Count the number of cents
			while(a>=1){
				a=a-1;
				numberofcent=numberofcent+1;
			}
			
			
//Case 1: If there is only 1 quarter
			if(numberofquarter==1){
//Case 1(1): If there is no dime & nickel & cent
				if(numberofdime==0 && numberofnickle==0 && numberofcent==0){
					printf(" %d quarter.", numberofquarter);
				}
//Case 1(2): If there is some dime or nickel or cent
				else{
					printf(" %d quarter,", numberofquarter);
				}
			}
//Case 2: If there is more than 1 quarter
			else if(numberofquarter>1){
//Case 2(1): If there is no dime & nickel & cent
				if(numberofdime==0 && numberofnickle==0 && numberofcent==0){
					printf(" %d quarters.", numberofquarter);
				}
//Case 2(2): If there is some dime or nickel or cent
				else{
					printf(" %d quarters,", numberofquarter);
				}
			}
				
				
//Case 3: If there is only 1 dime
			if(numberofdime==1){
//Case 3(1): If there is no nickel & cent
				if(numberofnickle==0 && numberofcent==0){
					printf(" %d dime.", numberofdime);
				}
//Case 3(2): If there is some nickel or cent
				else{
					printf(" %d dime,", numberofdime);
				}
			}
//Case 4: If there is more than 1 dime
			else if(numberofdime>1){
//Case 4(1): If there is no nickel & cent
				if(numberofnickle==0 && numberofcent==0){
					printf(" %d dimes.", numberofdime);
				}
//Case 4(2): If there is some nickel or cent
				else{
					printf(" %d dimes,", numberofdime);
				}
			}
				
				
				
//Case 5: If there is only 1 nickel
			if(numberofnickle==1){
//Case 5(1): If there is no cent
				if(numberofcent==0){
					printf(" %d nickel.", numberofnickle);
				}
//Case 5(2): If there is some cent
				else{
					printf(" %d nickel,", numberofnickle);
				}
			}
//Case 6: If there is more than 1 nickel
			else if(numberofnickle>1){
//Case 6(1): If there is no cent
				if(numberofcent==0){
					printf(" %d nickels.", numberofnickle);
				}
//Case 6(2): If there is some cent
				else{
					printf(" %d nickels,", numberofnickle);
				}
			}
				
				
//Case 7: If there is only 1 cent
			if(numberofcent==1){
				printf(" %d cent.", numberofcent);
				}
//Case 8: If there is more than 1 cent
			else if(numberofcent>1){
				printf(" %d cents.", numberofcent);					
				}
				
			
//Ask the users whether want to continue
	printf("\nPlease give an amount in cents less than 100: ");
	scanf("%d", &a);
		
		if(a>1 && a<100){
			printf("%d cents:", a);
//Re-assign 0 to all variable for next loop
			numberofquarter=0;
			numberofdime=0;
			numberofnickle=0;
			numberofcent=0;
		}
	}
//When users type some number not in [1,100], then we will jump from the while loop
	printf("Goodbye");
	
	return 0;
}
