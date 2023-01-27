/*
The Backpack is the Area on the left, that show one weapon at a time,
and change what is shown by pressing R, applys polymorhpism with the 
pointers Elements by making them any weapon in the start method
*/

class BackPack : public GameObject
{
private:
    Item* Elements[8];
    int index;
    Img::Image ImagenTableLeft;
    Font* font;

    void QuickSort();

    void InputReceiver();

public:
    BackPack();

    void Start();

    void Update();
    void Update(SDL_Renderer* renderer);

    void Release();

    int Get_Index();

    Item* GetCurrentItem();

    void Set_Font(Font* font);
};