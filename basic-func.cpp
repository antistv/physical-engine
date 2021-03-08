#include "main.hpp"

void basicFuncion::update(sf::Sprite &object, sf::Vector2f &velocity){
    object.move(velocity.x, velocity.y);
    velocity.x=0; velocity.y=0;
}