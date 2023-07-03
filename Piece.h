#pragma once

#include<vector>
#include "Colour.h"
#include "Type.h"

class Player;
class Square;

class Piece
{
	public:
	
		Type m_type = NONE;
		Square* PieceSquare;

		std::vector<std::vector<int>> path;

		bool isCaptured = false;

		Player* m_player = NULL;

		Piece(Player* player, Square* square);

		virtual ~Piece();

		virtual bool canCapture(Piece* capture_piece) = 0;

		virtual bool isValidPath(int finalX, int finalY) = 0;

		virtual void drawPath(int finalX,int finalY) = 0;

};

