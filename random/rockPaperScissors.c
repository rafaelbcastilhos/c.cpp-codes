// hand game, rock, paper or scissors
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROCK 1
#define PAPER 2
#define SCISSORS 3

// functions prototype
int printItem(int aux);
int check(int player, int computer);

int main(){
	int pickPlayer, pickComputer, i;
	
	printf("[1] - rock");
	printf("\n[2] - paper");
	printf("\n[3] - scissors");
	printf("\n-----> ");
	scanf("%d", &pickPlayer);
	
	srand(time(NULL));
	pickComputer = rand()%3+1;
	
	printItem(pickPlayer); // pick player
	printf("x");
	printItem(pickComputer); // pick computer
	
	int winner = check(pickPlayer, pickComputer);
	
	if(winner == 1)
		printf("\n-----> player won!");
	else if(winner == 2)
		printf("\n-----> computer won!");
	else
		printf("\n-----> draw!");
}

int printItem(int aux){
	if(aux == ROCK)
		printf("  rock  ");
	else if(aux == PAPER)
		printf("  paper  ");

	else if(aux == SCISSORS)
		printf("  scissors  ");
	else
		return 0;

}

int check(int player, int computer){
	int winner;
	
	if(player == computer)
		winner = 0;
	
	// playerayer won
	if(player == ROCK && computer == SCISSORS)
		winner = 1;
	
	if(player == SCISSORS && computer == PAPER)
		winner = 1;
	
	if(player == PAPER && computer == ROCK)
		winner = 1;
	
	// computer won
	if(player == ROCK && computer == PAPER)
		winner = 2;
	
	if(player == PAPER && computer == SCISSORS)
		winner = 2;
	
	if(player == SCISSORS && computer == ROCK)
		winner = 2;
	
	return winner;
}
