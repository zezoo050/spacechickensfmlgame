#include <SFML/Graphics.hpp>
#include <iostream>


using namespace std;
using namespace sf;

const int eN = 1e4;

Texture eggtexture,egg2texture;
Sprite eggSprite,egg2Sprite;



struct pos5
{
    double x,y;
};


struct egg
{
    pos5 p;
    Sprite e;
    int cooldown=0;
    bool out =0;
    bool on_ground=0;
};



egg eggs[eN];


void adde(egg e)
{
    for (int i = 0; i < eN; i++)
    {
        if (!eggs[i].out)
        {
            eggs[i] = e;
            break;
        }
    }
}



void newegg(double x, double y)
{
    egg e;
    e.cooldown = 0;
    e.p.x = x;
    e.p.y = y;
    e.e = eggSprite;
    e.out = 1;
    adde(e);
}

void modegg(Sprite s,int &page, int &level, bool &inboss, int &number_of_waves , double &x  , double  &y  , int &score , int &chance , int& bullet_count,bool &gameover)
{
    for (int i = 0; i < eN; i++)
    {
        if (eggs[i].out)
        {
            if(!eggs[i].cooldown)
                eggs[i].p.y += 2;
            if (eggs[i].e.getGlobalBounds().intersects(s.getGlobalBounds()) && !eggs[i].on_ground && eggs[i].p.y>500)
            {
                ship1.health--;
                play_player_hit_sound();
                eggs[i].out = 0;
                if(ship1.health==0)
                {
                    gameover = 1;
                    
                }
            }
        }
    }

    for (int i = 0; i < eN; i++)
    {
        if (eggs[i].p.y > 750 && !eggs[i].cooldown && eggs[i].out)
        {
            eggs[i].cooldown = 10;
            eggs[i].e=egg2Sprite;
            eggs[i].on_ground=1;
        }
        else if(eggs[i].p.y > 750&&eggs[i].out)
        {
            
            eggs[i].cooldown--;
        }
        if(eggs[i].cooldown<0)
            eggs[i].out=0;
    }
}

void drawegg(RenderWindow& window)
{
    for (int i = 0; i < eN; i++)
    {
        if (eggs[i].out)
        {
            eggs[i].e.setPosition(eggs[i].p.x, eggs[i].p.y);
            window.draw(eggs[i].e);
        }
    }
}

