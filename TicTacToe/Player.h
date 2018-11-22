#pragma once
#include "Game.h"

class Player:public Game
{
public:
	Player();
	~Player();

	edge m_edgeStatus;

	void GetInput();
	void UpdateBroad(edge m_edgeStatus, int m_intBroad[3][3]);
};

