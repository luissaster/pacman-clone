#ifndef CLYDE_H
#define CLYDE_H

#include "ghost.h"
class Clyde : public Ghost
{
public:
	Clyde(int x, int y);
	~Clyde();
	virtual void renderGhost(ALLEGRO_BITMAP* img, int sprite);
	virtual void chasePacman(std::vector<std::vector<char>> mapa, float pacmanX, float pacmanY);
};

#endif // !CLYDE_H
