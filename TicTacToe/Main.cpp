#include "Player.h"
#include "Game.h"
#include "AIwithMinMax.h"

using namespace std;

int main() {
	Game m_game;
	AIwithMinMax m_StatusGame;
	Player m_player;
	bool exit = false;
	//
	m_game.Init();
	m_game.Render(m_game.m_intBroad);
	//
	while (m_StatusGame.CheckStateMatch(m_game.m_intBroad) == 0 && !exit) {
		//turn
		m_player.GetInput();
		m_player.UpdateBroad(m_player.m_edgeStatus, m_game.m_intBroad);
		//process
		m_game.Update(m_game.m_intBroad, m_StatusGame.FindBestWay(m_game.m_intBroad).x, m_StatusGame.FindBestWay(m_game.m_intBroad).y);
		//update
		m_game.Render(m_game.m_intBroad);
		//check
		if (m_StatusGame.CheckStateMatch(m_game.m_intBroad) == -1) {
			m_game.EndGame(-1);
			exit = true;
		}
	}
	system("pause");
}
