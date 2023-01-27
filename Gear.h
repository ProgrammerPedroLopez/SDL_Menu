#pragma once

/*
Not use in the program
*/

class Gear : public Item
{
protected:
    GearType gearType;
    DisplayText gearTypeName;

public:
    Gear();

    virtual void Start();

    virtual void Update();

    virtual void Update(SDL_Renderer* renderer);

    virtual void Release();

    void Set_GearType(GearType param, int x, int y, Font* font);

    GearType Get_GearType();
};