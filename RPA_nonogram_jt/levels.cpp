#include <SFML/Graphics.hpp>
#include "screens.h"

void levelsScreen() {
	sf::RenderWindow levels(sf::VideoMode(1080, 1080), "NonogramRPA - Levels");
	sf::Event event;
	sf::Texture background;
	background.loadFromFile("assets/bg/2.gif");
	sf::Sprite s(background);
	sf::Font font;
	font.loadFromFile("assets/font.ttf");

	sf::Texture exitBtn;
	sf::Sprite exitBtnImg;
	exitBtn.loadFromFile("assets/btn/X.png");
	exitBtnImg.setScale(0.10f, 0.10f);
	exitBtnImg.setPosition(30.0f, 30.0f);
	exitBtnImg.setTexture(exitBtn);

	sf::Text title;
	title.setFont(font);
	title.setString("Levels");
	title.setCharacterSize(150);
	title.setFillColor(sf::Color::White);
	title.setPosition(40.0f, 150.0f);

	sf::RectangleShape rectangle(sf::Vector2f(128.0f, 128.0f));
	rectangle.setPosition(320, 750);
	rectangle.setOutlineColor(sf::Color::White);	


	while (levels.isOpen()) {
		levels.clear();
		levels.clear(sf::Color::White);
		levels.draw(s);
		levels.draw(exitBtnImg);
		levels.draw(title);
		levels.draw(rectangle);
		levels.display();
		auto mouse = sf::Mouse::getPosition(levels);
		auto mousePos = levels.mapPixelToCoords(mouse);
		if (exitBtnImg.getGlobalBounds().contains(mousePos)) {
			exitBtnImg.setScale(0.09f, 0.09f);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				levels.close(); welcomeScreen();
			}
		}
		else exitBtnImg.setScale(0.10f, 0.10f);
	}
}