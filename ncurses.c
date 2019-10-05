#include <stdio.h>
#include <ncurses/ncurses.h>
int main(void)
{
	int w = 0, x = 0, y = 0, xmax = 0, ymax = 0; //initialize the variables
	initscr();									 //init the screen
	keypad(stdscr, true);						 //eneable keypad
	getmaxyx(stdscr, ymax, xmax);				 //get the maximum dimensions of the screen

	while (w != 'q')
	{
		// in this switch y and x will increase or decrease depending on user's input
		switch (w)
		{
		case KEY_DOWN:
			y++;
			if (y > xmax)
				y--;
			break;
		case KEY_UP:
			y--;
			if (y < 0)
				y++;
			break;
		case KEY_RIGHT:
			x++;
			if (x > ymax)
				x--;
			break;
		case KEY_LEFT:
			x--;
			if (x < 0)
				x++;
			break;
		default:
			break;
		}
		mvprintw(y, x, "+");							  //print a marker
		mvprintw(40, 40, "x: %d,y:%d", x, y);			  //print the current x and y points
		mvprintw(41, 40, "xmax: %d,ymax:%d", xmax, ymax); //print maximum size of the screen
		w = getch();									  //w receives the user input
		clear();										  //window clear
	}
	endwin(); //window closure
}
