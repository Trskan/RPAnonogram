#include "SFML/Graphics.hpp"
#include "window.h"
#include "levels.h"
#include "welcome.h"

	Window::Window() {
		this->window = NULL;
		exitBtn.loadFromFile("assets/btn/X.png");
		exitBtnImg.setScale(0.10f, 0.10f);
		exitBtnImg.setPosition(30.0f, 30.0f);
		exitBtnImg.setTexture(exitBtn);

		font.loadFromFile("assets/font.ttf");

		background.loadFromFile("assets/bg/1.gif");
		s.setTexture(background);

		title.setFont(font);
		title.setString("How to play?");
		title.setCharacterSize(100);
		title.setFillColor(sf::Color::White);
		title.setPosition(400.0f, 400.0f);
		subtitle.setFont(font);
		subtitle.setString("The clues are the numbers at the ends of rows and columns.\nEach number is the number of consecutive black squares.\nTwo adjoining consecutive squares blocks are separated\nby more than one white squares.");
		subtitle.setCharacterSize(25);
		subtitle.setFillColor(sf::Color::White);
		subtitle.setPosition(350.0f, 550.0f);

		playBtn.loadFromFile("assets/btn/play01.png");
		playBtnnn.loadFromFile("assets/btn/play03.png");
		playBtnn.loadFromFile("assets/btn/play02.png");
		playBtnImg.setScale(0.25f, 0.25f);
		playBtnImg.setPosition(800.0f, 700.0f);
		playBtnImg.setTexture(playBtn);
		this->window = new sf::RenderWindow(sf::VideoMode(1080, 1080), "NonogramRPA - Info");
	}

	void Window::render() {
		this->window->clear();
		this->window->draw(s);
		this->window->draw(exitBtnImg);
		this->window->draw(title);
		this->window->draw(subtitle);
		this->window->draw(playBtnImg);
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
		if (playBtnImg.getGlobalBounds().contains(mousePos)) {
			playBtnImg.setTexture(playBtnn);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				playBtnImg.setTexture(playBtnnn);
				this->window->close(); WindowL l; l.run();
			}
		}
		else playBtnImg.setTexture(playBtn);
	}

	void Window::run() {
		while (this->window->isOpen()) {
			this->render();
		}
	}

	Window::~Window() {
		delete this->window;
	}
