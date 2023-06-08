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
bool Pacman::checkGhostCollision(Blinky& f1, Pinky& f2, Inky& f3, Clyde& f4) {
    if (this->entityConvertedX == f1.getEntityConvertedX() && this->entityConvertedY == f1.getEntityConvertedY()) {
        return true;
    }
    if (this->entityConvertedX == f2.getEntityConvertedX() && this->entityConvertedY == f2.getEntityConvertedY()) {
        return true;
    }
    if (this->entityConvertedX == f3.getEntityConvertedX() && this->entityConvertedY == f3.getEntityConvertedY()) {
        return true;
    }
    if (this->entityConvertedX == f4.getEntityConvertedX() && this->entityConvertedY == f4.getEntityConvertedY()) {
        return true;
    }
    return false;
}
Pacman::~Pacman() {

}