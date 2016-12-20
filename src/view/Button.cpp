#include "Button.h"

/**
 * Parameterized Constructor
 * @author Arthur
 * @date 6/04 - 20/05
 */
Button::Button(const std::vector<sf::IntRect> & clipRect,
               sf::Texture &image, float x, float y, float w, float h, bool isRadio):
            GraphicElement(image, x, y, w, h), m_clipRectArray{clipRect},
            m_currentClipRect{0}, m_isRadio{isRadio},  m_pressed{false},
            m_active{false}, m_disabled{false}
{
    this->setTextureRect(m_clipRectArray[m_currentClipRect]);
}


/**
 * Copy Constructor
 * @author Arthur
 * @date 6/04 - 22/05
 */
Button::Button(Button const& other) :
    GraphicElement(other), m_clipRectArray{other.m_clipRectArray},
    m_currentClipRect{0}, m_isRadio{other.m_isRadio},
    m_pressed{false}, m_active{false}, m_disabled{false}
{
    this->setTextureRect(m_clipRectArray[m_currentClipRect]);
}


/**
 * Destructor
 * @author Arthur
 * @date 6/04
 */
Button::~Button()
{}


//=== Getters

bool Button::getDisabledState() const { return m_disabled; }


//=== Setters

void Button::setPressedState(bool state) { m_pressed = state; }
void Button::setActivatedState(bool state) { m_active = state; }
void Button::setDisabledState(bool state) { m_disabled = state; }
void Button::setClipRectArray(std::vector<sf::IntRect> crA)
{
    m_clipRectArray = crA;
}


/**
 * Synchronization Function : change animation
 * @author Arthur
 * @date 6/04 - 20/05
 */
void Button::sync()
{
    if (!m_isRadio)
        this->setTextureRect(m_clipRectArray[m_pressed]);
    else
    {
        if ( !m_disabled && m_active && !m_pressed )
            this->setTextureRect(m_clipRectArray[0]);
        if ( !m_disabled && m_active && m_pressed )
            this->setTextureRect(m_clipRectArray[1]);
        if ( !m_disabled && !m_active && !m_pressed )
            this->setTextureRect(m_clipRectArray[2]);
        if ( !m_disabled && !m_active && m_pressed )
            this->setTextureRect(m_clipRectArray[3]);
        if ( m_disabled && m_active)
            this->setTextureRect(m_clipRectArray[4]);
        if ( m_disabled && !m_active)
            this->setTextureRect(m_clipRectArray[5]);
    }
}