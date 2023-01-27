#include <string.h>
#include "Header.h"
#include "GameObject.h"
#include "Vector2.h"
#include "Font.h"
#include "DisplayText.h"
#include "GlobalVariables.h"

DisplayText::DisplayText()
{
    Position.x = 0;
    Position.y = 0;
    size = 0;
}

void DisplayText::Start() 
{

}
void DisplayText::Update(SDL_Renderer* renderer)
{
    int i = 0;
    while (i < size)
    {
        SDL_RenderCopy(renderer, ptr[i].texture, NULL, &ptr[i].rect);
        i++;
    }
}
void DisplayText::Update() 
{

}
void DisplayText::Release()
{
    delete[] ptr;
}

void DisplayText::Set_Text(std::string param, Font* font)
{
    text = param;

    //inicializar
    int i = 0;
    while (text[i] != '\0')
    {
        i++;
    }
    size = i;
    ptr = new Img::Image[size];

    //Obtener la imagen
    i = 0;
    while (i < size)
    {
        if (text[i] == 32) //espacio
        {
            ptr[i] = font->Letters[26];
        }
        else
        {
            if (text[i] >= 48 && text[i] <= 57)
            {
                ptr[i] = font->Numbers[text[i] - 48];
            }
            else
            {
                if (text[i] == 46)
                {
                    ptr[i] = font->Letters[27];
                }
                else
                {
                    ptr[i] = font->Letters[text[i] - 97]; //a minuscula
                }
            }
        }
        i++;
    }

}
std::string DisplayText::Get_Text()
{
    return text;
}

void DisplayText::Set_Position(int x, int y)
{
    Position.x = x;
    Position.y = y;

    ptr[0].rect.x = Position.x;
    ptr[0].rect.y = Position.y;

    //Posicionar el texto
    int i = 0;
    while (i < size - 1)
    {
        ptr[(i + 1)].rect.x = ptr[(i)].rect.x + ptr[(i)].rect.w;
        ptr[(i + 1)].rect.y = ptr[(i)].rect.y;
        i++;
    }
}
Vector2 DisplayText::Get_Position()
{
    return Position;
}

