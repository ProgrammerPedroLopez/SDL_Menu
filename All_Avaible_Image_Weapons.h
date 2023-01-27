#pragma once

/*
This class was made to store the images of the weapons, 
works with the class Table to show the weapons in the 
area on the right
*/

#define AVAIBLE_WEAPONS 7

class All_Avaible_Image_Weapons
{
private:
    Img::Image ImagenWeaponContainer[AVAIBLE_WEAPONS];
    char directory[40];
    char extension[20];
    char letra[2];
    char path[62];
    int i = 0;
public:
    All_Avaible_Image_Weapons();

    void Start();

    Img::Image* Get_Weapon_Texture(int param);
};