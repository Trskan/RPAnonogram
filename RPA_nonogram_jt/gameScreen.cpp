#include "game.h"
#include "welcome.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <fstream>



gameWindow::gameWindow() {
	this->window = NULL; int n; char ch;
	x = false; k = -1; l = -1;
	exitBtn.loadFromFile("assets/btn/X.png");
	exitBtnImg.setScale(0.10f, 0.10f);
	exitBtnImg.setPosition(30.0f, 30.0f);
	exitBtnImg.setTexture(exitBtn);
	map.open("map01.txt");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) { //za preverjanje pravilnosti
			map >> n >> ch;
			mapa[i][j] = n;
		}
	}
	font.loadFromFile("assets/font.ttf");
	tableT.loadFromFile("assets/table.png");
	table.setScale(1, 1);
	table.setPosition(350, 250);
	table.setTexture(tableT);
	background.loadFromFile("assets/bg/5.jpg");
	s.setTexture(background);

	heartFull.loadFromFile("assets/game/full.png");
	heartEmpty.loadFromFile("assets/game/empty.png");
	heartIcon.setScale(5, 5);
	heartIcon.setPosition(100, 440);
	heartIcon.setTexture(heartFull);
	heartIcon2.setScale(5, 5);
	heartIcon2.setPosition(100, 540);
	heartIcon2.setTexture(heartFull);
	heartIcon3.setScale(5, 5);
	heartIcon3.setPosition(100, 640);
	heartIcon3.setTexture(heartFull);
	this->window = new sf::RenderWindow(sf::VideoMode(1080, 1080), "NonogramRPA - Welcome");
}

void gameWindow::checkLives() {
	if (remLives == 0) { // konec potez
		this->heartIcon3.setTexture(heartEmpty);
		std::cout << "You lost!" << std::endl;
		this->window->close(); Welcome w; w.run();
	}
	else { // nekaj potez
		if (remLives == 2) {
			this->heartIcon.setTexture(heartEmpty);
		}
		else if (remLives == 1) {
			this->heartIcon2.setTexture(heartEmpty);
		}
	}
}

void gameWindow::render() {
	while (this->window->isOpen()) {
		this->window->clear();
		this->window->draw(s);
		this->window->draw(exitBtnImg);
		this->window->draw(subtitle);
		this->window->draw(heartIcon);
		this->window->draw(heartIcon2);
		this->window->draw(heartIcon3);
		// this->window->draw(table);
		int n = 60, m = 60;
		sf::RectangleShape cell[10][10];
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if ((k == i && l == j)) {
					cell[i][j].setFillColor(sf::Color::Black);
				}
				cell[i][j].setOutlineThickness(2);
				cell[i][j].setSize(sf::Vector2f(n - 1, m - 1));
				cell[i][j].setOutlineColor(sf::Color::Black);
				cell[i][j].setPosition((j * n) + 350, (i * m) + 250);
				this->window->draw(cell[i][j]);
			}
		}
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
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					if (cell[i][j].getGlobalBounds().contains(mousePos)) {
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
							if(x == false) {
								if (mapa[i][j] == 1) {
									k = i;
									l = j;
								}
								else {
									remLives = remLives - 1;
									checkLives();
								} x = true;
							}
						}
					}
					
				}
			}
		}
		else x = false;
	}
	
}

void gameWindow::run() {
		remLives = 3; 
		this->render();
}

gameWindow::~gameWindow() {
	delete this->window;
}
