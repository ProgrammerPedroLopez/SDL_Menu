#pragma once

/*
Contains most of the information of each weapon in the backpack class, 
this class is meant to be inherited to weapon and gear
*/

class Item : public GameObject
{
protected:
    Manufactorer manufactorer;
    DisplayText manufactorerName;
    Rarity rarity;
    DisplayText rarityName;
    float price;
    char priceBuffer[10];
    DisplayText priceName;
    DisplayText description;
    ElementalDamage elementalDamage;
    DisplayText elementalDamageName;
    DisplayText name;
    int score;
    char scoreBuffer[10];
    DisplayText scoreName;
    Img::Image ImagenSlot;
    Font* font;

public:
    Item();

    virtual void Start();

    virtual void Update();

    virtual void Update(SDL_Renderer* renderer);

    virtual void Release();

    void Set_Manufactorer(Manufactorer param, int x, int y, Font* font);
    void Set_Rarity(Rarity param, int x, int y, Font* font);
    void Set_Price(float param);
    void Set_Description(DisplayText param);
    void Set_ElementalDamage(ElementalDamage param);
    void Set_Name(DisplayText param);
    void Set_Imagen(const char* path, int x, int y);
    void Set_Score(int param, int x, int y, Font* font);
    void Set_Price(float param, int x, int y, Font* font);
    void Set_Font(Font* font);

    Img::Image Get_Image();
    float Get_Price();
    int Get_Score();
};