
#include <SFML/Graphics.hpp>
#include <iostream>
// #include "str.h"

using namespace std;
using namespace sf;





Texture shiptexture;
Sprite shipsprite;

void drawship(RenderWindow& window)
{
    ship1.s.setPosition(ship1.p.x,ship1.p.y);
    window.draw(ship1.s);
}


void modship(double x)
{
    if(x>0 && ship1.p.x < 1170)
    {
        ship1.p.x += 10;
    }

    if(x<0 && ship1.p.x > 0)
    {
        ship1.p.x += -10;
    }

}


