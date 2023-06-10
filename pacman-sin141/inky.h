#ifndef INKY_H
#define INKY_H

#include "ghost.h"
class Inky : public Ghost {
public:
	Inky(int x, int y);
	~Inky();
	void renderInky(ALLEGRO_BITMAP* imgInky, int sprite);
};

#endif // !INKY_H

