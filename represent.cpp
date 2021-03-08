#include "main.hpp"

void myRepresent::start(bool RECT_VISUAL) {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Gravity", sf::Style::Default);
    window.setFramerateLimit(FRAMES);

    while (window.isOpen()) {

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        if(RECT_VISUAL) rectVisualisation(window, true, true, true, true);
    }
}

void myRepresent::rectVisualisation(sf::RenderWindow &window, bool GRAVITY, bool ELASTIC_REBOUND, bool USE_MOUSE, bool USE_KEYBOARD) {
    sf::Texture texture;
    if (!texture.loadFromFile("textures/blue.png", sf::IntRect(0, 0, gridSize, gridSize))) {
        std::cout << "ERROR - to load texture\n";
        exit(0);
    }

    rect.setTexture(texture);

    bool moveMouse = NULL;
    bool moveKeyboard = NULL;

    if(USE_MOUSE == true) moveMouse  = basicModules.move(event, rect, window);
    if(USE_KEYBOARD == true) moveKeyboard = basicModules.moveKeyboard(event, velocity, window);

    if(moveMouse == false && moveKeyboard == false){
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

    window.clear();
    window.draw(rect);
    window.display();
}