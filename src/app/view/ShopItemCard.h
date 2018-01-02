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

#ifndef SHOP_ITEM_CARD_H
#define SHOP_ITEM_CARD_H

#include "../model/ShopItem.h"
#include "../../libs/MDC-SFML/Button.h"
#include "TextHandler.h"
#include "../utils/definitions.h"

/**
 * ShopItemCard Class
 * @author Arthur
 * @date 16/05/16 - 27/12/17
 */
class ShopItemCard : public mdsf::Sprite
{
public:
    //=== CTORs / DTORs
    ShopItemCard(int id, ShopItem *item);
    ~ShopItemCard() override;

    //=== GETTERS
    int getId() const;
    mdsf::Button *getBuyButton() const;
    ShopItem *getItem() const;

    //=== METHODS
    void loadImages();
    void sync() override;
    void syncWithButtonLabelRetrieval(const DataBase &dataBase);
    void draw(sf::RenderWindow *window) const override;

private:
    //=== ATTRIBUTES
    int m_id;
    ShopItem *m_item;
    mdsf::Text m_title;
    mdsf::Text m_content;
    mdsf::Button *m_buyButton;
    mdsf::Button *m_boughtButton;
};

#endif