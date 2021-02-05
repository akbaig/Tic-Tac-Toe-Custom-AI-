#ifndef HARD_H_
#define HARD_H_
#endif /* HARD_H_ */

int ImpossibleMove(int array[])
{
	int count;
	count = TurnCount(array);
	if(count >= 3)
	{
		if(count >= 9) return 1;
		if(Predict(array) != 0) return 1;
		if(CornerStrategy(array) == 0)
		{
			if(RandFillCorner(array) != -1) return 1;
			if(!IsFilled(array, 4)) array[4] = 2;
			else if(RandFillEdge(array) == 0) RandFillCorner(array);
		}
	}
	else
	{
		if(count == 0) RandFillCorner(array);
		else if(count == 1 || count == 2)
		{
				if(!IsFilled(array, 4)) array[4] = 2;
				else RandFillCorner(array); //where 4 is center slot
		}
		else RandFillCorner(array);
	}
	return 1;
}
