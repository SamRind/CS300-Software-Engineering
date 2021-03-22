Sam Rind
CS300 Project 1
Date: 18 - oct - 2020

Goal: The purpose of this project was to work with libncurses to develop
a terminal-based Linux application. The project must be using the project rubric 
and following the instructions of the library. In the end we are supposed to display
the hello world in a box while centering the box on the linux screen while getting the parameters. 

Sources: The sources are used for the program, are mostly from the instructions of the program. 
while learning about the given functions on ncurses wikipedia page. The hello world tutorial was 
also helpful in the matter of learning about building the assignment and setting up the int main. 

Code: 1. First my code includes all the important libraries needed like iostream and ncurses 
      
      2. Secondly I started with initscr() this function is helpful to initialize the terminal in curses mode. Also helps with the clearing and blank screen. 
     
      3. Thirdly i initialize all my variables because this way i dont have to worry about calling variables again and again.
         The variables are also helpful with working on parameters around the box. 
      
      4. Fourth I used Window command multiplying with win which we use to get the height and width, i.e: 12, 40 and basically setting up where the box should be starting at. 
      
      5.I learned about wborder function including all the sides of the box from the website on rubric, tldp.org. 
      I instantly knew this function would save me alot of time to set the border around. The website is: https://tldp.org/HOWTO/html_single/NCURSES-Programming-HOWTO/ 
      (Also i remember doing something like this back in 161 in python which was helpful.)
        
      6. wprintw is helpful function was interesting because it took me a while to figure out how to use the lINES and COLS thing in the function which was tricky at first.
         I tried to use my math to see if i could do something which the length of my string without being able to take the string itself in size. (Another 161 perks)

      7. Lastly, most everything worked just fine once i figured that part out from above step. The Last compilation error i had was refresh not being at correct places
         which was not anything smart but just playing around with my possibilities and again reading the documentation on refresh from tldp file. Refresh turned out to be a very simple function touse when i learned it prints out data on window by using coordinates like width and height

      8. Makefile was super easy to make. Had some issues with spaces at first but following Proffessors instructions on zoom, i made the Make file and worked just fine. 
