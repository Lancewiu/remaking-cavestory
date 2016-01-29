#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <map>
#include <string>
#include <vector>
#include "sprite.h"
#include "globals.h"

class Graphics;

class AnimatedSprite : public Sprite{
public:
  AnimatedSprite();
  AnimatedSprite(Graphics &graphics, const std::string &filePath, 
    int sourceX, int sourceY, int width, int height, float posX, 
    float posY, float timeToUpdate);
  /*  Plays animation if not already playing  */
  void playAnimation(std::string animation, bool once = false);

  /*  Updates sprite animation  */
  void update(int elapsedTime);

  void draw(Graphics &graphics, int x, int y);

  /*  Sets up all animations for sprite */
  virtual void setupAnimations();
protected:
  bool _currentAnimationOnce;
  double _timeToUpdate;
  std::string _currentAnimation;

  /*  Adds animation to animations map */
  void addAnimation(int frames, int x, int y, std::string name,
    int width, int height, Vector2 offset);

  /*  Clear animations map  */
  void resetAnimations();

  /*  Pauses current animation  */
  void stopAnimation();

  /*  Visibility of sprite  */
  void setVisible(bool visible);
  
  /*  Run after animation ends  */
  virtual void animationDone(std::string currentAnimation);
private:
  bool _visible;
  int _frameIndex;
  double _timeElapsed;

  std::map<std::string, std::vector<SDL_Rect> > _animations;
  std::map<std::string, Vector2> _offsets;
};
#endif
