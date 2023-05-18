#include "pacman.h"

Pacman::Pacman() {
    moveSpeed = 2.0;

    // Position of the player in pixels
    // This is never used, as when we create the player in main.cpp we give it a position
    playerX = 32;
    playerY = 32;

    // Player position in the array
    playerColY = 0;
    playerColX = 0;

    // Collision Up
    colYCollisionUp = 0;
    colXCollisionUp = 0;
    colYCollisionUpNext = 0;
    colXCollisionUpNext = 0;

    // Collision Left
    colYCollisionLeft = 0;
    colXCollisionLeft = 0;
    colYCollisionLeftNext = 0;
    colXCollisionLeftNext = 0;

    // Collision Right
    colYCollisionRight = 0;
    colXCollisionRight = 0;
    colYCollisionRightNext = 0;
    colXCollisionRightNext = 0;

    // Collision Bottom
    colYCollisionBottom = 0;
    colXCollisionBottom = 0;
    colYCollisionBottomNext = 0;
    colXCollisionBottomNext = 0;

    score = 0;

    // Sprite Height and Width
    pacmanHeight = 32;
    pacmanWidth = 32;

    // Direction variables
    moveUp = false;
    moveRight = false;
    moveDown = false;
    moveLeft = false;
    direction = 0;
}

Pacman::Pacman(int x, int y) : Pacman() {
    // Position of the player in pixels
    playerX = x;
    playerY = y;
}
// This is the conversion algorithm, we use it to convert pacman's float positions into intengers that can be used in the map array
// Without this, collisions would have been messy, as sometimes it would round the value the wrong way
void Pacman::calculatePacmanPosition() {
    // Player position
    playerColY = playerY / PLAYER_SIZE;
    playerColX = playerX / PLAYER_SIZE;

    // Collision Up
    colYCollisionUp = ceil(playerY / PLAYER_SIZE);
    colXCollisionUp = playerX / PLAYER_SIZE;
    colYCollisionUpNext = ceil(playerY / PLAYER_SIZE);
    colXCollisionUpNext = ceil(playerX / PLAYER_SIZE);

    // Collision Left
    colYCollisionLeft = ceil(playerY / PLAYER_SIZE);
    colXCollisionLeft = ceil(playerX / PLAYER_SIZE);
    colYCollisionLeftNext = playerY / PLAYER_SIZE;
    colXCollisionLeftNext = ceil(playerX / PLAYER_SIZE);

    // Collision Right
    colYCollisionRight = ceil(playerY / PLAYER_SIZE);
    colXCollisionRight = playerX / PLAYER_SIZE;
    colYCollisionRightNext = playerY / PLAYER_SIZE;
    colXCollisionRightNext = playerX / PLAYER_SIZE;

    // Collision Bottom
    colYCollisionBottom = playerY / PLAYER_SIZE;
    colXCollisionBottom = ceil(playerX / PLAYER_SIZE);
    colYCollisionBottomNext = playerY / PLAYER_SIZE;
    colXCollisionBottomNext = playerX / PLAYER_SIZE;
}

bool Pacman::checkWallCollision(std::vector<std::vector<char>>& map) {
    return map[playerColY][playerColX] != 0;
}

void Pacman::checkCoinCollision(std::vector<std::vector<char>>& map) {
    if (map[getPacmanArrayPosY()][getPacmanArrayPosX()] == '1') {
        map[getPacmanArrayPosY()][getPacmanArrayPosX()] = '2';
        score++;
    }
}

void Pacman::checkTeleportCollisionLeft(std::vector<std::vector<char>>& map) {
    if (getPacmanArrayPosY() == 9 && getPacmanArrayPosX() == 0 && moveLeft == true) {
        this->setPacmanX(576);
        this->setPacmanY(288);
        moveLeft = true;
        moveRight = false;
        moveUp = false;
        moveDown = false;
    }
}
void Pacman::checkTeleportCollisionRight(std::vector<std::vector<char>>& map) {
    if (getPacmanArrayPosY() == 9 && getPacmanArrayPosX() == 17 && moveRight == true) {
        this->setPacmanX(0);
        this->setPacmanY(288);
        moveLeft = false;
        moveRight = true;
        moveUp = false;
        moveDown = false;
    }
}

