#include "pinky.h"
Pinky::Pinky(int x, int y) : Ghost() {
	entityX = x;
	entityY = y;
}
Pinky::~Pinky(){}
void Pinky::renderPinky(ALLEGRO_BITMAP* imgPinky, int sprite) {
	al_draw_bitmap_region(imgPinky, direction * entityWidth, sprite * entityHeight, entityWidth, entityHeight, getEntityX(), getEntityY(), 0);
}