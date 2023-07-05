#include <SFML/Graphics.hpp>
#include "animation.h"
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Lab_1");
    sf::Font mainFont;
    sf::Text textObject;
    if (!mainFont.loadFromFile("ext/font/GoogleSans-Regular.ttf")) {
        std::cout << "Failed to load font" << std::endl;
        return -1;
    }

    AnimatedText text("Hello, world!", 13);
    textObject.setFont(mainFont);
    textObject.setCharacterSize(20);
    textObject.setFillColor(sf::Color::Black);
    textObject.setStyle(sf::Text::Regular);
    textObject.setPosition(0, 0);

    sf::Clock t;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        std::string s = text.getText(t.getElapsedTime().asSeconds());
        textObject.setString(s);

        window.clear(sf::Color::White);
        window.draw(textObject);
        window.display();
    }

    return 0;
}
