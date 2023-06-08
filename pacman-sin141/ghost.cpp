#include "ghost.h"
Ghost::Ghost() {
    moveSpeed = 2.0;
    entityHeight = 32;
    entityWidth = 32;
    entitySize = 32;
}
Ghost::~Ghost() {}
void Ghost::newDirection(std::vector<std::vector<char>> mapa) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    randomDirection = std::rand() % 4; // 0 cima 1 direita 2 esquerda 3 baixo
    std::cout << "Numero sorteado: " << randomDirection << std::endl;
    switch (randomDirection) {
    case 0:
        checkEntityMovement(ALLEGRO_KEY_UP, mapa);
        break;
    case 1:
        checkEntityMovement(ALLEGRO_KEY_RIGHT, mapa);
        break;
    case 2:
        checkEntityMovement(ALLEGRO_KEY_LEFT, mapa);
        break;
    case 3:
        checkEntityMovement(ALLEGRO_KEY_DOWN, mapa);
        break;
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
    if (isWalking) {
        moveEntity(mapa);
    }
    else {
        newDirection(mapa);
    }
}