#include <ncurses.h>



int main()
{
	initscr();
	noecho();

	while (true)
		getch();

	endwin();

	return 0;
}
