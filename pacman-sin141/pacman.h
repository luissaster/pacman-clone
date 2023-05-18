#ifndef PACMAN_H
#define PACMAN_H

#include <vector>
#include <math.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_audio.h>

#define PLAYER_SIZE 32 // Our pacman sprite is 32x32 pixels


class Pacman {
public:
    Pacman();
    Pacman(int x, int y);

    bool checkWallCollision(std::vector<std::vector<char>>& map);
    bool checkPacmanCollisionUp(std::vector<std::vector<char>>& map);
    bool checkPacmanCollisionDown(std::vector<std::vector<char>>& map);
    bool checkPacmanCollisionRight(std::vector<std::vector<char>>& map);
    bool checkPacmanCollisionLeft(std::vector<std::vector<char>>& map);

    int getScore();
    int getPacmanArrayPosX();
    int getPacmanArrayPosY();

    float getPacmanX();
    float getPacmanY();

    void calculatePacmanPosition();
    void checkCoinCollision(std::vector<std::vector<char>>& map);
    void checkTeleportCollisionLeft(std::vector<std::vector<char>>& map);
    void checkTeleportCollisionRight(std::vector<std::vector<char>>& map);
    void setPacmanX(float x);
    void setPacmanY(float y);
    void checkPacmanMovement(int instruction, std::vector<std::vector<char>>& map);
    void movePacman(std::vector<std::vector<char>>& map, ALLEGRO_SAMPLE* chomp);
    void renderPacman(ALLEGRO_BITMAP* imgPacman, int sprite);

    ~Pacman();

private:
    // Normal float values for the pacman, these have to be converted to int
    float moveSpeed;
    float playerX;
    float playerY;

    // This is part of the float -> intenger conversion algorithm
    int playerColY;
    int playerColX;

    int colYCollisionUp;
    int colXCollisionUp;
    int colYCollisionUpNext;
    int colXCollisionUpNext;

    int colYCollisionLeft;
    int colXCollisionLeft;
    int colYCollisionLeftNext;
    int colXCollisionLeftNext;

    int colYCollisionRight;
    int colXCollisionRight;
    int colYCollisionRightNext;
    int colXCollisionRightNext;

    int colYCollisionBottom;
    int colXCollisionBottom;
    int colYCollisionBottomNext;
    int colXCollisionBottomNext;

    // Related to the game's functionality
    int score;
    int pacmanHeight;
    int pacmanWidth;
    int direction;

    bool moveUp;
    bool moveDown;
    bool moveLeft;
    bool moveRight;
};

#endif // PACMAN_H
