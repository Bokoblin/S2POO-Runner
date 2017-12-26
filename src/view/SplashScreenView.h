/* Copyright 2016-2017 Jolivet Arthur & Laronze Florian

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

#ifndef SPLASH_SCREEN_VIEW_H
#define SPLASH_SCREEN_VIEW_H

#include "AbstractView.h"
#include "../model/SplashScreenModel.h"
#include "../utils/definitions.h"

/**
 * The SplashScreenView class displays
 * the app's splash screen at startup
 * @author Arthur
 * @date 27/03/16 - 24/12/17
 */
class SplashScreenView : public AbstractView
{
public:
    //=== CTORs / DTORs
    SplashScreenView(sf::RenderWindow *window, TextHandler *textHandler, SplashScreenModel *splashModel);
    virtual ~SplashScreenView() override;

    //=== METHODS
    virtual void synchronize() override;
    virtual void draw() const override;
    virtual void loadImages() override;
    virtual bool handleEvents(sf::Event event) override;

private:
    //=== ATTRIBUTES
    SplashScreenModel *m_splashModel;
    GraphicElement *m_splashScreenGraphic;

    //For transition
    ScrollingBackground *m_farBackground;
    ScrollingBackground *m_nearBackground;
    GraphicElement *m_titleGraphic;
};

#endif
