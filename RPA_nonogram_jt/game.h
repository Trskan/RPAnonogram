#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

class gameWindow {
protected:
	std::ifstream map;
	bool mapa[8][8];
	int remLives,k,l;
	bool x,wasColored;
	std::vector<int> colClues[10];
        std::vector<int> rowClues[10];
        std::map<int, sf::Text> colCluesMap;
        std::map<int, sf::Text> rowCluesMap;
	sf::Texture background;
	sf::RectangleShape* cell[10][10];
	sf::Cursor cursor;
	sf::Event event;
	sf::Font font;
	sf::Texture exitBtn;
	sf::Sprite exitBtnImg;
	sf::Sprite s;
	sf::Texture heartFull;
	sf::Texture heartEmpty;
	sf::Sprite heartIcon;
	sf::Sprite heartIcon2;
	sf::Sprite heartIcon3;
	sf::Texture tableT;
	sf::Sprite table;
	sf::Text subtitle;
	sf::RenderWindow* window;
public:
	gameWindow();
	void render();
	void run();
	void makeTable();
	void checkLives();
	virtual ~gameWindow();
};
