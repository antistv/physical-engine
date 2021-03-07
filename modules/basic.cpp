#include "modules.hpp"

bool basicMod::locationAllowedR(sf::RectangleShape &rect, const int WINDOW_WIDTH, const int WINDOW_HEIGHT) {
    //std::cout << rect.getPosition().x << " " << rect.getPosition().y << '\n';
    //Left colision
    if(rect.getPosition().x < 0.f){
        rect.setPosition(0.f, rect.getPosition().y);
    }
    //Top colision
    else if(rect.getPosition().y < 0.f){
        rect.setPosition(rect.getPosition().x, 0.f);
    }
    //Right colision
    else if(rect.getPosition().x + rect.getGlobalBounds().width > WINDOW_WIDTH){
        rect.setPosition(WINDOW_WIDTH - rect.getGlobalBounds().width, rect.getPosition().y);
    }
    //Bottom colision
    else if(rect.getPosition().y + rect.getGlobalBounds().height >= WINDOW_HEIGHT){
        rect.setPosition(rect.getPosition().x, WINDOW_HEIGHT - rect.getGlobalBounds().height);
        return false;
    }

    return true;
}

bool basicMod::move(sf::Event event, sf::RectangleShape &rect, sf::RenderWindow &window){
    if ((sf::Mouse::isButtonPressed( sf::Mouse::Left ))) {
        sf::Vector2i localPosition = sf::Mouse::getPosition( window );
        rect.setPosition ( localPosition.x, localPosition.y );

        return true;
    } else { //Nie porusza sie
        return false;
    }
}