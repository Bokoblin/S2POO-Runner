#include "MovableElement.h"

using namespace std;

/********************************************
    Parameterized Constructor
*********************************************
    @author Arthur  @date 23/02 - 09/04
    @author Florian @date 02/03 - 02/03
*********************************************/
MovableElement::MovableElement(float x, float y, float w, float h, float mvX, float mvY) :
    m_posX{x}, m_posY{y}, m_width{w}, m_height{h}, m_moveX{mvX}, m_moveY{mvY},
    m_collisionState{false}, m_elementType{-1}
{}


/********************************************
    Destructor
*********************************************
    @author Arthur  @date 23/02
*********************************************/
MovableElement::~MovableElement()
{}


/********************************************
    Getters
*********************************************
    @author Arthur  @date 23/02 - 23/10
*********************************************/
float MovableElement::getPosX()  const { return m_posX;  }
float MovableElement::getPosY()  const { return m_posY;  }
float MovableElement::getWidth() const { return m_width; }
float MovableElement::getHeight()const { return m_height;}
int MovableElement::getType() const { return m_elementType; }
bool MovableElement::getCollisionState() const { return m_collisionState; }


/********************************************
    Setters
*********************************************
    @author Arthur  @date 23/02 - 12/04
*********************************************/
void MovableElement::setMoveX(float mvX) { m_moveX = mvX;}
void MovableElement::setMoveY(float mvY) { m_moveY = mvY;}
void MovableElement::setCollisionState(bool state) { m_collisionState = state;}


/********************************************
   Check if a position belongs to an element
*********************************************
    @author Arthur  @date 08/03 - 09/04
*********************************************/
bool MovableElement::contains( float posX, float posY) const
{
    float  maxX = m_posX + m_width;
    float  maxY = m_posY + m_height;

    return (posX >= m_posX) && (posX < maxX) && (posY >= m_posY) && (posY < maxY);
}


/********************************************
   Test collision function
*********************************************
    @author Arthur  @date 02/04 - 11/04
*********************************************/
bool MovableElement::collision( const MovableElement& other) const
{
    /**<  Coordinates note : element's origin corresponds to left-bottom point */

    float leftA, leftB;
    float rightA, rightB;
    float topA, topB;
    float bottomA, bottomB;

    leftA = m_posX;
    rightA = m_posX + m_width;
    topA = m_posY - m_height;
    bottomA = m_posY;

    leftB = other.m_posX;
    rightB = other.m_posX + other.m_width;
    topB = other.m_posY - other.m_height;
    bottomB = other.m_posY;

    if(bottomA < topB)
        return false;
    if(topA > bottomB)
        return false;
    if(rightA < leftB)
        return false;
    if(leftA > rightB)
        return false;

    return true;
}