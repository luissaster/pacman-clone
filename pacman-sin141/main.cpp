#include<iostream>
#include<stdio.h>
#include<allegro5/allegro5.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_native_dialog.h>

#include"map.h"

using namespace std;

int main(void) {
    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_EVENT_QUEUE* queue = NULL;
    ALLEGRO_TIMER* timer = NULL;

    al_init(); //inicializacoes
    al_init_image_addon();
    al_install_keyboard();

    //checagem das inicializacoes
    if (!al_init()) {
        al_show_native_message_box(display, "Error", "Error", "Falha ao iniciar o Allegro",
            NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }
    if (!al_init_image_addon()) {
        al_show_native_message_box(display, "Error", "Error", "Falha ao iniciar o al_init_image_addon!",
            NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }


    display = al_create_display(608, 672); //quantidade de paredes em uma linha/coluna * 32 (tamanho do sprite)
    queue = al_create_event_queue();
    timer = al_create_timer(1.0 / 60); //60 quadros por segundo

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool running = true;
    al_start_timer(timer);
    draw_map();
    while (running) {

        ALLEGRO_EVENT event;
        al_wait_for_event(queue, &event);

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            running = false;
        }
        if (event.type == ALLEGRO_EVENT_TIMER) {
            al_flip_display();
        }

    }

    al_uninstall_keyboard();
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    return 0;
}