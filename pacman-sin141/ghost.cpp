#include "ghost.h"
Ghost::Ghost() {
    moveSpeed = 2.0;
    entityHeight = 32;
    entityWidth = 32;
    entitySize = 32;
    randomDirection = 0;
}
Ghost::~Ghost() {}
void Ghost::newDirection(std::vector<std::vector<char>> map) {
    bool canGoUp, canGoDown, canGoLeft, canGoRight;

    if (checkEntityCollisionUp(map)) {
        canGoUp = true;
    }
    else {
        canGoUp = false;
    }

    if (checkEntityCollisionDown(map)) {
        canGoDown = true;
    }
    else {
        canGoDown = false;
    }

    if (checkEntityCollisionLeft(map)) {
        canGoLeft = true;
    }
    else {
        canGoLeft = false;
    }

    if (checkEntityCollisionRight(map)) {
        canGoRight = true;
    }
    else {
        canGoRight = false;
    }

    if (canGoLeft && !canGoRight && !canGoUp && !canGoDown) {
        checkEntityMovement(ALLEGRO_KEY_LEFT, map);
    }

    if (!canGoLeft && canGoRight && !canGoUp && !canGoDown) {
        checkEntityMovement(ALLEGRO_KEY_RIGHT, map);
    }

    if (!canGoLeft && !canGoRight && canGoUp && !canGoDown) {
        checkEntityMovement(ALLEGRO_KEY_UP, map);
    }

    if (!canGoLeft && !canGoRight && !canGoUp && canGoDown) {
        checkEntityMovement(ALLEGRO_KEY_DOWN, map);
    }

    if (canGoUp && canGoLeft) {
        int randomDirection = std::rand() % 2;
        if (randomDirection == 0) {
            checkEntityMovement(ALLEGRO_KEY_UP, map);
        }
        else {
            checkEntityMovement(ALLEGRO_KEY_LEFT, map);
        }
    }

    if (canGoUp && canGoDown) {
        int randomDirection = std::rand() % 2;
        if (randomDirection == 0) {
            checkEntityMovement(ALLEGRO_KEY_UP, map);
        }
        else {
            checkEntityMovement(ALLEGRO_KEY_DOWN, map);
        }
    }

    if (canGoUp && canGoRight) {
        int randomDirection = std::rand() % 2;
        if (randomDirection == 0) {
            checkEntityMovement(ALLEGRO_KEY_UP, map);
        }
        else {
            checkEntityMovement(ALLEGRO_KEY_RIGHT, map);
        }
    }

    if (canGoDown && canGoLeft) {
        int randomDirection = std::rand() % 2;
        if (randomDirection == 0) {
            checkEntityMovement(ALLEGRO_KEY_DOWN, map);
        }
        else {
            checkEntityMovement(ALLEGRO_KEY_LEFT, map);
        }
    }

    if (canGoDown && canGoRight) {
        int randomDirection = std::rand() % 2;
        if (randomDirection == 0) {
            checkEntityMovement(ALLEGRO_KEY_DOWN, map);
        }
        else {
            checkEntityMovement(ALLEGRO_KEY_RIGHT, map);
        }
    }

    if (canGoLeft && canGoRight) {
        int randomDirection = std::rand() % 2;
        if (randomDirection == 0) {
            checkEntityMovement(ALLEGRO_KEY_LEFT, map);
        }
        else {
            checkEntityMovement(ALLEGRO_KEY_RIGHT, map);
        }
    }

    if (canGoUp && canGoLeft && canGoRight) {
        int randomDirection = std::rand() % 3;
        if (randomDirection == 0) {
            checkEntityMovement(ALLEGRO_KEY_UP, map);
        }
        else if (randomDirection == 1) {
            checkEntityMovement(ALLEGRO_KEY_LEFT, map);
        }
        else {
            checkEntityMovement(ALLEGRO_KEY_RIGHT, map);
        }
    }

    if (canGoUp && canGoLeft && canGoDown) {
        int randomDirection = std::rand() % 3;
        if (randomDirection == 0) {
            checkEntityMovement(ALLEGRO_KEY_UP, map);
        }
        else if (randomDirection == 1) {
            checkEntityMovement(ALLEGRO_KEY_LEFT, map);
        }
        else {
            checkEntityMovement(ALLEGRO_KEY_DOWN, map);
        }
    }

    if (canGoUp && canGoRight && canGoDown) {
        int randomDirection = std::rand() % 3;
        if (randomDirection == 0) {
            checkEntityMovement(ALLEGRO_KEY_UP, map);
        }
        else if (randomDirection == 1) {
            checkEntityMovement(ALLEGRO_KEY_RIGHT, map);
        }
        else {
            checkEntityMovement(ALLEGRO_KEY_DOWN, map);
        }
    }

    if (canGoDown && canGoLeft && canGoRight) {
        int randomDirection = std::rand() % 3;
        if (randomDirection == 0) {
            checkEntityMovement(ALLEGRO_KEY_DOWN, map);
        }
        else if (randomDirection == 1) {
            checkEntityMovement(ALLEGRO_KEY_LEFT, map);
        }
        else {
            checkEntityMovement(ALLEGRO_KEY_RIGHT, map);
        }
    }

    if (canGoDown && canGoUp && canGoLeft && canGoRight) {
        int randomDirection = std::rand() % 4;
        if (randomDirection == 0) {
            checkEntityMovement(ALLEGRO_KEY_DOWN, map);
        }
        else if (randomDirection == 1) {
            checkEntityMovement(ALLEGRO_KEY_UP, map);
        }
        else if (randomDirection == 2) {
            checkEntityMovement(ALLEGRO_KEY_LEFT, map);
        }
        else {
            checkEntityMovement(ALLEGRO_KEY_RIGHT, map);
        }
    }
}

