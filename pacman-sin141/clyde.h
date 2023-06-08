#ifndef CLYDE_H
#define CLYDE_H

#include "ghost.h"
class Clyde : public Ghost
{
public:
	Clyde(int x, int y);
	~Clyde();
	void renderClyde(ALLEGRO_BITMAP* imgClyde, int sprite);
};

#endif // !CLYDE_H
