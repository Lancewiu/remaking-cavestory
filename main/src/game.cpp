#include <SDL2/SDL.h>

#include "game.h"
#include "graphics.h"
#include "input.h"

namespace{
  /* configuration for 50 fps, which cavestory runs at */
  const int FPS = 50;
  const int MAX_FRAME_TIME = 5*1000/FPS;
}

Game::Game(){
  SDL_Init(SDL_INIT_EVERYTHING);
  this->gameLoop();
}

Game::~Game(){}

void Game::gameLoop(){
  Graphics graphics;
  Input input;
  SDL_Event event;

  this->_player = Player(graphics,100,100);

  unsigned int LAST_UPDATE_TIME = SDL_GetTicks(); 
  //init game loop
  while(true){
    //keyboard shenanigans
    input.beginNewFrame();

    //temporary state of most recent direction pressed.
    SDL_Scancode mostRecentDirection = SDL_SCANCODE_UNKNOWN;

    if(SDL_PollEvent(&event)){
      if(event.type == SDL_KEYDOWN){
        if(event.key.repeat == 0){
          input.keyDownEvent(event);
        }
      }else if(event.type == SDL_KEYUP){
        input.keyUpEvent(event); 
      }else if(event.type == SDL_QUIT){
        return;
      }

      /*  Keyboard events  
          Modified from original tutorial to remove key bias
          (where holding left key negates checking for right key)*/
      if(input.wasKeyPressed(SDL_SCANCODE_ESCAPE)){
        return;
      }

      if(input.wasKeyPressed(SDL_SCANCODE_LEFT)){
        mostRecentDirection = SDL_SCANCODE_LEFT;
      }
      if(input.wasKeyPressed(SDL_SCANCODE_RIGHT)){
        mostRecentDirection = SDL_SCANCODE_RIGHT;
      }

      if(input.isKeyHeld(SDL_SCANCODE_LEFT) && 
          input.isKeyHeld(SDL_SCANCODE_RIGHT)){
        if(mostRecentDirection == SDL_SCANCODE_LEFT){
          this->_player.moveLeft();
        }else if(mostRecentDirection == SDL_SCANCODE_RIGHT){
          this->_player.moveRight();
        }
      }else if(!(input.isKeyHeld(SDL_SCANCODE_LEFT) || 
          input.isKeyHeld(SDL_SCANCODE_RIGHT))){
        this->_player.stopMoving();
        mostRecentDirection = SDL_SCANCODE_UNKNOWN;
      }else{
        if(input.isKeyHeld(SDL_SCANCODE_LEFT)){
          this->_player.moveLeft();
        }
        if(input.isKeyHeld(SDL_SCANCODE_RIGHT)){
          this->_player.moveRight();
        }
      }
    }

    //update times
    const unsigned int CURRENT_TIME_MS = SDL_GetTicks();
    unsigned int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
    this->update(
      std::min<unsigned int>(ELAPSED_TIME_MS, MAX_FRAME_TIME));
    LAST_UPDATE_TIME = CURRENT_TIME_MS;

    this->draw(graphics);
  }
}

void Game::draw(Graphics &graphics){
  graphics.clear();
  this->_player.draw(graphics);
  graphics.flip();
}

void Game::update(float elapsedTime){
  this->_player.update(elapsedTime);
}
