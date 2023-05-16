#pragma once
#include <SFML/Graphics.hpp>

class Window {
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
	sf::RenderWindow* window;
public:
	Window();
	void render();
	void run();
	virtual ~Window();
};