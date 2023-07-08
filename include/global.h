#ifndef GLOBAL
#define GLOBAL

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#define FONT_HEIGHT 27 //arial height with size 24

extern bool run; //variable for the main loop
extern bool completed; //variable to set when sorting is completed to visualize everything green
extern bool fullscreen; //variable to check if fullscreen is on or off
extern bool loaded; //true if the array has been randomized, false if already sorted
extern bool menuShowed; //true if the menu is currently on screen, false if not
extern SDL_Event event; //variable for event poll
extern SDL_Window *window; //main window
extern SDL_Renderer *renderer; //main renderer
extern TTF_Font *arial; //text font
extern SDL_Keycode key;
extern SDL_Surface *surfaceSortInfo; //surface that contains current sorting algorithm info
extern SDL_Texture *textureSortInfo; //texture that contains current sorting algorithm info
extern SDL_Rect SortInfo_Rect; //rectangle where textureSortInfo will be rendered
extern SDL_Surface *surfaceCommands; //surface with commands info to show when the sorting is completed
extern SDL_Texture *textureCommands; //texture with commands info to show when the sorting is completed
extern SDL_Rect Commands_Rect; //rectangle where textureCommands will be rendered
extern SDL_Surface *surfaceMenu; //surface that contains the menu
extern SDL_Texture *textureMenu; //texture that contains the menu
extern SDL_Rect Menu_Rect; //rectangle where textureMenu will be rendered
extern SDL_Color White; //text color

extern int WIDTH;  //current size of the window
extern int HEIGHT;
extern int WINDOWED_WIDTH; //size of the window in windowed mode and width of every rectangle
extern int WINDOWED_HEIGHT;
extern int RECT_WIDTH;
extern std::vector<int>v; //vector for data

#endif