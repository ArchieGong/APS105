	#include <stdio.h>
	#include <math.h>
	//Full Name: Jiawei Gong
	//Student Number: 1007249951
	//This program will help the user to calculate the future value of the investment
	
	int main()
{	
	//The data type of the following 4 varibles is double
	double The_amount_deposited;
	double The_interest_rate;
	double The_number_of_times;
	double The_period_of_time;
	
	//Use prinf function to tell what users should do
	//Then use scanf to store the entered data in "The_amount_deposited"
	printf("The amount deposited P: ");
	scanf("%lf", &The_amount_deposited);
	
	//Use prinf function to tell what users should do
	//Then use scanf to store the entered data in "The_interest_rate"
	printf("The interest rate r: ");
	scanf("%lf", &The_interest_rate);
	
	//Use prinf function to tell what users should do
	//Then use scanf to store the entered data in "The_number_of_times"
	printf("The number of times the interest is compounded n: ");
	scanf("%lf", &The_number_of_times);
	
	//Use prinf function to tell what users should do
	//Then use scanf to store the entered data in "The_period_of_time"
	printf("The period of time t the money is invested (in years): ");
	scanf("%lf", &The_period_of_time);
	
	double the_future_value = The_amount_deposited * pow((1+(The_interest_rate/The_number_of_times)), The_number_of_times*The_period_of_time);
	printf("The future value of the investment A: %.2lf\n", the_future_value);
	return 0;
}
