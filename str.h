#include <SFML/Graphics.hpp>
#include <iostream>


using namespace std;
using namespace sf;


struct pos
{
    double x,y;
};






struct bullet
{
    pos p;
    double xoff=0;
    Sprite s;
    bool out=0;
};

struct gift
{
    pos p;
    Sprite g;
    bool out =0;
};





struct ship
{
    pos p;
    
    int health = 3;
    int bullet_count=9;
    Sprite s;
}ship1;



struct chicken
{
    pos p;
    pos temp;
    double mx=1;
    double my =1.5;
    Sprite ch;
    int hp=1000;
    bool out=0;
} chic[1000];




struct Menu
{
    int menu_select=0;

    Sprite menu_background , menu_logo , fcis_logo;
    
} Menu1;




struct Boss
{
	pos p;
	bool out=1;
	Sprite s;
	int health = 100000;
}boss1;
