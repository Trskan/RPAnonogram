#pragma once
#include <SFML/Graphics.hpp>

class Welcome {
protected:
	sf::Texture background;
	sf::Cursor cursor;
	sf::Font font;
	sf::Texture exitBtn;
	sf::Sprite exitBtnImg;
	sf::Sprite s;
	sf::Texture infoBtn;
	sf::Sprite infoBtnImg;
	sf::Text title;
	sf::Text subtitle;
	sf::Texture playBtn;
	sf::Texture playBtnn;
	sf::Texture playBtnnn;
	sf::Sprite playBtnImg;
	sf::RenderWindow *window;
public:
	Welcome();
	void render();
	void run();
	virtual ~Welcome();
};