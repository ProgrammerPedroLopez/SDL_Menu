#include <string.h>
#include "Header.h"
//enum
#include "ElementalDamage.h"
#include "Manufacturer.h"
#include "Rarity.h"
#include "WeaponType.h"
//struct
#include "Vector2.h"
//class
#include "GameObject.h"
#include "Font.h"
#include "DisplayText.h"
#include "Item.h"
#include "Weapon.h"
#include "CurrentWeapons.h"

#pragma region

void Weapon_1::Start()
{
    Weapon::Start();

    name.Start();
    name.Set_Text("arma italiana", font);
    name.Set_Position(WEAPON_POSITION_X, WEAPON_POSITION_Y);

    Set_WeaponType(WeaponType::Shotgun, WEAPON_POSITION_X, (WEAPON_POSITION_Y + WEAPON_OFFSET_Y), font);
    Set_Manufactorer(Manufactorer::Atlas, WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 2)), font);
    Set_Rarity(Rarity::Legendary, WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 3)), font);
    Set_Imagen("assets/items/slot_weapon_1.png", WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 4)));
    Set_Score(0, WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 6)), font);
    Set_Price(19.99f, WEAPON_POSITION_X, (WEAPON_POSITION_Y + 20 + (WEAPON_OFFSET_Y * 7)), font);
};
void Weapon_1::Update() {}
void Weapon_1::Update(SDL_Renderer* renderer)
{
    name.Update(renderer);
    Weapon::Update(renderer);
};
void Weapon_1::Release()
{
    name.Release();
    Weapon::Release();
};

void Weapon_2::Start()
{
    Weapon::Start();

    name.Start();
    name.Set_Text("arma suiza", font);
    name.Set_Position(WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 0)));

    Set_WeaponType(WeaponType::Submachine, WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 1)), font);
    Set_Manufactorer(Manufactorer::Dahl, WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 2)), font);
    Set_Rarity(Rarity::VeryRare, WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 3)), font);
    Set_Imagen("assets/items/slot_weapon_2.png", WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 4)));
    Set_Score(15, WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 6)), font);
    Set_Price(102.36f, WEAPON_POSITION_X, (WEAPON_POSITION_Y + 20 + (WEAPON_OFFSET_Y * 7)), font);
};
void Weapon_2::Update() {}
void Weapon_2::Update(SDL_Renderer* renderer)
{
    name.Update(renderer);
    Weapon::Update(renderer);
};
void Weapon_2::Release()
{
    name.Release();
    Weapon::Release();
};

void Weapon_3::Start()
{
    Weapon::Start();

    name.Start();
    name.Set_Text("arma belgica", font);
    name.Set_Position(WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 0)));

    Set_WeaponType(WeaponType::Sniper, WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 1)), font);
    Set_Manufactorer(Manufactorer::Eridian, WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 2)), font);
    Set_Rarity(Rarity::Rare, WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 3)), font);
    Set_Imagen("assets/items/slot_weapon_3.png", WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 4)));
    Set_Score(3, WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 6)), font);
    Set_Price(5.99f, WEAPON_POSITION_X, (WEAPON_POSITION_Y + 20 + (WEAPON_OFFSET_Y * 7)), font);
};
void Weapon_3::Update() {}
void Weapon_3::Update(SDL_Renderer* renderer)
{
    name.Update(renderer);
    Weapon::Update(renderer);
};
void Weapon_3::Release()
{
    name.Release();
    Weapon::Release();
};

void Weapon_4::Start()
{
    Weapon::Start();

    name.Start();
    name.Set_Text("slovakia", font);
    name.Set_Position(WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 0)));

    Set_WeaponType(WeaponType::CombatRifle, WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 1)), font);
    Set_Manufactorer(Manufactorer::Hyperion, WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 2)), font);
    Set_Rarity(Rarity::Uncommon, WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 3)), font);
    Set_Imagen("assets/items/slot_weapon_4.png", WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 4)));
    Set_Score(78, WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 6)), font);
    Set_Price(65.32f, WEAPON_POSITION_X, (WEAPON_POSITION_Y + 20 + (WEAPON_OFFSET_Y * 7)), font);
};
void Weapon_4::Update() {}
void Weapon_4::Update(SDL_Renderer* renderer)
{
    name.Update(renderer);
    Weapon::Update(renderer);
};
void Weapon_4::Release()
{
    name.Release();
    Weapon::Release();
};

void Weapon_5::Start()
{
    Weapon::Start();

    name.Start();
    name.Set_Text("netherlands", font);
    name.Set_Position(WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 0)));

    Set_WeaponType(WeaponType::Shotgun, WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 1)), font);
    Set_Manufactorer(Manufactorer::Jakobs, WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 2)), font);
    Set_Rarity(Rarity::Common, WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 3)), font);
    Set_Imagen("assets/items/slot_weapon_5.png", WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 4)));
    Set_Score(156, WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 6)), font);
    Set_Price(999.99f, WEAPON_POSITION_X, (WEAPON_POSITION_Y + 20 + (WEAPON_OFFSET_Y * 7)), font);
};
void Weapon_5::Update() {}
void Weapon_5::Update(SDL_Renderer* renderer)
{
    name.Update(renderer);
    Weapon::Update(renderer);
};
void Weapon_5::Release()
{
    name.Release();
    Weapon::Release();
};

void Weapon_6::Start()
{
    Weapon::Start();

    name.Start();
    name.Set_Text("tailandia", font);
    name.Set_Position(WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 0)));

    Set_WeaponType(WeaponType::Submachine, WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 1)), font);
    Set_Manufactorer(Manufactorer::Atlas, WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 2)), font);
    Set_Rarity(Rarity::Uncommon, WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 3)), font);
    Set_Imagen("assets/items/slot_weapon_6.png", WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 4)));
    Set_Score(8, WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 6)), font);
    Set_Price(36.01f, WEAPON_POSITION_X, (WEAPON_POSITION_Y + 20 + (WEAPON_OFFSET_Y * 7)), font);
};
void Weapon_6::Update() {}
void Weapon_6::Update(SDL_Renderer* renderer)
{
    name.Update(renderer);
    Weapon::Update(renderer);
};
void Weapon_6::Release()
{
    name.Release();
    Weapon::Release();
};

void Weapon_7::Start()
{
    Weapon::Start();

    name.Start();
    name.Set_Text("monaco", font);
    name.Set_Position(WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 0)));

    Set_WeaponType(WeaponType::Sniper, WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 1)), font);
    Set_Manufactorer(Manufactorer::Eridian, WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 2)), font);
    Set_Rarity(Rarity::Common, WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 3)), font);
    Set_Imagen("assets/items/slot_weapon_7.png", WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 4)));
    Set_Score(28, WEAPON_POSITION_X, (WEAPON_POSITION_Y + (WEAPON_OFFSET_Y * 6)), font);
    Set_Price(50000.11f, WEAPON_POSITION_X, (WEAPON_POSITION_Y + 20 + (WEAPON_OFFSET_Y * 7)), font);
};
void Weapon_7::Update() {}
void Weapon_7::Update(SDL_Renderer* renderer)
{
    name.Update(renderer);
    Weapon::Update(renderer);
};
void Weapon_7::Release()
{
    name.Release();
    Weapon::Release();
};

#pragma endregion