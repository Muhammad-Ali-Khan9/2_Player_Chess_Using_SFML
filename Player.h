#pragma once

#include "Colour.h"
#include<SFML/Graphics.hpp>
#include<vector>

class Piece;
class Game;

class  Player
{

public:

	Game* game;

	bool goesFirst = false;

	Colour colour;
	int score = 0;

	bool isLoser = false;


	Player();

	bool operator == (const Player& Player2);

	bool operator != (const Player& Player2);

	void setColour(Colour colour);

	std::vector<Piece*> AllyPieces;
	std::vector<Piece*> EnemyPieces;

	void getAllyPiece();

	void getEnemyPiece();

};
