#ifndef GHOST_H
#define GHOST_H

#include "entity.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

enum ghostState {
	WANDER,
	CHASE,
	SCATTER,
	DEAD,
	ANGRY
};

class Ghost : public Entity {
public:
	Ghost();
	~Ghost();
private:
};

#endif // !GHOST_H
