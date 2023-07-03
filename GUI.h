#pragma once
#include<SFML/Graphics.hpp>
#include "Game.h"

class GUI
{
	public:
	
		Game chessGame;
		sf::Event event;
		sf::RenderWindow window;
		sf::Texture PieceTexture[2][6];
		sf::RectangleShape chessBoard[8][8];
		sf::Sprite PieceSprite[4][8];
		bool ToDrawOrNotToDraw[4][8];


		GUI();
		~GUI();

		void fillSquareRed(sf::Color& pre_square_colour, int& x, int& y);
		void update();
		void selectPiece(sf::Event& event, int& selected_posx, int& selected_posy, int& sprite_posx, int& sprite_posy, bool& selected);
		bool IsSpritePressed(sf::Sprite& sprite, sf::RenderWindow& window);
		void moveSpriteToMouse(sf::Sprite& sprite, sf::Vector2i& mouse_pos);
		void LoadGameTexture();
		
};

