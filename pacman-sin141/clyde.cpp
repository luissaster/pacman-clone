#include "clyde.h"
Clyde::Clyde(int x, int y) : Ghost() {
	entityX = x;
	entityY = y;
	this->ghostType = 4;
}
Clyde::~Clyde() {}
void Clyde::renderGhost(ALLEGRO_BITMAP* imgClyde, int sprite) {
	al_draw_bitmap_region(imgClyde, direction * entityWidth, sprite * entityHeight, entityWidth, entityHeight, getEntityX(), getEntityY(), 0);
}

void Clyde::chasePacman(std::vector<std::vector<char>> mapa, float pacmanX, float pacmanY)
{
}
