#include "input.h"

/*
    Input class
    Keyboard state tracking
*/

//called at beginning of new frame
//reset keys no longer relevent
void Input::beginNewFrame(){
  this->_pressedKeys.clear();
  this->_releasedKeys.clear();
}

//called whenever key is released
void Input::keyUpEvent(const SDL_Event& event){
  this->_releasedKeys[event.key.keysym.scancode] = true;
  this->_heldKeys[event.key.keysym.scancode] = false;
}

//called whenever key is pressed
void Input::keyDownEvent(const SDL_Event& event){
  this->_pressedKeys[event.key.keysym.scancode] = true;
  this->_heldKeys[event.key.keysym.scancode] = true;
}

//Check if certain key pressed
bool Input::wasKeyPressed(SDL_Scancode key){
  return this->_pressedKeys[key]; 
}

//Check if certain key released
bool Input::wasKeyReleased(SDL_Scancode key){
  return this->_releasedKeys[key];
}

//Check if certain key held
bool Input::isKeyHeld(SDL_Scancode key){
  return this->_heldKeys[key];
}
