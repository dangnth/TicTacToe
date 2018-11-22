#pragma once
#include <cmath>
#include <iostream>

struct edge
{
	int x, y;
};

class Game
{
public:
	Game();
	~Game();
	//
	int m_intBroad[3][3];

	void EndGame(int);

	void Init();
	void Render(int broad[3][3]);
	void Update(int broad[3][3], int, int);
};

