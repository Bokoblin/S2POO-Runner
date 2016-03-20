/* Copyright (C) 2016 Jolivet Arthur & Laronze Florian

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include "../header/Ball.h"

using namespace std;

/********************************************
    Parameterized Constructor
*********************************************
    Arthur : 22/02 - 02/03
    Florian: 22/02 - 02/03
*********************************************/
Ball::Ball(int posX, int posY, int w, int h, int mvX, int mvY) :
    MovableElement(posX, posY, w, h, mvX, mvY), m_life{100}
{

}

/********************************************
    Destructor
*********************************************
    Arthur : 23/02 - 22/02
    Florian: 22/02 - 22/02
*********************************************/
Ball::~Ball()
{

}


/********************************************
    Setter
*********************************************
    Arthur : 20/03
*********************************************/
void Ball::setLife(int new_life)
{
    m_life = new_life;
    if (m_life < 0)
        m_life = 0;
}


/********************************************
    Ball Moving
*********************************************
    Arthur : 10/02
*********************************************/
void Ball::move()
{
    //to implement in v0.3.0
}
