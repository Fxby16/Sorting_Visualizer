#include <global.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int GetMenu(){ //function that creates menu texture
const char text[]="Press one button at a time to avoid bugs\n0: Generate new array    1: Bubble Sort    2: Selection Sort    3: Insertion Sort    4: Merge Sort    5: Quick Sort    6: Heap Sort    7: Shell Sort    8: Bingo Sort    9: Comb Sort    a: Cocktail Sort    f: Toggle Fullscreen    q: quit";
    if(textureMenu!=NULL){ //destroying texture menu if it was already created with different resolution (might be unnecessary)
        SDL_DestroyTexture(textureMenu);
        textureMenu=NULL;
    }
    surfaceMenu=TTF_RenderText_Blended_Wrapped(arial,text,White,WIDTH); //initializing surface that contains the text
    if(surfaceMenu==NULL){
        fprintf(stderr,"Couldn't initialize surfaceMenu: %s",TTF_GetError());
        return EXIT_FAILURE;
    }
    textureMenu=SDL_CreateTextureFromSurface(renderer,surfaceMenu); //initializing texture that contains the text
    if(textureMenu==NULL){
        fprintf(stderr,"Couldn't initialize textureMenu: %s",TTF_GetError());
        return EXIT_FAILURE;
    }

    Menu_Rect.x=0;  //controls the rect's x coordinate 
    Menu_Rect.y=0; // controls the rect's y coordinte
    Menu_Rect.w=surfaceMenu->w; // controls the width of the rect
    Menu_Rect.h=surfaceMenu->h; // controls the height of the rect

    SDL_FreeSurface(surfaceMenu); //surfaceMenu not needed anymore, if needed, it will be initialized again
    surfaceMenu=NULL;

    return EXIT_SUCCESS;
}

void ShowMenu(){ //function that clears the renderer and shows menu texture
    SDL_SetRenderDrawColor(renderer,38,38,168,0); //setting draw color
    SDL_RenderClear(renderer); //clearing the renderer with base background color (selected in the line above)

    SDL_RenderCopy(renderer,textureMenu,NULL,&Menu_Rect); //copy menu texture
    SDL_RenderPresent(renderer); //move everything from the hidden target to the actual window

    menuShowed=true; //set menu as currently on screen
}

bool init(){ //function that initialize everything needed
    if(SDL_Init(SDL_INIT_VIDEO)<0){ //initializing video subsystem; automatically initializes the events subsystem
        fprintf(stderr,"Couldn't initialize SDL: %s\n",SDL_GetError());
        return EXIT_FAILURE;
    }
    if(TTF_Init()<0){ //initializing sdl_ttf
        fprintf(stderr,"Couldn't initialize TTF: %s\n",TTF_GetError());
        return EXIT_FAILURE;
    }

    if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1")) //enabling linear filtering
        fprintf(stderr,"Warning: Couldn't enable linear texture filtering\n");
    
    window=SDL_CreateWindow("Sorting Visualizer by Fxby16",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,SDL_WINDOW_SHOWN); //initializing the window
    if(window==NULL){
        fprintf(stderr,"Couldn't create the window: %s",SDL_GetError());
        return EXIT_FAILURE;
    }

    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); //initializing the renderer (hardware acceleration enabled)
    if(renderer==NULL){
        fprintf(stderr,"Couldn't create the renderer: %s",SDL_GetError());
        return EXIT_FAILURE;
    }

    arial=TTF_OpenFont("fonts/arial.ttf",24); //initializing the font
    if(arial==NULL){
        fprintf(stderr,"Couldn't create the font: %s",SDL_GetError());
        return EXIT_FAILURE;
    }

    //initializing commands info text
    surfaceCommands=TTF_RenderText_Blended_Wrapped(arial,"q: quit    m: menu",White,0); //initializing surface that contains the text
    if(surfaceCommands==NULL){
        fprintf(stderr,"Couldn't initialize surfaceCommands: %s",TTF_GetError());
        return EXIT_FAILURE;
    }
    textureCommands=SDL_CreateTextureFromSurface(renderer,surfaceCommands); //initializing texture that contains the text
    if(textureCommands==NULL){
        fprintf(stderr,"Couldn't initialize textureSortInfo: %s",TTF_GetError());
        return EXIT_FAILURE;
    }

    Commands_Rect.x=WIDTH-surfaceCommands->w;  //controls the rect's x coordinate 
    Commands_Rect.y=0; // controls the rect's y coordinte
    Commands_Rect.w=surfaceCommands->w; // controls the width of the rect
    Commands_Rect.h=surfaceCommands->h; // controls the height of the rect

    SDL_FreeSurface(surfaceCommands); //surfaceCommands not needed anymore, if needed, it will be initialized again
    surfaceCommands=NULL;

    if(GetMenu()){ //creating menu texture
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}

