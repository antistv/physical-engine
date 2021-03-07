#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

#include "modules/modules.hpp"

class basicFuncion{
    public:
        void update(sf::RectangleShape &object,  sf::Vector2f &velocity);
};

class myRepresent{
    public:
        void start(bool RECT_VISUAL);
        void rectVisualisation(sf::RenderWindow &window, bool GRAVITY, bool ELASTIC_REBOUND);
    
    protected:
        const double meter {3.f};
        double gravitySpeed {1.f};
        const double accelGravitySpeed {9.81 * meter};
        bool checkGrav {false};

        const int WINDOW_WIDTH {1280};
        const int WINDOW_HEIGHT {720};
        const double gridSize {50.f};
        const int FRAMES {30};

        sf::Vector2f velocity;        
        sf::RectangleShape rect;
        sf::Event event;

        basicMod basicModules;
        physicalModels physicalModel;
        basicFuncion basic;
};