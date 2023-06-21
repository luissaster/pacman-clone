#ifndef ENTITY_H
#define ENTITY_H
#include <vector>
#include <math.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_audio.h>

class Entity
{
public:
    Entity();
    ~Entity();
    bool checkWallCollision(std::vector<std::vector<char>>& map);
    bool checkEntityCollisionUp(std::vector<std::vector<char>>& map);
    bool checkEntityCollisionDown(std::vector<std::vector<char>>& map);
    bool checkEntityCollisionRight(std::vector<std::vector<char>>& map);
    bool checkEntityCollisionLeft(std::vector<std::vector<char>>& map);
    float getEntityX();
    float getEntityY();
    int getEntityConvertedX();
    int getEntityConvertedY();
    int getNextMove();
    void setNextMove(int);
    void calculateEntityPosition();
    void setEntityXPosition(float x);
    void setEntityYPosition(float y);
    void checkEntityMovement(int instruction, std::vector<std::vector<char>>& map);
    void moveEntity(std::vector<std::vector<char>>& map);
    void checkTeleportCollision(std::vector<std::vector<char>>& map);
protected:
    float moveSpeed, entityX, entityY;
    bool moveUp, moveDown, moveLeft, moveRight;
    int nextMove;
    int entityConvertedY, entityConvertedX, direction, entityHeight, entityWidth, entitySize;
    int colYCollisionUp, colXCollisionUp, colYCollisionUpNext, colXCollisionUpNext;
    int colYCollisionLeft, colXCollisionLeft, colYCollisionLeftNext, colXCollisionLeftNext;
    int colYCollisionRight, colXCollisionRight, colYCollisionRightNext, colXCollisionRightNext;
    int colYCollisionBottom, colXCollisionBottom, colYCollisionBottomNext, colXCollisionBottomNext;

};

#endif // !ENTITY_H
