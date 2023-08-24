# Sorting Visualizer
Sorting visualizer made with SDL.

## Sortings available
- Bubble Sort
- Selection Sort
- Insertion Sort
- Merge Sort
- Quick Sort
- Heap Sort
- Shell Sort
- Bingo Sort
- Comb Sort
- Cocktail Sort

## Requirements  
- SDL
- SDL ttf
- make (optional)
## Installation
If you are on Windows, you can use the preinstalled SDL version in SDL folder (it's the 64-bit version). If you are on Linux you can run this command to install SDL
```
sudo apt-get install libsdl2-dev libsdl2-ttf-dev
```
## Build
You can find two makefiles in makefiles folder. Move the one corresponding to your OS in the main folder and run 
```
make
```  
If you don't have make, run the command corresponding to your OS:  
#### Windows
```
g++ -I SDL/include -I include -L SDL/lib -o bin/sorting_visualizer main.cpp src/global.cpp src/sortings.cpp src/utilities.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf
```
#### Linux
```
g++ -I include -o bin/sorting_visualizer main.cpp src/global.cpp src/sortings.cpp src/utilities.cpp -lSDL2main -lSDL2 -lSDL2_ttf
```

## Execute
To run the executable file run 
```
bin/sorting_visualizer
```

## Notes
- For each sorting algorithm the time complexity and the auxiliary space are shown. Note that when best and worst case time complexity aren't the same, average time complexity is shown
