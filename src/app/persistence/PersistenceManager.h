﻿/* Copyright 2018-2019 Jolivet Arthur

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

#ifndef PERSISTENCE_MANAGER_H
#define PERSISTENCE_MANAGER_H

#include "libs/Logger/Logger.h"
#include "app/model/core/AppCore.h"
#include "app/persistence/PersistenceException.h"
#include "app/persistence/FileBasedPersistence.h"

class AppCore;

/**
 * The PersistenceManager class manages the app persistence. \n
 * The persistence method is abstracted from app's point of view in order to easily change
 * persistence system by only changing this file. \n
 * The current persistence system used by this manager is a file-based config file.
 *
 * @author Arthur
 * @date 27/01/18 - 13/10/18
 */
class PersistenceManager
{
public:
    //=== METHODS
    static void initContext(AppCore& appCore);
    static void closeContext();
    static void checkContext();
    static void initPersistence();
    static void fetchConfiguration();
    static void fetchStatistics();
    static void fetchLeaderboard();
    static void fetchActivatedBonus();
    static void fetchShopItems();
    static void updatePersistence(); //TODO [2.0.x] global + split versions
    static void resetPersistence();
    static void deletePersistence();
    static std::string getContextLocation();  //FIXME [2.0.x] Temporary: We should not expose it like that

    //=== GETTERS
    static bool isInit();
private:
    //=== ATTRIBUTES
    static bool m_isInit;
};

#endif
