#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define BOARDROWS 9
#define BOARDCOLS 11

void asdf(int* row, int* column, int* orientation){
	printf("Invalid Input\n");
	*row = 0;
	*column = 0;
	*orientation = 0;
	printf("Give starting row, starting column and orientation (3 inputs) for ship of size=5:");
	scanf("%d", row);
	scanf("%d", column);
	scanf("%d", orientation);
	return;
}


void ghjk(int* row1, int* column1, int* orientation1){
	*row1 = getRand(1,9);
	*column1 = getRand(1,11);
	*orientation1 = getRand(0,1);
	return;
}



void populateBoard(bool getUserInput, int board[BOARDROWS+1][BOARDCOLS+1]){
		int row_5, column_5, orientation_5;
		int row_4, column_4, orientation_4;
		int row_3, column_3, orientation_3;
		int row_2, column_2, orientation_2;
		int row_1, column_1, orientation_1;
		printf("Rows are 1 -9, Columns are 1 -11\n");
		printf("Orientation is 0 for across, 1 for down");
		
		if(getUserInput){
			
			int check_5=0;
			printf("Give starting row, starting column and orientation (3 inputs) for ship of size=5:");
			scanf("%d", &row_5);
			scanf("%d", &column_5);
			scanf("%d", &orientation_5);
			while(check_5==0){
				if(row_5>5 && orientation_5==1)
					asdf(&row_5, &column_5, &orientation_5);
				else if(column_5>7 && orientation_5==0)
					asdf(&row_5, &column_5, &orientation_5);
				else if(row_5<1 || row_5>9 || orientation_5<0 || orientation_5>1 || column_5<1 || column_5>11)
					asdf(&row_5, &column_5, &orientation_5);
				else
				check_5=1;
			}
			for(int i5=0; i5<5; i5++){
				if(orientation_5==0)
				board[row_5-1][column_5-1+i5]=5;
				else if(orientation_5==1)
				board[row_5-1+i5][column_5-1]=5;
			}
////////////////////////////////////////////////////////////////////////
			printf("Give starting row, starting column and orientation (3 inputs) for ship of size=4:");
			scanf("%d", &row_4);
			scanf("%d", &column_4);
			scanf("%d", &orientation_4);
			int check_4=0;
			while(check_4==0){
				if(row_4>6 && orientation_4==1)
					asdf(&row_4, &column_4, &orientation_4);
				else if(column_4>8 && orientation_4==0)
					asdf(&row_4, &column_4, &orientation_4);
				else if(row_4<1 || row_4>9 || orientation_4<0 || orientation_4>1 || column_4<1 || column_4>11)
					asdf(&row_4, &column_4, &orientation_4);
				else if(orientation_4==0 && board[row_4-1][column_4-1]>0)
					asdf(&row_4, &column_4, &orientation_4);
				else if(orientation_4==1 && board[row_4-1][column_4-1]>0)
					asdf(&row_4, &column_4, &orientation_4);
				else if(orientation_4==0 && board[row_4-1][column_4-1+1]>0)
					asdf(&row_4, &column_4, &orientation_4);
				else if(orientation_4==0 && board[row_4-1][column_4-1+2]>0)
					asdf(&row_4, &column_4, &orientation_4);
				else if(orientation_4==0 && board[row_4-1][column_4-1+3]>0)
					asdf(&row_4, &column_4, &orientation_4);
				else if(orientation_4==1 && board[row_4-1+1][column_4-1]>0)
					asdf(&row_4, &column_4, &orientation_4);
				else if(orientation_4==1 && board[row_4-1+2][column_4-1]>0)
					asdf(&row_4, &column_4, &orientation_4);
				else if(orientation_4==1 && board[row_4-1+3][column_4-1]>0)
					asdf(&row_4, &column_4, &orientation_4);
					
				else{
				check_4=1;
				}
			}
			
			for(int i4=0; i4<4; i4++){
				if(orientation_4==0)
				board[row_4-1][column_4-1+i4]=4;
				else if(orientation_4==1)
				board[row_4-1+i4][column_4-1]=4;
			}
//////////////////////////////////
			
			
			printf("Give starting row, starting column and orientation (3 inputs) for ship of size=3:");
			scanf("%d", &row_3);
			scanf("%d", &column_3);
			scanf("%d", &orientation_3);
			int check_3=0;
			while(check_3==0){
			if(row_3>7 && orientation_3==1)
					asdf(&row_3, &column_3, &orientation_3);
			else if(column_3>9 && orientation_3==0)
					asdf(&row_3, &column_3, &orientation_3);
			else if(row_3<1 || row_3>9 || orientation_3<0 || orientation_3>1 || column_3<1 || column_3>11)
					asdf(&row_3, &column_3, &orientation_3);
					
			else if(orientation_3==0 && board[row_3-1][column_3-1]>0)
					asdf(&row_3, &column_3, &orientation_3);
			else if(orientation_3==0 && board[row_3-1][column_3-1+1]>0)
					asdf(&row_3, &column_3, &orientation_3);
			else if(orientation_3==0 && board[row_3-1][column_3-1+2]>0)
					asdf(&row_3, &column_3, &orientation_3);
			else if(orientation_3==1 && board[row_3-1][column_3-1]>0)
					asdf(&row_3, &column_3, &orientation_3);
			else if(orientation_3==1 && board[row_3-1+1][column_3-1]>0)
					asdf(&row_3, &column_3, &orientation_3);
			else if(orientation_3==1 && board[row_3-1+2][column_3-1]>0)
					asdf(&row_3, &column_3, &orientation_3);
			else
			check_3=1;
			}
			
			for(int i3=0; i3<3; i3++){
				if(orientation_3==0)
				board[row_3-1][column_3-1+i3]=3;
				else if(orientation_3==1)
				board[row_3-1+i3][column_3-1]=3;
			}
						
//////////////////////////////////
			
			printf("Give starting row, starting column and orientation (3 inputs) for ship of size=2:");
			scanf("%d", &row_2);
			scanf("%d", &column_2);
			scanf("%d", &orientation_2);
			int check_2=0;
			while(check_2==0){
			if(row_2>8 && orientation_2==1)
					asdf(&row_2, &column_2, &orientation_2);
			else if(column_2>10 && orientation_2==0)
					asdf(&row_2, &column_2, &orientation_2);
			else if(row_2<1 || row_2>9 || orientation_2<0 || orientation_2>1 || column_2<1 || column_2>11)
					asdf(&row_2, &column_2, &orientation_2);
					
			else if(orientation_2==0 && board[row_2-1][column_2-1]>0)
					asdf(&row_2, &column_2, &orientation_2);
			else if(orientation_2==0 && board[row_2-1][column_2-1+1]>0)
					asdf(&row_2, &column_2, &orientation_2);
			else if(orientation_2==1 && board[row_2-1][column_2-1]>0)
					asdf(&row_2, &column_2, &orientation_2);
			else if(orientation_2==1 && board[row_2-1+1][column_2-1]>0)
					asdf(&row_2, &column_2, &orientation_2);
			else
			check_2=1;
			}
			
			for(int i2=0; i2<2; i2++){
				if(orientation_2==0)
				board[row_2-1][column_2-1+i2]=2;
				else if(orientation_2==1)
				board[row_2-1+i2][column_2-1]=2;
			}
			
//////////////////////////////////

			printf("Give starting row, starting column and orientation (3 inputs) for ship of size=1:");
			scanf("%d", &row_1);
			scanf("%d", &column_1);
			scanf("%d", &orientation_1);
			int check_1=0;
			while(check_1==0){
			if(row_1>9 && orientation_1==1)
					asdf(&row_1, &column_1, &orientation_1);
			else if(column_1>11 && orientation_1==0)
					asdf(&row_1, &column_1, &orientation_1);
			else if(row_1<1 || row_1>9 || orientation_1<0 || orientation_1>1 || column_1<1 || column_1>11)
					asdf(&row_1, &column_1, &orientation_1);
					
			else if(orientation_1==0 && board[row_1-1][column_1-1]>0)
					asdf(&row_1, &column_1, &orientation_1);
			else if(orientation_1==1 && board[row_1-1][column_1-1]>0)
					asdf(&row_1, &column_1, &orientation_1);
			
			else
			check_1=1;
			}
			
			for(int i1=0; i1<1; i1++){
				if(orientation_1==0)
				board[row_1-1][column_1-1+i1]=1;
				else if(orientation_1==1)
				board[row_1-1+i1][column_1-1]=1;
			}

		}
		
/////////////////////////////////////////////////////////////			
/////////////////////////////////////////////////////////////			
/////////////////////////////////////////////////////////////			
/////////////////////////////////////////////////////////////			
/////////////////////////////////////////////////////////////	
		
		else if(getUserInput!=1){
//			int row_5, column_5, orientation_5;
//			int row_4, column_4, orientation_4;
//			int row_3, column_3, orientation_3;
//			int row_2, column_2, orientation_2;
//			int row_1, column_1, orientation_1;
			
			row_5 = getRand(1,11);
			column_5 = getRand(1,9);
			orientation_5 = getRand(0,1);
			
			int check_5=0;
			while(check_5==0){
				
				if(row_5>5 && orientation_5==1)
					ghjk(&row_5, &column_5, &orientation_5);
				else if(column_5>7 && orientation_5==0)
					ghjk(&row_5, &column_5, &orientation_5);
//				else if(row_5<1 || row_5>9 || orientation_5<0 || orientation_5>1 || column_5<1 || column_5>11)
//					asdf(&row_5, &column_5, &orientation_5);
				else
				check_5=1;
			}
			
			for(int i5=0; i5<5; i5++){
				if(orientation_5==0)
				board[row_5-1][column_5-1+i5]=5;
				else if(orientation_5==1)
				board[row_5-1+i5][column_5-1]=5;
			}
/////////////////////////////////////////////////////////////			
			
			row_4 = getRand(1,11);
			column_4 = getRand(1,9);
			orientation_4 = getRand(0,1);
			
			int check_4=0;
			while(check_4==0){
				if(row_4>6 && orientation_4==1)
					ghjk(&row_4, &column_4, &orientation_4);
				else if(column_4>8 && orientation_4==0)
					ghjk(&row_4, &column_4, &orientation_4);
//				else if(row_4<1 || row_4>9 || orientation_4<0 || orientation_4>1 || column_4<1 || column_4>11)
//					asdf(&row_4, &column_4, &orientation_4);
				else if(orientation_4==0 && board[row_4-1][column_4-1]>0)
					ghjk(&row_4, &column_4, &orientation_4);
				else if(orientation_4==1 && board[row_4-1][column_4-1]>0)
					ghjk(&row_4, &column_4, &orientation_4);
				else if(orientation_4==0 && board[row_4-1][column_4-1+1]>0)
					ghjk(&row_4, &column_4, &orientation_4);
				else if(orientation_4==0 && board[row_4-1][column_4-1+2]>0)
					ghjk(&row_4, &column_4, &orientation_4);
				else if(orientation_4==0 && board[row_4-1][column_4-1+3]>0)
					ghjk(&row_4, &column_4, &orientation_4);
				else if(orientation_4==1 && board[row_4-1+1][column_4-1]>0)
					ghjk(&row_4, &column_4, &orientation_4);
				else if(orientation_4==1 && board[row_4-1+2][column_4-1]>0)
					ghjk(&row_4, &column_4, &orientation_4);
				else if(orientation_4==1 && board[row_4-1+3][column_4-1]>0)
					ghjk(&row_4, &column_4, &orientation_4);
					
				else{
				check_4=1;
				}
			}
			
			for(int i4=0; i4<4; i4++){
				if(orientation_4==0)
				board[row_4-1][column_4-1+i4]=4;
				else if(orientation_4==1)
				board[row_4-1+i4][column_4-1]=4;
			}
/////////////////////////////////////////////////////////////	
			row_3 = getRand(1,11);
			column_3 = getRand(1,9);
			orientation_3 = getRand(0,1);
			
			int check_3=0;
			while(check_3==0){
			if(row_3>7 && orientation_3==1)
					ghjk(&row_3, &column_3, &orientation_3);
			else if(column_3>9 && orientation_3==0)
					ghjk(&row_3, &column_3, &orientation_3);
//			else if(row_3<1 || row_3>9 || orientation_3<0 || orientation_3>1 || column_3<1 || column_3>11)
//					asdf(&row_3, &column_3, &orientation_3);

			else if(orientation_3==0 && board[row_3-1][column_3-1]>0)
					ghjk(&row_3, &column_3, &orientation_3);
			else if(orientation_3==0 && board[row_3-1][column_3-1+1]>0)
					ghjk(&row_3, &column_3, &orientation_3);
			else if(orientation_3==0 && board[row_3-1][column_3-1+2]>0)
					ghjk(&row_3, &column_3, &orientation_3);
			else if(orientation_3==1 && board[row_3-1][column_3-1]>0)
					ghjk(&row_3, &column_3, &orientation_3);
			else if(orientation_3==1 && board[row_3-1+1][column_3-1]>0)
					ghjk(&row_3, &column_3, &orientation_3);
			else if(orientation_3==1 && board[row_3-1+2][column_3-1]>0)
					ghjk(&row_3, &column_3, &orientation_3);
			else
			check_3=1;
			}
			
			for(int i3=0; i3<3; i3++){
				if(orientation_3==0)
				board[row_3-1][column_3-1+i3]=3;
				else if(orientation_3==1)
				board[row_3-1+i3][column_3-1]=3;
			}
/////////////////////////////////////////////////////////////				
			row_2 = getRand(1,11);
			column_2 = getRand(1,9);
			orientation_2 = getRand(0,1);
			
			int check_2=0;
			while(check_2==0){
			if(row_2>8 && orientation_2==1)
					ghjk(&row_2, &column_2, &orientation_2);
			else if(column_2>10 && orientation_2==0)
					ghjk(&row_2, &column_2, &orientation_2);
//			else if(row_2<1 || row_2>9 || orientation_2<0 || orientation_2>1 || column_2<1 || column_2>11)
//					asdf(&row_2, &column_2, &orientation_2);
					
			else if(orientation_2==0 && board[row_2-1][column_2-1]>0)
					ghjk(&row_2, &column_2, &orientation_2);
			else if(orientation_2==0 && board[row_2-1][column_2-1+1]>0)
					ghjk(&row_2, &column_2, &orientation_2);
			else if(orientation_2==1 && board[row_2-1][column_2-1]>0)
					ghjk(&row_2, &column_2, &orientation_2);
			else if(orientation_2==1 && board[row_2-1+1][column_2-1]>0)
					ghjk(&row_2, &column_2, &orientation_2);
			else
			check_2=1;
			}
			
			for(int i2=0; i2<2; i2++){
				if(orientation_2==0)
				board[row_2-1][column_2-1+i2]=2;
				else if(orientation_2==1)
				board[row_2-1+i2][column_2-1]=2;
			}
/////////////////////////////////////////////////////////////		
			row_1 = getRand(1,11);
			column_1 = getRand(1,9);
			orientation_1 = getRand(0,1);
			
			int check_1=0;
			while(check_1==0){
			if(row_1>9 && orientation_1==1)
					ghjk(&row_1, &column_1, &orientation_1);
			else if(column_1>11 && orientation_1==0)
					ghjk(&row_1, &column_1, &orientation_1);
//			else if(row_1<1 || row_1>9 || orientation_1<0 || orientation_1>1 || column_1<1 || column_1>11)
//					asdf(&row_1, &column_1, &orientation_1);
					
			else if(orientation_1==0 && board[row_1-1][column_1-1]>0)
					ghjk(&row_1, &column_1, &orientation_1);
			else if(orientation_1==1 && board[row_1-1][column_1-1]>0)
					ghjk(&row_1, &column_1, &orientation_1);
			
			else
			check_1=1;
			}
			
			for(int i1=0; i1<1; i1++){
				if(orientation_1==0)
				board[row_1-1][column_1-1+i1]=1;
				else if(orientation_1==1)
				board[row_1-1+i1][column_1-1]=1;
			}
			
			
			
			
			
			
		}
	
	}




int main()
{

	return 0;
}
