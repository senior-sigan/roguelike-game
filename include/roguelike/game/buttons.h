//
// Created by Илья Сиганов on 01/10/2018.
//

#ifndef ROGUELIKE_BUTTONS_H
#define ROGUELIKE_BUTTONS_H

#ifdef BEARLIBTERMINAL

#define EXIT_KEY 0xE0
#define UP_KEY 0x1A
#define DOWN_KEY 0x16
#define LEFT_KEY 0x04
#define RIGHT_KEY 0x07

#endif  // BEARLIBTERMINAL

#ifdef NCURSES

#define EXIT_KEY 'q'
#define UP_KEY 'w'
#define DOWN_KEY 's'
#define LEFT_KEY 'a'
#define RIGHT_KEY 'd'

#endif  // NCURSES

#endif  // ROGUELIKE_BUTTONS_H
