#include <string.h>
#include "Header.h"
//enum
#include "ElementalDamage.h"
#include "Manufacturer.h"
#include "Rarity.h"
#include "GearType.h"
//struct
#include "Vector2.h"
//class
#include "GameObject.h"
#include "Font.h"
#include "DisplayText.h"
#include "Item.h"
#include "Gear.h"
#include "CurrentGears.h"

#pragma region

void Gear_1::Start()
{
    Gear::Start();

    name.Start();
    name.Set_Text("Martillo", font);
    name.Set_Position(GEAR_POSITION_X, GEAR_POSITION_Y);

    Set_GearType(GearType::Ring, GEAR_POSITION_X, (GEAR_POSITION_Y + GEAR_OFFSET_Y), font);
    Set_Manufactorer(Manufactorer::Eridian, GEAR_POSITION_X, (GEAR_POSITION_Y + (GEAR_OFFSET_Y * 2)), font);
    Set_Rarity(Rarity::Legendary, GEAR_POSITION_X, (GEAR_POSITION_Y + (GEAR_OFFSET_Y * 3)), font);
    Set_Imagen("assets/items/slot_weapon_1.png", GEAR_POSITION_X, (GEAR_POSITION_Y + (GEAR_OFFSET_Y * 4)));
    Set_Score(0, GEAR_POSITION_X, (GEAR_POSITION_Y + (GEAR_OFFSET_Y * 6)), font);
    Set_Price(19.99f, GEAR_POSITION_X, (GEAR_POSITION_Y + 20 + (GEAR_OFFSET_Y * 7)), font);

};
void Gear_1::Update()
{

};
void Gear_1::Update(SDL_Renderer* renderer)
{
    name.Update(renderer);
    Gear::Update(renderer);
};
void Gear_1::Release()
{
    name.Release();
    Gear::Release();
};

#pragma endregion

