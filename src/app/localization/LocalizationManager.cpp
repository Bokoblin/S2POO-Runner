#include "LocalizationManager.h"

using std::string;
using Bokoblin::SimpleLogger::Logger;
using Bokoblin::XMLUtils::XMLHelper;
namespace ViewResources = Bokoblin::BokoRunner::Resources::Model;

//------------------------------------------------
//          STATIC MEMBERS
//------------------------------------------------

bool LocalizationManager::m_isInit = false;
AppCore* LocalizationManager::m_appCore = nullptr;

//------------------------------------------------
//          PUBLIC METHODS
//------------------------------------------------

/**
 * @brief Inits the app persistence manager context
 * and the persistence system
 *
 * @author Arthur
 * @date 04/02/17
 */
void LocalizationManager::initContext(AppCore& appCore)
{
    m_appCore = &appCore;
    m_isInit = true;
}

/**
 * @brief Closes the persistence manager context
 *
 * @author Arthur
 * @date 04/02/17
 */
void LocalizationManager::closeContext()
{
    m_isInit = false;
    m_appCore = nullptr;
}

/**
 * @brief Checks if persistence context is valid,
 * @details takes the necessary measures otherwise
 *
 * @author Arthur
 * @date 11/02/17
 */
void LocalizationManager::checkContext()
{
    if (m_isInit && m_appCore != nullptr) {
        Logger::printInfo("Localization context verified");
    } else {
        Logger::printError("Localization context check failed, please init it first...");
        throw LocalizationException();
    }
}

/**
 * @brief Retrieves a localized string for a given label.
 * @details Allows abstraction of the internationalization storage system
 *
 * @param label the label to describe the string
 * @return the localized string
 *
 * @author Arthur
 * @date 04/01/2017 - 02/05/2020
 */
string LocalizationManager::fetchLocalizedString(const string& label)
{
    string result;
    try {
        LocalizationManager::checkContext();

        string currentLocaleFile = getLanguageFile();
        result = XMLHelper::loadLabeledString(currentLocaleFile, label);
    } catch (const LocalizationException& e) {
        Logger::printWarning(e.what() + string("Localization checking failure, applying default language"));
        result = XMLHelper::loadLabeledString(ViewResources::ENGLISH_STRINGS, label);
    }

    if (result == "<" + label + ">") {
        Logger::printWarning("No string was found for expression \"" + label + "\"");
    }

    return result;
}


//------------------------------------------------
//          PRIVATE METHODS
//------------------------------------------------

/**
 * @brief Retrieves language file following app language
 *
 * @return the adequate language file
 *
 * @author Arthur
 * @date 11/02/18 - 22/03/20
 */
const string& LocalizationManager::getLanguageFile()
{
    if (m_appCore->getLanguage() == ViewResources::FRENCH) {
        return ViewResources::FRENCH_STRINGS;
    } else if (m_appCore->getLanguage() == ViewResources::SPANISH) {
        return ViewResources::SPANISH_STRINGS;
    } else {
        return ViewResources::ENGLISH_STRINGS; //Default
    }
}
