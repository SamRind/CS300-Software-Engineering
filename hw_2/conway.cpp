//Sam Rind
//CS300
//Project 2
//11-01-2020
//Conway's Game Of Life

#include <iostream>
#include <ncurses.h>
#include <cctype>
#include <chrono>
#include <vector>
#include <thread>

#define ALIVE "X"
#define DEAD " "
#define QUIT (int) 'q'
#define PLAYPAUSE (int) 'p'
#define STEP (int) 'n'

using namespace std; 

//PROTOTYPES
void set_grid(vector<vector<int>> &old_grid); 
void draw(vector<vector<int>> &old_grid); 
int play(vector<vector<int>> &old_grid); 
int pause(vector<vector<int>> &old_grid, int &x, int &y, int &choice); 
void update_grid(vector<vector<int>> &old_grid); 

const float FRAME_RATE = 0.5; 

//MAIN 
int main()
{
    initscr(); 
    noecho(); 
    cbreak(); 
    nodelay(stdscr, TRUE); 
    keypad(stdscr, TRUE);
    int x = 0; 
    int y = 0; 
    vector<vector<int>> old_grid; 
    int choice; 
    set_grid(old_grid); 
    choice = getch();

    do
    {
        choice = pause(old_grid, x, y, choice); 
        if(choice == PLAYPAUSE)
            choice = play(old_grid);
    }while(choice != QUIT && choice == PLAYPAUSE);
    endwin(); 
    return 0; 
}

//Initializing and Filling the array 
void set_grid(vector<vector<int>> &old_grid)
{
    for(int w = 0; w < LINES; ++w)
    {
        vector<int>n; 
        for(int h = 0; h < COLS; ++h)
        {
            n.push_back(0);
        }
        old_grid.push_back(n);
    }
}

//Print the screen according to the 
void draw(vector<vector<int>> &old_grid)
{
    for(int w = 0; w < LINES; ++w)
    {
        for(int h = 0; h < COLS; ++h)
        {
            if(old_grid[w][h] == 1)
            {
                mvprintw(w, h, ALIVE);
            }
            else
            {
                mvprintw(w, h, DEAD); 
            }
        }
    }
}

//Updating the grid with the changes made
void update_grid(vector<vector<int>> &grid)
{
    curs_set(0); 
    vector<vector<int>> new_grid; 

    for (int l = 0; l < LINES - 1; ++l)
    { 
        vector <int> temp;
        for (int m = 0; m < COLS - 1; ++m) 
        { 
            int aliveCells = 0; 
            if(l == 0 || l == LINES - 1 || m == 0 || m == COLS - 1)
            {
                temp.push_back(0); 
            }
            else
            {
                for (int i = -1; i < 2; ++i) 
                    for (int j = -1; j < 2; ++j) 
                        aliveCells +=  grid[l + i] [m + j]; 

                aliveCells -= grid[l][m]; 

                //Rules: 

                if ((grid[l][m] == 1) &&  (aliveCells < 2)) 
                    temp.push_back(0); 

                // Cell dies due to over population 
                else if ((grid[l][m] == 1) && (aliveCells > 3)) 
                    temp.push_back(0); 

                // A new cell is born 
                else if ((grid[l][m] == 0) && (aliveCells == 3)) 
                    temp.push_back(1); 

                // Remains the same 
                else
                    temp.push_back(grid[l][m]); 
            }
        } 
        new_grid.push_back(temp); 
    }
    grid = new_grid; 
}

//Play the game 
int play(vector<vector<int>> &grid)
{
    nodelay(stdscr, TRUE); 
    int choice;
    do
    {
        curs_set(0); 
        update_grid(grid);        
        int seconds = 1000 * FRAME_RATE; //delay screen frames
        this_thread::sleep_for(chrono::milliseconds(seconds)); 
        draw(grid);  
        curs_set(0); 
        refresh(); 
        choice = getch(); 

    }while(choice != PLAYPAUSE && choice != QUIT); 
    return choice; 
}

//Pause to play the game and this is how the game starts in paused mode
int pause(vector<vector<int>> &old_grid, int &x, int &y, int &choice)
{
    nodelay(stdscr, FALSE); 

    do
    {
        switch(choice)
        {
            case KEY_UP: 
                if(y == 0)
                {
                    y = 1; 
                }
                else
                    --y; 
                break; 

            case KEY_DOWN:
                if(y == LINES) 
                {
                    y = LINES -1;
                }
                else
                    ++y; 
                break; 

            case KEY_RIGHT:
                if(x == COLS) 
                {
                    x = COLS - 1; 
                }
                else
                    ++x; 
                break; 

            case KEY_LEFT:
                if(x == 0)
                {
                    x = 1; 
                }
                else
                    --x; 
                break;

            case (int) 'x':
                if(old_grid[y][x] == 0)
                    old_grid[y][x] = 1; 
                else
                    old_grid[y][x] = 0;
                choice = 0; 
                break; 

            case QUIT:
                break; 

            case STEP:
                update_grid(old_grid);
                break; 
        }

        draw(old_grid); 
        move(y, x);     
        choice = mvgetch(y, x); 
        curs_set(1);

    }while(choice != PLAYPAUSE && choice != QUIT);
    return choice;
}
