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

#ifndef _MODEL_H
#define _MODEL_H

#include "DataBase.h"

#define NORMAL_DIFFICULTY 0
#define MASTER_DIFFICULTY 2

/********************************************
    Model Class
*********************************************
    @author Arthur  @date 21/02 - 21/05
    @author Florian @date 21/02 - 2/03
*********************************************/
class Model
{
public:
    //=== CTORs / DTORs
    Model(int w, int h);
    Model( const Model & model);
    virtual ~Model();

    //=== GETTERS
    DataBase *getDataBase() const;
    int getDifficulty() const;
    bool getIntroState() const;
    bool getMenuState() const;
    bool getGameState() const;
    bool getResetGameState() const;

    //=== SETTERS
    void setDataBase(DataBase *data);
    void setDifficulty(int difficulty);
    void setIntroState(bool state);
    void setMenuState(bool state);
    void setGameState(bool state);
    void setResetGameState(bool state);

    //=== METHODS
    virtual void nextStep();

protected:
    //=== ATTRIBUTES
    int m_width, m_height;
    int m_difficulty;
    DataBase *m_dataBase;

private:
    bool m_introState;
    bool m_menuState;
    bool m_gameState;
    bool m_resetGameState;
};

#endif