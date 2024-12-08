/*
 * File:        project_reversi_skeleton.c
 * Author:      APS105H1 Teaching Team
 * Modified by: * Jiawei Gong *
 *
 * Date: Jan 2021
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "project_reversi_skeleton.h" // DO NOT modify this line

// Note: You may want to add more function declarations here
// =========   Function declaration  ==========
/* None for now */
bool checkIfEmpty(char board[][26], int row, int col){
	bool IfEmpty = false;
	if(board[row][col]=='U'){
		IfEmpty = true;
	}
	else{
		IfEmpty = false;
	}
return IfEmpty;
}

bool checkIfOppositeColor(char board[][26], int row, int col, char colour, int n){
	bool IfOppositeColor=false;
	if(positionInBounds(n, row, col)!=true){
		IfOppositeColor=false;
	}
	else{
	if(colour=='W'){
		if(board[row][col] == 'B'){
			IfOppositeColor=true;
		}
		else if(board[row][col] == 'W'){
			IfOppositeColor=false;
		}
		else if(board[row][col] == 'U'){
			IfOppositeColor=false;
		}
	}
	else if(colour=='B'){
		if(board[row][col] == 'W'){
			IfOppositeColor=true;
		}
		else if(board[row][col] == 'B'){
			IfOppositeColor=false;
		}
		else if(board[row][col] == 'U'){
			IfOppositeColor=false;
		}
	}
//	else if(board[row][col] == 'U'){
//		IfOppositeColor=false;
	}
	
		
return IfOppositeColor;
}

bool checkIfSameColor(char board[][26], int row, int col, char colour){
	bool IfSameColor=true;
	if(colour=='W')
		IfSameColor = board[row][col] == 'W';
	else if(colour=='B')
		IfSameColor = board[row][col] == 'B';
return IfSameColor;
}
// ========= Function implementation ==========
/*
 * Function:  printBoard 
 * --------------------
 * Print the whole board to the terminal window.
 */
void printBoard(char board[][26], int n){
	int rowPB, columnPB;
	for(rowPB=0; rowPB<n; rowPB++){
		for(columnPB=0; columnPB<n; columnPB++){
			printf("%c", board[rowPB][columnPB]);
		}
		printf("\n");
	}
	(void)board;
    (void)n;
}

/*
 * Function:  positionInBounds 
 * --------------------
 * Checks whether the specified (row, col) lies within the board dimensions.
 */
bool positionInBounds(int n, int row, int col) {
	bool ifLieInBoard = false;
	if(row<n && row>=0 && col<n && col>=0){
		ifLieInBoard = true;
	}
//	
//    (void)n;
//    (void)row;
//    (void)col;
    return ifLieInBoard;  
}

/*
 * Function:  checkLegalInDirection 
 * --------------------
 * Checks whether (row, col) is a legal position for a tile of colour by “looking” in the direction 
 * specified by deltaRow and deltaCol.
 */
bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol){
	bool ifLegalInDirection=false;
	if(checkIfEmpty(board, row, col)){
		if(board[row+deltaRow][col+deltaCol]==colour){
			ifLegalInDirection=false;
		}
		else{
			if(deltaRow==-1 && deltaCol==-1){
			while(checkIfOppositeColor(board, row+deltaRow, col+deltaCol, colour, n) && positionInBounds(n, row+deltaRow, col+deltaCol)){
			deltaRow=deltaRow-1;
			deltaCol=deltaCol-1;
			}
			}
			else if(deltaRow==-1 && deltaCol==0){
			while(checkIfOppositeColor(board, row+deltaRow, col+deltaCol, colour, n) && positionInBounds(n, row+deltaRow, col+deltaCol)){
			deltaRow=deltaRow-1;
			deltaCol=deltaCol+0;
			}
			}
			else if(deltaRow==-1 && deltaCol==1){
			while(checkIfOppositeColor(board, row+deltaRow, col+deltaCol, colour, n) && positionInBounds(n, row+deltaRow, col+deltaCol)){
			deltaRow=deltaRow-1;
			deltaCol=deltaCol+1;
			}
			}
			else if(deltaRow==0 && deltaCol==-1){
			while(checkIfOppositeColor(board, row+deltaRow, col+deltaCol, colour, n) && positionInBounds(n, row+deltaRow, col+deltaCol)){
			deltaRow=deltaRow+0;
			deltaCol=deltaCol-1;
			}
			}
			else if(deltaRow==0 && deltaCol==1){
			while(checkIfOppositeColor(board, row+deltaRow, col+deltaCol, colour, n) && positionInBounds(n, row+deltaRow, col+deltaCol)){
			deltaRow=deltaRow+0;
			deltaCol=deltaCol+1;
			}
			}
			else if(deltaRow==1 && deltaCol==-1){
			while(checkIfOppositeColor(board, row+deltaRow, col+deltaCol, colour, n) && positionInBounds(n, row+deltaRow, col+deltaCol)){
			deltaRow=deltaRow+1;
			deltaCol=deltaCol-1;
			}
			}
			else if(deltaRow==1 && deltaCol==0){
			while(checkIfOppositeColor(board, row+deltaRow, col+deltaCol, colour, n) && positionInBounds(n, row+deltaRow, col+deltaCol)){
			deltaRow=deltaRow+1;
			deltaCol=deltaCol+0;
			}
			}
			else if(deltaRow==1 && deltaCol==1){
			while(checkIfOppositeColor(board, row+deltaRow, col+deltaCol, colour, n) && positionInBounds(n, row+deltaRow, col+deltaCol)){
			deltaRow=deltaRow+1;
			deltaCol=deltaCol+1;
			}
			}
		
		if(board[row+deltaRow][col+deltaCol]==colour){
			ifLegalInDirection=true;
		}
		else if(board[row+deltaRow][col+deltaCol]=='U'){
			ifLegalInDirection=false;
		}
		else if(positionInBounds(n, row+deltaRow, col+deltaCol)==false){
			ifLegalInDirection=false;
		}
		}
		
	}
	else{
		ifLegalInDirection=false;
	}
//    (void)board;
//    (void)n;
//    (void)row;
//    (void)col;
//    (void)colour;
//    (void)deltaRow;
//    (void)deltaCol;
    return ifLegalInDirection;             
}

bool checkAllDirection(char board[][26], int n, int row, int col, char colour){
	bool ifAllValid=true;
	if( \
	checkLegalInDirection(board, n, row, col, colour, -1, -1) || \
	checkLegalInDirection(board, n, row, col, colour, -1, 0) || \
	checkLegalInDirection(board, n, row, col, colour, -1, 1) || \
	checkLegalInDirection(board, n, row, col, colour, 0, -1) || \
	checkLegalInDirection(board, n, row, col, colour, 0, 1) || \
	checkLegalInDirection(board, n, row, col, colour, 1, -1) || \
	checkLegalInDirection(board, n, row, col, colour, 1, 0) || \
	checkLegalInDirection(board, n, row, col, colour, 1, 1)){
		ifAllValid=true;
	}
	else{
		ifAllValid=false;
	}
	return ifAllValid;
}

void filpUpInOneDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol){
	if(checkLegalInDirection(board, n, row, col, colour, deltaRow, deltaCol)){
		board[row][col]=colour;
		if(colour=='W'){
		while(board[row+deltaRow][col+deltaCol]=='B'){
			board[row+deltaRow][col+deltaCol]='W';
			if(deltaRow==-1 && deltaCol==-1){
			deltaRow=deltaRow-1;
			deltaCol=deltaCol-1;
			}
			else if(deltaRow==-1 && deltaCol==0){
			deltaRow=deltaRow-1;
			deltaCol=deltaCol+0;
			}
			else if(deltaRow==-1 && deltaCol==1){
			deltaRow=deltaRow-1;
			deltaCol=deltaCol+1;
			}
			else if(deltaRow==0 && deltaCol==-1){
			deltaRow=deltaRow+0;
			deltaCol=deltaCol-1;
			}
			else if(deltaRow==0 && deltaCol==1){
			deltaRow=deltaRow+0;
			deltaCol=deltaCol+1;
			}
			else if(deltaRow==1 && deltaCol==-1){
			deltaRow=deltaRow+1;
			deltaCol=deltaCol-1;
			}
			else if(deltaRow==1 && deltaCol==0){
			deltaRow=deltaRow+1;
			deltaCol=deltaCol+0;
			}
			else if(deltaRow==1 && deltaCol==1){
			deltaRow=deltaRow+1;
			deltaCol=deltaCol+1;
			}
		}
		}
		else if(colour=='B'){
			while(board[row+deltaRow][col+deltaCol]=='W'){
			board[row+deltaRow][col+deltaCol]='B';
			if(deltaRow==-1 && deltaCol==-1){
			deltaRow=deltaRow-1;
			deltaCol=deltaCol-1;
			}
			else if(deltaRow==-1 && deltaCol==0){
			deltaRow=deltaRow-1;
			deltaCol=deltaCol+0;
			}
			else if(deltaRow==-1 && deltaCol==1){
			deltaRow=deltaRow-1;
			deltaCol=deltaCol+1;
			}
			else if(deltaRow==0 && deltaCol==-1){
			deltaRow=deltaRow+0;
			deltaCol=deltaCol-1;
			}
			else if(deltaRow==0 && deltaCol==1){
			deltaRow=deltaRow+0;
			deltaCol=deltaCol+1;
			}
			else if(deltaRow==1 && deltaCol==-1){
			deltaRow=deltaRow+1;
			deltaCol=deltaCol-1;
			}
			else if(deltaRow==1 && deltaCol==0){
			deltaRow=deltaRow+1;
			deltaCol=deltaCol+0;
			}
			else if(deltaRow==1 && deltaCol==1){
			deltaRow=deltaRow+1;
			deltaCol=deltaCol+1;
			}
		}
	}
	}
	return;
}

void fileAllDirection(char board[][26], int n, int row, int col, char colour){
	filpUpInOneDirection(board, n, row, col, colour, -1, -1);
	filpUpInOneDirection(board, n, row, col, colour, -1, 0);
	filpUpInOneDirection(board, n, row, col, colour, -1, 1);
	filpUpInOneDirection(board, n, row, col, colour, 0, -1);
	filpUpInOneDirection(board, n, row, col, colour, 0, 1);
	filpUpInOneDirection(board, n, row, col, colour, 1, -1);
	filpUpInOneDirection(board, n, row, col, colour, 1, 0);
	filpUpInOneDirection(board, n, row, col, colour, 1, 1);
	return;
}

/*
 * Function:  makeMove 
 * --------------------
 * The player "turn" makes a move at (row, col).
 * Note: This function MUST NOT change board, only row and col can be changed to reflect the move.
 */
int makeMove(const char board[26][26], int n, char turn, int *row, int *col) {
    (void)board;
    (void)n;
    (void)turn;
    (void)row;
    (void)col;
    return 0;
}

