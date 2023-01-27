#include <string.h>
#include "Header.h"
//enum
#include "ElementalDamage.h"
#include "GearType.h"
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
#include "Input.h"
#include "BackPack.h"

void BackPack::QuickSort() {}

void BackPack::InputReceiver()
{
    if (Input::Key_R)
    {
        index++;

        if (index == 7)
        {
            index = 0;
        }

        Input::Key_R = false;
    }
}

BackPack::BackPack()
{
    font = nullptr;
    index = 0;
    int i = 0;
    while (i < 8)
    {
        Elements[i] = nullptr;
        i++;
    }
}

void BackPack::Start()
{
    Img::LoadImage("assets/table.png", ImagenTableLeft);
    ImagenTableLeft.rect.x = 50;
    ImagenTableLeft.rect.y = 100;

    index = 0;
    Elements[0] = new Weapon_1;
    Elements[1] = new Weapon_2;
    Elements[2] = new Weapon_3;
    Elements[3] = new Weapon_4;
    Elements[4] = new Weapon_5;
    Elements[5] = new Weapon_6;
    Elements[6] = new Weapon_7;

    int i = 0;
    while (i < 7)
    {
        Elements[i]->Set_Font(font);
        Elements[i]->Start();
        i++;
    }
}

void BackPack::Update() {}

void BackPack::Update(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, ImagenTableLeft.texture, NULL, &ImagenTableLeft.rect);
    InputReceiver();

    switch (index)
    {
    case 0:
        Elements[0]->Update(renderer);
        break;

    case 1:
        Elements[1]->Update(renderer);
        break;

    case 2:
        Elements[2]->Update(renderer);
        break;

    case 3:
        Elements[3]->Update(renderer);
        break;

    case 4:
        Elements[4]->Update(renderer);
        break;

    case 5:
        Elements[5]->Update(renderer);
        break;

    case 6:
        Elements[6]->Update(renderer);
        break;

    default:
        break;
    }
}

void BackPack::Release()
{
    int i = 0;
    while (i < 7)
    {
        Elements[i]->Release();
        i++;
    }
}

int BackPack::Get_Index()
{
    return index;
}

Item* BackPack::GetCurrentItem()
{
    return Elements[index];
}

void BackPack::Set_Font(Font* font)
{
    this->font = font;
}