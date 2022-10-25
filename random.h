#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cmath>
// #include "bullet.h"
#include "chicken.h"

using namespace std;
using namespace sf;




string chickenstypes[]={"chicken1.png","chicken2.png","chicken3.png","chicken4.png","chicken5.png"};


int randcolor()
{
    return (rand()%256);
}

int rand_drop()
{
	return(rand() % 48);
}


void randomize()
{
    bullettexture.loadFromFile("bullet.png");
    bullettexture.setSmooth(true);
    bulletsprite.setTexture(bullettexture);
    bulletsprite.setColor(Color(randcolor(),randcolor(),randcolor()));


    gifttexture.loadFromFile("gift.png");
    giftSprite.setTexture(gifttexture);
    giftSprite.setColor(Color(randcolor(),randcolor(),randcolor()));



    chickentexture.loadFromFile(chickenstypes[rand()%5]);
    chickentexture.setSmooth(true);
    chickenprite.setTexture(chickentexture);

}


void rand_gift(int &level, int &random_gift_drop)
{
	random_gift_drop = level*3 + rand() % (level*2);
}


void rand_heart(int &level, int &random_heart_drop)
{
	random_heart_drop = level*100 + rand() % (level*50);
}

void rand_egg(int &level, int &random_egg_drop , int num)
{
	random_egg_drop = num/level + rand()%(level*2);
}