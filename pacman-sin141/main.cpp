#include <iostream>
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
#include "ghost.h"
#include "blinky.h"
#include "pinky.h"
#include "inky.h"
#include "clyde.h"

#define PACMAN_SPRITE "sprites/pacman.png"
#define BLINKY_SPRITE "sprites/blinky.png"
#define PINKY_SPRITE "sprites/pinky.png"
#define INKY_SPRITE "sprites/inky.png"
#define CLYDE_SPRITE "sprites/clyde.png"
#define MAP_SPRITE "sprites/mapaoverlay.png"
#define FONT "fonts/arial.ttf"
#define MAIN_SONG "sounds/mainTheme.mp3"
#define PACMAN_CHOMP "sounds/pacmanChomp.wav"
#define PACMAN_DEATH_SOUND "sounds/pacmanDeath.mp3"
#define FPS 60

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
    ALLEGRO_DISPLAY* display = al_create_display(608, 672); // Number of walls in a row/column * 32 (sprite size); 
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();;
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / FPS);  // 60 frames per second;
    ALLEGRO_BITMAP* pacman_sprite = al_load_bitmap(PACMAN_SPRITE);;
    ALLEGRO_BITMAP* blinky_sprite = al_load_bitmap(BLINKY_SPRITE);;
    ALLEGRO_BITMAP* pinky_sprite = al_load_bitmap(PINKY_SPRITE);;
    ALLEGRO_BITMAP* inky_sprite = al_load_bitmap(INKY_SPRITE);;
    ALLEGRO_BITMAP* clyde_sprite = al_load_bitmap(CLYDE_SPRITE);;
    ALLEGRO_BITMAP* map_sprite = al_load_bitmap(MAP_SPRITE);
    ALLEGRO_FONT* font = al_load_font(FONT, 24, 0);;
    ALLEGRO_SAMPLE* mainSongAudio = al_load_sample(MAIN_SONG);;
    ALLEGRO_SAMPLE* pacmanEatAudio = al_load_sample(PACMAN_CHOMP);;
    ALLEGRO_SAMPLE* pacmanDiesAudio = al_load_sample(PACMAN_DEATH_SOUND);;
    ALLEGRO_SAMPLE_ID mainSongID;

    al_reserve_samples(3); // Quantity of sounds
    std::vector<std::vector<char>> mapa; // Create the map array

    // Check initializations
    bool isStarting = true;
    while(isStarting){
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
        if (!font) {
            al_show_native_message_box(display, "Error", "Error", "Failed to load fonts/arial.ttf!",
                NULL, ALLEGRO_MESSAGEBOX_ERROR);
            return 0;
        }
        if (!mainSongAudio) {
            al_show_native_message_box(display, "Error", "Error", "Failed to load songs/mainTheme.mp3",
                NULL, ALLEGRO_MESSAGEBOX_ERROR);
            return 0;
        }
        if (!pacmanEatAudio) {
            al_show_native_message_box(display, "Error", "Error", "Failed to load songs/pacmanChomp.wav",
                NULL, ALLEGRO_MESSAGEBOX_ERROR);
            return 0;
        }if (!pacmanDiesAudio) {
            al_show_native_message_box(display, "Error", "Error", "Failed to load songs/pacmanDeath.mp3",
                NULL, ALLEGRO_MESSAGEBOX_ERROR);
            return 0;
        }
        if (!pacman_sprite) {
            al_show_native_message_box(display, "Error", "Error", "Failed to load sprites/pacman.png!",
                NULL, ALLEGRO_MESSAGEBOX_ERROR);
            return 0;
        }
        if (!blinky_sprite) {
            al_show_native_message_box(display, "Error", "Error", "Failed to load sprites/blinky.png!",
                NULL, ALLEGRO_MESSAGEBOX_ERROR);
            return 0;
        }
        if (!pinky_sprite) {
            al_show_native_message_box(display, "Error", "Error", "Failed to load sprites/pinky.png!",
                NULL, ALLEGRO_MESSAGEBOX_ERROR);
            return 0;
        }
        if (!inky_sprite) {
            al_show_native_message_box(display, "Error", "Error", "Failed to load sprites/inky.png!",
                NULL, ALLEGRO_MESSAGEBOX_ERROR);
            return 0;
        }
        if (!clyde_sprite) {
            al_show_native_message_box(display, "Error", "Error", "Failed to load sprites/clyde.png!",
                NULL, ALLEGRO_MESSAGEBOX_ERROR);
            return 0;
        }

        isStarting = false;
    }

    // Registering
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_start_timer(timer);

    // Variables 
    bool running = true;
    bool teclas[255] = { false };
    int sprite = 0, fator = 1, tempo, miliseg = 200;
    bool redraw = true;

    // Objects
    Map gameMap;
    Pacman playerPacman(288, 480);
    Blinky ghostBlinky(288, 256); //256, 288 <--- blinky's old spawn, spawning at 32,32 to avoid getting stuck in the spawn
    Pinky ghostPinky(320, 288);
    Inky ghostInky(288, 288);
    Clyde ghostClyde(256, 288);

    al_play_sample(mainSongAudio, 0.3, 0, 1, ALLEGRO_PLAYMODE_LOOP, &mainSongID);
    gameMap.loadMap("map.txt", mapa);

    Ghost* ghostVet[4];
    ghostVet[0] = &ghostClyde;
    ghostVet[1] = &ghostPinky;
    ghostVet[2] = &ghostInky;
    ghostVet[3] = &ghostBlinky;

    while (running) {
        ALLEGRO_EVENT event;
        al_wait_for_event(queue, &event);
        tempo = al_get_timer_count(timer);

        playerPacman.calculateEntityPosition();
        playerPacman.checkCoinCollision(mapa, pacmanEatAudio);
        playerPacman.checkTeleportCollision(mapa);
        playerPacman.checkEntityMovement(playerPacman.getNextMove(), mapa);
        playerPacman.moveEntity(mapa);

        std::cout << "[" << playerPacman.getEntityConvertedX() << "][" << playerPacman.getEntityConvertedY() << "]" << std::endl;

        //Ghost functions, we only have Blinky (ghostVet[3]) in chase mode
        for (int i = 0; i < 4; i++) {
            ghostVet[i]->calculateEntityPosition();
            ghostVet[i]->checkTeleportCollision(mapa);
        }
        for (int i = 0; i < 3; i++)
        {
            ghostVet[i]->randomDirection(mapa);
            ghostVet[i]->moveEntity(mapa);
        }

        ghostVet[3]->chasePacman(mapa, playerPacman.getEntityConvertedX(), playerPacman.getEntityConvertedY());
        ghostVet[3]->checkEntityMovement(ghostVet[3]->getNextMove(), mapa);
        ghostVet[3]->moveEntity(mapa);

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
                playerPacman.setNextMove(ALLEGRO_KEY_UP, mapa);
            }
            if (teclas[ALLEGRO_KEY_DOWN]) {
                playerPacman.setNextMove(ALLEGRO_KEY_DOWN, mapa);
            }
            if (teclas[ALLEGRO_KEY_LEFT]) {
                playerPacman.setNextMove(ALLEGRO_KEY_LEFT, mapa);
            }
            if (teclas[ALLEGRO_KEY_RIGHT]) {
                playerPacman.setNextMove(ALLEGRO_KEY_RIGHT, mapa);
            }

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
            gameMap.renderMap(mapa);
            al_draw_bitmap(map_sprite, 0, -32, 0);
            playerPacman.renderPacman(pacman_sprite, sprite); 

            ghostVet[0]->renderGhost(clyde_sprite, sprite);
            ghostVet[1]->renderGhost(pinky_sprite, sprite);
            ghostVet[2]->renderGhost(inky_sprite, sprite);
            ghostVet[3]->renderGhost(blinky_sprite, sprite);

            al_draw_textf(font, al_map_rgb(255, 255, 255), 32, 0, 0, "Score: %d", playerPacman.getScore());
            al_flip_display();
        }

        //CLOSING CONDITIONS
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            running = false;
        }
        // End the game when there's no more coins left
        if (playerPacman.getScore() == 151) {
            running = false;
        }
        if (playerPacman.checkGhostCollision(ghostBlinky, ghostPinky, ghostInky, ghostClyde)) {
            al_stop_sample(&mainSongID);
            al_play_sample(pacmanDiesAudio, 0.6, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
            al_rest(3);
            running = false;
        }
    }

    // Cleaning: if u create something, don't forget to destroy it
    // In cases like the walls and coins, where they are included objects, don't forget to destroy the bitmap in the classes' destructor
    al_uninstall_keyboard();
    al_destroy_sample(mainSongAudio);
    al_destroy_sample(pacmanEatAudio);
    al_destroy_sample(pacmanDiesAudio);
    al_uninstall_audio();
    al_destroy_bitmap(pacman_sprite);
    al_destroy_bitmap(blinky_sprite);
    al_destroy_bitmap(pinky_sprite);
    al_destroy_bitmap(inky_sprite);
    al_destroy_bitmap(clyde_sprite);
    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    return 0;
}
