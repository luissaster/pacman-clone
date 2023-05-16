#ifndef ENTIDADE_H
#define ENTIDADE_H
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

class Entidade
{
public:
	Entidade();
	~Entidade();

	int getX();
	int getY();
	void setX(float x);
	void setY(float y);
	int getDirection();
	void setDirection(int dir);


protected:
	int posX = 0;
	int posY = 0;
	int direction = 4; // 0 - cima, 1 - direita, 2 - esquerda, 3 - baixo, 4 - parado
};


#endif // !ENTIDADE_H
