#include"wall.h"
#define WALL_SPRITE "sprites/wall.png"
Wall::Wall() {
	wall_sprite = al_load_bitmap(WALL_SPRITE);
}
Wall::~Wall() {
	al_destroy_bitmap(wall_sprite);
}
void Wall::renderWall(int linha, int coluna) {
	al_draw_bitmap(wall_sprite, coluna * 32, linha * 32, 0);
}