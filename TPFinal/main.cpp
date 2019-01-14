#include <iostream>
#include "DRAW.h"

#define SCREEN_W (16*BLOCK_SIZE)
#define SCREEN_H (12*BLOCK_SIZE)

int main(void)
{
	//Allegro Allegro;

	ALLEGRO_SAMPLE * music = NULL;
	ALLEGRO_TIMER * timer = NULL;
	ALLEGRO_DISPLAY * display = NULL;
	ALLEGRO_EVENT_QUEUE	* queue = NULL;

	if (al_init())	//inicializo allegro
	{
		if (al_install_audio())	//inicializo los audios
		{
			if (al_init_acodec_addon())
			{
				if ((al_reserve_samples(1)))	//para la musica
				{
					if (al_init_image_addon())	//addon para las imagenes
					{
						if (al_install_keyboard())	//inicializo para que lea teclado
						{
							if ((queue = al_create_event_queue()))	//creo la cola de eventos
							{
								if ((display = al_create_display(SCREEN_W, SCREEN_H)))	//creo el display
								{
									al_register_event_source(queue, al_get_keyboard_event_source());	//hago que la cola de eventos registre el teclado
									al_register_event_source(queue, al_get_display_event_source(display));	//que registre cosas del display
																														//al_register_event_source(this->queue, al_get_timer_event_source(this->timer));	//y del timer
								}
							}
						}
					}
					else
						fprintf(stderr, "ERROR: Failed to load Image addon\n");
				}
				else
					fprintf(stderr, "ERROR: Failed to reserve sample\n");
			}
			else
				fprintf(stderr, "ERROR: Failed to install acodec addon\n");
		}
		else
			fprintf(stderr, "ERROR: Failed to install audio\n");
	}
	else
		fprintf(stderr, "ERROR: Failed to initialize allegro system\n");

	al_clear_to_color(al_map_rgb(255, 255, 255));
	al_flip_display();
	al_rest(3);

	return 0;
}