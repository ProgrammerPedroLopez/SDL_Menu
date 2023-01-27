#pragma once

/*
This class works with DisplayText for showing text and numbers
*/

class Font : public GameObject
{
    friend class DisplayText;

    Img::Image Letters[28];
    Img::Image Numbers[10];
    char directory[20];
    char extension[20];
    char letra[2];
    char number[2];
    char path[20];

public:

    Font();

    void Start();

    void Update();

    void Release();
};