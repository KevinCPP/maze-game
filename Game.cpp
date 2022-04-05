#include "Game.h"
#include "TextButton.h"

Game::Game(){
    engine = std::make_unique<Engine>(sf::VideoMode(1280, 720), "title");
    currentState = mainMenu;
}

void Game::handleEvents(){
    sf::Event event;
    while(engine->pollEvent(event)){
        if(event.type == sf::Event::Closed){
            engine->close();
        }
    }     
}

void Game::runMainLoop(){
    
    sf::Font test;
    test.loadFromFile("assets/default.ttf");

    TextButton t(sf::Vector2f(10, 10), sf::Color::White, sf::Color::Yellow, L"test", test, 32);

    while(engine->windowIsOpen()){
        handleEvents();
        
        engine->clear();  
      
        switch(currentState){
            case mainMenu:
                if(t.pollClicked(engine->getMousePos()))
                    std::cout << "Clicked\n";

                engine->draw(t);
                displayMainMenu();
                break;
            case optionsMenu:
                displayOptionsMenu();
                break;
            case inGame:
                displayGame();
                break;
        }

        engine->display();
    }
}

void Game::displayMainMenu(){
        
}

void Game::displayOptionsMenu(){

}

void Game::displayGame(){

}
