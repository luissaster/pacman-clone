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
void Pacman::checkTeleportCollisionLeft(std::vector<std::vector<char>>& map) {
    if (getEntityConvertedY() == 9 && getEntityConvertedX() == 0 && moveLeft == true) {
        this->setEntityXPosition(576);
        this->setEntityYPosition(288);
        moveLeft = true;
        moveRight = false;
        moveUp = false;
        moveDown = false;
    }
}
void Pacman::checkTeleportCollisionRight(std::vector<std::vector<char>>& map) {
    if (getEntityConvertedY() == 9 && getEntityConvertedX() == 17 && moveRight == true) {
        this->setEntityXPosition(0);
        this->setEntityYPosition(288);
        moveLeft = false;
        moveRight = true;
        moveUp = false;
        moveDown = false;
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