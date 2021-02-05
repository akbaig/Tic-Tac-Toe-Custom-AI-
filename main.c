/*
 * main.c
 *
 *  Created on: Dec 15, 2018
 *      Author: ahmad
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "functions.h"
#include "easy.h"
#include "normal.h"
#include "impossible.h"


int main()
{
	srand (time(NULL));
	char yn; int again = 1, draws = 0, wins1 = 0, wins2 = 0, dmode = 0;
	printf("Welcome to\n\n");
	printf(" _________   _   _____      _________   _____   _____       _________   ______   ____\n");
	printf("|         | | | |  __/     |         | |  _  | | ___/      |         | |  __  | |  __|\n");
	printf("    | |     | | | |            | |     | | | | | |             | |     | |  | | | |__\n");
	printf("    | |	    | | | |            | |     | |_| | | |             | |     | |  | | |  __|\n");
	printf("    | |     | | | |__          | |     | | | | | |__           | |     | |__| | | |__ \n");
	printf("    |_|     |_| |____\\         |_|     |_| |_| |____\\          |_|     |______| |____|   (by Akbaig)\n\n");
	while(again == 1)
	{
		if(dmode == 0)
		{
			do
			{
				if(dmode != 0) printf("Wrong input! Select an appropriate difficulty level:\n\n1. Easy\n2. Normal\n3. Impossible\n");
				else
				{
					printf("Select difficulty level:\n\n1. Easy\n2. Normal\n3. Impossible\n");
				}
				fflush(stdout);
				scanf("%d", &dmode);
			}while(dmode < 1 || dmode > 3);
			if(dmode == 1) printf("\n>> Computer: I'll go easy on you! :)\n\n");
			if(dmode == 2) printf("\nComputer: Up for some challenge, eh? ;)\n\n");
			if(dmode == 3) printf("\nComputer: You aint gonna win, wrong choice! :>\n\n");
		}
		else
		{
			again = 0;
			int won = 0;
			int slots[9] = {0}, input, terminate = 0;
			char cslots[9] = {' '}, cinput;
			printf("Remeber these positions while playing.\n\n");
			printf(" ___________\n");
			printf("| 1 | 2 | 3 |\n");
			printf("|___|___|___|\n");
			printf("| 4 | 5 | 6 |\n");
			printf("|___|___|___|\n");
			printf("| 7 | 8 | 9 |\n");
			printf("|___|___|___|\n");
			printf("\nYou are cross (x) and Computer is circle(o)\n");
			int turn = rand()%2;
			if(turn == 0) printf("\nIts computer's turn! ");
			else printf("\nIts your turn!\n ");
			while(terminate != 9 && won == 0)
			{
				if(!(turn == 0 && terminate == 0))
				{
					printf("\nEnter a position to make your move (1 to 9): ");fflush(stdout);
					scanf(" %c", &cinput);
					input = cinput - '0';
					while(!isdigit(cinput) ||input < 1 || input > 9 || slots[input-1] != 0)
					{
						printf("Wrong Input! Enter an appropriate position: ");fflush(stdout);
						scanf(" %c", &cinput);
						input = cinput - '0';
					}
					input--;
					slots[input] = 1;
				}
				won = Match(slots);
				if(won == 0)
				{
					if(dmode == 1) EasyMove(slots);
					if(dmode == 2) NormalMove(slots);
					if(dmode == 3) ImpossibleMove(slots);
				}
				terminate = 0;
				for(int i = 0; i < 9; i++)
				{
					if(slots[i] != 0) terminate++;
					if(slots[i] == 1) cslots [i] = 'x';
					if(slots[i] == 2) cslots[i] = 'o';
				}
				puts("");
				printf(" ___________\n");
				printf("| %c | %c | %c |\n", cslots[0], cslots[1], cslots[2]);
				printf("|___|___|___|\n");
				printf("| %c | %c | %c |\n", cslots[3], cslots[4], cslots[5]);
				printf("|___|___|___|\n");
				printf("| %c | %c | %c |\n", cslots[6], cslots[7], cslots[8]);
				printf("|___|___|___|\n");
				won = Match(slots);
				if(won == 1)
				{
					printf("\nYou have won!");
					wins1++;
				}
				else if(won == 2)
				{
					printf("\nComputer has won!");
					wins2++;
				}
				else if(terminate == 9)
				{
					printf("\nIt's a draw.");
					draws++;
				}

			}
			printf("\n\nDo you want to play again (Y/N/D)? ");
			printf("(Note: Type \" D \" to select difficulty).. ");fflush(stdout);
			scanf(" %c", &yn);
			while(toupper(yn) != 'Y' && toupper(yn) != 'N' && toupper(yn) != 'D')
			{
				printf("Couldn't understand! Type (Y/N/D) to decide.");fflush(stdout);
				scanf(" %c", &yn);
			}
			if(toupper(yn) == 'D')
			{
				dmode = 0;
				again = 1;
				puts("");
			}
			if(toupper(yn) == 'Y')
			{
				again = 1;
				printf("\n\n\n\n");
			}
		}

	}
	printf("\nTotal number of games won: %d", wins1);
	printf("\nTotal number of games lost: %d", wins2);
	printf("\nTotal number of draws: %d", draws);
	printf("\n----------------\nPress enter to exit the game!");
	return 0;
}
