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

#include "View/Intro.h"
#include "View/MenuView.h"
#include "View/GameView.h"


/********************************************
    Constant Variables
********************************************/
const int INTRO_WIDTH = 400;
const int INTRO_HEIGHT = 200;

using namespace std;


/**
 * Main function
 * @author Arthur, Florian
 * @date 21/02 - 20/12
 */
int main()
{
    srand((unsigned int) time(NULL));
    sf::RenderWindow *window = new sf::RenderWindow( sf::VideoMode(SCREEN_WIDTH,
            SCREEN_HEIGHT, SCREEN_BPP), APP_TITLE, sf::Style::None );
    window->setFramerateLimit(FRAMERATE);

    DataBase data;
    Model model(SCREEN_WIDTH, SCREEN_HEIGHT);
    model.setDataBase(&data);
    TextHandler *text = new TextHandler(&data, SCREEN_WIDTH, SCREEN_HEIGHT);

    while(window->isOpen() )
    {
        if  ( model.getAppState() == INTRO )
        {
            Intro intro(INTRO_WIDTH, INTRO_HEIGHT, window, text);
            intro.setModel(&model);
            while( model.getAppState() == INTRO && intro.treatEvents() )
            {
                intro.synchronize();
                intro.draw();
            }
        }

        if  ( model.getAppState() == MENU )
        {
            MenuModel mModel(model);
            mModel.setDataBase(&data);
            MenuView mView(SCREEN_WIDTH, SCREEN_HEIGHT, window, text);
            mView.setModel(&model);
            mView.setMenuModel(&mModel);
            while( model.getAppState() == MENU && mView.treatEvents()  )
            {
                mModel.nextStep();
                mView.synchronize();
                mView.draw();
            }
        }

        if  ( model.getAppState() == GAME )
        {
            GameModel gModel(model);
            gModel.setDataBase(&data);
            GameView gView(SCREEN_WIDTH, SCREEN_HEIGHT, window, text);
            gView.setModel(&model);
            gView.setGameModel(&gModel);
            while( model.getAppState() == GAME && gView.treatEvents() )
            {
                gModel.nextStep();
                gView.synchronize();
                gView.draw();
            }
            if ( model.getAppState() == RESET_GAME )
            {
                model.setAppState(GAME);
            }
        }
    }

    data.pushConfigurationToFile();

    delete text;
    delete window;

    return EXIT_SUCCESS;
}