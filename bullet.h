#include <SFML/Graphics.hpp>
#include <iostream>
// #include "str.h"
#include "sound.h"
using namespace std;
using namespace sf;

Texture bullettexture;
Sprite bulletsprite;

const int bN = 1e5;

bullet bullets[bN];

void modbullets(int &level,int &number_of_waves,bool &inboss , int &score , int &random_gift_drop , void rand_gift(int& , int& ), int &random_heart_drop , void rand_heart(int& , int& ),void newheart(double , double))
{
    boss1.s.setPosition(boss1.p.x,boss1.p.y);
    for(int i=0;i<bN;i++)
    {
        if(bullets[i].out)
        {
            bullets[i].p.x += bullets[i].xoff;
            bullets[i].p.y -= 7;
            bullets[i].s.setPosition(bullets[i].p.x,bullets[i].p.y);

            for(int j=0;j<48;j++)
            {
                if(chic[j].out)
                {
                    // chic[j].ch.setPosition(chic[i].temp.x,chic[i].temp.y);
                    if(chic[j].ch.getGlobalBounds().intersects(bullets[i].s.getGlobalBounds()))
                    {
                        bullets[i].out=0;
                        chic[j].hp--;
						play_chicken_sound();
                        if(chic[j].hp<=0)
                        {
                            chic[j].out=0;
							random_gift_drop--;
							if (random_gift_drop < 0)
							{

								newgift(chic[j].temp.x, chic[j].temp.y);
								rand_gift(level , random_gift_drop);
							}
                            random_heart_drop--;
                            if (random_heart_drop < 0)
							{

								newheart(chic[j].temp.x, chic[j].temp.y);
								rand_heart(level , random_heart_drop);
							}
							score++;
                            
                        }

                    }
					
                }
            }
            if(inboss)
            {
                if(boss1.s.getGlobalBounds().intersects(bullets[i].s.getGlobalBounds()))
                {
                    boss1.health--;
                    bullets[i].out=0;

                    play_boss_sound();
                }
                if(boss1.health<=0)
                {
                    number_of_waves=0;
                    level++;
                    inboss=0;
                    boss1.out=1;
					score += 10;
                }
            }
        }
    }

    for(int i=0;i<bN;i++)
    {
        if((bullets[i].p.y < 0 || bullets[i].p.x < -20 || bullets[i].p.x > 1300)&&bullets[i].out)
        {
            bullets[i].out=0;
        }
    }
}


void addb(bullet b)
{
    for(int i=0;i<bN;i++)
    {
        if(!bullets[i].out)
        {
            bullets[i]=b;
            break;
        }
    }
}



void newbullets(double x,ship s)
{
    
	x+= 40;
    double y =660;
    bullet b;
    b.s=bulletsprite;
    b.s.setScale(0.75,0.75);
    b.p.y=y;
    b.out=1;
    switch(s.bullet_count){
     case 0:
            b.p.x=x;
            addb(b);
            break;
     case 1:
         b.p.x=x-25;
         addb(b);
         b.p.x=x+25;
         addb(b);
         break;
     case 2:
         b.p.x=x-10;
         b.xoff = -0.5;
         b.s.setRotation(-6);
         addb(b);
         b.p.x=x+10;
         b.xoff = 0.5;
         b.s.setRotation(6);
         addb(b);
         break;
     case 3:
         b.p.x=x-30;
         addb(b);
         b.p.x=x+30;
         addb(b);
         b.p.x=x;
         b.p.y-=20;
         addb(b);
         break;
     case 4:
         b.p.x=x;
         addb(b);
         b.p.x=x-10;
         b.xoff = -1;
         b.s.setRotation(-11);
         addb(b);
         b.p.x=x+10;
         b.xoff = 1;
         b.s.setRotation(11);
         addb(b);
         break;
     case 5:
         b.p.x=x-10;
         b.xoff = -0.5;
         b.s.setRotation(-6);
         addb(b);
         b.p.x=x+10;
         b.xoff = 0.5;
         b.s.setRotation(6);
         addb(b);
         b.p.x=x-20;
         b.xoff = -1.25;
         b.s.setRotation(-15);
         addb(b);
         b.p.x=x+20;
         b.xoff = 1.25;
         b.s.setRotation(15);
         addb(b);
         break;
     case 6:
         b.p.x=x;
         addb(b);
         b.p.x=x-10;
         b.xoff = -0.5;
         b.s.setRotation(-6);
         addb(b);
         b.p.x=x+10;
         b.xoff = 0.5;
         b.s.setRotation(6);
         addb(b);
         b.p.x=x-20;
         b.xoff = -1.25;
         b.s.setRotation(-15);
         addb(b);
         b.p.x=x+20;
         b.xoff = 1.25;
         b.s.setRotation(15);
         addb(b);
         break;
     case 7:
         b.p.x=x-10;
         b.xoff = -0.5;
         b.s.setRotation(-6);
         addb(b);

         b.p.x=x+10;
         b.xoff = 0.5;
         b.s.setRotation(6);
         addb(b);

         b.p.x=x-20;
         b.xoff = -1.25;
         b.s.setRotation(-15);
         addb(b);

         b.p.x=x+20;
         b.xoff = 1.25;
         b.s.setRotation(15);
         addb(b);

         b.p.x=x-30;
         b.xoff = -1.75;
         b.s.setRotation(-18);
         addb(b);

         b.p.x=x+30;
         b.xoff = 1.75;
         b.s.setRotation(18);
         addb(b);
         break;
     default:
         b.p.x=x;
         addb(b);

         b.p.x=x-10;
         b.xoff = -0.5;
         b.s.setRotation(-6);
         addb(b);

         b.p.x=x+10;
         b.xoff = 0.5;
         b.s.setRotation(6);
         addb(b);

         b.p.x=x-20;
         b.xoff = -1.25;
         b.s.setRotation(-15);
         addb(b);

         b.p.x=x+20;
         b.xoff = 1.25;
         b.s.setRotation(15);
         addb(b);

         b.p.x=x-30;
         b.xoff = -1.75;
         b.s.setRotation(-18);
         addb(b);

         b.p.x=x+30;
         b.xoff = 1.75;
         b.s.setRotation(18);
         addb(b);
         break;
     }
}

void drawbullets(RenderWindow& window)
{
    for(int i = 0;i<bN;i++)
    {
        if(bullets[i].out)
        {
            bullets[i].s.setPosition(bullets[i].p.x,bullets[i].p.y);
            window.draw(bullets[i].s);
        }
    }
}