int Pacman::getScore() {
    return score;
}

bool Pacman::checkPacmanCollisionUp(std::vector<std::vector<char>>& map) {
    return map[colYCollisionUp - 1][colXCollisionUp] != '0' && map[colYCollisionUpNext - 1][colXCollisionUpNext] != '0';
}

bool Pacman::checkPacmanCollisionDown(std::vector<std::vector<char>>& map) {
    return map[colYCollisionBottom + 1][colXCollisionBottom] != '0' && map[colYCollisionBottomNext + 1][colXCollisionBottomNext] != '0';
}

bool Pacman::checkPacmanCollisionRight(std::vector<std::vector<char>>& map) {
    return map[colYCollisionRight][colXCollisionRight + 1] != '0' && map[colYCollisionRightNext][colXCollisionRightNext + 1] != '0';
}

bool Pacman::checkPacmanCollisionLeft(std::vector<std::vector<char>>& map) {
    return map[colYCollisionLeft][colXCollisionLeft - 1] != '0' && map[colYCollisionLeftNext][colXCollisionLeftNext - 1] != '0';
}

int Pacman::getPacmanArrayPosX() {
    return playerColX;
}

int Pacman::getPacmanArrayPosY() {
    return playerColY;
}

float Pacman::getPacmanX() {
    return playerX;
}

float Pacman::getPacmanY() {
    return playerY;
}

void Pacman::setPacmanX(float x) {
    playerX = x;
}

void Pacman::setPacmanY(float y) {
    playerY = y;
}

void Pacman::checkPacmanMovement(int instruction, std::vector<std::vector<char>>& map) {
    // Check if the command can be executed and set the variables accordingly

    // Move Up
    if (instruction == ALLEGRO_KEY_UP && checkPacmanCollisionUp(map)) {
        moveUp = true;
        moveDown = false;
        moveLeft = false;
        moveRight = false;
        direction = 3;
    }

    // Move Down
    if (instruction == ALLEGRO_KEY_DOWN && checkPacmanCollisionDown(map)) {
        moveDown = true;
        moveUp = false;
        moveLeft = false;
        moveRight = false;
        direction = 1;
    }

    // Move Left
    if (instruction == ALLEGRO_KEY_LEFT && checkPacmanCollisionLeft(map)) {
        moveLeft = true;
        moveUp = false;
        moveDown = false;
        moveRight = false;
        direction = 2;
    }

    // Move Right
    if (instruction == ALLEGRO_KEY_RIGHT && checkPacmanCollisionRight(map)) {
        moveRight = true;
        moveUp = false;
        moveDown = false;
        moveLeft = false;
        direction = 0;
    }
}

void Pacman::movePacman(std::vector<std::vector<char>>& map, ALLEGRO_SAMPLE* chomp) {
    // Execute the movement
    al_play_sample(chomp, 0.03, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
    if (moveUp && checkPacmanCollisionUp(map)) {
        setPacmanY(getPacmanY() - moveSpeed); // Move up
    }

    if (moveDown && checkPacmanCollisionDown(map)) {
        setPacmanY(getPacmanY() + moveSpeed); // Move down
    }

    if (moveLeft && checkPacmanCollisionLeft(map)) {
        setPacmanX(getPacmanX() - moveSpeed); // Move left
    }

    if (moveRight && checkPacmanCollisionRight(map)) {
        setPacmanX(getPacmanX() + moveSpeed); // Move right
    }

    calculatePacmanPosition();
}

void Pacman::renderPacman(ALLEGRO_BITMAP* imgPacman, int sprite) {
    al_draw_bitmap_region(imgPacman, direction * pacmanWidth, sprite * pacmanHeight, pacmanWidth, pacmanHeight, getPacmanX(), getPacmanY(), 0);
}

Pacman::~Pacman() {

}