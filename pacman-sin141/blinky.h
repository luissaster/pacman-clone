#ifndef BLINKY_H
#define BLINKY_H

#include "ghost.h"
class Blinky : public Ghost{
public:
	Blinky(int x, int y);
	~Blinky();
	void renderBlinky(ALLEGRO_BITMAP* imgBlinky, int sprite);
};

#endif // !BLINKY_H
