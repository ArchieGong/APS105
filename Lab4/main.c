	#include <stdio.h>
	#include <stdbool.h>
	#include <math.h>
	#include <stdlib.h>
	#include <time.h>
	//Full Name: Jiawei Gong
	//Student Number: 1007249951
	//This program will help the user to calculate the future value of the investment
	
	int main(int argc, char **argv)
{
	if(argc==1)
	srand(time(NULL));
	else
	srand(atoi(argv[1]));
	//make the seed depend on time
	
	//The data type of the following 4 varibles is double and integer "a"
	int FirstCardDealer=1+rand()%13;
	int FirstCardPlayer=1+rand()%13;
	int SumOfDealer=0;
	int SumOfPlayer=0;
	int a;
	int b = 1;
	//first time tell the user to choose 1 or 0
	printf("First cards: player %d, dealer %d\n", FirstCardPlayer, FirstCardDealer);
	printf("Type 1 for Hit, 0 to Stay:");
	scanf("%d", &a);
	//Start the first "if": First condition is when user choose hit in 1st time; Second condiiton is when user choose stop in 1st time
	if(a==1){
		
		if(FirstCardPlayer>10){
			SumOfPlayer=(floor(FirstCardPlayer/10)*10);
		}
		else{
			SumOfPlayer=FirstCardPlayer;
		}
	//Start the first while loop: when users to choose to hit and the current sum of player is less than 21			
		
		while(b==1 && SumOfPlayer<21){
			int rand1=1+rand()%13;
			if(rand1>10){
				SumOfPlayer=SumOfPlayer+(floor(rand1/10)*10);
			}
			else{
				SumOfPlayer=SumOfPlayer+rand1;
			}
			printf("Player gets a %d, worth is %d\n", rand1, SumOfPlayer);
			printf("Type 1 for Hit, 0 to Stay:");
			scanf("%d", &b);
		}
	//Start the second "if": First condition is when sum of player is greater than 21; Second condiiton is when user choose stop
		if(SumOfPlayer>21){
			printf("\nPlayers over 21, Dealer wins\n\n");
		}
		else if(b==0){
			SumOfDealer=FirstCardDealer;
			printf("Dealer gets:");
			while(SumOfDealer<17){
				int rand2=1+rand()%13;
				printf(" %d", rand2);
				if(rand2>10){
					SumOfDealer=SumOfDealer+(floor(rand2/10)*10);
				}
				else{
					SumOfDealer=SumOfDealer+rand2;
				}
			}
			if(SumOfDealer>21){
				printf("\nDealer over 21, Player wins\n\n");
			}
			else{
				if(SumOfDealer==SumOfPlayer){
					printf("\nTie!\n\n");
				}
				else if(SumOfDealer>SumOfPlayer){
					printf("\nDealer better than Player, Dealer wins\n\n");
				}
				else{
					printf("\nPlayer better than Player, Player wins\n\n");
				}
			}
		}
	}
	else if(a==0){
		SumOfDealer = FirstCardDealer;
		printf("Dealer gets:");
		while(SumOfDealer<17){
			int rand3=1+rand()%13;
			printf(" %d", rand3);
			if(rand3>10){
				SumOfDealer=SumOfDealer+(floor(rand3/10)*10);
			}
			else{
				SumOfDealer=SumOfDealer+rand3;
			}
			}
		if(SumOfDealer>21){
			printf("\nDealer over 21, player wins\n\n");
		}
		else{
			printf("\nDealer better than Player, Dealer wins\n\n");
		}
	}
	return 0;
}
