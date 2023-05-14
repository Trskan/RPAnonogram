#include <SFML\Graphics.hpp>
#include <iostream>
#include "screens.h"

void infoScreen() {
	sf::RenderWindow info(sf::VideoMode(1080, 1080), "NonogramRPA - Info");
	sf::Event event;
	sf::Texture background;
	background.loadFromFile("assets/bg/1.gif");
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
	title.setString("How to play?");
	title.setCharacterSize(100);
	title.setFillColor(sf::Color::White);
	title.setPosition(400.0f, 400.0f);
	sf::Text subtitle;
	subtitle.setFont(font);
	subtitle.setString("The clues are the numbers at the ends of rows and columns.\nEach number is the number of consecutive black squares.\nTwo adjoining consecutive squares blocks are separated\nby more than one white squares.");
	subtitle.setCharacterSize(25);
	subtitle.setFillColor(sf::Color::White);
	subtitle.setPosition(350.0f, 550.0f);

	sf::Texture playBtn;
	sf::Texture playBtnn;
	sf::Texture playBtnnn;
	sf::Sprite playBtnImg;
	playBtn.loadFromFile("assets/btn/play01.png");
	playBtnnn.loadFromFile("assets/btn/play03.png");
	playBtnn.loadFromFile("assets/btn/play02.png");
	playBtnImg.setScale(0.25f, 0.25f);
	playBtnImg.setPosition(800.0f, 700.0f);
	playBtnImg.setTexture(playBtn);

	while (info.isOpen()) {
		info.clear();
		info.clear(sf::Color::White);
		info.draw(s);
		info.draw(exitBtnImg);
		info.draw(title);
		info.draw(subtitle);
		info.draw(playBtnImg);
		info.display();
		auto mouse = sf::Mouse::getPosition(info);
		auto mousePos = info.mapPixelToCoords(mouse);
		if (exitBtnImg.getGlobalBounds().contains(mousePos)) {
			exitBtnImg.setScale(0.09f, 0.09f);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				info.close(); welcomeScreen();
			}
		}
		else exitBtnImg.setScale(0.10f, 0.10f);
		if (playBtnImg.getGlobalBounds().contains(mousePos)) {
			playBtnImg.setTexture(playBtnn);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				playBtnImg.setTexture(playBtnnn);
				std::cout << "o";
			}
		}
		else playBtnImg.setTexture(playBtn);
	}
}