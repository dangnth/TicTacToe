#pragma once
#include "Game.h"

class AIwithMinMax:public Game
{
public:
	AIwithMinMax();
	~AIwithMinMax();
	
	int value;

	int CheckStateMatch(int broad[3][3]);
	edge FindBestWay(int broad[3][3]);
	void MinMax(int broad[3][3], bool);
};

