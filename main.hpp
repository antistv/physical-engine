#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

#include "modules/modules.hpp"

class basicFuncion{
    public:
        void update(sf::Sprite &object,  sf::Vector2f &velocity);
};

class myRepresent{
    public:
        void start(bool RECT_VISUAL, bool VAXUM_VISUAL);
        void rectVisualisation(sf::RenderWindow &window, bool GRAVITY, bool ELASTIC_REBOUND, bool USE_MOUSE, bool USE_KEYBOARD);
        void noGravityVisualisation(sf::RenderWindow &window,  bool USE_MOUSE, bool USE_KEYBOARD, bool VACUUM);
    
    protected:
        const double meter {3.f};
        sf::Vector2f vacumSpeed;
        double gravitySpeed {1.f};
        const double accelGravitySpeed {9.81 * meter};
        bool checkGrav {false};

        const int WINDOW_WIDTH {1280};
        const int WINDOW_HEIGHT {720};
        const double gridSize {50.f};
        const int FRAMES {30};

        sf::Vector2f velocity;        
        sf::Sprite rect;
        sf::Event event;

        basicMod basicModules;
        physicalModels physicalModel;
        basicFuncion basic;
};