#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>

bool run=true; 
bool completed=false;
bool fullscreen=false;
bool loaded=false; 
bool menuShowed=false; 
SDL_Event event; 
SDL_Window *window=NULL; 
SDL_Renderer *renderer=NULL; 
TTF_Font *arial=NULL; 
SDL_Keycode key;
SDL_Surface *surfaceSortInfo=NULL; 
SDL_Texture *textureSortInfo=NULL; 
SDL_Rect SortInfo_Rect; 
SDL_Surface *surfaceCommands=NULL; 
SDL_Texture *textureCommands=NULL; 
SDL_Rect Commands_Rect; 
SDL_Surface *surfaceMenu=NULL; 
SDL_Texture *textureMenu=NULL; 
SDL_Rect Menu_Rect; 
SDL_Color White={255,255,255}; 

int WIDTH=1280,HEIGHT=720; 
std::vector<int>v; 