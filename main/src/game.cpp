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

  this->_player = AnimatedSprite(graphics, 
    "content/sprites/MyChar.png",0,0,16,16,100,100,100);
  this->_player.setupAnimations();
  this->_player.playAnimation("RunRight");

  unsigned int LAST_UPDATE_TIME = SDL_GetTicks();
  //init game loop
  while(true){
    //keyboard shenanigans
    input.beginNewFrame();

    if(SDL_PollEvent(&event)){
      if(event.type == SDL_KEYDOWN){
        if(event.key.repeat == 0){
          input.keyDownEvent(event);
        }
      } else if(event.type == SDL_KEYUP){
        input.keyUpEvent(event);
      } else if(event.type == SDL_QUIT){
        return;
      }

      if(input.wasKeyPressed(SDL_SCANCODE_ESCAPE)){
        return;
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
  this->_player.draw(graphics,100,100);
  graphics.flip();
}

void Game::update(float elapsedTime){
  this->_player.update(elapsedTime);
}