#ifndef COMPETE_MODE // DO NOT DELETE THIS LINE
int main(void) {
    // Complete your main function here

//11111111111/11111111111/11111111111/11111111111/11111111111/11111111111
	int dimension;
	char initialBoard[26][26];
	printf("Enter the board dimension: ");
	scanf("%d", &dimension);
	
	int rowPut, columnPut;
	for(rowPut=0; rowPut<dimension; rowPut++){
		for(columnPut=0; columnPut<dimension; columnPut++){
			initialBoard[rowPut][columnPut]='U';
		}
	}
	initialBoard[dimension/2-1][dimension/2-1]='W';
	initialBoard[dimension/2][dimension/2]='W';
	initialBoard[dimension/2-1][dimension/2]='B';
	initialBoard[dimension/2][dimension/2-1]='B';
	
	printBoard(initialBoard, dimension);
	
//222222222222222222222222222222222222222222222222222222222222222222222222
//	char *userInput[50];
	char userInput[4];
	printf("Enter board configuration:\n");
	do{
	scanf("%s", userInput);
	initialBoard[*(userInput+1)-'a'][*(userInput+2)-'a']=*userInput;
	}
	while(*userInput!='!');
	
//	do{
//		scanf("%s", *(userInput+i));
//		i=i+1;
//	}
//	while(strcmp(*(userInput+i-1), "!!!")!=0);

	
	
//	for(int j=0; j<(i-1); j++){
//		initialBoard[*(userInput-j)[1]-'a'][*(userInput-j)[2]-'a']=*(userInput-j)[0];
//	}
//	
	printBoard(initialBoard, dimension);
	
	
	
//333333333333333333333333333333333333333333333333333333333333333333
	printf("Available moves for W:\n");
	for(int checkRow=0; checkRow<dimension; checkRow++){
		for(int checkCol=0; checkCol<dimension; checkCol++){
//			if(checkAllDirection(initialBoard, dimension, checkRow, checkCol, 'W')){
			if(checkLegalInDirection(initialBoard, dimension, checkRow, checkCol, 'W', -1, -1) || \
			checkLegalInDirection(initialBoard, dimension, checkRow, checkCol, 'W', -1, 0) || \
			checkLegalInDirection(initialBoard, dimension, checkRow, checkCol, 'W', -1, 1) || \
			checkLegalInDirection(initialBoard, dimension, checkRow, checkCol, 'W', 0, -1) || \
			checkLegalInDirection(initialBoard, dimension, checkRow, checkCol, 'W', 0, 1) || \
			checkLegalInDirection(initialBoard, dimension, checkRow, checkCol, 'W', 1, -1) || \
			checkLegalInDirection(initialBoard, dimension, checkRow, checkCol, 'W', 1, 0) || \
			checkLegalInDirection(initialBoard, dimension, checkRow, checkCol, 'W', 1, 1)){
			
			printf("%c%c\n", 'a'+checkRow, 'a'+checkCol);
			}
		}
	}
	
	printf("Available moves for B:\n");
	for(int checkRow=0; checkRow<dimension; checkRow++){
		for(int checkCol=0; checkCol<dimension; checkCol++){
			if(checkAllDirection(initialBoard, dimension, checkRow, checkCol, 'B')){
//			checkLegalInDirection(initialBoard[26][26], dimension, checkRow, checkCol, 'B', -1, -1)
//			checkLegalInDirection(initialBoard[26][26], dimension, checkRow, checkCol, 'B', -1, 0);
//			checkLegalInDirection(initialBoard[26][26], dimension, checkRow, checkCol, 'B', -1, 1);
//			checkLegalInDirection(initialBoard[26][26], dimension, checkRow, checkCol, 'B', 0, -1);
//			checkLegalInDirection(initialBoard[26][26], dimension, checkRow, checkCol, 'B', 0, 1);
//			checkLegalInDirection(initialBoard[26][26], dimension, checkRow, checkCol, 'B', 1, -1);
//			checkLegalInDirection(initialBoard[26][26], dimension, checkRow, checkCol, 'B', 1, 0);
//			checkLegalInDirection(initialBoard[26][26], dimension, checkRow, checkCol, 'B', 1, 1);
			
			printf("%c%c\n", 'a'+ checkRow, 'a'+ checkCol);
			}
		}
	}
	
////44444444444444444444444444444444444444444444444444444444444444444444444444444444
	char userFirstMove[4];
	printf("Enter a move:\n");
	scanf("%s", userFirstMove);
	if(checkAllDirection(initialBoard, dimension, userFirstMove[1]-'a', userFirstMove[2]-'a', userFirstMove[0]))
		printf("Valid move.\n");
	else
		printf("Invalid move.\n");
	
	fileAllDirection(initialBoard, dimension, userFirstMove[1]-'a', userFirstMove[2]-'a', userFirstMove[0]);
	printBoard(initialBoard, dimension);
	


    return 0;
}
#endif // DO NOT DELETE THIS LINE