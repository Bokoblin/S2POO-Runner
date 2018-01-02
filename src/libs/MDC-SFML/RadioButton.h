/* Copyright 2016-2018 Jolivet Arthur & Laronze Florian

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

#ifndef RADIO_BUTTON_H
#define RADIO_BUTTON_H

#include "Button.h"

namespace Bokoblin
{
namespace MaterialDesignComponentsForSFML
{

/**
 * The RadioButton Class inherited from Button class
 * adds different syncing behaviours
 * a pre-configured texture with its clip rectangles
 * and a different label location than other buttons
 *
 * @author Arthur
 * @date 23/12/16 - 02/01/18
 */
class RadioButton : public Button
{
public:
    //=== CTORs / DTORs
    RadioButton(float x, float y, float diameter);
    RadioButton(float x, float y, float diameter, const std::string &label);
    RadioButton(const RadioButton& other);
    ~RadioButton() override;

    //=== METHODS
    void sync() override;
    void syncLabelPosition() override;

private:
    //=== METHODS
    void setRadioClipRect();

    //=== CONSTANTS
    const std::string RADIO_BUTTONS_IMAGE = "../res/images/ui/radio_buttons.png";
    const std::string INDICATOR_IMAGE = "../res/images/ui/indicator_buttons.png";
};

} //namespace MaterialDesignComponentsForSFML
} //namespace Bokoblin

#endif
