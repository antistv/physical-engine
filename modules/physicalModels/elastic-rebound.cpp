#include "../modules.hpp"

void physicalModels::elasticRebound(sf::Vector2f &velocity, double &gravitySpeed){
    velocity.y -= gravitySpeed;
    gravitySpeed = 0;
}