#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>


using namespace std;
using namespace sf;


Texture chickentexture;
Sprite chickenprite;


void Input(int x,int y,int level)
{
    for(int i=0; i<48; i++)
    {
        chic[i].ch=chickenprite;
        chic[i].ch.setScale(0.7,0.7);
        chic[i].out=1;
        chic[i].hp=level;
        if(i%4==0)
        {
            x+=104;
            y=0;
            chic[i].p.x=x;
            chic[i].p.y=y;
        }
        else
        {
            y+=127;
            chic[i].p.x=x;
            chic[i].p.y=y;
        }
        chic[i].ch.setPosition(x,y-500);
        chic[i].temp.x = chic[i].p.x;
        chic[i].temp.y = chic[i].p.y-500;
        ///chic[i].ch.setTextureRect(IntRect(0,0,36,32));
    }
}



void drawchicken(RenderWindow& window)
{
    for(int i=0; i<48; i++)
    {
        chic[i].ch.setPosition(chic[i].temp.x,chic[i].temp.y);
        if(chic[i].hp<0)
            chic[i].out=0;
        if(chic[i].out)
            window.draw(chic[i].ch);
    }
}

void modchicken(int level,int &random_egg1_drop , void rand_egg(int&, int&,int),void newegg(double, double))
{
    for(int i=0;i<48;i++)
    {
        if(chic[i].out)
        {
            random_egg1_drop--;
            if(random_egg1_drop<=0)
            {
                newegg(chic[i].p.x+30,chic[i].temp.y+10);
                rand_egg(level, random_egg1_drop,10000);
            }
        }
        if(abs(chic[i].p.x-chic[i].temp.x)>10)
            chic[i].mx=-chic[i].mx;

        if(chic[i].temp.y < chic[i].p.y)
            chic[i].temp.y +=chic[i].my;

        chic[i].temp.x +=chic[i].mx;
    }
}