void close(){ //function that close sdl
    SDL_DestroyTexture(textureSortInfo);
    SDL_DestroyTexture(textureCommands);
    SDL_DestroyTexture(textureMenu);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int getText(const char *text){ //creating texture that contains the text passed as parameter (current sorting algorithm info)
    surfaceSortInfo=TTF_RenderUTF8_Blended(arial,text,White); //initializing surface that contains the text
    if(surfaceSortInfo==NULL){
        fprintf(stderr,"Couldn't initialize surfaceSortInfo: %s",TTF_GetError());
        return EXIT_FAILURE;
    }
    textureSortInfo=SDL_CreateTextureFromSurface(renderer,surfaceSortInfo); //initializing texture that contains the text
    if(textureSortInfo==NULL){
        fprintf(stderr,"Couldn't initialize textureSortInfo: %s",TTF_GetError());
        return EXIT_FAILURE;
    }

    SortInfo_Rect.x=0;  //controls the rect's x coordinate 
    SortInfo_Rect.y=0; // controls the rect's y coordinte
    SortInfo_Rect.w=surfaceSortInfo->w; // controls the width of the rect
    SortInfo_Rect.h=surfaceSortInfo->h; // controls the height of the rect

    SDL_FreeSurface(surfaceSortInfo); //surfaceSortInfo not needed anymore, if needed, it will be initialized again
    surfaceSortInfo=NULL;

    return EXIT_SUCCESS;
}

void visualize(int x=-1,int y=-1,int z=-1){ //function that visualize the vector on the screen
    SDL_SetRenderDrawColor(renderer,38,38,168,0); //setting draw color
    SDL_RenderClear(renderer); //clearing the renderer with base background color (selected in the line above)

int j=0;
    for(int i=0;i<WIDTH;i+=RECT_WIDTH){ //loop for visualization (it goes while it have not reached the windows' width)
        SDL_PumpEvents(); //event queue update
        SDL_Rect rect; //rectangle to draw
        rect.x=i; //the x location of the rectangle's upper left corner
        rect.y=HEIGHT-v[j]; //the y location of the rectangle's upper left corner
        rect.w=RECT_WIDTH; //the width of the rectangle
        rect.h=v[j]; //the height of the rectangle

        if(completed){ //true only when the vector is sorted, it draws every rectangle green
            SDL_SetRenderDrawColor(renderer,27,228,37,0);
            SDL_RenderDrawRect(renderer, &rect);
        }else if(j==x){ //first vector cell to highlight
            SDL_SetRenderDrawColor(renderer,255,0,0,0); 
            SDL_RenderFillRect(renderer, &rect);
        }else if(j==y){ //second vector cell to highlight
            SDL_SetRenderDrawColor(renderer,255,255,0,0);
            SDL_RenderFillRect(renderer, &rect);
        }else if(j==z){ //third vector cell to highlight 
            SDL_SetRenderDrawColor(renderer,27,228,37,0);
            SDL_RenderFillRect(renderer, &rect);
        }else{  //the current vector cell should not be highlighted, just drawn
            SDL_SetRenderDrawColor(renderer,255,255,255,0);
            SDL_RenderDrawRect(renderer,&rect);
        }
        j++; //move to the next cell
    }
    if(textureSortInfo!=NULL) //if the function is visualizing a sorting, show the info
        SDL_RenderCopy(renderer,textureSortInfo,NULL,&SortInfo_Rect);
    if((textureCommands!=NULL && completed) || (x==-1 && y==-1 && z==-1)) //if nothing is being executed, show commands
        SDL_RenderCopy(renderer,textureCommands,NULL,&Commands_Rect);
    SDL_RenderPresent(renderer); //move everything from the hidden target to the actual window
}

void buildArr(){ //function that fill the vector with random numbers and visualize it
    v.resize(WIDTH/RECT_WIDTH); //resize the vector considering current window width
    textureSortInfo=NULL; //to avoid that the text remains on the screen when it shouldn't
    srand(time(NULL));
    for(int i=0;i<v.size();i++){ //generating every number (the number should always be <= to the height were the text starts)
        v[i]=rand()%(HEIGHT-FONT_HEIGHT);
    }
    loaded=true; //the vector has been randomized
    if(!menuShowed) //if the menu is not on screen, visualize the new generated vector
        visualize();
}

void ToggleFullscreen() {
    fullscreen=!fullscreen;
    bool ResizeEvent=false;
    if(fullscreen){
        SDL_SetWindowFullscreen(window,SDL_WINDOW_FULLSCREEN_DESKTOP); //set fullscreen mode
        SDL_GetWindowSize(window,&WIDTH,&HEIGHT);

        while(!ResizeEvent){ //wait for the update confirmation
            while(SDL_PollEvent(&event)){
                if(event.window.event==SDL_WINDOWEVENT_EXPOSED){
                    ResizeEvent=true;
                    break;
                }
            }
        }
    }
    else{
        SDL_SetWindowFullscreen(window,0); //set windowed mode
        HEIGHT=WINDOWED_HEIGHT;
        WIDTH=WINDOWED_WIDTH;

        while(!ResizeEvent){ //wait for the update confirmation
            while(SDL_PollEvent(&event)){
                if(event.window.event==SDL_WINDOWEVENT_EXPOSED){
                    ResizeEvent=true;
                    break;
                }
            }
        }
        SDL_SetWindowPosition(window,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED);
    }
    Commands_Rect.x=WIDTH-Commands_Rect.w;
    buildArr();
    GetMenu();
    ShowMenu();
}