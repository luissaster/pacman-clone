#include "pacman.h"
#include <stdio.h>
#define PACMAN_SPRITE_RIGHT "sprites/pacman_right.png"
#define PACMAN_SPRITE_LEFT "sprites/pacman_left.png"
#define PACMAN_SPRITE_UP "sprites/pacman_up.png"
#define PACMAN_SPRITE_DOWN "sprites/pacman_down.png"

#define START_X 288
#define START_Y 480

Pacman::Pacman() {
	Pacman_sprite = al_load_bitmap(PACMAN_SPRITE_RIGHT);
	setX(START_X);
	setY(START_Y);
	setDirection(4);
	colisaoBaixo = false;
	colisaoCima = false;
	colisaoDireita = false;
	colisaoEsquerda = false;
}
void Pacman::renderPacman() {
	al_draw_bitmap(Pacman_sprite, getX(), getY(), 0);
}
void Pacman::movePacman() {
	switch (getDirection()) { //0 - cima, 1 - direita, 2 - esquerda, 3 - baixo
	case 0:
		//Pacman_sprite = al_load_bitmap(PACMAN_SPRITE_UP);
		this->setY(posY -= 0.7);
		break;
	case 1:
		//Pacman_sprite = al_load_bitmap(PACMAN_SPRITE_RIGHT);
		this->setX(posX += 0.7);
		break;
	case 2:
		//Pacman_sprite = al_load_bitmap(PACMAN_SPRITE_LEFT);
		this->setX(posX -= 0.7);
		break;
	case 3:
		//Pacman_sprite = al_load_bitmap(PACMAN_SPRITE_DOWN);
		this->setY(posY += 0.7);
		break;
	default:
		break;
	}
}
Pacman::~Pacman() {
}