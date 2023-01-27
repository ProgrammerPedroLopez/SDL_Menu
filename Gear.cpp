#include <string.h>
#include "ElementalDamage.h"
#include "Manufacturer.h"
#include "Rarity.h"
#include "GearType.h"
#include "Vector2.h"
#include "Header.h"
#include "GameObject.h"
#include "Font.h"
#include "DisplayText.h"
#include "Item.h"
#include "GlobalVariables.h"
#include "Gear.h"

Gear::Gear() 
{
    gearType = GearType::Uninitialize;
}

void Gear::Start()
{
    Item::Start();
};

void Gear::Update()
{

}

void Gear::Update(SDL_Renderer* renderer)
{
    gearTypeName.Update(renderer);
    Item::Update();
};

void Gear::Release()
{
    gearTypeName.Release();
    Item::Release();
};

void Gear::Set_GearType(GearType param, int x, int y, Font* font)
{
    gearType = param;
    gearTypeName.Start();
    switch (gearType)
    {
    case GearType::Amulet:
        gearTypeName.Set_Text("amulet", font);
        break;

    case GearType::Armor:
        gearTypeName.Set_Text("armor", font);
        break;

    case GearType::Ring:
        gearTypeName.Set_Text("ring", font);
        break;

    case GearType::Shield:
        gearTypeName.Set_Text("shield", font);
        break;

    case GearType::SpellBook:
        gearTypeName.Set_Text("spellbook", font);
        break;

    default:
        gearTypeName.Set_Text(" ", font);
        break;
    }
    gearTypeName.Set_Position(x, y);
}

GearType Gear::Get_GearType()
{
    return gearType;
}
