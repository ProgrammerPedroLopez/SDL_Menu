#pragma once

/*
Table is the right part of the screen, each time the player press E the selected 
weapon in the backpack is going to be set in a slot in this class.

with WASD the player can move the selected slot

the weapon selected only is going to be add to the table if player has enough money and level

with Q the player can remove a weapon from the table
*/

#define verticalRows 4
#define horizontalRows 2

class Table
{
private:
    Img::Image ImagenSlotsContainers[verticalRows][horizontalRows];
    Img::Image ImagenSlot;
    Img::Image ImagenSlotSelected;
    SDL_Rect Positions[verticalRows][horizontalRows];
    int SelectedPosition_vertical;
    int SelectedPosition_horizontal;
    int i;
    int j;
    float moneyInWallet;
    char moneyInWalletBuffer[10];
    DisplayText moneyInWalletName;
    int PlayerLevel;
    char PlayerLevelBuffer[10];
    DisplayText PlayerLevelName;
    Font* font;

public:
    Table();

    void Start();
    void Update(SDL_Renderer*);
    void Update();

    void On_Key_Released_W();
    void On_Key_Released_S();
    void On_Key_Released_A();
    void On_Key_Released_D();

    void ChangeGun(Img::Image* texture, float price, int actualLevel);
    void UnequipGun();

    int Get_SelectedPosition_vertical();
    int Get_SelectedPosition_horizontal();

    void Set_Price(float param, int x, int y);
    void Set_PlayerLevel(int param, int x, int y);
    void Set_Font(Font* font);

};