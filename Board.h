#pragma once

#include<vector>
#include "Type.h"
#include "Square.h"

class Piece;
class Player;

class Board
{
	public:
	
		int width, height;
		Square*** board;
		Piece*** boardPiece;

		Board();
		Board(int width, int height);
		~Board();

		std::vector<Piece*> whitePieces;
		std::vector<Piece*> blackPieces;

		Piece* getPiece(Square* square);

		bool PathIsNotObscured(std::vector<std::vector<int>>& path);
		void setupPieceVector();
		void MovePiece(int finalX, int finalY, Piece* piece);
		void SetPiece(Piece* piece,Square* newSquare);
		bool validLeaping(Piece* piece, int** path);
		//bool EndGame(int finalX, int finalY, Piece* piece);
		bool isValidMove(Piece* piece, int finalX, int finalY);
		bool isWithinBoard(int finalX,int finalY);
		bool isNotOrigin(Square* square, int finalX, int finaly);
		void setupPieces(Player* Player1,Player* Player2);
		void setupPlayer1Pieces(Player* player);
		void setupPlayer2Pieces(Player* player);

};

