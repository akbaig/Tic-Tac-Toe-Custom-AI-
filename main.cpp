#include <iostream>
#include <time.h>
#include "comp.h"
#include <stdlib.h>

using namespace std;



int main()
{
	srand(time_t(NULL));

	int slots[9] = { 0 }, pos, terminate = 0;
	cout << "Welcome to Tic Tac Toe (by akbaig)\n\n" << "Remember these positions while playing:\n\n";
	cout << "| 1 | 2 | 3 |\n";
	cout << "-------------\n";
	cout << "| 4 | 5 | 6 |\n";
	cout << "-------------\n";
	cout << "| 7 | 8 | 9 |\n\n";
	while (terminate == 0)
	{
		cout << "Enter position to make your move: ";
		cin >> pos;
		while (slots[pos - 1] != 0 || (pos < 1 && pos > 9))
		{
			cout << "Wrong position! Enter a correct position: ";
			cin >> pos;
		}
		slots[pos - 1] = 'x';
		if (MatchCheck(slots) == 0 && TurnCount(slots) != 9)
		{
			Calculation(slots);
			if (MatchCheck(slots) != 0 || TurnCount(slots) >= 9) terminate = 1;
		}
		else terminate = 1;
		cout << "| " << char(slots[0]) << " | " << char(slots[1]) << " | " << char(slots[2]) << " |\n";
		cout << "-------------\n";
		cout << "| " << char(slots[3]) << " | " << char(slots[4]) << " | " << char(slots[5]) << " |\n";
		cout << "-------------\n";
		cout << "| " << char(slots[6]) << " | " << char(slots[7]) << " | " << char(slots[8]) << " |\n\n";
	}
	if (MatchCheck(slots) == 1) cout << "\nYou won!\n";
	else if(MatchCheck(slots) == 2) cout << "\nComputer won!\n";
	else cout << "\nIt's a draw!\n";
	system("pause");
	return 0;
}
