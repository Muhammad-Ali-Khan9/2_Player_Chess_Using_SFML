#pragma once
#include "Piece.h"
class King : public Piece
{
	public:
		King(Player* player, Square* square);
		bool canCapture(Piece* canCapture);
		bool isValidPath(int finalX,int finalyY);
		void drawPath(int finalX, int finalY);
		//~King();
};

