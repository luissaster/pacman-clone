#ifndef GHOST_H
#define GHOST_H

#include "entity.h"
#include "pacman.h"
#include <cstdlib>
#include <ctime>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

class Ghost : public Entity {
public:
	Ghost();
	~Ghost();
protected:
};

#endif // !GHOST_H
