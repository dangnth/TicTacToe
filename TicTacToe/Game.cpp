#include "Game.h"

Game::Game()
{
}


Game::~Game()
{
}

void Game::Init() {
	for (int i=0; i<3; ++i)
		for (int j = 0; j < 3; ++j) {
			m_intBroad[i][j] = 0;
		}
}

void Game::Render(int broad[3][3]) {
	std::cout << std::endl;
	std::cout << " ";
	for (int i = 0; i < 3; i++) std::cout << " " << i ;
	std::cout << std::endl;
	//draw broad game
	for (int i = 0; i < 3; ++i) {
		std::cout << i;
		for (int j = 0; j < 3; ++j) {
			if (broad[i][j] == 1) {
				std::cout << " O";
			}
			else if (broad[i][j] == 2) {
				std::cout << " X";
			}
			else std::cout << " .";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Game::Update(int broad[3][3], int x, int y) {
	broad[x][y] = 1;
}


void Game::EndGame(int status) {
	if (status = -1) std::cout << "DRAW" << std::endl;
}