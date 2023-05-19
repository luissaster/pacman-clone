#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include "map.h"
#include "pacman.h"

#define PACMAN_SPRITE "sprites/pacman.png"
#define FONT "fonts/arial.ttf"
#define MAIN_SONG "sounds/mainTheme.mp3"
#define PACMAN_CHOMP "sounds/pacmanChomp.wav"
#define FPS 60

void loadMap(const char* archiveName, std::vector<std::vector<char>>& mapa) { // vetor de vetores = matriz, utilizado para carregar as informacoes no txt do mapa
    std::ifstream arquivo(archiveName);
    std::string linha;

    if (arquivo.is_open()) {
        while (getline(arquivo, linha)) {
            std::vector<char> linhaMapa;
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
        std::cout << "Error while opening the map file." << std::endl;
    }
}
int main(void) {
    // Initializations
    al_init();
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_acodec_addon();
    al_install_audio();
    al_install_keyboard();

    // Definitions - remember to always clean everything in the end of main
    ALLEGRO_DISPLAY* display = NULL; 
    ALLEGRO_EVENT_QUEUE* queue = NULL;
    ALLEGRO_TIMER* timer = NULL;
    ALLEGRO_BITMAP* pacman_sprite = NULL;
    ALLEGRO_FONT* font = NULL;
    ALLEGRO_SAMPLE* sample1 = NULL; // main song
    ALLEGRO_SAMPLE* sample2 = NULL; // pacman walk sound
    ALLEGRO_SAMPLE_ID mainSongID;
    sample1 = al_load_sample(MAIN_SONG);
    sample2 = al_load_sample(PACMAN_CHOMP);
    pacman_sprite = al_load_bitmap(PACMAN_SPRITE);
    font = al_load_font(FONT, 24, 0);
    display = al_create_display(608, 672); // Number of walls in a row/column * 32 (sprite size)
    queue = al_create_event_queue();
    timer = al_create_timer(1.0 / FPS);  // 60 frames per second
    al_reserve_samples(2); // Quantity of sounds
    // Load the map
    std::vector<std::vector<char>> mapa;
    loadMap("map.txt", mapa);

    // Check initializations
    if (!al_init()) {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize Allegro!",
            NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }
    if (!al_init_image_addon()) {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!",
            NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }
    if (!al_init_ttf_addon()) {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_ttf_addon!",
            NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }
    if (!al_init_font_addon()) {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_font_addon!",
            NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }
    if (!al_init_acodec_addon()) {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_acodec_addon!",
            NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }
    if (!al_install_audio()) {
        al_show_native_message_box(display, "Error", "Error", "Failed to install audio!",
            NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }
    if (!al_install_keyboard()) {
        al_show_native_message_box(display, "Error", "Error", "Failed to install keyboard!",
            NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }
    if (!display) {
        al_show_native_message_box(display, "Error", "Error", "Failed to create display!",
            NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }
    if (!queue) {
        al_show_native_message_box(display, "Error", "Error", "Failed to create event queue!",
            NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }
    if (!timer) {
        al_show_native_message_box(display, "Error", "Error", "Failed to create timer!",
            NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }
    if (!pacman_sprite) {
        al_show_native_message_box(display, "Error", "Error", "Failed to load sprites/pacman.png!",
            NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }
    if(!font){
        al_show_native_message_box(display, "Error", "Error", "Failed to load fonts/arial.ttf!",
            NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }
    if (!sample1) {
        al_show_native_message_box(display, "Error", "Error", "Failed to load songs/mainTheme.mp3",
            NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }
    if (!sample2) {
        al_show_native_message_box(display, "Error", "Error", "Failed to load songs/pacmanChomp.wav",
            NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }

    // Registering
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_start_timer(timer);

    // Variables 
    bool running = true; // Game's main loop
    bool teclas[255] = { false }; // Store player's input
    int sprite = 0, fator = 1, tempo, miliseg = 200; // Used for animations
    bool redraw = true; // Game's condition to redraw ("refresh") the screen
    int proximaInstrucao = 0; // Player's next intended movement
    Pacman player(288, 480); // Starts the player somewhere close to the centre, TBH I don't remember where the player starts in the OG PacMan
    al_play_sample(sample1, 0.5, 0, 1, ALLEGRO_PLAYMODE_LOOP, &mainSongID);

    while (running) {
        ALLEGRO_EVENT event;
        al_wait_for_event(queue, &event);
        tempo = al_get_timer_count(timer);
        // Player functions
        player.calculatePacmanPosition();
        player.checkCoinCollision(mapa);
        player.checkTeleportCollisionLeft(mapa);
        player.checkTeleportCollisionRight(mapa);

        if (event.type == ALLEGRO_EVENT_TIMER) {
            // Timer to change the bitmap, used for animating PACMAN
            if (tempo == ((FPS * miliseg) / 1000) || tempo > ((FPS * miliseg) / 1000)) {
                al_set_timer_count(timer, 0);
                sprite = sprite + fator;
                if (sprite == 0) fator = 1;
                if (sprite == 1) fator = -1; // As our sprite only has an animation composed of two images, "sprite == 1"
            }

            // Receive the command and store it until it can be executed
            if (teclas[ALLEGRO_KEY_UP]) {
                proximaInstrucao = ALLEGRO_KEY_UP;
            }
            if (teclas[ALLEGRO_KEY_DOWN]) {
                proximaInstrucao = ALLEGRO_KEY_DOWN;
            }
            if (teclas[ALLEGRO_KEY_LEFT]) {
                proximaInstrucao = ALLEGRO_KEY_LEFT;
            }
            if (teclas[ALLEGRO_KEY_RIGHT]) {
                proximaInstrucao = ALLEGRO_KEY_RIGHT;
            }
                
            // More player functions, these are responsible for checking if the next movement is valid and executing it, respectively
            player.checkPacmanMovement(proximaInstrucao, mapa);
            player.movePacman(mapa, sample2);

            redraw = true;
        }

        if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            teclas[event.keyboard.keycode] = true;
        }
        if (event.type == ALLEGRO_EVENT_KEY_UP) {
            teclas[event.keyboard.keycode] = false;
        }

        // Redraw function, basically calls every object's draw function to update it's position and flip the display
        if (redraw && al_is_event_queue_empty(queue)) {
            redraw = false;
            al_clear_to_color(al_map_rgb(0, 0, 0));
            renderMap(mapa);
            player.renderPacman(pacman_sprite, sprite);
            al_draw_textf(font, al_map_rgb(255, 255, 255), 32, 0, 0, "Score: %d", player.getScore());
            al_flip_display();
        }

        // End the game when closing the window
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            running = false;
            break;
        }
        // End the game when there's no more coins left
        if (player.getScore() == 151) {
            running = false;
        }
    }

    // Cleaning: if u create something, don't forget to destroy it
    // In cases like the walls and coins, where they are included objects, don't forget to destroy the bitmap in the classes' destructor
    al_uninstall_keyboard();
    al_destroy_sample(sample1);
    al_destroy_sample(sample2);
    al_uninstall_audio();
    al_destroy_bitmap(pacman_sprite);
    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    return 0;
}
