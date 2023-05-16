#pragma once
#include "SFML/Graphics.hpp"

class Lives {
private:
    sf::RectangleShape shape;
    sf::RectangleShape shape2;
    sf::RectangleShape shape3;
    sf::Texture heartTextureFull;
    sf::Texture heartTextureEmpty;

    void drawShape();
public:
    static int numberOfHearts;
public:
    Lives();
    void operator ++();
    void operator--();
    ~Lives();
    static bool remainingLives();
    void render(sf::RenderTarget* target);
};