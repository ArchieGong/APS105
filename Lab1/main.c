#include <stdio.h>
	//This program can calculte the (1)half the sum (2)twice the product (3)avergae of 3 numbers that you put in
	//Full Name: Jiawei Gong
	//Student Number: 1007249951
	int main()
{
	//The data type of the following 6 varibles is double
	double input_Number1;
	double input_Number2;
	double input_Number3;
	double Half_the_Sum;
	double Twice_the_Product;
	double Ave;

	//Use prinf function to tell what users should do
	//Then use scanf to  store the entered data in "input_Number1" in the for
	printf("Enter First Number:");
	scanf("%lf", &input_Number1);
	
	//Use prinf function to tell what users should do
	//Then use scanf to  store the entered data in "input_Number2" in the for
	printf("Enter Second Number:");
	scanf("%lf", &input_Number2);
	
	//Use prinf function to tell what users should do
	//Then use scanf to  store the entered data in "input_Number3" in the for
	printf("Enter Third Number:");
	scanf("%lf", &input_Number3);
	
	//Then use "=" to asign the last 3 variables with calculated values.
	Half_the_Sum = (input_Number1 + input_Number2 + input_Number3)/2;
	Twice_the_Product = (input_Number1 * input_Number2 * input_Number3)*2;
	Ave = (input_Number1 + input_Number2 + input_Number3)/3;
	
	//Use "printf" funcion to show the values of variables in the place of %.2lf
	//%.2lf specificies that the amount of numbers after decimal point is 2
	printf("Half the Sum: %.2lf\n", Half_the_Sum);
	printf("Twice the Product: %.2lf\n", Twice_the_Product);
	printf("Average: %.2lf\n", Ave);
	return 0;
}
