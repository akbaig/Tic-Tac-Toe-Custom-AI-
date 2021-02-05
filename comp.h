//comp

#include <stdlib.h>


int IsFilled(int array[], int pos);
int RandomFill(int array[]);
int Calculation(int array[]);
int TurnCount(int array[]);

int TurnCount(int array[])
{
	int count = 0;
	for (int i = 0; i < 9; i++)
	{
		if (array[i] != 0) count++;
	}
	return count;
}
int IsFilled(int array[], int pos)
{
	if (array[pos] != 0) return 1;
	else return 0;
}
int RandomFill(int array[])
{
	int random;
	random = rand() % 9;
	while (IsFilled(array, random)) random = rand() % 9;
	array[random] = 'o';
	return 1;
}
int MatchCheck(int array[])
{
	//Horizontally
	for (int i = 0; i < 9; i+=3)
	{
		if (array[i] == 'x' && array[i + 1] == 'x' && array[i + 2] == 'x')
		{
			return 1;
		}
		if (array[i] == 'o' && array[i + 1] == 'o' && array[i + 2] == 'o')
		{
			return 2;
		}
	}
	//Vertically
	for (int i = 0; i < 3; i++)
	{
		if (array[i] == 'x' && array[i + 3] == 'x' && array[i + 6] == 'x')
		{
			return 1;
		}
		if (array[i] == 'o' && array[i + 3] == 'o' && array[i + 6] == 'o')
		{
			return 2;
		}
	}
	//Diagonally
	for(int i = 0; i < 3; i+=2)
	{
		if (array[i] == 'x' && array[i + (4 - i)] == 'x' && array[i + (8 - i*2)] == 'x')
		{
			return 1;
		}
		if (array[i] == 'o' && array[i + (4 - i)] == 'o' && array[i + (8 - i * 2)] == 'o')
		{
			return 2;
		}
	}
	return 0;
}
int Calculation(int array[])
{
	RandomFill(array);
	return 1;
}
