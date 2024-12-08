	#include <stdio.h>
	#include <math.h>
	//Full Name: Jiawei Gong
	//Student Number: 1007249951
	//This program will calculate the saved money and final charge when "for every 3 dollars spent, you get 10 cents cash back"
	
	int main()
{	
	//The data type of the following 2 varibles is double
	double the_price_per_pound;
	double the_total_weight;
	
	//Use prinf function to tell what users should do
	//Then use scanf to store the entered data in "the_price_per_pound"
	printf("Enter the price per pound:\n");
	scanf("%lf", &the_price_per_pound);
	
	//Use prinf function to tell what users should do
	//Then use scanf to store the entered data in "the_total_weight"
	printf("Enter the total weight:\n");
	scanf("%lf", &the_total_weight);
	
	//Calculate the value of (1)number of 3 dollars in the total price & (2)customer'saved money & (3)total charge
	int number_of_3dollars = (the_price_per_pound * the_total_weight)/3;
	double you_saved = number_of_3dollars * 0.1;
	double total_charge = (the_price_per_pound * the_total_weight) - you_saved;
	
	//Use "printf" funcion to show the values of variables in the place of %.2lf
	//%.2lf specificies that the amount of numbers after decimal point is 2
	printf("The total charge is: %.2lf\n", total_charge);
	printf("You saved: %.2lf\n", you_saved);
	
	return 0;
}
