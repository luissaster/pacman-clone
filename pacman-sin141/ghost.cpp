#include "ghost.h"
Ghost::Ghost() {
    moveSpeed = 2.0;
    entityHeight = 32;
    entityWidth = 32;
    entitySize = 32;
    randomDirection = 0;
}
Ghost::~Ghost() {}
void Ghost::newDirection(std::vector<std::vector<char>> mapa) {
    bool podeCima, podeBaixo, podeEsquerda, podeDireita;
    if (checkEntityCollisionUp(mapa)) {
        podeCima = true;
    }
    else {
        podeCima = false;
    }
    if (checkEntityCollisionDown(mapa)) {
        podeBaixo = true;
    }
    else {
        podeBaixo = false;
    }
    if (checkEntityCollisionLeft(mapa)) {
        podeEsquerda = true;
    }
    else {
        podeEsquerda = false;
    }
    if (checkEntityCollisionRight(mapa)) {
        podeDireita = true;
    }
    else {
        podeDireita = false;
    }
    if (podeEsquerda && !podeDireita && !podeCima && !podeBaixo) {
        checkEntityMovement(ALLEGRO_KEY_LEFT, mapa);
    }
    if (!podeEsquerda && podeDireita && !podeCima && !podeBaixo) {
        checkEntityMovement(ALLEGRO_KEY_RIGHT, mapa);
    }
    if (!podeEsquerda && !podeDireita && podeCima && !podeBaixo) {
        checkEntityMovement(ALLEGRO_KEY_UP, mapa);
    }
    if (!podeEsquerda && !podeDireita && !podeCima && podeBaixo) {
        checkEntityMovement(ALLEGRO_KEY_DOWN, mapa);
    }
    if (podeCima && podeEsquerda) {
        randomDirection = std::rand() % 2;
        if (randomDirection == 0) {
            checkEntityMovement(ALLEGRO_KEY_UP, mapa);
        }
        else {
            checkEntityMovement(ALLEGRO_KEY_LEFT, mapa);
        }
    }
    if (podeCima && podeBaixo) {
        randomDirection = std::rand() % 2;
        if (randomDirection == 0) {
            checkEntityMovement(ALLEGRO_KEY_UP, mapa);
        }
        else {
            checkEntityMovement(ALLEGRO_KEY_DOWN, mapa);
        }
    }
    if (podeCima && podeDireita) {
        randomDirection = std::rand() % 2;
        if (randomDirection == 0) {
            checkEntityMovement(ALLEGRO_KEY_UP, mapa);
        }
        else {
            checkEntityMovement(ALLEGRO_KEY_RIGHT, mapa);
        }
    }
    if (podeBaixo && podeEsquerda) {
        randomDirection = std::rand() % 2;
        if (randomDirection == 0) {
            checkEntityMovement(ALLEGRO_KEY_DOWN, mapa);
        }
        else {
            checkEntityMovement(ALLEGRO_KEY_LEFT, mapa);
        }
    }
    if (podeBaixo && podeDireita) {
        randomDirection = std::rand() % 2;
        if (randomDirection == 0) {
            checkEntityMovement(ALLEGRO_KEY_DOWN, mapa);
        }
        else {
            checkEntityMovement(ALLEGRO_KEY_RIGHT, mapa);
        }
    }
    if (podeEsquerda && podeDireita) {
        randomDirection = std::rand() % 2;
        if (randomDirection == 0) {
            checkEntityMovement(ALLEGRO_KEY_LEFT, mapa);
        }
        else {
            checkEntityMovement(ALLEGRO_KEY_RIGHT, mapa);
        }
    }
    if (podeCima && podeEsquerda && podeDireita) {
        randomDirection = std::rand() % 3;
        if (randomDirection == 0) {
            checkEntityMovement(ALLEGRO_KEY_UP, mapa);
        }
        else if (randomDirection == 1) {
            checkEntityMovement(ALLEGRO_KEY_LEFT, mapa);
        }
        else {
            checkEntityMovement(ALLEGRO_KEY_RIGHT, mapa);
        }
    }
    if (podeCima && podeEsquerda && podeBaixo) {
        randomDirection = std::rand() % 3;
        if (randomDirection == 0) {
            checkEntityMovement(ALLEGRO_KEY_UP, mapa);
        }
        else if (randomDirection == 1) {
            checkEntityMovement(ALLEGRO_KEY_LEFT, mapa);
        }
        else {
            checkEntityMovement(ALLEGRO_KEY_DOWN, mapa);
        }
    }
    if (podeCima && podeDireita && podeBaixo) {
        randomDirection = std::rand() % 3;
        if (randomDirection == 0) {
            checkEntityMovement(ALLEGRO_KEY_UP, mapa);
        }
        else if (randomDirection == 1) {
            checkEntityMovement(ALLEGRO_KEY_RIGHT, mapa);
        }
        else {
            checkEntityMovement(ALLEGRO_KEY_DOWN, mapa);
        }
    }
    if (podeBaixo && podeEsquerda && podeDireita) {
        randomDirection = std::rand() % 3;
        if (randomDirection == 0) {
            checkEntityMovement(ALLEGRO_KEY_DOWN, mapa);
        }
        else if (randomDirection == 1) {
            checkEntityMovement(ALLEGRO_KEY_LEFT, mapa);
        }
        else {
            checkEntityMovement(ALLEGRO_KEY_RIGHT, mapa);
        }
    }
    if (podeBaixo && podeCima && podeEsquerda && podeDireita) {
        randomDirection = std::rand() % 4;
        if (randomDirection == 0) {
            checkEntityMovement(ALLEGRO_KEY_DOWN, mapa);
        }
        else if (randomDirection == 1) {
            checkEntityMovement(ALLEGRO_KEY_UP, mapa);
        }
        else if (randomDirection == 2) {
            checkEntityMovement(ALLEGRO_KEY_LEFT, mapa);
        }
        else {
            checkEntityMovement(ALLEGRO_KEY_RIGHT, mapa);
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