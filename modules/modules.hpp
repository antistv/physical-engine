#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

class physicalModels{
    public:
        void gravitySys(double &gravitySpeed, sf::Vector2f &velocity, const double accelGravitySpeed, const int FRAMES);
        void elasticRebound(sf::Vector2f &velocity, double &gravitySpeed);
};

class basicMod{
    public:
        bool move(sf::Event event, sf::Sprite &rect, sf::RenderWindow &window);
        bool moveKeyboard(sf::Event, sf::Vector2f &velocity, sf::RenderWindow &window);
        bool locationAllowedR(sf::Sprite &rect, const int WINDOW_WIDTH, const int WINDOW_HEIGHT);
};

class forces{
    public:
        float newTonToJ(float newton);
};