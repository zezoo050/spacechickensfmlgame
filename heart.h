#include <SFML/Graphics.hpp>
#include <iostream>
// #include "str.h"

using namespace std;
using namespace sf;

struct pos1
{
    double x,y;
};

struct heart
{
    pos1 p;
    Sprite g;
    bool out =0;
};

const int hN = 1e4;

Texture hearttexture;
Sprite heartSprite;

heart hearts[hN] ;


void addh(heart g)
{
    for(int i=0;i<hN;i++)
    {
        if(!hearts[i].out)
        {
            hearts[i]=g;
            break;
        }
    }
}



void newheart(double x,double y)
{
    hearttexture.loadFromFile("heart.png");
    heartSprite.setTexture(hearttexture);
    // heartSprite.setScale();
    heart h;
    h.p.x = x;
    h.p.y = y;
    h.g=heartSprite;
    h.out=1;
    addh(h);
}

void modheart(Sprite s,int &health)
{
    for(int i=0;i<hN;i++)
    {
        if(hearts[i].out)
        {
            hearts[i].p.y += 2;
            if(hearts[i].g.getGlobalBounds().intersects( s.getGlobalBounds() ))
            {   
                health++;
                hearts[i].out=0;
            }
        }
    }

    for(int i=0;i<hN;i++)
    {
        if(hearts[i].p.y>900)
            hearts[i].out=0;
    }
}

void drawheart(RenderWindow& window)
{
    for(int i=0;i<hN;i++)
    {
        if(hearts[i].out)
        {
            hearts[i].g.setPosition(hearts[i].p.x,hearts[i].p.y);
            window.draw(hearts[i].g);
        }
    }
}
