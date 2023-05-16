#include "SFML/Graphics.hpp"
#include "levels.h"
#include "game.h"
#include "welcome.h"

WindowL::WindowL() {
	this->window = NULL;
	exitBtn.loadFromFile("assets/btn/X.png");
	exitBtnImg.setScale(0.10f, 0.10f);
	exitBtnImg.setPosition(30.0f, 30.0f);
	exitBtnImg.setTexture(exitBtn);

	font.loadFromFile("assets/font.ttf");

	background.loadFromFile("assets/bg/2.gif");
	s.setTexture(background);

	title.setFont(font);
	title.setString("levels");
	title.setCharacterSize(150);
	title.setFillColor(sf::Color::White);
	title.setPosition(40.0f, 150.0f);


	plbg.loadFromFile("assets/btn/level03.png");
	lbg.loadFromFile("assets/btn/level01.png");
	const auto* elbg = &lbg;
	const auto* eelbg = &plbg;
	this->rectangle = new sf::RectangleShape(sf::Vector2f(128.0f, 128.0f));
	this->rectangle->setPosition(250, 700);
	this->rectangle->setTexture(elbg);
	
	t.setFont(font);
	t.setString("1");
	t.setCharacterSize(75);
	t.setFillColor(sf::Color::Black);
	t.setPosition(300.0f, 705.0f);
	this->rectangle2 = new sf::RectangleShape(sf::Vector2f(128.0f, 128.0f));
	this->rectangle2->setPosition(500, 700);
	this->rectangle2->setTexture(elbg);
	
	t2.setFont(font);
	t2.setString("2");
	t2.setCharacterSize(75);
	t2.setFillColor(sf::Color::Black);
	t2.setPosition(550.0f, 705.0f);
	this->rectangle3 = new sf::RectangleShape(sf::Vector2f(128.0f, 128.0f));
	this->rectangle3->setPosition(750, 700);
	this->rectangle3->setTexture(elbg);
	
	t3.setFont(font);
	t3.setString("3");
	t3.setCharacterSize(75);
	t3.setFillColor(sf::Color::Black);
	t3.setPosition(800.0f, 705.0f);
	this->window = new sf::RenderWindow(sf::VideoMode(1080, 1080), "NonogramRPA - Info");
}

void WindowL::render() {
	const auto* elbg = &lbg;
	const auto* eelbg = &plbg;
	this->window->clear();
	this->window->draw(s);
	this->window->draw(exitBtnImg);
	this->window->draw(title);
	this->window->draw(*rectangle);
	this->window->draw(*rectangle2);
	this->window->draw(*rectangle3);
	this->window->draw(t); this->window->draw(t2); this->window->draw(t3);
	this->window->display();
	auto mouse = sf::Mouse::getPosition(*window);
	auto mousePos = this->window->mapPixelToCoords(mouse);
	if (cursor.loadFromSystem(sf::Cursor::Arrow)) this->window->setMouseCursor(cursor);
	if (exitBtnImg.getGlobalBounds().contains(mousePos)) {
		exitBtnImg.setScale(0.09f, 0.09f);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			this->window->close(); Welcome w; w.run();
		}
	}
	else exitBtnImg.setScale(0.10f, 0.10f);
	if (this->rectangle->getGlobalBounds().contains(mousePos)) {
		this->rectangle->setTexture(eelbg);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			this->window->close(); gameWindow l; l.run();
		}
	}
	else this->rectangle->setTexture(elbg);
	if (this->rectangle2->getGlobalBounds().contains(mousePos)) {
		this->rectangle2->setTexture(eelbg);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			this->window->close();
		}
	}
	else this->rectangle2->setTexture(elbg);
	if (this->rectangle3->getGlobalBounds().contains(mousePos)) {
		this->rectangle3->setTexture(eelbg);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			this->window->close();
		}
	}
	else this->rectangle3->setTexture(elbg);
}

void WindowL::run() {
	while (this->window->isOpen()) {
		this->render();
	}
}

WindowL::~WindowL() {
	delete this->window;
}
