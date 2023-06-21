#ifndef PINKY_H
#define PINKY_H

#include "ghost.h"
class Pinky : public Ghost
{
public:
	Pinky(int x, int y);
	~Pinky();
	virtual void renderGhost(ALLEGRO_BITMAP* img, int sprite);
	virtual void chasePacman(std::vector<std::vector<char>> mapa, float pacmanX, float pacmanY);

};

#endif // !PINKY_H
