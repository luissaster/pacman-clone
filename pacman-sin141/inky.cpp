#include "inky.h"
Inky::Inky(int x, int y) : Ghost() {
	entityX = x;
	entityY = y;
}
Inky::~Inky() {}
void Inky::renderInky(ALLEGRO_BITMAP* imgInky, int sprite) {
	al_draw_bitmap_region(imgInky, direction * entityWidth, sprite * entityHeight, entityWidth, entityHeight, getEntityX(), getEntityY(), 0);
}