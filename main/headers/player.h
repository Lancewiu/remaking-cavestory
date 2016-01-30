#ifndef PLAYER_H
#define PLAYER_H

#include "animatedsprite.h"
#include "globals.h"

class Graphics;

class Player : public AnimatedSprite{
public:
  Player();
  Player(Graphics &graphics, float x, float y);
  void draw(Graphics &graphics);
  void update(float elapsedTime);

  /*  Movement methods */
  void moveLeft();
  void moveRight();
  void stopMoving();

  /*  From AnimatedSprite  */
  virtual void animationDone(std::string currentAnimation);
  virtual void setupAnimations();
private:
  float _dx, _dy;
  Direction _facing;
};

#endif
