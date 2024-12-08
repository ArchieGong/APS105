#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool positionInBounds(int n, int row, int col){
	bool ifLieInBoard = false;
	if(row<n && row>=0 && col<n && col>=0){
		ifLieInBoard = true;
	}
    return ifLieInBoard;  
}

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
	printf("  ");
	for(int letter=0; letter<n; letter++){
	printf("%c", 'a'+letter);
	}
	printf("\n");
	for(rowPB=0; rowPB<n; rowPB++){
		printf("%c ", 'a'+rowPB);
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



bool isGameOverForOne(char board[26][26], int n, char color){
	bool gameNotOver = false;
	
	for(int checkRow=0; checkRow<n; checkRow++){
		for(int checkCol=0; checkCol<n; checkCol++){
			if(checkAllDirection(board, n, checkRow, checkCol, color)){
			gameNotOver = true;
			}
		}
	}
return gameNotOver;
}

int result(char board[26][26], int n){
	int result1=0;
	int whiteNum=0;
	int blackNum=0;
	for(int checkRow=0; checkRow<n; checkRow++){
		for(int checkCol=0; checkCol<n; checkCol++){
			if(board[checkRow][checkCol]=='B'){
				blackNum=blackNum+1;
			}
			else if(board[checkRow][checkCol]=='W'){
				whiteNum=whiteNum+1;
			}
		}
	}
	
	if(whiteNum==blackNum){
		result1=0;
	}
	else if(whiteNum < blackNum){
		result1=-1;
	}
	else if(whiteNum > blackNum){
		result1=1;
	}
	
	return result1;
}


char changeTurn(char turn){
	char turn1='B';
	if(turn=='B'){
		turn1 = 'W';
	}
	else if(turn=='W'){
		turn1 = 'B';
	}
return turn1;
}


int countFile(const char board[26][26], int n, char color){
	int number1=0;
	for(int checkRow=0; checkRow<n; checkRow++){
		for(int checkCol=0; checkCol<n; checkCol++){
			if(board[checkRow][checkCol]==color){
				number1=number1+1;
			}
		}
	}
return number1;
}



//char* copyBoard(const char board[26][26], int n){
//	char temBoard[26][26];
//	for(int checkRow=0; checkRow<n; checkRow++){
//		for(int checkCol=0; checkCol<n; checkCol++){
//			temBoard[checkRow][checkCol]=board[checkRow][checkCol];
//		}
//	}
//return temBoard;
//}



int makeMove(const char board[26][26], int n, char turn, int *row, int *col){
	int previous=0;
	int after=0;
	int biggestScore=0;
	int score=0;
	char afterBoard[26][26];
	for(int checkRow=0; checkRow<n; checkRow++){
		for(int checkCol=0; checkCol<n; checkCol++){
			if(checkAllDirection(board, n, checkRow, checkCol, turn)){
				previous = countFile(board, n, turn);
				
			for(int checkRow=0; checkRow<n; checkRow++){
				for(int checkCol=0; checkCol<n; checkCol++){
					afterBoard[checkRow][checkCol]=board[checkRow][checkCol];
				}
			}
				
				fileAllDirection(afterBoard, n, checkRow, checkCol, turn);
				after = countFile(afterBoard, n, turn);
				score=after-previous-1;
				if(biggestScore<score){
				biggestScore=score;
				*row=checkRow;
				*col=checkCol;
				}
			}
		}
	}
return score;	
}


int main()
{
	int rowBest=0; 
	int colBest=0;
	int dimension;
	char initialBoard[26][26];
	char computerColor[2];
	char turn='B';
	char userInput[3];
	bool gameOver1=false;
	printf("Enter the board dimension: ");
	scanf("%d", &dimension);
	
	printf("Computer plays (B/W) : ");
	scanf("%s", computerColor);
	
	char playerColor;
	if(*computerColor=='W'){
	playerColor='B';
	}
	else if(*computerColor=='B'){
	playerColor='W';
	}
	
	
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
	
while(isGameOverForOne(initialBoard, dimension, 'W') || isGameOverForOne(initialBoard, dimension, 'B')){
	if(turn==*computerColor){
		makeMove(initialBoard, dimension, *computerColor, &rowBest, &colBest);
		fileAllDirection(initialBoard, dimension, rowBest, colBest, *computerColor);
		printf("Computer places %c at %c%c.\n", *computerColor, 'a'+rowBest, 'a'+colBest);
		printBoard(initialBoard, dimension);
	}
	else if(turn==playerColor){
		printf("Enter move for colour %c (RowCol): \n", playerColor);
		scanf("%s", userInput);
		if(checkAllDirection(initialBoard, dimension, (*(userInput)-'a'), (*(userInput+1)-'a'), playerColor)){
			fileAllDirection(initialBoard, dimension, (*(userInput)-'a'), (*(userInput+1)-'a'), playerColor);
			printBoard(initialBoard, dimension);
		}
		else{
			printf("Invalid move.\n");
			printf("%c player wins.\n", *computerColor);
			gameOver1=true;
				for(int checkRow22=0; checkRow22<dimension; checkRow22++){
					for(int checkCol22=0; checkCol22<dimension; checkCol22++){
						initialBoard[checkRow22][checkCol22]='B';
					}
				}
		}
	}
	
	if (gameOver1==false){
		if(isGameOverForOne(initialBoard, dimension, changeTurn(turn))==true){
			turn=changeTurn(turn);
		}
		else if(isGameOverForOne(initialBoard, dimension, turn)==true){
			turn=turn;
		}
		else if((isGameOverForOne(initialBoard, dimension, 'W')==false) || (isGameOverForOne(initialBoard, dimension, 'B')==false)){
			if(result(initialBoard, dimension)==0){
				printf("Draw!");
			}
			else if(result(initialBoard, dimension)==-1){
				printf("B player wins.");
			}
			else if(result(initialBoard, dimension)==1){
				printf("W player wins.");
			}
		}
	}
	
}
	
	
	return 0;
}