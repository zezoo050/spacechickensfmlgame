#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;


Font font;
Text Menu_choices[9]  ;

Sprite heart_logo;
Texture heart_skin; 
 



Texture Menu_background_skin, Menu_logo_skin , fcis_logo_skin;


void Menu_setup(double width , double hight , int *level_ptr , int *score_ptr , int &chance )
{
    Menu_background_skin.loadFromFile("space2.png");
    Menu1.menu_background.setTexture(Menu_background_skin);
    Menu1.menu_background.setScale(3,3);
	Menu_logo_skin.loadFromFile("menu logo.png");
	Menu1.menu_logo.setTexture(Menu_logo_skin);
	Menu1.menu_logo.setScale(0.5, 0.5);
	Menu1.menu_logo.setPosition(500 ,10);
	fcis_logo_skin.loadFromFile("FCIS 25.png");
	Menu1.fcis_logo.setTexture(fcis_logo_skin);
	Menu1.fcis_logo.setPosition(810, 100);

    if(!font.loadFromFile("futureforcescondital.ttf"));

    Menu_choices[0].setFont(font);
    Menu_choices[0].setFillColor(Color::Red);
    Menu_choices[0].setString("Start");
    Menu_choices[0].setCharacterSize(100);
    Menu_choices[0].setPosition(Vector2f(width/2 -60 , hight / (4 +1)));

    Menu_choices[1].setFont(font);
    Menu_choices[1].setFillColor(Color::White);
    Menu_choices[1].setString("High Score");
    Menu_choices[1].setCharacterSize(50);
    Menu_choices[1].setPosition(Vector2f(width/2 -60 , hight / (4 +1)*2));

    Menu_choices[3].setFont(font);
    Menu_choices[3].setFillColor(Color::White);
    Menu_choices[3].setString("Mute");
    Menu_choices[3].setCharacterSize(50);
    Menu_choices[3].setPosition(Vector2f(width/2 -60 , hight / (4 +1)*4));

	Menu_choices[2].setFont(font);
	Menu_choices[2].setFillColor(Color::White);
	Menu_choices[2].setString("New Game");
	Menu_choices[2].setCharacterSize(50);
	Menu_choices[2].setPosition(Vector2f(width / 2 - 60, hight / (4 + 1) * 3));

    Menu_choices[4].setFont(font);
    Menu_choices[4].setFillColor(Color::White);
    Menu_choices[4].setString("Exit");
    Menu_choices[4].setCharacterSize(50);
    Menu_choices[4].setPosition(Vector2f(width/10 -60 , hight / (4 +1)*4));




	Menu_choices[5].setFont(font);
	Menu_choices[5].setFillColor(Color::White);
	Menu_choices[5].setString("Score : " + to_string(*score_ptr));
	Menu_choices[5].setCharacterSize(50);
	Menu_choices[5].setPosition(Vector2f(width / 100, hight/100 ));


	Menu_choices[6].setFont(font);
	Menu_choices[6].setFillColor(Color::White);
	Menu_choices[6].setString("Level : "+to_string(*level_ptr));
	Menu_choices[6].setCharacterSize(50);
	Menu_choices[6].setPosition(Vector2f(width / 100, hight / 100 +50));


	Menu_choices[7].setFont(font);
	Menu_choices[7].setFillColor(Color::White);
	Menu_choices[7].setString(to_string(chance));
	Menu_choices[7].setCharacterSize(50);
	Menu_choices[7].setPosition(Vector2f(width / 100 +150 , hight / 100 + 100));
	

    Menu_choices[8].setFont(font);
	Menu_choices[8].setFillColor(Color::White);
	Menu_choices[8].setCharacterSize(150);
	Menu_choices[8].setPosition(Vector2f(width / 2 -150, hight / 2 - 150));

	heart_skin.loadFromFile("heart.png");
	heart_logo.setTexture(heart_skin);
	heart_logo.setPosition(50, 120);

    
}



void move_down()
{

    if(Menu1.menu_select < 5)
    {
        Menu_choices[Menu1.menu_select].setFillColor(Color::White);
        Menu_choices[Menu1.menu_select].setCharacterSize(50);

        Menu1.menu_select++;
        if(Menu1.menu_select>=5)
            Menu1.menu_select=0;
        Menu_choices[Menu1.menu_select].setFillColor(Color::Red);
        Menu_choices[Menu1.menu_select].setCharacterSize(100);
    }
}



void move_up()
{

    if(Menu1.menu_select > -1)
    {
        Menu_choices[Menu1.menu_select].setFillColor(Color::White);
        Menu_choices[Menu1.menu_select].setCharacterSize(50);
        Menu1.menu_select--;
        if(Menu1.menu_select<=-1)
            Menu1.menu_select=4;
        Menu_choices[Menu1.menu_select].setFillColor(Color::Red);
        Menu_choices[Menu1.menu_select].setCharacterSize(100);
    }
}




void draw_Menu(RenderWindow &window)
{
    window.draw(Menu1.menu_background);
	window.draw(Menu1.menu_logo);
	window.draw(Menu1.fcis_logo);
	window.draw(heart_logo);

    for(int i=0;i<8;i++)
    {
        window.draw(Menu_choices[i]);
    }
}


void new_game(int &page, int &level, bool &inboss, int &number_of_waves , double &x  , double  &y  , int &score , int &chance , int& bullet_count ,int&message_delay,bool &inmessage,int &chicken_alive)
{
    inboss = 0; 
    level = 1; 
    number_of_waves = 0; 
    x = 600; 
    y = 700; 
    Input(-90, 0,level);
    score = 0;
    chance = 3;
    bullet_count = 0;
    page = 1;
    message_delay=-1;
    inmessage=0;
    chicken_alive=0;
}


void Menu_pressed(int &page, int &level, bool &inboss, int &number_of_waves , double &x  , double  &y  , int &score , int &chance , int& bullet_count,int&message_delay,bool &inmessage,int chicken_alive)
{
	if (Menu1.menu_select == 0)
	{
		page = 1;
	}
    else if(Menu1.menu_select==1)
    {

    }
   
	else if (Menu1.menu_select == 2)
	{
		new_game(page, level, inboss, number_of_waves , x  , y  , score , chance , bullet_count,message_delay,inmessage,chicken_alive);

	}

	else if (Menu1.menu_select == 3)
	{
		if (soundmute)
		{
			soundmute = 0;
			Menu_music.setVolume(100);
		}
		else
		{
			soundmute = 1;
			Menu_music.setVolume(0);
		}
	}


	else if (Menu1.menu_select == 4)
	{
		exit(0);
	}
}



void display_message(int &message_delay , bool &inmessage, string s)
{
    	Menu_choices[8].setString(s);   
        inmessage=1;
        message_delay = 120;

}

void drawmessage(RenderWindow &window)
{
    window.draw(Menu_choices[8]);
}