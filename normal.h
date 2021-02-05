/*
 * normal.h
 *
 *  Created on: Dec 18, 2018
 *      Author: ahmad
 */

#ifndef NORMAL_H_
#define NORMAL_H_

int NormalMove(int array[]);

int NormalMove(int array[])
{
	if(TurnCount(array) >= 9) return 1;
	if(Predict(array) != 0) return 1;
	int p = rand()%5;
	if(p == 0) ImpossibleMove(array);
	else EasyMove(array);
	return 1;
}

#endif /* NORMAL_H_ */
