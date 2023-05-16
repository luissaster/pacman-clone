#include "entidade.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

float Entidade::getX() {
	return this->posX;
}
float Entidade::getY() {
	return this->posY;
}
void Entidade::setX(float x) {
	this->posX = x;
}
void Entidade::setY(float y) {
	this->posY = y;
}
int Entidade::getDirection() {
	return this->direction;
}
void Entidade::setDirection(int dir) {
	this->direction = dir;
}
Entidade::Entidade()
{
}

Entidade::~Entidade()
{
}