void Ghost::moveRandom(std::vector<std::vector<char>> mapa) {
    // se nao encontrar parede nem cruzamento = continua andando
    // se bater numa parede na direção que estava indo, sorteia uma direção nova diferente da atual
    // se encontrar encruzilhada, verifica possiveis movimentos
    bool isWalking;
    if (moveUp || moveDown || moveLeft || moveRight) {
        isWalking = true;
    }
    else {
        isWalking = false;
    }
    if (isWalking && checkEntityCollisionUp(mapa) && checkEntityCollisionDown(mapa) && checkEntityCollisionLeft(mapa) && checkEntityCollisionRight(mapa)) {
        newDirection(mapa);
    }
    if (isWalking && checkEntityCollisionUp(mapa) && checkEntityCollisionDown(mapa) && checkEntityCollisionLeft(mapa)) {
        newDirection(mapa);
    }
    if (isWalking && checkEntityCollisionUp(mapa) && checkEntityCollisionDown(mapa) && checkEntityCollisionRight(mapa)) {
        newDirection(mapa);
    }
    if (isWalking && checkEntityCollisionUp(mapa) && checkEntityCollisionRight(mapa) && checkEntityCollisionLeft(mapa)) {
        newDirection(mapa);
    }
    if (isWalking && checkEntityCollisionDown(mapa) && checkEntityCollisionLeft(mapa) && checkEntityCollisionRight(mapa)) {
        newDirection(mapa);
    }
    if (isWalking && checkEntityCollisionDown(mapa) && checkEntityCollisionLeft(mapa) && checkEntityCollisionUp(mapa)) {
        newDirection(mapa);
    }
    if (isWalking && checkEntityCollisionDown(mapa) && checkEntityCollisionRight(mapa) && checkEntityCollisionUp(mapa)) {
        newDirection(mapa);
    }
    if (isWalking && checkEntityCollisionUp(mapa) && checkEntityCollisionLeft(mapa)) {
        newDirection(mapa);
    }
    if (isWalking && checkEntityCollisionUp(mapa) && checkEntityCollisionRight(mapa)) {
        newDirection(mapa);
    }
    if (isWalking && checkEntityCollisionDown(mapa) && checkEntityCollisionLeft(mapa)) {
        newDirection(mapa);
    }
    if (isWalking && checkEntityCollisionDown(mapa) && checkEntityCollisionRight(mapa)) {
        newDirection(mapa);
    }
    if (isWalking) {
        moveEntity(mapa);
    }
    else {
        newDirection(mapa);
    }
}