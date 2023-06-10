#include "blinky.h"
Blinky::Blinky(int x, int y) : Ghost() {
	entityX = x;
	entityY = y;
}
Blinky::~Blinky(){}
void Blinky::renderBlinky(ALLEGRO_BITMAP* imgBlinky, int sprite) {
	al_draw_bitmap_region(imgBlinky, direction * entityWidth, sprite * entityHeight, entityWidth, entityHeight, getEntityX(), getEntityY(), 0);
}
