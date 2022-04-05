#include "Engine.h"

//constructor
Engine::Engine(const sf::VideoMode& videoMode, const std::string& title, const uint32_t style, const uint32_t TPS){
    //set up the render window
    window.create(videoMode, title, style);
    
    //set tps to be used for logic cycles
    ticksPerSecond = TPS;  
  
    //directory the default font is in
    std::string fontDir = "assets/default.ttf";

    //load the font
    if(!defaultFont.loadFromFile(fontDir))
        std::cout << "Error loading the font. Check if it exists at: " << fontDir << std::endl;
    
}

//calculates the FPS from the time elapsed since this function was last called.
//this function is private and should only be called in display()
double Engine::calculateFPS(){
    //how many microseconds have elapsed since this function was last called
    double elapsed = framerateClock.getElapsedTime().asMicroseconds();
    //calculate FPS based on time elapsed
    lastFPS = 1000000 / elapsed;
    //restart the clock
    framerateClock.restart();
    //return the value (is also stored in lastFPS which is a class member)
    return lastFPS;
}

//calculates how many logic cycles have happened since this function was last called.
//this function is private and should only be called in display()
double Engine::calculateLC(){
    //how many microseconds have elapsed since this function was last called
    double elapsed = logicClock.getElapsedTime().asMicroseconds();
    //calculate how many ticks should have happened during that window
    lastLC = (elapsed * ticksPerSecond) / 1000000;
    //restart the clock
    logicClock.restart();
    //return the value (is also stored in lastLC which is a class member)
    return lastLC;
}

void Engine::close(){
    window.close();
}

bool Engine::windowIsOpen(){
    return window.isOpen();
}

bool Engine::pollEvent(sf::Event& event){
    return window.pollEvent(event);
}

//should be called at the start of each frame to clear off the previous frame
void Engine::clear(){
    window.clear();
}

//draw something to the screen. must be called between clear() and display()
void Engine::draw(const sf::Drawable& drawable, const sf::RenderStates& states){
    window.draw(drawable, states);
}

//should be called after draw() has been called for everything to display it all to the screen
void Engine::display(){
    //display everything that was drawn this frame to the screen
    window.display();
    //calculate logic cycles elapsed since the last display() statement
    calculateLC();
    //calculate the FPS from time elapsed since the last display() statement
    calculateFPS();
}

//returns the size of the rendering region of the window
sf::Vector2u Engine::getResolution(){
    return window.getSize();
}

sf::Vector2f Engine::getMousePos(){
    sf::Vector2i mousePos2i = sf::Mouse::getPosition(window);
    sf::Vector2f mousePos2f;
    mousePos2f.x = (float)mousePos2i.x;
    mousePos2f.y = (float)mousePos2i.y;
    return mousePos2f;
}

double Engine::getLogicCycles(){
    return lastLC;
}

/*
    public function that will return lastFPS (the fps at the time it was last calculated using calculateFPS()).
    
    Why I have two separate functions for this: if there was one public function for calculating FPS, and the
    function was called twice within the same frame by accident, it would end up restarting the clock twice in
    one frame, therefore making the results inaccurate. Doing it this way allows the function to be called as many
    times as you like without it affecting the result. calculateFPS() is a private function and it's handled within
    this class, so there won't be an issue with calling it twice in one frame.
*/
double Engine::getFramerate(){
    return lastFPS;
}

sf::Font Engine::getFont(){
    return defaultFont;
}

void Engine::setResolution(uint32_t x, uint32_t y) {
    std::cout << "not implemented, Engine::setResolution()\n";
}

void Engine::setTitle(const std::string& title) {
    std::cout << "not implemented, Engine::setTitle()\n";
}

void Engine::setTPS(uint32_t tps){
    std::cout << "not implemented, Engine::setTPS()\n";
}





