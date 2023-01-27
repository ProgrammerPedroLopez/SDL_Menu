#pragma once

/*
This class works with Font for showing text and numbers
*/

class DisplayText : public GameObject
{
private:
    Img::Image* ptr = nullptr;
    std::string text;
    int size;
    Vector2 Position;

public:
    DisplayText();

    void Start();
    void Update(SDL_Renderer*);
    void Update();

    void Set_Text(std::string param, Font* font);
    std::string Get_Text();

    void Set_Position(int x, int y);
    Vector2 Get_Position();

    void Release();
};