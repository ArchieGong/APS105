	#include <stdio.h>
	#include <math.h>
	//Full Name: Jiawei Gong
	//Student Number: 1007249951
	//This program will help the cashier round the price the closest nickle
	
	int main()
{	
	//The data type of the following varible is double
	double the_price;
	
	//Use prinf function to tell what users should do
	//Then use scanf to store the entered data in "the_price"
	printf("Enter the price as a float with two decimals: ");
	scanf("%lf", &the_price);
	
	//Use "printf" funcion to show the values of variables in the place of %.2lf
	double the_total_charge = rint(the_price/0.05)*0.05;
	printf("The total charge is: %.2lf\n", the_total_charge);
	return 0;
}
