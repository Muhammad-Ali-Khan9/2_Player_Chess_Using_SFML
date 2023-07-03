#pragma once

class Square
{	
	public:

		int x;
		int y;

		bool hasPiece = false;

		bool operator == (const Square& otherSqaure);

		Square(int x, int y);

		~Square();

};

