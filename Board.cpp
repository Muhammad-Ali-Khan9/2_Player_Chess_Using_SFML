#include "Board.h"
#include "Player.h"
#include "Piece.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"
#include<iostream>

Board::Board(int width,int height)
{
	this->height = height;
	this->width = width;
	board = new Square**[height];

	for (int i = 0; i < height; i++)
		board[i] = new Square * [width];

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			board[i][j] = new Square(i, j);
	}

	boardPiece = new Piece * *[4];

	for (int i = 0; i < 4; i++)
		boardPiece[i] = new Piece * [8];
}

void Board::setupPieces(Player* player1, Player* Player2)
{
	setupPlayer1Pieces(player1);
	setupPlayer2Pieces(Player2);
	setupPieceVector();
}

void Board::setupPieceVector()
{
	for (int i = 0; i < width; i++) {
		whitePieces.push_back(boardPiece[0][i]);
		whitePieces.push_back(boardPiece[1][i]);
		blackPieces.push_back(boardPiece[2][i]);
		blackPieces.push_back(boardPiece[3][i]);
	}
}

void Board::setupPlayer2Pieces(Player* player)
{
	for (int i = 0; i < width; i++)
	{
		if (i == 0 || i == 7)
			boardPiece[0][i] = new Rook(player, board[0][i]);
		if (i == 1 || i == 6)
			boardPiece[0][i] = new Bishop(player, board[0][i]);
		if (i == 2 || i == 5)
			boardPiece[0][i] = new Knight(player, board[0][i]);
		if (i == 3)
			boardPiece[0][i] = new King(player, board[0][i]);
		if (i == 4)
			boardPiece[0][i] = new Queen(player, board[0][i]);
		boardPiece[1][i] = new Pawn(player, board[1][i]);

		board[0][i]->hasPiece = true;
		board[1][i]->hasPiece = true;
	}
}

void Board::setupPlayer1Pieces(Player* player)
{

	for (int i = 0; i < width; i++)
	{
		if (i == 0 || i == 7)
			boardPiece[3][i] = new Rook(player, board[7][i]);
		if (i == 1 || i == 6)
			boardPiece[3][i] = new Bishop(player, board[7][i]);
		if (i == 2 || i == 5)
			boardPiece[3][i] = new Knight(player, board[7][i]);
		if (i == 3)
			boardPiece[3][i] = new King(player, board[7][i]);
		if (i == 4)
			boardPiece[3][i] = new Queen(player, board[7][i]);

		boardPiece[2][i] = new Pawn(player, board[6][i]);
		board[6][i]->hasPiece = true;
		board[7][i]->hasPiece = true;
	}
}

bool Board::isValidMove(Piece* piece,int finalX,int finalY)
{
	piece->drawPath(finalX, finalY);

	if (isWithinBoard(finalX, finalY) && isNotOrigin(piece->PieceSquare, finalX, finalY) && PathIsNotObscured(piece->path)) {
		if (board[finalX][finalY]->hasPiece){
			Piece* capture_piece = getPiece(board[finalX][finalY]);

			if(piece -> canCapture(capture_piece)){
				if (capture_piece->m_type == KING)
					capture_piece->m_player->isLoser = true;
				return true;
			
			}
			return false;
		}
		if (piece->isValidPath(finalX, finalY)) {
			return true;
		}
		return false;
	}

	return false;
}

Piece* Board::getPiece(Square* square)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++)
		{
			if (!boardPiece[i][j]->isCaptured && *boardPiece[i][j]->PieceSquare == *square)
				return boardPiece[i][j];
		}
	}
}

bool Board::PathIsNotObscured(std::vector<std::vector<int>> &path)
{
	if (path[0].size() == 0)
		return true;


	for (int i = 0; i < path[0].size(); i++)
	{
		if (board[path[0][i]][path[1][i]]->hasPiece)
			return false;
	}

	return true;
}

void Board::SetPiece(Piece* piece,Square* newSquare)
{
	if (newSquare->hasPiece)
	{
		Piece* capturedPiece = getPiece(newSquare);
		capturedPiece->isCaptured = true;
	}

	piece->PieceSquare->hasPiece = false;
	piece->PieceSquare = newSquare;
	newSquare->hasPiece = true;
}

void Board::MovePiece(int finalX,int finalY,Piece* piece)
{
	SetPiece(piece, board[finalX][finalY]);
}

bool Board::validLeaping(Piece* piece, int** path)
{
	for (int i = 0; i < sizeof(path[0]); i++)
	{
		if (board[path[0][i]][path[1][i]] != NULL)
			return false;
	}

	if (piece->m_type == KNIGHT)
		return true;

	if (piece->m_type == PAWN || piece->m_type == KING)
		return true;

	return false;
}

bool Board::isWithinBoard(int finalX, int finalY)
{
	if ((finalX < width && finalX >= 0) && (finalY >= 0 && finalY < height))
		return true;

	return false;
}

bool Board::isNotOrigin(Square* piecesquare, int finalX, int finalY)
{
	if ((finalX - piecesquare->x) != 0 || (finalY - piecesquare->y) != 0)
		return true;

	return false;
}

Board::~Board()
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
		{
			delete board[i][j];
		}
	}

	for (int i = 0; i < height; i++)
		delete[] board[i];

	delete[] board;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 8; j++)
			delete boardPiece[i][j];

	for (int i = 0; i < 4; i++)
		delete[] boardPiece[i];

	delete[] boardPiece;
}