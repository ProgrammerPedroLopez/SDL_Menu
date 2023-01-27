#include <string.h>
#include "Header.h"
#include "GameObject.h"
#include "Font.h"

Font::Font() 
{
    strcpy_s(directory, "assets/font/");
    strcpy_s(extension, ".png");
    strcpy_s(letra, "a");
    strcpy_s(number, "0");
    strcpy_s(path, "");
}

void Font::Start()
{
    int i = 0;
    while (i < 26)
    {
        strcpy_s(path, directory);
        strcat_s(path, letra);
        strcat_s(path, extension);
        Img::LoadImage(path, Letters[i]);

        /*se suma porque en la tabla ascii las letras estan en orden consecutivo*/
        letra[0]++;
        i++;
    }

    i = 0;
    while (i < 10)
    {
        strcpy_s(path, directory);
        strcat_s(path, number);
        strcat_s(path, extension);
        Img::LoadImage(path, Numbers[i]);

        /*se suma porque en la tabla ascii las letras estan en orden consecutivo*/
        number[0]++;
        i++;
    }
    Img::LoadImage("assets/font/espacio.png", Letters[26]);
    Img::LoadImage("assets/font/punto.png", Letters[27]);
}

void Font::Update()
{

}

void Font::Release()
{

}