#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;



 Texture boss_texture;


float Xvelocity = 5;
float Yvelocity = 2;
float bosstheta = 2;




void drawBoss(int x, int y , RenderWindow &Window,int level , int &random_egg1_drop , void newegg(double, double))
{
    if(!boss1.out)
    {
	    boss1.s.setPosition(x, y);
		
		random_egg1_drop--;
		if(random_egg1_drop<=0)
		{
			newegg(boss1.p.x+130,boss1.p.y+250);
			rand_egg(level, random_egg1_drop,60);
		}
    
        Window.draw(boss1.s);
    }
}

int  BossMoveY()
{
	if (boss1.p.y < 0){
		for (int i = 0; i < 5; i++)
		{
		
			boss1.p.y += 1;
		}

	}
	else {
		boss1.p.y += Yvelocity;

		if (boss1.p.y <= 0 || boss1.p.y >= 100)
		{
			Yvelocity *= -1;

		}
	}
	return boss1.p.y;
}



int BossMoveX()
{

	boss1.p.x += Xvelocity;

	boss1.s.setRotation(bosstheta);
	if (boss1.p.x <= 0 || boss1.p.x >= 900){
		Xvelocity *= -1;
		bosstheta *= -1;
	}

	return boss1.p.x;

}

void newboss(int level)
{
    boss_texture.loadFromFile("please.png");
	boss1.s.setTexture(boss_texture);
	boss1.s.setScale(1, 1);
	boss1.s.setPosition(400, -400);
	boss1.p.x = 400;
	boss1.p.y = -400;
    boss1.health=level*100;
    boss1.out = 0;
}












	