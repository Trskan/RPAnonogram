#include "SFML/Graphics.hpp"
#include "welcome.h"
#include "levels.h"
#include "window.h"

Welcome::Welcome() {
	this->window = NULL;
	exitBtn.loadFromFile("assets/btn/X.png");
	exitBtnImg.setScale(0.10f, 0.10f);
	exitBtnImg.setPosition(30.0f, 30.0f);
	exitBtnImg.setTexture(exitBtn);

	font.loadFromFile("assets/font.ttf");

	background.loadFromFile("assets/bg/1.gif");
	s.setTexture(background);

	infoBtn.loadFromFile("assets/btn/I.png");
	infoBtnImg.setScale(2.3f, 2.3f);
	infoBtnImg.setPosition(100.0f, 20.0f);
	infoBtnImg.setTexture(infoBtn);

	title.setFont(font);
	title.setString("NONOGRAM");
	title.setCharacterSize(150);
	title.setFillColor(sf::Color::White);
	title.setPosition(400.0f, 400.0f);
	subtitle.setFont(font);
	subtitle.setString("By Jan Trstenjak");
	subtitle.setCharacterSize(50);
	subtitle.setFillColor(sf::Color::White);
	subtitle.setPosition(623.0f, 550.0f);

	playBtn.loadFromFile("assets/btn/play01.png");
	playBtnnn.loadFromFile("assets/btn/play03.png");
	playBtnn.loadFromFile("assets/btn/play02.png");
	playBtnImg.setScale(0.25f, 0.25f);
	playBtnImg.setPosition(800.0f, 700.0f);
	playBtnImg.setTexture(playBtn);
	this->window = new sf::RenderWindow(sf::VideoMode(1080, 1080), "NonogramRPA - Welcome");
}

void Welcome::render() {
	this->window->clear();
	this->window->draw(s);
	this->window->draw(exitBtnImg);
	this->window->draw(title);
	this->window->draw(subtitle);
	this->window->draw(playBtnImg);
	this->window->draw(infoBtnImg);
	this->window->display();
	auto mouse = sf::Mouse::getPosition(*window);
	auto mousePos = this->window->mapPixelToCoords(mouse);
	if (cursor.loadFromSystem(sf::Cursor::Arrow)) this->window->setMouseCursor(cursor);
	if (exitBtnImg.getGlobalBounds().contains(mousePos)) {
		exitBtnImg.setScale(0.09f, 0.09f);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			this->window->close();
		}
	}
	else exitBtnImg.setScale(0.10f, 0.10f);
	if (infoBtnImg.getGlobalBounds().contains(mousePos)) {
		infoBtnImg.setScale(2.1f, 2.1f);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			this->window->close(); Window w; w.run();
		}
	}
	else infoBtnImg.setScale(2.3f, 2.3f);
	if (playBtnImg.getGlobalBounds().contains(mousePos)) {
		playBtnImg.setTexture(playBtnn);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			playBtnImg.setTexture(playBtnnn);
			this->window->close(); WindowL l; l.run();
		}
	}
	else playBtnImg.setTexture(playBtn);
}

void Welcome::run() {
	while (this->window->isOpen()) {
		this->render();
	}
}

Welcome::~Welcome(){
	delete this->window;	
}