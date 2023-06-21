#ifndef INKY_H
#define INKY_H

#include "ghost.h"
class Inky : public Ghost {
public:
	Inky(int x, int y);
	~Inky();
	virtual void renderGhost(ALLEGRO_BITMAP* img, int sprite);
	virtual void chasePacman(std::vector<std::vector<char>> mapa, float pacmanX, float pacmanY);
};

#endif // !INKY_H

