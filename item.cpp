#include "Manufacturer.h"
#include "Rarity.h"
#include "ElementalDamage.h"
#include "Vector2.h"
#include "Header.h"
#include "GameObject.h"
#include "Font.h"
#include "DisplayText.h"
#include "Item.h"
#include "GlobalVariables.h"

Item::Item()
{
    manufactorer = Manufactorer::Uninitialize;
    elementalDamage = ElementalDamage::Uninitialize;
    rarity = Rarity::Uninitialize;
    strcpy_s(scoreBuffer, "");
    strcpy_s(priceBuffer, "");
    score = 0;
    price = 0.0f;
}

void Item::Start()
{
};

void Item::Update()
{

};

void Item::Update(SDL_Renderer* renderer)
{
    manufactorerName.Update(renderer);
    rarityName.Update(renderer);
    scoreName.Update(renderer);
    priceName.Update(renderer);
    SDL_RenderCopy(renderer, ImagenSlot.texture, NULL, &ImagenSlot.rect);
};

void Item::Release()
{
    
}

void Item::Set_Manufactorer(Manufactorer param, int x, int y, Font* font)
{
    manufactorer = param;
    manufactorerName.Start();
    switch (manufactorer)
    {
    case Manufactorer::Atlas:
        manufactorerName.Set_Text("atlas", font);
        break;

    case Manufactorer::Dahl:
        manufactorerName.Set_Text("dahl", font);
        break;

    case Manufactorer::Eridian:
        manufactorerName.Set_Text("eridian", font);
        break;

    case Manufactorer::Hyperion:
        manufactorerName.Set_Text("hyperion", font);
        break;

    case Manufactorer::Jakobs:
        manufactorerName.Set_Text("jakobs", font);
        break;

    default:
        manufactorerName.Set_Text(" ", font);
        break;
    }
    manufactorerName.Set_Position(x, y);
}
void Item::Set_Rarity(Rarity param, int x, int y, Font* font)
{
    rarity = param;
    rarityName.Start();
    switch (rarity)
    {
    case Rarity::Legendary:
        rarityName.Set_Text("legendary", font);
        break;

    case Rarity::VeryRare:
        rarityName.Set_Text("very rare", font);
        break;

    case Rarity::Rare:
        rarityName.Set_Text("rare", font);
        break;

    case Rarity::Uncommon:
        rarityName.Set_Text("uncommon", font);
        break;

    case Rarity::Common:
        rarityName.Set_Text("common", font);
        break;

    default:
        rarityName.Set_Text(" ", font);
        break;
    }
    rarityName.Set_Position(x, y);
}
void Item::Set_Price(float param)
{
    price = param;
}
void Item::Set_Description(DisplayText param)
{
    description = param;
}
void Item::Set_ElementalDamage(ElementalDamage param)
{
    elementalDamage = param;
}
void Item::Set_Name(DisplayText param)
{
    name = param;
}
void Item::Set_Imagen(const char* path, int x, int y)
{
    Img::LoadImage(path, ImagenSlot);
    ImagenSlot.rect.x = x;
    ImagenSlot.rect.y = y;
}
void Item::Set_Score(int param, int x, int y, Font* font)
{
    score = param;
    _itoa_s(score, scoreBuffer, 10);
    scoreName.Start();
    scoreName.Set_Text(scoreBuffer, font);
    scoreName.Set_Position(x, y);
}
void Item::Set_Price(float param, int x, int y, Font* font)
{
    price = param;
    _gcvt_s(priceBuffer, 10, price, 5);
    priceName.Start();
    priceName.Set_Text(priceBuffer, font);
    priceName.Set_Position(x, y);
}
void Item::Set_Font(Font* font) 
{
    this->font = font;
}

Img::Image Item::Get_Image()
{
    return ImagenSlot;
}
float Item::Get_Price()
{
    return price;
}
int Item::Get_Score()
{
    return score;
}
