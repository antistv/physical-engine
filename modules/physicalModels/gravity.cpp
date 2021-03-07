#include "../modules.hpp"

void physicalModels::gravitySys(double &gravitySpeed, sf::Vector2f &velocity, const double accelGravitySpeed, const int FRAMES){
    gravitySpeed += (accelGravitySpeed/FRAMES);
    velocity.y = gravitySpeed;
    //std::cout << gravitySpeed << '\n';
}