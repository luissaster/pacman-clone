#include "blinky.h"
Blinky::Blinky(int x, int y) : Ghost() {
	entityX = x;
	entityY = y;
	this->ghostType = 1;
}
Blinky::~Blinky(){}
void Blinky::renderGhost(ALLEGRO_BITMAP* imgBlinky, int sprite) {
	al_draw_bitmap_region(imgBlinky, direction * entityWidth, sprite * entityHeight, entityWidth, entityHeight, getEntityX(), getEntityY(), 0);
}

void Blinky::chasePacman(std::vector<std::vector<char>> map, int pacX, int pacY)
{
	int blinkyX = this->getEntityConvertedX();
	int blinkyY = this->getEntityConvertedY();
	int currentMove = this->getCurrentMove();  // Obtenha a direção atual do Blinky, 0 - RIGHT, 1 - DOWN, 2 - LEFT, 3 - UP

	enum moveKeys {
		RIGHT,
		DOWN,
		LEFT,
		UP
	};

	if (blinkyX == 9 && blinkyY == 8) { // Impedir que o blinky entre de volta na caixa
		this->setNextMove(ALLEGRO_KEY_UP, map);
		return;
	}

	if (blinkyX > pacX && blinkyY > pacY) { // Blinky à direita do Pacman e abaixo do pacman
		// PRIORIDADE: SE MOVER PARA A ESQUERDA -> SE MOVER PARA CIMA
		if (currentMove != RIGHT && checkEntityCollisionLeft(map)) {
			this->setNextMove(ALLEGRO_KEY_LEFT, map);
			return;
		}
		else if (currentMove != DOWN && checkEntityCollisionUp(map)) {
			this->setNextMove(ALLEGRO_KEY_UP, map);
			return;
		}
		else if (currentMove != LEFT && checkEntityCollisionRight(map)) {
			this->setNextMove(ALLEGRO_KEY_RIGHT, map);
			return;
		}
		else if (currentMove != UP && checkEntityCollisionDown(map)) {
			this->setNextMove(ALLEGRO_KEY_DOWN, map);
			return;
		}
	} 
	else if (blinkyX > pacX && blinkyY < pacY) { // Blinky à direita do Pacman e acima do pacman
		// PRIORIDADE: SE MOVER PARA A ESQUERDA -> SE MOVER PARA BAIXO
		if (currentMove != RIGHT && checkEntityCollisionLeft(map)) {
			this->setNextMove(ALLEGRO_KEY_LEFT, map);
			return;
		}
		else if (currentMove != UP && checkEntityCollisionDown(map)) {
			this->setNextMove(ALLEGRO_KEY_DOWN, map);
			return;
		}
		else if (currentMove != LEFT && checkEntityCollisionRight(map)) {
			this->setNextMove(ALLEGRO_KEY_RIGHT, map);
			return;
		}
		else if (currentMove != DOWN && checkEntityCollisionUp(map)) {
			this->setNextMove(ALLEGRO_KEY_UP, map);
			return;
		}
	}
	else if (blinkyX > pacX && blinkyY == pacY) { // Blinky à direita do Pacman e na mesma altura do pacman
		// PRIORIDADE: SE MOVER PARA A ESQUERDA -> SE MOVER PARA BAIXO
		if (currentMove != RIGHT && checkEntityCollisionLeft(map)) {
			this->setNextMove(ALLEGRO_KEY_LEFT, map);
			return;
		}
		else if (currentMove != UP && checkEntityCollisionDown(map)) {
			this->setNextMove(ALLEGRO_KEY_DOWN, map);
			return;
		}
		else if (currentMove != DOWN && checkEntityCollisionUp(map)) {
			this->setNextMove(ALLEGRO_KEY_UP, map);
			return;
		}
		else if (currentMove != LEFT && checkEntityCollisionRight(map)) {
			this->setNextMove(ALLEGRO_KEY_RIGHT, map);
			return;
		}
	}
	else if (blinkyX < pacX && blinkyY == pacY) { // Blinky à esquerda do Pacman e na mesma altura do pacman
		// PRIORIDADE: SE MOVER PARA A DIRETA -> SE MOVER PARA BAIXO
		if (currentMove != LEFT && checkEntityCollisionRight(map)) {
			this->setNextMove(ALLEGRO_KEY_RIGHT, map);
			return;
		}
		else if (currentMove != UP && checkEntityCollisionDown(map)) {
			this->setNextMove(ALLEGRO_KEY_DOWN, map);
			return;
		}
		else if (currentMove != DOWN && checkEntityCollisionUp(map)) {
			this->setNextMove(ALLEGRO_KEY_UP, map);
			return;
		}
		else if (currentMove != RIGHT && checkEntityCollisionLeft(map)) {
			this->setNextMove(ALLEGRO_KEY_LEFT, map);
			return;
		}
	}
	else if (blinkyX == pacX && blinkyY < pacY) { // Blinky na mesma coluna do Pacman e acima do pacman
		// PRIORIDADE: SE MOVER PARA BAIXO -> SE MOVER NA HORIZONTAL
		if (currentMove != UP && checkEntityCollisionDown(map)) {
			this->setNextMove(ALLEGRO_KEY_DOWN, map);
			return;
		}
		else if (currentMove != RIGHT && checkEntityCollisionLeft(map)) {
			this->setNextMove(ALLEGRO_KEY_LEFT, map);
			return;
		}
		else if (currentMove != LEFT && checkEntityCollisionRight(map)) {
			this->setNextMove(ALLEGRO_KEY_RIGHT, map);
			return;
		}
		else if (currentMove != DOWN && checkEntityCollisionUp(map)) {
			this->setNextMove(ALLEGRO_KEY_UP, map);
			return;
		}
	}
	else if (blinkyX == pacX && blinkyY > pacY) { // Blinky na mesma coluna do Pacman e abaixo do pacman
		// PRIORIDADE: SE MOVER PARA CIMA -> SE MOVER NA HORIZONTAL
		if (currentMove != DOWN && checkEntityCollisionUp(map)) {
			this->setNextMove(ALLEGRO_KEY_UP, map);
			return;
		}
		else if (currentMove != LEFT && checkEntityCollisionRight(map)) {
			this->setNextMove(ALLEGRO_KEY_RIGHT, map);
			return;
		}
		else if (currentMove != RIGHT && checkEntityCollisionLeft(map)) {
			this->setNextMove(ALLEGRO_KEY_LEFT, map);
			return;
		}
		else if (currentMove != UP && checkEntityCollisionDown(map)) {
			this->setNextMove(ALLEGRO_KEY_DOWN, map);
			return;
		}
	}
	else if (blinkyX < pacX && blinkyY > pacY) { // Blinky à esquerda do Pacman e abaixo do pacman
		// PRIORIDADE: SE MOVER PARA A DIREITA -> SE MOVER PARA CIMA
		if (currentMove != LEFT && checkEntityCollisionRight(map)) {
			this->setNextMove(ALLEGRO_KEY_RIGHT, map);
			return;
		}
		else if (currentMove != DOWN && checkEntityCollisionUp(map)) {
			this->setNextMove(ALLEGRO_KEY_UP, map);
			return;
		}
		else if (currentMove != RIGHT && checkEntityCollisionLeft(map)) {
			this->setNextMove(ALLEGRO_KEY_LEFT, map);
			return;
		}
		else if (currentMove != UP && checkEntityCollisionDown(map)) {
			this->setNextMove(ALLEGRO_KEY_DOWN, map);
			return;
		}
	}
	else if (blinkyX < pacX && blinkyY < pacY) { // Blinky à esquerda do Pacman e acima do pacman
		// PRIORIDADE: SE MOVER PARA A DIREITA -> SE MOVER PARA BAIXO
		if (currentMove != LEFT && checkEntityCollisionRight(map)) {
			this->setNextMove(ALLEGRO_KEY_RIGHT, map);
			return;
		}
		else if (currentMove != UP && checkEntityCollisionDown(map)) {
			this->setNextMove(ALLEGRO_KEY_DOWN, map);
			return;
		}
		else if (currentMove != RIGHT && checkEntityCollisionLeft(map)) {
			this->setNextMove(ALLEGRO_KEY_LEFT, map);
			return;
		}
		else if (currentMove != DOWN && checkEntityCollisionUp(map)) {
			this->setNextMove(ALLEGRO_KEY_UP, map);
			return;
		}
	}
}






