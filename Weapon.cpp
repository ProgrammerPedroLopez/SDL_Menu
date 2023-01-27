#include <string.h>
#include "ElementalDamage.h"
#include "Manufacturer.h"
#include "Rarity.h"
#include "WeaponType.h"
#include "Vector2.h"
#include "Header.h"
#include "GameObject.h"
#include "Font.h"
#include "DisplayText.h"
#include "Item.h"
#include "Weapon.h"
#include "GlobalVariables.h"

Weapon::Weapon()
{
    weaponType = WeaponType::Uninitialize;
}

void Weapon::Start()
{
    Item::Start();
};

void Weapon::Update()
{

}

void Weapon::Update(SDL_Renderer* renderer)
{
    weaponTypeName.Update(renderer);
    Item::Update(renderer);
};

void Weapon::Release()
{
    weaponTypeName.Release();
    Item::Release();
};

void Weapon::Set_WeaponType(WeaponType param, int x, int y, Font* font)
{
    weaponType = param;
    weaponTypeName.Start();
    switch (weaponType)
    {
    case WeaponType::Shotgun:
        weaponTypeName.Set_Text("shotgun", font);
        break;

    case WeaponType::Submachine:
        weaponTypeName.Set_Text("submachine", font);
        break;

    case WeaponType::Sniper:
        weaponTypeName.Set_Text("sniper", font);
        break;

    case WeaponType::CombatRifle:
        weaponTypeName.Set_Text("combat rifle", font);
        break;

    default:
        weaponTypeName.Set_Text(" ", font);
        break;
    }
    weaponTypeName.Set_Position(x, y);
}

WeaponType Weapon::Get_WeaponType()
{
    return weaponType;
}
