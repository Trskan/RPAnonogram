#pragma once
#pragma once
#include <SFML/Graphics.hpp>

class WindowL {
protected:
	sf::Texture background;
	sf::Cursor cursor;
	sf::Font font;
	sf::Texture exitBtn;
	sf::Sprite exitBtnImg;
	sf::Sprite s;
	sf::Text title;
	sf::Text subtitle;
	sf::Texture playBtn;
	sf::Texture playBtnn;
	sf::Texture playBtnnn;
	sf::Sprite playBtnImg;
	sf::RectangleShape *rectangle;
	sf::RectangleShape *rectangle2;
	sf::RectangleShape *rectangle3;
	sf::Text t;
	sf::Text t2;
	sf::Text t3;
	sf::Texture lbg;
	sf::Texture plbg;
	sf::RenderWindow* window;
public:
	WindowL();
	void render();
	void run();
	virtual ~WindowL();
};