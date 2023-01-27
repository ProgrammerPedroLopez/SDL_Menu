#include <string.h>
#include "Header.h"
//enum
#include "ElementalDamage.h"
#include "GearType.h"
#include "Manufacturer.h"
#include "Rarity.h"
#include "WeaponType.h"
//struct
#include "Vector2.h"
//class
#include "GameObject.h"
#include "Font.h"
#include "DisplayText.h"
#include "Item.h"
#include "Weapon.h"
#include "CurrentWeapons.h"
#include "Input.h"
#include "BackPack.h"
#include "Gear.h"
#include "CurrentGears.h"
#include "Table.h"
#include "All_Avaible_Image_Weapons.h"
using namespace std;

#define WIDTH 1280
#define HEIGHT 720
#define FPS 24
#define frameDelay (1000/FPS)
#define IMG_PATH "sample.png"

SDL_Renderer* renderer = NULL;
Img::Image playerImage1, playerImage2, playerImage3, playerImage4;
SDL_Rect srcR;

Font font;
Table* table = nullptr;
BackPack* backPack = nullptr;
All_Avaible_Image_Weapons* all_Avaible_Image_Weapons = nullptr;

//mis datos
Img::Image ImagenBackground;
Img::Image ImagenTable;

int main(int argc, char* args[]) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
       std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("r/gamedev", 100, 100, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    //Loads image
    Img::SetRenderer(renderer);
    Img::LoadImage("assets/original.png", ImagenBackground);
    Img::LoadImage("assets/table.png", ImagenTable);
    
    ImagenBackground.rect.x = 0;
    ImagenTable.rect.x = 900;
    ImagenTable.rect.y = 100;
    
    font.Start();
    
    backPack = new BackPack;
    table = new Table;
    all_Avaible_Image_Weapons = new All_Avaible_Image_Weapons;

    backPack->Set_Font(&font);
    table->Set_Font(&font);

    backPack->Start();
    table->Start();
    all_Avaible_Image_Weapons->Start();

    SDL_Event event;
    bool quit = false;

    Uint32 frameStart;
    int frameTime;

    while (!quit) {

        frameStart = SDL_GetTicks();

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE) {
                quit = true;
            }

            if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_s)
            {
                table->On_Key_Released_S();
            }
            if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_w)
            {
                table->On_Key_Released_W();
            }
            if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_a)
            {
                table->On_Key_Released_A();
            }
            if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_d)
            {
                table->On_Key_Released_D();
            }
            if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_e)
            {
                //cambiar el arma que se muestra
                table->ChangeGun(all_Avaible_Image_Weapons->Get_Weapon_Texture(backPack->Get_Index()), backPack->GetCurrentItem()->Get_Price(), backPack->GetCurrentItem()->Get_Score());
            }
            if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_q)
            {
                table->UnequipGun();
            }
            if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_r) 
            {
                Input::Key_R = true;
            }
            else 
            {
                Input::Key_R = false;
            }
        }

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }

        // clear the screen
        SDL_RenderClear(renderer);

        //Do render and game logic
        GameLoop(window);

        // flip the backbuffer
        // this means that everything that we prepared behind the screens is actually shown
        SDL_RenderPresent(renderer);
    }
    
    backPack->Release();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

void GameLoop(SDL_Window* window) {

    // copy the texture to the rendering context
    
    SDL_RenderCopy(renderer, ImagenBackground.texture, NULL, &ImagenBackground.rect);
    SDL_RenderCopy(renderer, ImagenTable.texture, NULL, &ImagenTable.rect);

    table->Update(renderer);
    font.Update();
    backPack->Update(renderer);
}