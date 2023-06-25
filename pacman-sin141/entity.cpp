#include "entity.h"
// Constructor & Destructor
Entity::Entity() {
    moveSpeed = entityX = entityY = 0;
    entityConvertedY = entityConvertedX = 0;
    entityHeight = entityWidth = entitySize = direction = nextMove = 0;
    moveUp = moveRight = moveDown = moveLeft = false;
    colYCollisionUp = colXCollisionUp = colYCollisionUpNext = colXCollisionUpNext = 0;
    colYCollisionLeft = colXCollisionLeft = colYCollisionLeftNext = colXCollisionLeftNext = 0;
    colYCollisionRight = colXCollisionRight = colYCollisionRightNext = colXCollisionRightNext = 0;
    colYCollisionBottom = colXCollisionBottom = colYCollisionBottomNext = colXCollisionBottomNext = 0;
}
Entity::~Entity() {
    // Destructor
}

// "Get" functions
int Entity::getEntityConvertedX() {
    return this->entityConvertedX;
}
int Entity::getEntityConvertedY() {
    return this->entityConvertedY;
}
int Entity::getCurrentMove()
{
    return direction;
    // 0 - RIGHT, 1 - DOWN, 2 - LEFT, 3 - UP
}
int Entity::getNextMove()
{
    return this->nextMove;
}
float Entity::getEntityX() {
    return this->entityX;
}
float Entity::getEntityY() {
    return this->entityY;
}

// "Set" functions
void Entity::setNextMove(int a, std::vector<std::vector<char>>& map)
{
    checkEntityMovement(a, map);
    this->nextMove = a;
}
void Entity::setEntityXPosition(float x) {
    entityX = x;
}
void Entity::setEntityYPosition(float y) {
    entityY = y;
}

// Movement related functions
void Entity::checkEntityMovement(int instruction, std::vector<std::vector<char>>& map) {
    if (instruction == ALLEGRO_KEY_UP && checkEntityCollisionUp(map)) {
        moveUp = true;
        moveDown = false;
        moveLeft = false;
        moveRight = false;
        direction = 3;
    }
    if (instruction == ALLEGRO_KEY_DOWN && checkEntityCollisionDown(map)) {
        moveDown = true;
        moveUp = false;
        moveLeft = false;
        moveRight = false;
        direction = 1;
    }
    if (instruction == ALLEGRO_KEY_LEFT && checkEntityCollisionLeft(map)) {
        moveLeft = true;
        moveUp = false;
        moveDown = false;
        moveRight = false;
        direction = 2;
    }
    if (instruction == ALLEGRO_KEY_RIGHT && checkEntityCollisionRight(map)) {
        moveRight = true;
        moveUp = false;
        moveDown = false;
        moveLeft = false;
        direction = 0;
    }
}
void Entity::moveEntity(std::vector<std::vector<char>>& map) {
    if (moveUp && checkEntityCollisionUp(map)) {
        setEntityYPosition(getEntityY() - moveSpeed);
    }
    else {
        moveUp = false;
    }
    if (moveDown && checkEntityCollisionDown(map)) {
        setEntityYPosition(getEntityY() + moveSpeed);
    }
    else {
        moveDown = false;
    }
    if (moveLeft && checkEntityCollisionLeft(map)) {
        setEntityXPosition(getEntityX() - moveSpeed);
    }
    else {
        moveLeft = false;
    }
    if (moveRight && checkEntityCollisionRight(map)) {
        setEntityXPosition(getEntityX() + moveSpeed);
    }
    else {
        moveRight = false;
    }
}

// Collision functions, returns "true" if there's no obstacle towards the intended direction
bool Entity::checkWallCollision(std::vector<std::vector<char>>& map) {
    return map[entityConvertedY][entityConvertedX] != '0';
}
bool Entity::checkEntityCollisionUp(std::vector<std::vector<char>>& map) {
    return map[colYCollisionUp - 1][colXCollisionUp] != '0' && map[colYCollisionUpNext - 1][colXCollisionUpNext] != '0';
}
bool Entity::checkEntityCollisionDown(std::vector<std::vector<char>>& map) {
    return map[colYCollisionBottom + 1][colXCollisionBottom] != '0' && map[colYCollisionBottomNext + 1][colXCollisionBottomNext] != '0';
}
bool Entity::checkEntityCollisionRight(std::vector<std::vector<char>>& map) {
    return map[colYCollisionRight][colXCollisionRight + 1] != '0' && map[colYCollisionRightNext][colXCollisionRightNext + 1] != '0';
}
bool Entity::checkEntityCollisionLeft(std::vector<std::vector<char>>& map) {
    return map[colYCollisionLeft][colXCollisionLeft - 1] != '0' && map[colYCollisionLeftNext][colXCollisionLeftNext - 1] != '0';
}

// Float position to intenger map array position converter
void Entity::calculateEntityPosition() {
    entityConvertedY = entityY / entitySize;
    entityConvertedX = entityX / entitySize;

    colYCollisionUp = ceil(entityY / entitySize);
    colXCollisionUp = entityX / entitySize;
    colYCollisionUpNext = ceil(entityY / entitySize);
    colXCollisionUpNext = ceil(entityX / entitySize);

    colYCollisionLeft = ceil(entityY / entitySize);
    colXCollisionLeft = ceil(entityX / entitySize);
    colYCollisionLeftNext = entityY / entitySize;
    colXCollisionLeftNext = ceil(entityX / entitySize);

    colYCollisionRight = ceil(entityY / entitySize);
    colXCollisionRight = entityX / entitySize;
    colYCollisionRightNext = entityY / entitySize;
    colXCollisionRightNext = entityX / entitySize;

    colYCollisionBottom = entityY / entitySize;
    colXCollisionBottom = ceil(entityX / entitySize);
    colYCollisionBottomNext = entityY / entitySize;
    colXCollisionBottomNext = entityX / entitySize;
}

// Misc. functions
void Entity::checkTeleportCollision(std::vector<std::vector<char>>& map) {
    if (getEntityConvertedY() == 9 && getEntityConvertedX() == 0 && moveLeft) {
        this->setEntityXPosition(544);
        this->setEntityYPosition(288);
    }
    else if (getEntityConvertedY() == 9 && getEntityConvertedX() == 17 && moveRight) {
        this->setEntityXPosition(32);
        this->setEntityYPosition(288);
    }
}
