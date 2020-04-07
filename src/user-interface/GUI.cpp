#include "user-interface/GUI.hpp"

GUI::GUI() {}

GUI::GUI(unsigned int width, unsigned int height){
    width = smax(width, MIN_WIDTH);
    height = smax(height, MIN_HEIGHT);

    window.create(sf::VideoMode(width, height), "MusicalBash", window_style);

    
    if (!playButtonTexture.loadFromFile("data/img/play_button.png")){
        std::cout << "Failed to load play button\n";
        window.close();
    }
    if (!nextButtonTexture.loadFromFile("data/img/skip_next_button.png")){
        std::cout << "Failed to load next/skip button\n";
        window.close();
    }
    if (!previousButtonTexture.loadFromFile("data/img/skip_previous_button.png")){
        std::cout << "Failed to load previous button\n";
        window.close();
    }
    if (!stopButtonTexture.loadFromFile("data/img/stop_button.png")){
        std::cout << "Failed to load stop button\n";
        window.close();
    }

    playButtonSprite.setTexture(playButtonTexture);
    nextButtonSprite.setTexture(nextButtonTexture);
    previousButtonSprite.setTexture(previousButtonTexture);
    stopButtonSprite.setTexture(stopButtonTexture);
}

bool GUI::isOpen()const{
    return window.isOpen();
}

sf::RenderWindow& GUI::getWindow(){
    return window;
}

void GUI::redraw(){
    window.clear();

    auto sz = window.getView().getSize();
    
    std::cout << sz.x << ' ' << sz.y << '\n';

    controlButtonSizeWidth = 0.05 * sz.x;
    controlButtonSizeHeight = 0.05 * sz.y;
    controlButtonSizeScaleX = controlButtonSizeWidth / buttonImageSize;
    controlButtonSizeScaleY = controlButtonSizeHeight / buttonImageSize;
    buttonSpacing = 0.9 * controlButtonSizeWidth;

    // std::cout << sz.x - 7 * controlButtonSize << ' ' << sz.y - 1.5 * controlButtonSize << '\n';
    stopButtonSprite.setPosition(sz.x - 7 * controlButtonSizeWidth, sz.y - 2 * controlButtonSizeHeight);
    stopButtonSprite.setScale(controlButtonSizeScaleX, controlButtonSizeScaleY);
    window.draw(stopButtonSprite);

    // std::cout << stopButtonSprite.getPosition().x << ' ' << stopButtonSprite.getPosition().y << '\n';

    previousButtonSprite.setPosition(stopButtonSprite.getPosition().x + controlButtonSizeWidth + buttonSpacing, stopButtonSprite.getPosition().y);
    previousButtonSprite.setScale(controlButtonSizeScaleX, controlButtonSizeScaleY);
    window.draw(previousButtonSprite);

    playButtonSprite.setPosition(previousButtonSprite.getPosition().x + controlButtonSizeWidth + buttonSpacing, stopButtonSprite.getPosition().y);
    playButtonSprite.setScale(controlButtonSizeScaleX, controlButtonSizeScaleY);
    window.draw(playButtonSprite);

    nextButtonSprite.setPosition(playButtonSprite.getPosition().x + controlButtonSizeWidth + buttonSpacing, stopButtonSprite.getPosition().y);
    nextButtonSprite.setScale(controlButtonSizeScaleX, controlButtonSizeScaleY);
    window.draw(nextButtonSprite);

    window.display();
}