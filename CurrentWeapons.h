#pragma once

/*
Each class is an implementation of Weapon and an attribute in the backpack class
*/

#pragma region

#define WEAPON_POSITION_X 75
#define WEAPON_POSITION_Y 225
#define WEAPON_OFFSET_Y 50

class Weapon_1 : public Weapon
{
public:
    void Start();
    void Update();
    void Update(SDL_Renderer* renderer);
    void Release();
};

class Weapon_2 : public Weapon
{
public:
    void Start();
    void Update();
    void Update(SDL_Renderer* renderer);
    void Release();
};

class Weapon_3 : public Weapon
{
public:
    void Start();
    void Update();
    void Update(SDL_Renderer* renderer);
    void Release();
};

class Weapon_4 : public Weapon
{
public:
    void Start();
    void Update();
    void Update(SDL_Renderer* renderer);
    void Release();
};

class Weapon_5 : public Weapon
{
public:
    void Start();
    void Update();
    void Update(SDL_Renderer* renderer);
    void Release();
};

class Weapon_6 : public Weapon
{
public:
    void Start();
    void Update();
    void Update(SDL_Renderer* renderer);
    void Release();
};

class Weapon_7 : public Weapon
{
public:
    void Start();
    void Update();
    void Update(SDL_Renderer* renderer);
    void Release();
};

#pragma endregion