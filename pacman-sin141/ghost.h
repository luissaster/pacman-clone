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
	void moveRandom(std::vector<std::vector<char>> mapa);
	void newDirection(std::vector<std::vector<char>> mapa);
protected:
	int randomDirection;
};

#endif // !GHOST_H
