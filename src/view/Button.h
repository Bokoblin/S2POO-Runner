/* Copyright 2016 Jolivet Arthur & Laronze Florian

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#ifndef BUTTON_H
#define BUTTON_H

#include "../../libs/pugixml-1.8/src/pugixml.hpp"
#include "../model/DataBase.h"
#include "GraphicElement.h"
#include "Text.h"

enum LabelPosition {
    TOP,
    RIGHT,
    BOTTOM,
    LEFT,
    CENTER
};

/**
 * The Button Class adds to a Graphic element
 * multiple clips from texture for them to change on events
 * and states to react differently when pressed,
 * activated, disabled or visible.
 * A button has also a text label that can be updated from
 * a string file thanks to its description
 *
 * @author Arthur
 * @date 6/04 - 23/12
 */
class Button : public GraphicElement
{
public:
    //=== CTORs / DTORs
    Button(const std::vector<sf::IntRect> & clipRect,
           sf::Texture &image, float x, float y, float w, float h);

    Button(const std::vector<sf::IntRect> & clipRect,
           sf::Texture &image, float x, float y, float w, float h, std::string labelDescription);
    Button(Button const& elementACopier);
    virtual ~Button();

    //TODO : LABEL POSITION

    //=== GETTERS
    bool isDisabled() const;
    bool isVisible() const;

    //=== SETTERS
    void setPressed(bool on);
    void setActivated(bool on);
    void setDisabled(bool on);
    void setVisible(bool on);
    void setClipRectArray(std::vector<sf::IntRect> array);
    void setPositionSelfCentered(double, double);
    void setLabelPosition(LabelPosition labelPosition);

    //=== METHODS
    virtual void sync() override;
    virtual void sync(DataBase *dataBase);
    virtual void draw(sf::RenderWindow *window)const;
    bool contains(float posX, float posY) const;

protected:
    //=== ATTRIBUTES
    std::vector<sf::IntRect> m_clipRectArray;
    unsigned int m_currentClipRect;
    bool m_isPressed;
    bool m_isActive;
    bool m_isDisabled;
    bool m_isVisible;
    sf::Font m_font;
    Text *m_label;
    LabelPosition m_labelPosition;
};

#endif
