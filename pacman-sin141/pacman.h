#ifndef PACMAN_H
#define PACMAN_H

#include "entity.h"
#include <vector>
#include <math.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_audio.h>

class Pacman : public Entity{
public:
    Pacman(int x, int y);
    ~Pacman();
    int getScore();
    void checkCoinCollision(std::vector<std::vector<char>>& map);
    void checkTeleportCollisionLeft(std::vector<std::vector<char>>& map);
    void checkTeleportCollisionRight(std::vector<std::vector<char>>& map);
    void renderPacman(ALLEGRO_BITMAP* imgPacman, int sprite);
private:
    int score;
};

#endif // PACMAN_H
