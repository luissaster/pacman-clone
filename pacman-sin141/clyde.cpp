#include "clyde.h"
Clyde::Clyde(int x, int y) : Ghost() {
	entityX = x;
	entityY = y;
}
Clyde::~Clyde() {}
void Clyde::renderClyde(ALLEGRO_BITMAP* imgClyde, int sprite) {
	al_draw_bitmap_region(imgClyde, direction * entityWidth, sprite * entityHeight, entityWidth, entityHeight, getEntityX(), getEntityY(), 0);
}