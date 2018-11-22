#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

void Player::GetInput() {
	std::cin >> m_edgeStatus.x;
	std::cin >> m_edgeStatus.y;
}

void Player::UpdateBroad(edge m_edgeStatus, int m_intBroad[3][3]) {
	m_intBroad[m_edgeStatus.x][m_edgeStatus.y] = 2;
}
