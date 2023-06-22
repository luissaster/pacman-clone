#include "ghost.h"
Ghost::Ghost() {
    moveSpeed = 2.0;
    entityHeight = 32;
    entityWidth = 32;
    entitySize = 32;
    ghostType = 0;
}
Ghost::~Ghost() {}
void Ghost::randomDirection(std::vector<std::vector<char>> map) {
    int flag = 0;
    int possibilities = 0;
    int directions[4];
    // Initialize directions array with zeros
    for (int i = 0; i < 4; i++) {
        directions[i] = 0;
    }
    if (this->getEntityConvertedX() == 8 && this->getEntityConvertedY() == 9) {
        this->setNextMove(ALLEGRO_KEY_RIGHT, map);
        return;
    }
    else if (this->getEntityConvertedX() == 9 && this->getEntityConvertedY() == 9) {
        this->setNextMove(ALLEGRO_KEY_UP, map);
        return;
    }
    else if (this->getEntityConvertedX() == 10 && this->getEntityConvertedY() == 9) {
        this->setNextMove(ALLEGRO_KEY_LEFT, map);
        return;
    }
    else if (this->getEntityConvertedX() == 9 && this->getEntityConvertedY() == 8) {
        this->setNextMove(ALLEGRO_KEY_UP, map);
        return;
    }
    if (moveLeft == true) {
        // Check for collision with entities on the left
        if (checkEntityCollisionLeft(map) == true) {
            directions[possibilities] = ALLEGRO_KEY_LEFT;
            possibilities++;
        }
        // Check for collision with entities above
        if (checkEntityCollisionUp(map) == true) {
            directions[possibilities] = ALLEGRO_KEY_UP;
            possibilities++;
        }
        // Check for collision with entities below
        if (checkEntityCollisionDown(map) == true) {
            directions[possibilities] = ALLEGRO_KEY_DOWN;
            possibilities++;
        }

        srand(time(NULL));

        // If there are possible directions to move
        if (possibilities > 0) {
            flag = rand() % possibilities;

            this->nextMove = directions[flag];
        }
    }
    else if (moveRight == true) {
        // Check for collision with entities on the right
        if (checkEntityCollisionRight(map) == true) {
            directions[possibilities] = ALLEGRO_KEY_RIGHT;
            possibilities++;
        }
        // Check for collision with entities above
        if (checkEntityCollisionUp(map) == true) {
            directions[possibilities] = ALLEGRO_KEY_UP;
            possibilities++;
        }
        // Check for collision with entities below
        if (checkEntityCollisionDown(map) == true) {
            directions[possibilities] = ALLEGRO_KEY_DOWN;
            possibilities++;
        }

        srand(time(NULL));

        // If there are possible directions to move
        if (possibilities > 0) {
            flag = rand() % possibilities;

            this->nextMove = directions[flag];
        }
    }
    else if (moveUp == true) {
        // Check for collision with entities on the left
        if (checkEntityCollisionLeft(map) == true) {
            directions[possibilities] = ALLEGRO_KEY_LEFT;
            possibilities++;
        }
        // Check for collision with entities on the right
        if (checkEntityCollisionRight(map) == true) {
            directions[possibilities] = ALLEGRO_KEY_RIGHT;
            possibilities++;
        }
        // Check for collision with entities above
        if (checkEntityCollisionUp(map) == true) {
            directions[possibilities] = ALLEGRO_KEY_UP;
            possibilities++;
        }

        srand(time(NULL));

        // If there are possible directions to move
        if (possibilities > 0) {
            flag = rand() % possibilities;

            this->nextMove = directions[flag];
        }
    }
    else if (moveDown == true) {
        // Check for collision with entities on the left
        if (checkEntityCollisionLeft(map) == true) {
            directions[possibilities] = ALLEGRO_KEY_LEFT;
            possibilities++;
        }
        // Check for collision with entities on the right
        if (checkEntityCollisionRight(map) == true) {
            directions[possibilities] = ALLEGRO_KEY_RIGHT;
            possibilities++;
        }
        // Check for collision with entities below
        if (checkEntityCollisionDown(map) == true) {
            directions[possibilities] = ALLEGRO_KEY_DOWN;
            possibilities++;
        }

        srand(time(NULL));

        // If there are possible directions to move
        if (possibilities > 0) {
            flag = rand() % possibilities;

            this->nextMove = directions[flag];
        }
    }
    else {
        // Check for collision with entities on the left
        if (checkEntityCollisionLeft(map) == true) {
            directions[possibilities] = ALLEGRO_KEY_LEFT;
            possibilities++;
        }
        // Check for collision with entities on the right
        if (checkEntityCollisionRight(map) == true) {
            directions[possibilities] = ALLEGRO_KEY_RIGHT;
            possibilities++;
        }
        // Check for collision with entities above
        if (checkEntityCollisionUp(map) == true) {
            directions[possibilities] = ALLEGRO_KEY_UP;
            possibilities++;
        }
        // Check for collision with entities below
        if (checkEntityCollisionDown(map) == true) {
            directions[possibilities] = ALLEGRO_KEY_DOWN;
            possibilities++;
        }

        srand(time(NULL));

        // If there are possible directions to move
        if (possibilities > 0) {
            flag = rand() % possibilities;

            this->nextMove = directions[flag];
        }
    }

    checkRandomDirection(map);
}

void Ghost::checkRandomDirection(std::vector<std::vector<char>> mapa)
{
    //moveUp
    if (this->nextMove == ALLEGRO_KEY_UP && checkEntityCollisionUp(mapa) == true && moveDown != true && moveUp != true)
    {
        moveUp = true;
        moveDown = false;
        moveLeft = false;
        moveRight = false;
        direction = 3;
    }
    //moveDown
    if (this->nextMove == ALLEGRO_KEY_DOWN && checkEntityCollisionDown(mapa) == true && moveUp != true && moveDown != true)
    {
        moveDown = true;
        moveUp = false;
        moveLeft = false;
        moveRight = false;
        direction = 1;
    }
    //moveLeft
    if (this->nextMove == ALLEGRO_KEY_LEFT && checkEntityCollisionLeft(mapa) == true && moveRight != true && moveLeft != true)
    {
        moveLeft = true;
        moveUp = false;
        moveDown = false;
        moveRight = false;
        direction = 2;
    }
    //moveRight
    if (this->nextMove == ALLEGRO_KEY_RIGHT && checkEntityCollisionRight(mapa) == true && moveLeft != true && moveRight != true)
    {
        moveRight = true;
        moveUp = false;
        moveDown = false;
        moveLeft = false;
        direction = 0;
    }
}

