#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <stdio.h>
#include<iostream>
#include"map.h"
//all

using namespace std;

int main() {

    ALLEGRO_DISPLAY* display = NULL; //Tela

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

    //Cria uma tela com essas dimensoes
    display = al_create_display(608, 672);

    if (!display) {
        al_show_native_message_box(display, "Error", "Error", "Falha ao iniciar o display!",
            NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }

    draw_map();

    al_flip_display();//Atualiza o Buffer da Tela
    system("pause");
    al_rest(5); //Tempo que a tela fica ativa (em segundos)

    al_destroy_display(display); //Destroi a tela

    return 0;
}
