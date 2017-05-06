#include "stdio.h"
#include "string.h"
#include "stdlib.h"

/*const nought=1;
const cross=2;
const border=3;
const empty=0;*/
enum{nought,cross,border,empty};
enum{hwin,cwin,draw};
const int directions[4]={1,5,4,6};
const int convertTo25[9]={
	6,7,8,
	11,12,13,
	16,17,18
};
const int inMiddle = 4;
const int corners[4] = { 0, 2, 6, 8 };
int  GetNumForDir(int start,const int dir,const int *board,const int us){
	int found=0;
	while(board[start]!=border){
		if(board[start]!=us)
			break;
		found++;
		start+=dir;
	}
	return found;
}
int FindThreeInARow(const int *board,const int ourindex,const int us){
	int dirIndex=0;
	int dir=0;
	int count=1;
	for(dirIndex=0;dirIndex<4;dirIndex++){
		dir=directions[dirIndex];
		count+=GetNumForDir(ourindex+dir,dir,board,us);
		count+=GetNumForDir(ourindex+dir*-1,dir*-1,board,us);
		if(count==3)
			break;
		count=1;
	}
	return count;

}

void InitBoard(int *board){
	int i=0;
	for(i=0;i<25;i++)
		board[i]=border;
	for(i=0;i<9;i++)
		board[convertTo25[i]]=empty;
}

void PrintBoard(const int *board){
	int i=0;
	char symbols[]="0X|-";
	printf("Board:\n");
	for(i=0;i<9;i++){
		if(i!=0 && i%3==0)
			printf("\n\n");
		printf("%4c",symbols[board[convertTo25[i]]]);
	}
	printf("\n");
}
int HasEmpty(const int *board){
	int i;
	for(i=0;i<9;i++)
		if(board[convertTo25[i]]==empty)
			return 1;
	return 0;	
}
void MakeMove(int *board,const int pos,const side){
	board[pos]=side;
}
int GetNextBest(const int *board){
	int ourMove=convertTo25[inMiddle];
	if(board[ourMove]==empty)
		return ourMove;
	int i=0;
	ourMove=-1;
	for(i=0;i<4;i++){
		ourMove=convertTo25[corners[i]];
		if(board[ourMove]==empty)
			break;
		ourMove=-1;
	}
	return ourMove;
}
int GetWinningMove(int *board,const int side){
	int ourMove=-1;
	int winFound=0;
	int i=0;
	for(i=0;i<9;i++){
		if(board[convertTo25[i]]==empty){
			ourMove=convertTo25[i];
			board[ourMove]=side;
			if(FindThreeInARow(board,ourMove,side)==3)
				winFound=1;
		}
		board[ourMove]=empty;
		if(winFound==1)
			break;
		ourMove=-1;
	}
	return ourMove;


}
int GetComputerMove(int *board,const int side){
	int i,free=0,avail[9],compmove;
	compmove=GetWinningMove(board,side);
	if(compmove!=-1)
		return compmove;
	compmove=GetWinningMove(board,side^1);
	if(compmove!=-1)
		return compmove;
	compmove=GetNextBest(board);
	if(compmove!=-1)
		return compmove;
	for(i=0;i<9;i++)
		if(board[convertTo25[i]]==empty)
			avail[free++]=convertTo25[i];
	compmove=(rand()%free);
	return avail[compmove];	
}
int GetHumanMove(const int *board){
	char input[4];
	int moveOk=0;
	int move =-1;

	while(moveOk==0){
		printf("Enter a move from 1 to 9:\n");
		fgets(input,3,stdin);
		fflush(stdin);
		if(strlen(input)!=2){
			printf("Invalid strlen()\n");
			continue;
		}
		if(sscanf(input,"%d",&move)!=1){
			move=-1;
			printf("Invalid sscanf()\n");
			continue;
		}
		if(move<1||move>9){
			move=-1;
			printf("Invalid range\n");
			continue;
		}
		move--;
		if(board[convertTo25[move]]!=empty){
			move=-1;
			printf("Square already filled!!!\n");
			continue;
		}
		moveOk=1;
	}
	printf("Move made...%d\n",(move+1));
	return convertTo25[move];

}

void RunGame(){
	int gameOver=0;
	int side=nought;
	int lastMoveMade=0;
	int board[25];
	InitBoard(&board[0]);
	PrintBoard(&board[0]);

	while(!gameOver){
		if(side==nought){
			lastMoveMade=GetHumanMove(&board[0]);
			MakeMove(&board[0],lastMoveMade,side);
			side=cross;
		}
		else{
			lastMoveMade=GetComputerMove(&board[0],side);
			MakeMove(&board[0],lastMoveMade,side);
			side=nought;
			PrintBoard(&board[0]);
		}
		if(FindThreeInARow(board,lastMoveMade,side^1)==3){
			printf("Game Over\n");
			gameOver=1;
			if(side==nought)
				printf("Computer wins\n");
			else printf("Human wins\n");
		}
		if(!HasEmpty(board)){
			printf("Game Over\n");
			gameOver=1;
			printf("Its a draw\n");
		}

	}
	PrintBoard(&board[0]);
	//gameOver=-1;
}
int main(){
	srand(time(NULL));
	RunGame();
}