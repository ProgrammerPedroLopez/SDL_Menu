#pragma once

/*
this class is going to be inherited by others classes (weapon1 to 7)
*/

class Weapon : public Item
{
protected:
    WeaponType weaponType;
    DisplayText weaponTypeName;

public:
    Weapon();

    virtual void Start();

    virtual void Update();

    virtual void Update(SDL_Renderer* renderer);

    virtual void Release();

    void Set_WeaponType(WeaponType param, int x, int y, Font* font);

    WeaponType Get_WeaponType();
};