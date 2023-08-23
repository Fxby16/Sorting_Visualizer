#if defined(_WIN32) || defined(_WIN64)
    #define _WIN32_WINNT 0x0A00
    #include <windows.h>
#endif

#include <SDL2/SDL.h>
#include <stdio.h>
#include <utilities.h>
#include <global.h>
#include <sortings.h>

int main(int argc,char *argv[]){

#if defined(_WIN32) || defined(_WIN64)
    SetProcessDPIAware();
#endif

    if(init()){
        fprintf(stderr,"Initialization failed\n");
        return EXIT_FAILURE;
    }
    ShowMenu();
    buildArr();
    loaded=true;
    while(run){
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT: //close button pressed
                    run=false;
                    break;
                case SDL_KEYDOWN: //any key pressed
                    key=event.key.keysym.sym;
                    if(key==SDLK_q){ //q to quit (same as pressing close button)
                        run=false;
                    }
                    if(key==SDLK_f){ //f to toggle fullscreen
                        ToggleFullscreen();
                    }
                    if(key==SDLK_m){ //m to show the menu
                        ShowMenu();
                    }
                    if(key==SDLK_0){ //0 to randomize the vector
                        buildArr();
                    }
                    if(key==SDLK_1){ //1 to run bubble sort
                        if(!loaded) //if the vector is already sorted, randomize it
                            buildArr();
                        if(getText("Bubble sort    Avg. Time Complexity: θ(N^2)    Auxiliary Space: O(1)")){
                            fprintf(stderr,"Couldn't initialize the text: %s",TTF_GetError());
                            return EXIT_FAILURE;
                        }
                        BubbleSort();
                        completed=true;
                        visualize(); //visualize the vector with color green
                        completed=false; //reset all
                        loaded=false;
                        menuShowed=false;
                    }
                    if(key==SDLK_2){ //2 to run selection sort
                        if(!loaded) //if the vector is already sorted, randomize it
                            buildArr();
                        if(getText("Selection Sort    Time Complexity: O(N^2)    Auxiliary Space: O(1)")){
                            fprintf(stderr,"Couldn't initialize the text: %s",TTF_GetError());
                            return EXIT_FAILURE;
                        }
                        SelectionSort();
                        completed=true;
                        visualize(); //visualize the vector with color green
                        completed=false; //reset all
                        loaded=false;
                        menuShowed=false;
                    }
                    if(key==SDLK_3){ //3 to run insertion sort
                        if(!loaded) //if the vector is already sorted, randomize it
                            buildArr();
                        if(getText("Insertion sort    Avg. Time Complexity: θ(N^2)    Auxiliary Space: O(1)")){
                            fprintf(stderr,"Couldn't initialize the text: %s",TTF_GetError());
                            return EXIT_FAILURE;
                        }
                        InsertionSort();
                        completed=true;
                        visualize(); //visualize the vector with color green
                        completed=false; //reset all
                        loaded=false;
                        menuShowed=false;
                    }
                    if(key==SDLK_4){ //4 to run merge sort
                        if(!loaded) //if the vector is already sorted, randomize it
                            buildArr();
                        if(getText("Merge sort    Time Complexity: O(N*logN)    Auxiliary Space: O(N)")){
                            fprintf(stderr,"Couldn't initialize the text: %s",TTF_GetError());
                            return EXIT_FAILURE;
                        }
                        MergeSort(0,v.size()-1);
                        completed=true;
                        visualize(); //visualize the vector with color green
                        completed=false; //reset all
                        loaded=false;
                        menuShowed=false;
                    }
                    if(key==SDLK_5){ //5 to run quick sort
                        if(!loaded) //if the vector is already sorted, randomize it
                            buildArr();
                        if(getText("Quick sort    Avg. Time Complexity: θ(N*logN)    Auxiliary Space: O(logN)")){
                            fprintf(stderr,"Couldn't initialize the text: %s",TTF_GetError());
                            return EXIT_FAILURE;
                        }
                        QuickSort(0,v.size()-1);
                        completed=true;
                        visualize(); //visualize the vector with color green
                        completed=false; //reset all
                        loaded=false;
                        menuShowed=false;
                    }
                    if(key==SDLK_6){ //6 to run heap sort
                        if(!loaded) //if the vector is already sorted, randomize it
                            buildArr();
                        if(getText("Heap sort    Time Complexity: O(N*logN)    Auxiliary Space: O(1)")){
                            fprintf(stderr,"Couldn't initialize the text: %s",TTF_GetError());
                            return EXIT_FAILURE;
                        }
                        HeapSort(v.size());
                        completed=true;
                        visualize(); //visualize the vector with color green
                        completed=false; //reset all
                        loaded=false;
                        menuShowed=false;
                    }
                    if(key==SDLK_7){ //7 to run shell sort
                        if(!loaded) //if the vector is already sorted, randomize it
                            buildArr();
                        if(getText("Shell sort    Avg. Time Complexity: θ(N*logN)    Auxiliary Space: O(1)")){
                            fprintf(stderr,"Couldn't initialize the text: %s",TTF_GetError());
                            return EXIT_FAILURE;
                        }
                        ShellSort(v.size());
                        completed=true;
                        visualize(); //visualize the vector with color green
                        completed=false; //reset all
                        loaded=false;
                        menuShowed=false;
                    }
                    if(key==SDLK_8){ //8 to run bingo sort
                        if(!loaded) //if the vector is already sorted, randomize it
                            buildArr();
                        if(getText("Bingo sort    Avg. Time Complexity: θ(N*M (M=number of distinct elements))    Auxiliary Space: O(1)")){
                            fprintf(stderr,"Couldn't initialize the text: %s",TTF_GetError());
                            return EXIT_FAILURE;
                        }
                        BingoSort(v.size());
                        completed=true;
                        visualize(); //visualize the vector with color green
                        completed=false; //reset all
                        loaded=false;
                        menuShowed=false;
                    }
                    if(key==SDLK_9){ //9 to run comb sort
                        if(!loaded) //if the vector is already sorted, randomize it
                            buildArr();
                        if(getText("Comb sort    Avg. Time Complexity: θ(N^2 * 2^p (p=number of increments))    Auxiliary Space: O(1)")){
                            fprintf(stderr,"Couldn't initialize the text: %s",TTF_GetError());
                            return EXIT_FAILURE;
                        }
                        CombSort(v.size());
                        completed=true;
                        visualize(); //visualize the vector with color green
                        completed=false; //reset all
                        loaded=false;
                        menuShowed=false;
                    }
                    if(key==SDLK_a){ //a to run comb sort
                        if(!loaded) //if the vector is already sorted, randomize it
                            buildArr();
                        if(getText("Cocktail sort    Avg. Time Complexity: θ(N^2)    Auxiliary Space: O(1)")){
                            fprintf(stderr,"Couldn't initialize the text: %s",TTF_GetError());
                            return EXIT_FAILURE;
                        }
                        CocktailSort(v.size());
                        completed=true;
                        visualize(); //visualize the vector with color green
                        completed=false; //reset all
                        loaded=false;
                        menuShowed=false;
                    }
                    break;
            }
        }
    }
    close(); //destroying textures,renderer,window and quitting sdl

    return EXIT_SUCCESS;
}