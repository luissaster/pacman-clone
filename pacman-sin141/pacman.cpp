#include "pacman.h"
#define PACMAN_SPRITE "sprites/pacman.png"
#define START_X 288
#define START_Y 480

Pacman::Pacman() {
	Pacman_sprite = al_load_bitmap(PACMAN_SPRITE);
	setX(START_X);
	setY(START_Y);
	setDirection(4);
}
void Pacman::renderPacman() {
	al_draw_bitmap(Pacman_sprite, getX(), getY(), 0);
}
void Pacman::movePacman() {
	switch (getDirection()) { //0 - cima, 1 - direita, 2 - esquerda, 3 - baixo
	case 0:
		this->setY(posY -= 2.5);
		break;
	case 1:
		this->setX(posX += 2.5);
		break;
	case 2:
		this->setX(posX -= 2.5);
		break;
	case 3:
		this->setY(posY += 2.5);
		break;
	default:
		break;
	}
}
Pacman::~Pacman() {
	al_destroy_bitmap(Pacman_sprite);
}