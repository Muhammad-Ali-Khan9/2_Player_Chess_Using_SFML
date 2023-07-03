#include "Player.h"
#include "Piece.h"
#include "Board.h"
#include "Game.h"

Player::Player()
{}

void Player::setColour(Colour colour)
{
	this->colour = colour;
}

void Player::getAllyPiece()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (*game->board.boardPiece[i][j]->m_player == *this) 
				AllyPieces.push_back(game->board.boardPiece[i][j]);

		}

	}
}

bool Player::operator==(const Player& player2)
{
	if (this->colour == player2.colour)
		return true;
	else
		return false;
}

bool Player::operator!=(const Player& player2)
{
	if (this->colour == player2.colour)
		return false;
	else
		return true;
}

void Player::getEnemyPiece()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (*game->board.boardPiece[i][j]->m_player == *this)
				EnemyPieces.push_back(game->board.boardPiece[i][j]);
		}
	}
}