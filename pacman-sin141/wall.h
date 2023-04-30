#ifndef WALL_H
#define WALL_H
#include<allegro5/allegro5.h>

class Wall {
public:
	Wall();
	~Wall();
	void draw_wall(int linha, int coluna);
private:
	ALLEGRO_BITMAP* wall_sprite;
};
#endif // !WALL_H
