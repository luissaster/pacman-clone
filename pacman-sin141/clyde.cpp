#include "clyde.h"
Clyde::Clyde(int x, int y) : Ghost() {
	entityX = x;
	entityY = y;
	ghostType = 4;
}
Clyde::~Clyde() {}
void Clyde::chasePacman(std::vector<std::vector<char>> map, int pacX, int pacY)
{
	// TODO: implement Clyde's unique chase method
}
void Clyde::renderGhost(ALLEGRO_BITMAP* imgClyde, int sprite) {
	al_draw_bitmap_region(imgClyde, direction * entityWidth, sprite * entityHeight, entityWidth, entityHeight, getEntityX(), getEntityY(), 0);
}

