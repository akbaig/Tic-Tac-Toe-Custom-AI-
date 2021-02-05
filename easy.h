#ifndef EASY_H_
#define EASY_H_
#endif /* EASY_H_ */
int EasyMove(int array[]);

int EasyMove(int array[])
{
	if(TurnCount(array) >= 9) return 1;
	RandomFill(array);
	return 1;
}
