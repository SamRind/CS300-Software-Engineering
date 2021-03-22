Sam Rind
CS300
11-01-2020
Conways Game Of Life
Project 2


GOAL: The purpose of this project was to work with ncurses to make a game, Conways game of life. 
It is a terminal-based adventure game using ncurses. The program was tested according to the program guidelines and it works for all the requirments
asked from the assignment. The program works perfectly fine after fixing of the bugs and reading much needed documentation online for ncurses and
vectors. Furthermore, details of the programs are written below with the sources cited that were used for this program: 

CODE:   

    1.  The program includes all the libraries that are needed for this programs execution. The new one being chrono and thread library. 

    2. Secondly the screen starts in a paused mode for the user to start entering the keys X. 

    3. The program has two modes play and pause. This part was really hard to figure out because i kept getting seg faults whenever I was trying to go back and forth between the games. After reading alot of cited resources i figured out that my problem was just not having enough of x and y coordinates at the right places and when i was calling my functions, they were really off. which was causing the seg faults and took me a long time to figure out.
    4. Forth thing was trying to figure out the update grid function, which took most of the time to figure out, the biggest help with this was lots of documentaiton online, I could not figure out why my screen was always one off from where it was suppose to be. I also half way through the game realized how i was calling the refresh in wrong places which was causing massive problems with my cursors. 
        The above point also was important for the glider to work properly which it did not the entire time until i tried to submit the assignment 
        because of many reasons but one big one being that my for loops in the update function were not nested properly and the cells were not 
        checking the alive or the dead neighbours properly, this made all the difference in the program and it started working fine. Glider was also a
        important because of the whole simulation of Conways game of life which is meant to be and getting that part right took a long time.
    5. The cursor set helped me refresh my cursor and reset it at the right places because without that it was almost impossible to get my cursor to spot moving and would always be away from where i was trying to print. This also came from the help from ncurses libraries. 
    6. The use of chrono was the easy one because Bart used it in one the example programs he showed us in the class. So that was the easiest part of the entire game and probably, the do while loops. 
    7. About do while loops, it was much easier to do them in seperate function which i realized was important because inside the int main was getting really big and only giving more bugs because of the declaration of the variables
    8. One of the most important thing that i probably learnt was vectors since i had never really used vectors. The cited source above for c++ helped me understand the vectors and turns out they were easier to use then it was to initialize the arrays. Arrays took probably most of the time. Next time, i must have a plan on how i am going to approach the games or programs because i ended up using the vectors very late in the game. 
    9. Since the program guidelines mentioned that the boundary conditions at the edge of the window are upto us: I tried my best to print the perfectly but only occassionally the x's wrap around the screen if initially they were printed on the top part of the screen rather than middle or bottom.  
    10. Lastly, I tried to work through many bugs of clang++ and fixed the errors. 
    11. Makefile was mostly used from the last program and with some changes it still works fine and compiles correctly. 
    12. Finally the program worked fine without the bugs.  


RESOURCES: https://www.geeksforgeeks.org/vector-in-cpp-stl/
https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/
https://stackoverflow.com/questions/15439485/game-of-life-cellular-automata-using-c-vectors-in-openframeworks
https://www.bitdegree.org/learn/c-plus-plus-vector
https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life






