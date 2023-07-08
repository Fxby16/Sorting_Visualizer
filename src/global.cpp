#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>

bool run=true; //variable for the main loop
bool completed=false; //variable to set when sorting is completed to visualize everything green
bool fullscreen=false; //variable to check if fullscreen is on or off
bool loaded=false; //true if the array has been randomized, false if already sorted
bool menuShowed=false; //true if the menu is currently on screen, false if not
SDL_Event event; //variable for event poll
SDL_Window *window=NULL; //main window
SDL_Renderer *renderer=NULL; //main renderer
TTF_Font *arial=NULL; //text font
SDL_Keycode key;
SDL_Surface *surfaceSortInfo=NULL; //surface that contains current sorting algorithm info
SDL_Texture *textureSortInfo=NULL; //texture that contains current sorting algorithm info
SDL_Rect SortInfo_Rect; //rectangle where textureSortInfo will be rendered
SDL_Surface *surfaceCommands=NULL; //surface with commands info to show when the sorting is completed
SDL_Texture *textureCommands=NULL; //texture with commands info to show when the sorting is completed
SDL_Rect Commands_Rect; //rectangle where textureCommands will be rendered
SDL_Surface *surfaceMenu=NULL; //surface that contains the menu
SDL_Texture *textureMenu=NULL; //texture that contains the menu
SDL_Rect Menu_Rect; //rectangle where textureMenu will be rendered
SDL_Color White={255,255,255}; //text color

int WIDTH=1280,HEIGHT=720; //current size of the window
int WINDOWED_WIDTH=1280,WINDOWED_HEIGHT=720,RECT_WIDTH=8; //size of the window in windowed mode and width of every rectangle
std::vector<int>v; //vector for data