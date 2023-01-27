#include<string>
#include"Header.h"

#include "Vector2.h"

#include "GameObject.h"
#include "Font.h"
#include "DisplayText.h"

#include "Table.h"

Table::Table()
{
    i = 0;
    while (i < verticalRows)
    {
        j = 0;
        while (j < horizontalRows)
        {
            Positions[i][j].x = 0;
            Positions[i][j].y = 0;
            Positions[i][j].w = 0;
            Positions[i][j].h = 0;
            j++;
        }
        i++;
    }
    SelectedPosition_vertical = 0;
    SelectedPosition_horizontal = 0;
    moneyInWallet = 0.0f;
    strcpy_s(moneyInWalletBuffer, "");
    PlayerLevel = 0;
    strcpy_s(PlayerLevelBuffer, "");
    i = 0;
    j = 0;
}

void Table::Start()
{
    SelectedPosition_vertical = 0;
    SelectedPosition_horizontal = 0;

    Img::LoadImage("assets/slot.png", ImagenSlot);
    Img::LoadImage("assets/slot_selected_2.png", ImagenSlotSelected);

    i = 0;
    while (i < verticalRows)
    {
        j = 0;
        while (j < horizontalRows)
        {
            ImagenSlotsContainers[i][j].texture = ImagenSlot.texture;
            Positions[i][j].x = 915 + (ImagenSlot.rect.w * j);
            Positions[i][j].y = 215 + (ImagenSlot.rect.h * i);
            Positions[i][j].w = ImagenSlot.rect.w;
            Positions[i][j].h = ImagenSlot.rect.h;
            j++;
        }
        i++;
    }

    ImagenSlotSelected.rect.x = 915;
    ImagenSlotSelected.rect.y = 215;

    Set_Price(250.35f, 950, 595);
    Set_PlayerLevel(30, 950, 650);
}

void Table::Update() 
{

}

void Table::Update(SDL_Renderer* renderer)
{
    i = 0;
    j = 0;
    while (i < verticalRows)
    {
        j = 0;
        while (j < horizontalRows)
        {
            SDL_RenderCopy(renderer, ImagenSlotsContainers[i][j].texture, NULL, &Positions[i][j]);
            j++;
        }
        i++;
    }

    SDL_RenderCopy(renderer, ImagenSlotSelected.texture, NULL, &ImagenSlotSelected.rect);
    moneyInWalletName.Update(renderer);
    PlayerLevelName.Update(renderer);
}

void Table::On_Key_Released_W()
{
    if (SelectedPosition_vertical > 0)
    {
        SelectedPosition_vertical--;
        ImagenSlotSelected.rect.y -= ImagenSlotSelected.rect.h;
    }
}

void Table::On_Key_Released_S()
{
    if (SelectedPosition_vertical < verticalRows - 1)
    {
        SelectedPosition_vertical++;
        ImagenSlotSelected.rect.y += ImagenSlotSelected.rect.h;
    }
}

void Table::On_Key_Released_A()
{
    if (SelectedPosition_horizontal > 0)
    {
        SelectedPosition_horizontal--;
        ImagenSlotSelected.rect.x -= ImagenSlotSelected.rect.w;
    }
}

void Table::On_Key_Released_D()
{
    if (SelectedPosition_horizontal < horizontalRows - 1)
    {
        SelectedPosition_horizontal++;
        ImagenSlotSelected.rect.x += ImagenSlotSelected.rect.w;
    }
}

void Table::ChangeGun(Img::Image* texture, float price, int actualLevel)
{
    float newMoneyInWallet = moneyInWallet - price;
    if (newMoneyInWallet > 0 && PlayerLevel >= actualLevel)
    {
        i = 0;
        j = 0;
        while (i < verticalRows)
        {
            j = 0;
            while (j < horizontalRows)
            {
                if (Positions[i][j].x == ImagenSlotSelected.rect.x && Positions[i][j].y == ImagenSlotSelected.rect.y)
                {
                    ImagenSlotsContainers[i][j].texture = texture->texture;
                }
                j++;
            }
            i++;
        }

        Set_Price(moneyInWallet - price, 950, 595);
    }
}

void Table::UnequipGun()
{
    i = 0;
    j = 0;
    while (i < verticalRows)
    {
        j = 0;
        while (j < horizontalRows)
        {
            if (Positions[i][j].x == ImagenSlotSelected.rect.x && Positions[i][j].y == ImagenSlotSelected.rect.y)
            {
                ImagenSlotsContainers[i][j].texture = ImagenSlot.texture;
            }
            j++;
        }
        i++;
    }
}

int Table::Get_SelectedPosition_vertical()
{
    return SelectedPosition_vertical;
}

int Table::Get_SelectedPosition_horizontal()
{
    return SelectedPosition_horizontal;
}

void Table::Set_Price(float param, int x, int y)
{
    moneyInWallet = param;
    _gcvt_s(moneyInWalletBuffer, 10, moneyInWallet, 5);
    moneyInWalletName.Start();
    moneyInWalletName.Set_Text(moneyInWalletBuffer, font);
    moneyInWalletName.Set_Position(x, y);
}

void Table::Set_PlayerLevel(int param, int x, int y)
{
    PlayerLevel = param;
    _itoa_s(PlayerLevel, PlayerLevelBuffer, 10);
    PlayerLevelName.Start();
    PlayerLevelName.Set_Text(PlayerLevelBuffer, font);
    PlayerLevelName.Set_Position(x, y);
}

void Table::Set_Font(Font* font)
{
    this->font = font;
}