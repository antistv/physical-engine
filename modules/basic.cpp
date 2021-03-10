#include "modules.hpp"

bool basicMod::locationAllowedR(sf::Sprite &rect, const int WINDOW_WIDTH, const int WINDOW_HEIGHT) {
    //std::cout << rect.getPosition().x << " " << rect.getPosition().y << '\n';
    //Left colision
    if(rect.getPosition().x < 0.f){
        rect.setPosition(WINDOW_WIDTH-rect.getGlobalBounds().width, rect.getPosition().y);
    }
    //Top colision
    else if(rect.getPosition().y < 0.f){
        rect.setPosition(rect.getPosition().x, 0.f);
    }
    //Right colision
    else if(rect.getPosition().x + rect.getGlobalBounds().width > WINDOW_WIDTH){
        rect.setPosition(0, rect.getPosition().y);
    } 
    //Bottom colision
    else if(rect.getPosition().y + rect.getGlobalBounds().height >= WINDOW_HEIGHT){
        rect.setPosition(rect.getPosition().x, WINDOW_HEIGHT - rect.getGlobalBounds().height);
        return false;
    }

    return true;
}

bool basicMod::move(sf::Event event, sf::Sprite &rect, sf::RenderWindow &window, sf::Vector2f &vacumSpeed){
    if ((sf::Mouse::isButtonPressed( sf::Mouse::Left ))) {
        sf::Vector2i localPosition = sf::Mouse::getPosition( window );
        rect.setPosition ( localPosition.x, localPosition.y );
        vacumSpeed = sf::Vector2f(0, 0);

        return true;
    } else { //Nie porusza sie
        return false;
    }
}

bool basicMod::moveKeyboard(sf::Event, sf::Vector2f &velocity, sf::RenderWindow &window, sf::Vector2f &vacumSpeed){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        velocity.y -= 10;
        vacumSpeed = sf::Vector2f(0, 0);
        vacumSpeed.y = -10;
        return true;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        velocity.y += 10;
        vacumSpeed = sf::Vector2f(0, 0);
        vacumSpeed.y = 10;
        return true;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        velocity.x += 10;
        vacumSpeed = sf::Vector2f(0, 0);
        vacumSpeed.x = 10;
        return true;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        velocity.x -= 10;
        vacumSpeed = sf::Vector2f(0, 0);
        vacumSpeed.x = -10;
        return true;
    }
    return false;
}