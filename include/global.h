#ifndef GLOBAL
#define GLOBAL

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#define FONT_HEIGHT 27 //arial height with size 24
#define WINDOWED_WIDTH 1280 
#define WINDOWED_HEIGHT 720
#define RECT_WIDTH 10

extern bool run; 
extern bool completed; 
extern bool fullscreen; 
extern bool loaded; 
extern bool menuShowed; 
extern SDL_Event event; 
extern SDL_Window *window; 
extern SDL_Renderer *renderer; 
extern TTF_Font *arial; 
extern SDL_Keycode key;
extern SDL_Surface *surfaceSortInfo; 
extern SDL_Texture *textureSortInfo; 
extern SDL_Rect SortInfo_Rect; 
extern SDL_Surface *surfaceCommands; 
extern SDL_Texture *textureCommands; 
extern SDL_Rect Commands_Rect; 
extern SDL_Surface *surfaceMenu; 
extern SDL_Texture *textureMenu; 
extern SDL_Rect Menu_Rect; 
extern SDL_Color White; 

extern int WIDTH;  
extern int HEIGHT;
extern std::vector<int>v;

#endif