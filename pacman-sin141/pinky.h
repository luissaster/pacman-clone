#ifndef PINKY_H
#define PINKY_H

#include "ghost.h"
class Pinky : public Ghost
{
public:
	Pinky(int x, int y);
	~Pinky();
	void renderPinky(ALLEGRO_BITMAP* imgPinky, int sprite);
};

#endif // !PINKY_H
