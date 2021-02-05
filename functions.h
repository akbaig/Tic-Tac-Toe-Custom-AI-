#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#endif /* FUNCTIONS_H_ */
#include <stdlib.h>

int ImpossibleMove(int array[]);
int TurnCount(int array[]);
int IsFilled(int array[], int slot);
int returnCornerSlot();
int RandFillCorner(int array[]);
int RandFillEdge(int array[]);
int Predict(int array[]);
int IsOppositeCornerFilled(int array[], int slot);
int FillLast(int array[]);
int CornerStrategy(int array[]);
int FillOppositeCorner(int array[], int slot);
int MatchCheck(int array[]);
int RandomFill(int array[]);


int Predict(int array[])
{
	for(int j=2; j>0; j--)
	{
		//Horizontally
		for (int i = 0; i < 9; i+=3)
		{
			if (array[i] == j && array[i + 1] == j && array[i + 2] == 0)
			{
				array[i + 2] = 2;
				return j;
			}
			if (array[i] == j && array[i + 1] == 0 && array[i + 2] == j)
			{
				array[i + 1] = 2;
				return j;
			}
			if (array[i] == 0 && array[i + 1] == j && array[i + 2] == j)
			{
				array[i] = 2;
				return j;
			}
		}
		//Vertically
		for (int i = 0; i < 3; i++)
		{
			if (array[i] == j && array[i + 3] == j && array[i + 6] == 0)
			{
				array[i+6] = 2;
				return j;
			}
			if (array[i] == j && array[i + 3] == 0 && array[i + 6] == j)
			{
				array[i+3] = 2;
				return j;
			}
			if (array[i] == 0 && array[i + 3] == j && array[i + 6] == j)
			{
				array[i] = 2;
				return j;
			}
		}
		//Diagonally
		for(int i = 0; i < 3; i+=2)
		{
			if (array[i] == j && array[i + (4 - i)] == j && array[i + (8 - i*2)] == 0)
			{
				array[i + (8 - i*2)] = 2;
				return j;
			}
			if (array[i] == j && array[i + (4 - i)] == 0 && array[i + (8- i*2)] == j)
			{
				array[i + (4-i)] = 2;
				return j;
			}
			if (array[i] == 0 && array[i + (4 - i)] == j && array[i + (8- i*2)] == j)
			{
				array[i] = 2;
				return j;
			}
		}
	}
	return 0;
}
int IsFilled(int array[],int slot)
{
	if (array[slot] != 0) return 1;
	else return 0;
}
int TurnCount(int array[])
{
	int count = 0, i;
	for(i = 0; i < 9; i++)
	{
		if(array[i] != 0)
		{
			count++;
		}
	}
	return count;
}
int returnCornerSlot()
{
	int slot;
	slot = rand()%9;
	while((slot%2 != 0) || (slot == 4)) slot = rand()%9;
	return slot;
}
int RandFillCorner(int array[])
{
	int slot, lastslot = -1, slotcount = 0;
	slot = returnCornerSlot();
	while(IsFilled(array, slot) && slotcount != 4)
	{
		if(lastslot != slot)
		{
			lastslot = slot;
			slotcount++;
		}
		slot = returnCornerSlot();
	}
	if(slotcount == 4) return -1;
	array[slot] = 2;
	return slot;
}
int RandFillEdge(int array[])
{
	for(int i = 1; i < 8; i+=2)
	{
		if(!IsFilled(array, i))
		{
			array[i] = 2;
			return 1;
		}
	}
	return 0;
}
int IsOppositeCornerFilled(int array[], int slot)
{
	if(slot == 0 && array[8] != 0) return 1;
	else return 8;
	if(slot == 2 && array[6] != 0) return 1;
	else return 6;
	if(slot == 6 && array[2] != 0) return 1;
	else return 2;
	if(slot == 8 && array[0] != 0) return 1;
	else return 0;
}
int FillOppositeCorner(int array[], int slot)
{
	if(slot == 0 && array[8] == 0) array[8] = 2;
	if(slot == 2 && array[6] == 0) array[6] = 2;
	if(slot == 6 && array[2] == 0) array[2] = 2;
	if(slot == 8 && array[0] == 0) array[0] = 2;
	return 1;
}
int FillLast(int array[])
{
	for(int i = 0; i < 9; i++)
	{
		if(!IsFilled(array, i))
		{
			array[i] = 2;
			break;
		}
	}
	return 1;
}
int CornerStrategy(int array[])
{
	//int slot = returnCornerSlot(), lastslot = -1, count = 0;
	if(array [0] != 0 && array[2] != 0 && array[6] != 0 && array[8] != 0)
	{
		if(RandFillEdge(array) == 0) RandFillCorner(array);
		return 1;
	}
	if(TurnCount(array) == 8)
	{
			FillLast(array);
			return 1;
	}
	if(array[0] == 1 && array[8] == 1 && array[4] == 2)
	{
		RandFillEdge(array);
		return 1;
	}

	if(array[2] == 1 && array[6] == 1 && array[4] == 2)
	{
		RandFillEdge(array);
		return 1;
	}
	if(TurnCount(array) == 3)
	{
		for(int i = 0; i < 9; i+=2)
		{
			if(i == 4) continue;
			for(int j=1; j<9; j+=2)
			{
				if(array[i] == 1 && array[j] == 1)
				{
					FillOppositeCorner(array, i);
					return 1;
				}
			}

		}
	}
	return 0;
}
int RandomFill(int array[])
{
	int random;
	random = rand() % 9;
	while (IsFilled(array, random)) random = rand() % 9;
	array[random] = 2;
	return 1;
}
int Match(int array[])
{
	//Horizontally
	for (int i = 0; i < 9; i+=3)
	{
		if (array[i] == 1 && array[i + 1] == 1 && array[i + 2] == 1)
		{
			return 1;
		}
		if (array[i] == 2 && array[i + 1] == 2 && array[i + 2] == 2)
		{
			return 2;
		}
	}
	//Vertically
	for (int i = 0; i < 3; i++)
	{
		if (array[i] == 1 && array[i + 3] == 1 && array[i + 6] == 1)
		{
			return 1;
		}
		if (array[i] == 2 && array[i + 3] == 2 && array[i + 6] == 2)
		{
			return 2;
		}
	}
	//Diagonally
	for(int i = 0; i < 3; i+=2)
	{
		if (array[i] == 1 && array[i + (4 - i)] == 1 && array[i + (8 - i*2)] == 1)
		{
			return 1;
		}
		if (array[i] == 2 && array[i + (4 - i)] == 2 && array[i + (8 - i * 2)] == 2)
		{
			return 2;
		}
	}
	return 0;
}
