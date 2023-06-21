#ifndef BLINKY_H
#define BLINKY_H

#include "ghost.h"
class Blinky : public Ghost{
public:
	Blinky(int x, int y);
	~Blinky();
	virtual void renderGhost(ALLEGRO_BITMAP* img, int sprite);
	virtual void chasePacman(std::vector<std::vector<char>> mapa, float pacmanX, float pacmanY);
private:
	float auxX, auxY;
};

#endif // !BLINKY_H
