#pragma once
#include "Player.h"
#include "Piece.h"
#include "Board.h"

class Game
{
	public:
	
		int turn = 0;
		bool quit = false;
		Board board;

		Player player1, player2;


		Game();

		void setupGame();
		void EndGame();
		void update();
		void choose1stturn();

		virtual ~Game();
};

