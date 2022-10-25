#include <SFML/Graphics.hpp>
#include <iostream>
// #include "str.h"

using namespace std;
using namespace sf;

const int gN = 1e4;

Texture gifttexture;
Sprite giftSprite;

gift gifts[gN];


void addg(gift g)
{
    for(int i=0;i<gN;i++)
    {
        if(!gifts[i].out)
        {
            gifts[i]=g;
            break;
        }
    }
}



void newgift(double x,double y)
{
    gift g;
    g.p.x = x;
    g.p.y = y;
    g.g=giftSprite;
    g.out=1;
    addg(g);
}

void modgift(void play_gift_sound())
{
    for(int i=0;i<gN;i++)
    {
        if(gifts[i].out)
        {
            gifts[i].p.y += 2;
            if(gifts[i].g.getGlobalBounds().intersects(ship1.s.getGlobalBounds()))
            {   
                ship1.bullet_count++;
                gifts[i].out=0;
                play_gift_sound();
            }
        }
    }

    for(int i=0;i<gN;i++)
    {
        if(gifts[i].p.y>900)
            gifts[i].out=0;
    }
}

void drawgift(RenderWindow& window)
{

    for(int i=0;i<gN;i++)
    {
		

        if(gifts[1].out)
        {
            gifts[1].g.setPosition(gifts[1].p.x,gifts[1].p.y);
            window.draw(gifts[1].g);
        }
    }
}
