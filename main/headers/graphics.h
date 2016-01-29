#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <map>
#include <string>

struct SDL_Window;
struct SDL_Renderer;

/* Holds all information dealing with graphics in our game */
class Graphics {
  public:
    Graphics();
    ~Graphics();

    /*  Loads image into spritesheets map if does not exist. 
        Thus, images will only be loaded once.
        
        RETURN: Image from map */
    SDL_Surface* loadImage(const std::string &filePath);

    /*  Draws texture to screen */
    void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

    /*  Renders everything to the screen  */
    void flip();

    /*  Clears the screen */
    void clear();

    SDL_Renderer* getRenderer() const;
  private:
    SDL_Window* _window;
    SDL_Renderer* _renderer;
    
    /*  All loaded spritesheets */
    std::map<std::string, SDL_Surface*> _spriteSheets;
};

#endif
