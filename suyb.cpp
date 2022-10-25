#include <SFML/Graphics.hpp>
#include <iostream>

#include "str.h"
#include "gift.h"
#include "bullet.h"
#include "ship.h"
#include "random.h"
#include "Main_Menu.h"
#include "boss.h"
#include "heart.h"
#include "egg.h"

// #include "sound.h"
// #include "chicken.h"

using namespace std;
using namespace sf;

int f = 0;
int d = 0;
int g = 0;

int level = 1 , score =0 ;
int *level_ptr = &level , *score_ptr=&score;


int number_of_waves = 0;
int random_gift_drop,random_heart_drop=30,random_egg1_drop=1005; 
bool inboss = 0 ,inmessage=0 ,gameover = 0;
int message_delay=-1;
int chicken_alive;
// bool soundmute=0;
double width = 1280;
double hight = 800;




int page = 0;

int main()
{
	RenderWindow window(sf::VideoMode(1280, 800), "ship ");
	window.setFramerateLimit(60);
	sound_setup();
	Menu_setup(width, hight , level_ptr , score_ptr , ship1.health);
	shiptexture.loadFromFile("spaceship.png");

	Sprite game_backgoround; 
	Texture game_backgoround_skin;
	game_backgoround_skin.loadFromFile("space2.png");
	game_backgoround.setTexture(game_backgoround_skin);
	game_backgoround.setScale(2, 2);


	eggtexture.loadFromFile("egg.png");
	egg2texture.loadFromFile("egg2.png");
	eggSprite.setTexture(eggtexture);
	egg2Sprite.setTexture(egg2texture);
	egg2Sprite.setScale(1,1);
	

	ship1.s.setTexture(shiptexture);

	ship1.p.x = 600;
	ship1.p.y = 700;
	// ship1.s.setScale(0.25, 0.25);
	randomize();
	play_Menu_Music();
	while (window.isOpen())
	{
		Menu_choices[6].setString("Level : " + to_string(*level_ptr)); 
		Menu_choices[5].setString("Score : " + to_string(*score_ptr));
		Menu_choices[7].setString(to_string(ship1.health));
		
		if (page == 0)
		{
			Event event;
			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case Event::Closed:
					window.close();
				}

				if (event.type == sf::Event::KeyPressed)
				{

					if (Keyboard::isKeyPressed(Keyboard::Key::Up))
					{
						move_up();
					}
					if (Keyboard::isKeyPressed(Keyboard::Key::Down))
					{
						move_down();
					}
					if (Keyboard::isKeyPressed(Keyboard::Key::Return))
					{
						Menu_pressed(page , level , inboss , number_of_waves , ship1.p.x , ship1.p.y , score , ship1.health , ship1.bullet_count,message_delay,inmessage,chicken_alive);
					}
				}
			}
			
			draw_Menu(window);
			window.display();

		}
		else if (page == 1)
		{
			pause_Menu_Music();

			if(inmessage)
			{
				cout<<1<<endl;
				message_delay--;
				if(message_delay<=0)
				{
					inmessage=0;
				}

				window.clear();
				window.draw(game_backgoround);
				drawmessage(window);
				window.display();

				continue;
			}
			if(gameover && message_delay<=0 && !inmessage)
			{
				
                new_game(page , level , inboss , number_of_waves , ship1.p.x , ship1.p.y , score , ship1.health , ship1.bullet_count,message_delay,inmessage,chicken_alive);
				gameover=0;
			}
			if(gameover && !inmessage)
			{
				display_message(message_delay,inmessage,"GAME OVER");
				boss1.out=0;
			}
			chicken_alive = 0;
			if(number_of_waves!=0)
			for (int i = 0; i<48; i++)
			{
				if (chic[i].out)
					chicken_alive++;
			}

			if (chicken_alive == 0 && !inboss && number_of_waves < level)
			{
				if(number_of_waves==0)
				{
					display_message(message_delay,inmessage,"LEVEL "+to_string(level));
				}
				number_of_waves++;
				Input(-90, 0,level);
			}

			chicken_alive = 0;
			for (int i = 0; i<48; i++)
			{
				if (chic[i].out)
					chicken_alive++;
			}
			if (number_of_waves >= level && !inboss && !chicken_alive)
			{
				newboss(level);
				random_egg1_drop=10;
				randomize();
				inboss = 1;
			}

			Event event;
			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case Event::Closed:
					window.close();
				}
			}

			if (Keyboard::isKeyPressed(Keyboard::Key::Right))
			{
				modship(0.25);
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Left))
			{
				modship(-0.25);
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Space) && d<1)
			{
				newbullets(ship1.p.x, ship1);
				play_bullet_sound();
				d = 20;
				// newegg(200,200);
								
			}
			d--;


			if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
			{
				page = 0;
				play_Menu_Music();
			}

			modbullets(level, number_of_waves, inboss ,score , random_gift_drop, rand_gift ,random_heart_drop,rand_heart,newheart);
			modgift(play_gift_sound);
			modchicken(level,random_egg1_drop,rand_egg,newegg);
			modheart(ship1.s, ship1.health);
			modegg(ship1.s,page , level , inboss , number_of_waves , ship1.p.x , ship1.p.y , score , ship1.health , ship1.bullet_count ,gameover);
			window.clear();
			window.draw(game_backgoround);
			drawegg(window);
			drawship(window);
			drawchicken(window);
			drawbullets(window);
			drawgift(window);
			drawBoss(BossMoveX(), BossMoveY(), window,level,random_egg1_drop,newegg);
			drawheart(window);
			window.display();
		}
	}
	return 0;
}