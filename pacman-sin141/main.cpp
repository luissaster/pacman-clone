#include<iostream>
#include<stdio.h>
#include<allegro5/allegro5.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_primitives.h>
#include<vector>
#include<fstream>
#include<string>
#include"map.h"
#include"pacman.h"
#define PACMAN_SPRITE "sprites/pacman.png"

using namespace std;

void carregarMapa(const char* nomeArquivo, vector<vector<char>>& mapa) {
    ifstream arquivo(nomeArquivo);
    string linha;

    if (arquivo.is_open()) {
        while (getline(arquivo, linha)) {
            vector<char> linhaMapa;
            for (char caractere : linha) {
                if (caractere != ' ') {
                    linhaMapa.push_back(caractere);
                }
            }
            mapa.push_back(linhaMapa);
        }
        arquivo.close();
    }
    else {
        cout << "Erro ao abrir o arquivo." << endl;
    }
}
const int FPS = 60;
int main(void) {

    al_init(); //inicializacoes
    al_init_image_addon();
    al_install_keyboard();

    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_EVENT_QUEUE* queue = NULL;
    ALLEGRO_TIMER* timer = NULL;
    ALLEGRO_BITMAP* pacman_sprite = NULL;
    pacman_sprite = al_load_bitmap(PACMAN_SPRITE);

    //carregar mapa
    vector<vector<char>> mapa;
    carregarMapa("map.txt", mapa);

    display = al_create_display(608, 672); //quantidade de paredes em uma linha/coluna * 32 (tamanho do sprite)
    queue = al_create_event_queue();
    timer = al_create_timer(1.0 / FPS); //60 quadros por segundo

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

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_start_timer(timer);

    bool running = true;
    bool teclas[255] = { false };
    int sprite = 0, fator = 1;
    int tempo, miliseg = 200;
    bool redraw = true;
    int proximaInstrucao = 0;
    Pacman player(32, 32);

    while (running) {
        ALLEGRO_EVENT event;
        al_wait_for_event(queue, &event);
        tempo = al_get_timer_count(timer);

        player.posicaoPacman();
        player.colisaoPacmanPirula(mapa);

        if(event.type == ALLEGRO_EVENT_TIMER) {


            //Timer para trocar o bitmap
            if (tempo == ((FPS * miliseg) / 1000) || tempo > ((FPS * miliseg) / 1000)) {
                al_set_timer_count(timer, 0);
                sprite = sprite + fator;
                if (sprite == 0) fator = 1;
                if (sprite == 1) fator = -1;
            }

            //Recebe o comando e guarda ele na variavel ate q ele seja possivel de ser executado

            if (teclas[ALLEGRO_KEY_UP])
            {
                proximaInstrucao = ALLEGRO_KEY_UP;
            }
            if (teclas[ALLEGRO_KEY_DOWN])
            {
                proximaInstrucao = ALLEGRO_KEY_DOWN;
            }
            if (teclas[ALLEGRO_KEY_LEFT])
            {
                proximaInstrucao = ALLEGRO_KEY_LEFT;
            }
            if (teclas[ALLEGRO_KEY_RIGHT])
            {
                proximaInstrucao = ALLEGRO_KEY_RIGHT;

            }

            player.movimentacaoPacman(proximaInstrucao, mapa);
            player.execusaoMovPacman(mapa);

            redraw = true;
        }
        else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            running = false;
            break;
        }
        else if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
             teclas[event.keyboard.keycode] = true;
        }
        else if (event.type == ALLEGRO_EVENT_KEY_UP) {
            teclas[event.keyboard.keycode] = false;

        }

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            running = false;
        }

        if (redraw && al_is_event_queue_empty(queue)) {
            redraw = false;
            al_clear_to_color(al_map_rgb(0, 0, 0));
            player.desenhaPacman(pacman_sprite, sprite);
            draw_map(mapa);
            al_flip_display();
        }

    }

        al_uninstall_keyboard();
        al_destroy_display(display);
        al_destroy_timer(timer);
        al_destroy_event_queue(queue);
        return 0;
    }

