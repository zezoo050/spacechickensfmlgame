#include <SFML/Audio.hpp>

using namespace sf;



SoundBuffer bullet_buffer,chicken_buffer , boss_buffer  , inter_buffer , gift_buffer ,player_hit_buffer;

Sound chicken_sound , bullet_sound , boss_sound , inter_sound , gift_sound, player_hit_sound;


Music Menu_music;


bool soundmute=0;


void sound_setup()
{
    Menu_music.openFromFile("mainmusic.oga");


    // Menu_music.setLoop(true);
    Menu_music.setVolume(100);




    chicken_buffer.loadFromFile("Ci1chickenhit.oga");
    chicken_sound.setBuffer(chicken_buffer);

    bullet_buffer.loadFromFile("Ionblaster.oga");
    bullet_sound.setBuffer(bullet_buffer);

	boss_buffer.loadFromFile("Ci1bosshit.oga");
	boss_sound.setBuffer(boss_buffer);
	
    gift_buffer.loadFromFile("Ci1weaponget.oga");
    gift_sound.setBuffer(gift_buffer);

	player_hit_buffer.loadFromFile("Ci1playerhit.oga");
    player_hit_sound.setBuffer(player_hit_buffer);

}


void play_chicken_sound()
{
    if(!soundmute)
    {
        chicken_sound.play();
    }
}


void play_bullet_sound()
{
    if(!soundmute)
    {
        bullet_sound.play();
    }
}


void play_boss_sound()
{
	if (!soundmute)
	{
		boss_sound.play();
	}
}


void play_Menu_Music()
{
    // if(!soundmute)
        Menu_music.play();
}

void pause_Menu_Music()
{
    Menu_music.pause();
}


void play_gift_sound()
{
    if(!soundmute)
        gift_sound.play();
}



void play_player_hit_sound()
{
    if(!soundmute)
        player_hit_sound.play();
}