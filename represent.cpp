#include "main.hpp"

void myRepresent::start(bool RECT_VISUAL) {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Gravity", sf::Style::Default);
    window.setFramerateLimit(FRAMES);

    while (window.isOpen()) {

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        if(RECT_VISUAL) rectVisualisation(window, true, true);
    }
}

void myRepresent::rectVisualisation(sf::RenderWindow &window, bool GRAVITY, bool ELASTIC_REBOUND) {
    rect.setSize(sf::Vector2f(gridSize, gridSize));
    rect.setFillColor(sf::Color(38, 133, 201));

    if(basicModules.move(event, rect, window) == false){
        //MODUL GRAWITACJI
        if(GRAVITY){
            if(checkGrav == false){
                gravitySpeed = 1;
                checkGrav = true;
            }
            if(basicModules.locationAllowedR(rect, WINDOW_WIDTH, WINDOW_HEIGHT)){
                physicalModel.gravitySys(gravitySpeed, velocity, accelGravitySpeed, FRAMES);
            } else {
                if(ELASTIC_REBOUND){
                    if(gravitySpeed > 2){
                        physicalModel.elasticRebound(velocity, gravitySpeed);
                    }
                }
            }
            std::cout << gravitySpeed << '\n';
        }
    } else {
        basicModules.locationAllowedR(rect, WINDOW_WIDTH, WINDOW_HEIGHT);
        //MODUL GRAWITACJI
        if(GRAVITY) checkGrav = false;
    }

    basic.update(rect, velocity);

    window.setActive();

    window.clear();
    window.draw(rect);
    window.display();
}