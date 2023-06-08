#include "pacman.h"

Pacman::Pacman(int x, int y) : Entity() {
    moveSpeed = 2.0;
    entityX = x;
    entityY = y;
    entityHeight = 32;
    entityWidth = 32;
    entitySize = 32;
    score = 0;
}
void Pacman::checkCoinCollision(std::vector<std::vector<char>>& map) {
    if (map[getEntityConvertedY()][getEntityConvertedX()] == '1') {
        map[getEntityConvertedY()][getEntityConvertedX()] = '2';
        score++;
    }
}
int Pacman::getScore() {
    return score;
}
void Pacman::renderPacman(ALLEGRO_BITMAP* imgPacman, int sprite) {
    al_draw_bitmap_region(imgPacman, direction * entityWidth, sprite * entityHeight, entityWidth, entityHeight, getEntityX(), getEntityY(), 0);
}
Pacman::~Pacman() {

}