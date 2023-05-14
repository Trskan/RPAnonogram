#include <SFML\Graphics.hpp>
#include <iostream>
#include "screens.h"

void welcomeScreen() {
	sf::RenderWindow zacetni(sf::VideoMode(1080, 1080), "NonogramRPA - Welcome");
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

	sf::Texture infoBtn;
	sf::Sprite infoBtnImg;
	infoBtn.loadFromFile("assets/btn/I.png");
	infoBtnImg.setScale(2.3f, 2.3f);
	infoBtnImg.setPosition(100.0f, 20.0f);
	infoBtnImg.setTexture(infoBtn);

	sf::Text title;
	title.setFont(font);
	title.setString("NONOGRAM");
	title.setCharacterSize(150);
	title.setFillColor(sf::Color::White);
	title.setPosition(400.0f, 400.0f);
	sf::Text subtitle;
	subtitle.setFont(font);
	subtitle.setString("By Jan Trstenjak");
	subtitle.setCharacterSize(50);
	subtitle.setFillColor(sf::Color::White);
	subtitle.setPosition(623.0f, 550.0f);

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

	while (zacetni.isOpen()) {
		zacetni.clear();
		zacetni.clear(sf::Color::White);
		zacetni.draw(s);
		zacetni.draw(exitBtnImg);
		zacetni.draw(title);
		zacetni.draw(subtitle);
		zacetni.draw(playBtnImg);
		zacetni.draw(infoBtnImg);
		zacetni.display();
		auto mouse = sf::Mouse::getPosition(zacetni);
		auto mousePos = zacetni.mapPixelToCoords(mouse);
		if (exitBtnImg.getGlobalBounds().contains(mousePos)) {
			exitBtnImg.setScale(0.09f, 0.09f);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				zacetni.close();
			}
		}
		else exitBtnImg.setScale(0.10f, 0.10f);
		if (infoBtnImg.getGlobalBounds().contains(mousePos)) {
			infoBtnImg.setScale(2.1f, 2.1f);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				zacetni.close(); infoScreen();
			}
		}
		else infoBtnImg.setScale(2.3f, 2.3f);
		if (playBtnImg.getGlobalBounds().contains(mousePos)) {
			playBtnImg.setTexture(playBtnn);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				playBtnImg.setTexture(playBtnnn);
				zacetni.close(); levelsScreen();
			}
		}
		else playBtnImg.setTexture(playBtn);
	}
}