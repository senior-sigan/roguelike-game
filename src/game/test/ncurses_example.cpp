/**
 * Created by Илья Сиганов on 26.05.2018.
 */

#include <ncurses.h>

void erase(int row, int col) {
    mvaddch(row, col, ' ');
}

void gameLoop(int row, int col) {
    char symbol = '@';
    bool looping = true;

    mvaddch(row, col, symbol);
    while (looping) {
        switch (getch()) {
            case KEY_LEFT: {
                erase(row, col);
                col -= 1;
                mvaddch(row, col, symbol);
                refresh();
                break;
            }
            case KEY_RIGHT: {
                erase(row, col);
                col += 1;
                mvaddch(row, col, symbol);
                refresh();
                break;
            }
            case KEY_UP: {
                erase(row, col);
                row -= 1;
                mvaddch(row, col, symbol);
                refresh();
                break;
            }
            case KEY_DOWN: {
                erase(row, col);
                row += 1;
                mvaddch(row, col, symbol);
                refresh();
                break;
            }
            case 'q': {
                looping = false;
                break;
            }
            default: break;
        }
    }
}

void start() {
    initscr();
    raw();
    clear();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);
    gameLoop(10, 10);
    endwin();
}

//int main() {
//    start();
//    return 0;
//}