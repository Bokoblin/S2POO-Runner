﻿/* Copyright 2016 Jolivet Arthur & Laronze Florian

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

#ifndef _DATABASE_H
#define _DATABASE_H

#include "../Libs/pugixml-1.7/src/pugixml.hpp"
#include <iostream>
#include <sstream>
#include <cassert>
#include <vector>
#include <set>
#include <fstream>

/********************************************
    Constant Variables
********************************************/

const int COIN_MULTIPLIER = 20;
const int MAX_SCORES = 10;

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
const std::string CONFIG_FILE = "Resources/config.xml";
#else
const std::string CONFIG_FILE = "~/.config/runner/config.xml";
#endif

const std::string DEFAULT_CONFIG_CONTENT = "<?xml version=\"1.0\"?>\n"
        "<runner>\n"
        "\t<config>\n"
        "\t\t<configItem name=\"language\" value=\"en\"/>\n"
        "\t\t<configItem name=\"ball_skin\" value=\"default\"/>\n"
        "\t\t<configItem name=\"total_coins_collected\" value=\"0\"/>\n"
        "\t\t<configItem name=\"total_distance_travelled\" value=\"0\"/>\n"
        "\t\t<configItem name=\"total_enemies_destroyed\" value=\"0\"/>\n"
        "\t\t<configItem name=\"total_games_played\" value=\"0\"/>\n"
        "\t</config>\n"
        "\t<shop>\n"
        "\t\t<shopItem id=\"doubler\" name=\"Coin Doubler\" description=\"Double coins collected number\" price=\"1000\" boughtState=\"false\"/>\n"
        "\t\t<shopItem id=\"shieldplus\" name=\"Increase Shield bonus\" description=\"Protect two times\" price=\"100\" boughtState=\"false\"/>\n"
        "\t\t<shopItem id=\"megaplus\" name=\"Increase Mega bonus\" description=\"Increase bonus duration by 5s\" price=\"200\" boughtState=\"false\"/>\n"
        "\t\t<shopItem id=\"flyplus\" name=\"Increase Fly bonus\" description=\"Increase bonus duration by 5s\" price=\"180\" boughtState=\"false\"/>\n"
        "\t\t<shopItem id=\"morphing\" name=\"Morph ball skin\" description=\"Unlock ball's morph skin\" price=\"500\" boughtState=\"false\"/>\n"
        "\t\t<shopItem id=\"capsule\" name=\"Capsule ball skin\" description=\"Unlock ball's capsule skin\" price=\"60\" boughtState=\"false\"/>\n"
        "\t</shop>\n"
        "\t<scores>\n"
        "\t\t<scoreItem value=\"0\"/>\n"
        "\t\t<scoreItem value=\"0\"/>\n"
        "\t\t<scoreItem value=\"0\"/>\n"
        "\t\t<scoreItem value=\"0\"/>\n"
        "\t\t<scoreItem value=\"0\"/>\n"
        "\t\t<scoreItem value=\"0\"/>\n"
        "\t\t<scoreItem value=\"0\"/>\n"
        "\t\t<scoreItem value=\"0\"/>\n"
        "\t\t<scoreItem value=\"0\"/>\n"
        "\t\t<scoreItem value=\"0\"/>\n"
        "\t</scores>\n"
        "</runner>";

/********************************************
    DataBase Class
*********************************************
    @author Arthur  @date 2/05 - 24/10
*********************************************/
class DataBase
{
public:
    //=== CTORs / DTORs
    DataBase();
    DataBase(const DataBase& d)=delete;

    //=== GETTERS
    int getTotalCoinsNumber() const;
    int getTotalDistance() const;
    int getTotalFlattenedEnemies() const;
    int getTotalGamesPlayed() const;
    int getCurrentCoinsNumber() const;
    int getCurrentDistance() const;
    int getCurrentFlattenedEnemies() const;
    int getCurrentScore() const;
    std::string getLanguage() const;
    std::string getBallSkin() const;
    const std::set<std::string>& getActivatedItemsArray() const;

    //=== SETTERS
    void setTotalCoinsCollected(int number);
    void setCurrentCoinsCollected(int number);
    void setCurrentDistance(int number);
    void setCurrentFlattenedEnemies(int number);
    void setCurrentScore(float speed);
    void setLanguage(std::string lang);
    void setBallSkin(std::string skin);

    //=== METHODS
    void createFile();
    bool checkFileIntegrity();
    void fetchConfigurationFromFile();
    void updateConfigValues();
    void updateActivatedItemsArray();
    void updateScoreArray();
    void pushConfigurationToFile();
    void addEntryToScoreArray(int new_score);
    void loadStringFromArray(std::string &scores_text);
    void saveCurrentGame();
    void resetCurrentGame();
    void resetScore();

private:
    //=== ATTRIBUTES
    //Global App
    int m_totalCoinsCollected;
    int m_totalDistance;
    int m_totalFlattenedEnemies;
    int m_totalGamesPlayed;
    std::string m_currentLanguage;
    std::string m_currentBallSkin;

    //Current Game
    int m_currentCoinsNumber;
    int m_currentDistance;
    int m_currentFlattenedEnemies;
    int m_currentScore;

    std::set<int> m_scoresArray;
    std::set<std::string> m_activatedItemsArray;
};

#endif