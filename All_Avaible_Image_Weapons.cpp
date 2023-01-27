#include <string.h>
#include "Header.h"
#include "All_Avaible_Image_Weapons.h"

All_Avaible_Image_Weapons::All_Avaible_Image_Weapons() 
{
    strcpy_s(directory, "assets/items/slot_unselected_weapon_");
    strcpy_s(extension, ".png");
    strcpy_s(letra, "1");
    strcpy_s(path, "");
    i = 0;
}

void All_Avaible_Image_Weapons::Start()
{
    i = 0;
    while (i < AVAIBLE_WEAPONS)
    {
        strcpy_s(path, directory);
        strcat_s(path, letra);
        strcat_s(path, extension);
        Img::LoadImage(path, ImagenWeaponContainer[i]);
        letra[0]++;
        i++;
    }
}

Img::Image* All_Avaible_Image_Weapons::Get_Weapon_Texture(int param)
{
    if (param > -1 && param < AVAIBLE_WEAPONS)
    {
        return &ImagenWeaponContainer[param];
    }
    return nullptr;
}