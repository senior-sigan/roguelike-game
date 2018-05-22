
#include <ncurses.h>

int main() {
    initscr();
    clear();
    printw("Seems that you can use ncurses ...\nPress any key to exit!");
    getch();
    endwin();
}