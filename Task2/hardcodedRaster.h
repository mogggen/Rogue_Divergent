#pragma once
#include <string>

namespace Game
{
#define ooo 0, 0, 0,
#define ooi 0, 0, 1,
#define oio 0, 1, 0,
#define oii 0, 1, 1,
#define ioo 1, 0, 0,
#define ioi 1, 0, 1,
#define iio 1, 1, 0,
#define iii 1, 1, 1,

#define ioooi 1, 0, 0, 0, 1,
#define ioioi 1, 0, 1, 0, 1,
#define iioii 1, 1, 0, 1, 1,

    void CharacterRasterization(SDL_Renderer* renderer, const std::string& c, int X, int Y, const unsigned w=3, const unsigned h=5)
    {
        bool* coordinatesToRender = new bool[15];

        for (size_t i = 0; i < c.length(); i++)
        {
            switch (c.at(i))
            {
            case ' ':
                coordinatesToRender = new bool[15]
                {
                    ooo
                    ooo
                    ooo
                    ooo
                    ooo
                };
                break;

            case '0':
                coordinatesToRender = new bool[15]
                {
                    iii
                    ioi
                    ioi
                    ioi
                    iii
                };
                break;
            
            case '1':
                coordinatesToRender = new bool[15]
                {
                    oio
                    iio
                    oio
                    oio
                    iii
                };
                break;

            case '2':
                coordinatesToRender = new bool[15]
                {
                    iii
                    ooi
                    iii
                    ioo
                    iii
                };
                break;

            case '3':
                coordinatesToRender = new bool[15]
                {
                    iii
                    ooi
                    iii
                    ooi
                    iii
                };
                break;

            case '4':
                coordinatesToRender = new bool[15]
                {
                    ioi
                    ioi
                    iii
                    ooi
                    ooi
                };
                break;

            case '5':
                coordinatesToRender = new bool[15]
                {
                    iii
                    ioo
                    iii
                    ooi
                    iii
                };
                break;

            case '6':
                coordinatesToRender = new bool[15]
                {
                    ioo
                    ioo
                    iii
                    ioi
                    iii
                };
                break;

            case '7':
                coordinatesToRender = new bool[15]
                {
                    iii
                    ooi
                    ooi
                    ooi
                    ooi
                };
                break;

            case '8':
                coordinatesToRender = new bool[15]
                {
                    iii
                    ioi
                    iii
                    ioi
                    iii
                };
                break;

            case '9':
                coordinatesToRender = new bool[15]
                {
                    iii
                    ioi
                    iii
                    ooi
                    ooi
                };
                break;

            case 'A':
                coordinatesToRender = new bool[15]
                {
                    oio
                    ioi
                    iii
                    ioi
                    ioi
                };
                break;

            case 'B':
                coordinatesToRender = new bool[15]
                {
                    iii
                    ioi
                    iio
                    ioi
                    iii
                };
                break;
            
            case 'C':
                coordinatesToRender = new bool[15]
                {
                    iii
                    ioo
                    ioo
                    ioo
                    iii
                };
                break;

            case 'D':
                coordinatesToRender = new bool[15]
                {
                    iio
                    ioi
                    ioi
                    ioi
                    iio
                };
                break;

            case 'E':
                coordinatesToRender = new bool[15]
                {
                    iii
                    ioo
                    iii
                    ioo
                    iii
                };
                break;

            case 'F':
                coordinatesToRender = new bool[15]
                {
                    iii
                    ioo
                    iii
                    ioo
                    ioo
                };
                break;
            case 'G':
                coordinatesToRender = new bool[15]
                {
                    iii
                    ioo
                    ioi
                    ioi
                    iii
                };
                break;
            case 'H':
                coordinatesToRender = new bool[15]
                {
                    ioi
                    ioi
                    iii
                    ioi
                    ioi
                };
                break;
            case 'I':
                coordinatesToRender = new bool[15]
                {
                    iii
                    oio
                    oio
                    oio
                    iii
                };
                break;
            case 'J':
                coordinatesToRender = new bool[15]
                {
                    iii
                    ooi
                    ooi
                    ioi
                    iii
                };
                break;
            case 'K':
                coordinatesToRender = new bool[15]
                {
                    ioi
                    iio
                    ioo
                    iio
                    ioi
                };
                break;
            case 'L':
                coordinatesToRender = new bool[15]
                {
                    ioo
                    ioo
                    ioo
                    ioo
                    iii
                };
                break;
            case 'M':
                coordinatesToRender = new bool[25]
                {
                    ioooi
                    iioii
                    ioioi
                    ioooi
                    ioooi
                };
                break;
            case 'N':
                coordinatesToRender = new bool[15]
                {
                    ioi
                    iii
                    iii
                    ioi
                    ioi
                };
                break;
            }

            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_Rect* r = new SDL_Rect[15];
            
            for (size_t y = 0; y < h; y++)
            {
                for (size_t x = 0; x < w; x++)
                {
                    if (coordinatesToRender[y * w + x])
                    {
                        r[y * w + x].x = X + x * w;
                        r[y * w + x].y = Y + y * h;
                        r[y * w + x].w = 3;
                        r[y * w + x].h = 5;
                        SDL_RenderFillRect(renderer, &r[y * w + x]);
                    }
                }
            }
            X += w * 4;
        }
        delete[] coordinatesToRender;
    }

}
