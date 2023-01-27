#pragma once

/*
Not use in the program but made for apply polymorphism in the Backpack class
*/

#pragma region

#define GEAR_POSITION_X 75
#define GEAR_POSITION_Y 225
#define GEAR_OFFSET_Y 50

class Gear_1 : public Gear
{
public:
    void Start();
    void Update();
    void Update(SDL_Renderer* renderer);
    void Release();
};

#pragma endregion

