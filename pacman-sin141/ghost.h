#ifndef GHOST_H
#define GHOST_H

#include "entity.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

class Ghost : public Entity {
public:
	Ghost();
	~Ghost();
	virtual void chasePacman(std::vector<std::vector<char>> mapa, float pacmanX, float pacmanY) = 0;
	virtual void randomDirection(std::vector<std::vector<char>> mapa);
	virtual void checkRandomDirection(std::vector<std::vector<char>> mapa);
	virtual void renderGhost(ALLEGRO_BITMAP* img, int sprite) = 0;
protected:
	int ghostType; // 1 - Blinky 2 - Inky 3 - Pinky 4 - Clyde
};

#endif // !GHOST_H
