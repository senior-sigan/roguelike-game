/**
 * Created by Илья Сиганов on 01.07.2018.
 */

#ifndef ROGUELIKE_GEOMETRY_H
#define ROGUELIKE_GEOMETRY_H

#include <core/Rectangle.h>
#include "Line.h"

namespace Core {
/**
* Checks if two rectangles intersect
*
* @param r1 first rectangle
* @param r2 second rectangle
* @return true if r1 and r2 intersect
*/
bool Intersect(Rectangle r1, Rectangle r2);

/**
 * Checks if rectangle and line intersect
 * @param rectangle
 * @param line
 * @return true if intersect and false otherwise
 */
bool Intersect(Rectangle rectangle, Line line);

/**
* Checks if the first rectangle contains the second.
*
* @param r1 first Rectangle
* @param r2 second Rectangle
* @return true if r1 contains r2
*/
bool Contains(Rectangle r1, Rectangle r2);

}

#endif //ROGUELIKE_GEOMETRY_H
