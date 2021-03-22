//Sam Rind
//CS300_P1
//18-10-2020
//Hello.cpp


#include <iostream>
#include <ncurses.h>


using namespace std; 

int main()
{
    initscr();      //Curses mode 
    int left, right, top, bottom, l_corner, r_corner, bl_corner, br_corner; //Variables for parameters.
    left = right = top = bottom = l_corner = r_corner = bl_corner = br_corner = (int)'#'; //setting all the corners for #
    WINDOW * win = newwin(12, 40, (LINES-12)/2, (COLS-40)/2); //Setting the box by using coordinates and terminal size by using WINDOW command
    refresh(); //Print on the real screen 
     
    //using W because i have created something on window and it can print on linux using the screen size 
    wborder(win, left, right, top, bottom, l_corner, r_corner, bl_corner, br_corner);  //Making borders with the use of wborder from tldp documentation 
    mvprintw((LINES/2), (COLS-13)/2, "Hello World!!"); //Prints hello world while getting the string in the middle using LINES and COLS 
    wrefresh(win); //using W because i have created something on window and it can print on linux using the screen size 
    move(LINES-1, COLS-1); //Moving the cursor to the bottom right corner of the screen as it uses the given parameters from subtraction to do that
    refresh();        //Print on screen  
    getch();          //user input
    endwin();         //Ending cursor mode

    return 0; 
}



