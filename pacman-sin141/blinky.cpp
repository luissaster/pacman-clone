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

/*void Blinky::chasePacman(std::vector<std::vector<char>> map, int pacX, int pacY)
{
	int blinkyX = this->getEntityConvertedX();
	int blinkyY = this->getEntityConvertedY();

	if (blinkyX > pacX) { //blinky a direita do pacman
		if (checkEntityCollisionLeft(map)) {
			this->setNextMove(ALLEGRO_KEY_LEFT);
		}
		else if (checkEntityCollisionLeft(map) == false && blinkyY > pacY) { //parede a esquerda, blinky abaixo do pacman
			if (checkEntityCollisionUp(map)) {
				this->setNextMove(ALLEGRO_KEY_UP);
			}
			else if (checkEntityCollisionDown(map)) {
				this->setNextMove(ALLEGRO_KEY_DOWN);
			}
			else if (checkEntityCollisionRight(map)) {
				this->setNextMove(ALLEGRO_KEY_RIGHT);
			}
		}
		else if (checkEntityCollisionLeft(map) == false && blinkyY < pacY) { //parede a esquerda, blinky acima do pacman
			if (checkEntityCollisionDown(map)) {
				this->setNextMove(ALLEGRO_KEY_DOWN);
			}
			else if (checkEntityCollisionUp(map)) {
				this->setNextMove(ALLEGRO_KEY_UP);
			}
			else if (checkEntityCollisionRight(map)) {
				this->setNextMove(ALLEGRO_KEY_RIGHT);
			}
		}
		else if (checkEntityCollisionLeft(map) == false && blinkyY == pacY) {  //parede a esquerda, blinky na mesma linha que o pacman
			if (checkEntityCollisionUp(map)) {
				this->setNextMove(ALLEGRO_KEY_UP);
			} else if(checkEntityCollisionDown(map)){
				this->setNextMove(ALLEGRO_KEY_DOWN);
			}
			else if (checkEntityCollisionRight(map)) {
				this->setNextMove(ALLEGRO_KEY_RIGHT);
			}
		}
	}
	else if (blinkyX < pacX) { //blinky a esquerda do pacman
		if (checkEntityCollisionRight(map)) {
			this->setNextMove(ALLEGRO_KEY_RIGHT);
		}
		else if (checkEntityCollisionRight(map) == false && blinkyY > pacY) { // parede a direita, blinky abaixo do pacman
			if (checkEntityCollisionUp(map)) {
				this->setNextMove(ALLEGRO_KEY_UP);
			}
			else if (checkEntityCollisionDown(map)) {
				this->setNextMove(ALLEGRO_KEY_DOWN);
			}
			else if (checkEntityCollisionLeft(map)) {
				this->setNextMove(ALLEGRO_KEY_LEFT);
			}
		}
		else if (checkEntityCollisionRight(map) == false && blinkyY < pacY) { // parede a direita, blinky acima do pacman
			if (checkEntityCollisionDown(map)) {
				this->setNextMove(ALLEGRO_KEY_DOWN);
			}
			else if (checkEntityCollisionUp(map)) {
				this->setNextMove(ALLEGRO_KEY_UP);
			}
			else if (checkEntityCollisionLeft(map)) {
				this->setNextMove(ALLEGRO_KEY_LEFT);
			}
		}
		else if (checkEntityCollisionRight(map) == false && blinkyY == pacY) { //parede a direita, blinky na mesma linha que o pacman
			if (checkEntityCollisionDown(map)) {
				this->setNextMove(ALLEGRO_KEY_DOWN);
			}
			else if (checkEntityCollisionUp(map)) {
				this->setNextMove(ALLEGRO_KEY_UP);
			}
			else if (checkEntityCollisionLeft(map)) {
				this->setNextMove(ALLEGRO_KEY_LEFT);
			}
		}
	}

	if(blinkyY > pacY) { //blinky abaixo do pacman
		if (checkEntityCollisionUp(map)) {
			this->setNextMove(ALLEGRO_KEY_UP);
		}
		else if (checkEntityCollisionUp(map) == false && blinkyX > pacX) { // parede acima, blinky a direita do pacman
			if (checkEntityCollisionLeft(map)) {
				this->setNextMove(ALLEGRO_KEY_LEFT);
			}
			else if (checkEntityCollisionDown(map)) {
				this->setNextMove(ALLEGRO_KEY_DOWN);
			}
			else if (checkEntityCollisionRight(map)) {
				this->setNextMove(ALLEGRO_KEY_RIGHT);
			}
		}
		else if (checkEntityCollisionUp(map) == false && blinkyX < pacX) { // parede acima, blinky a esquerda do pacman
			if (checkEntityCollisionRight(map)) {
				this->setNextMove(ALLEGRO_KEY_RIGHT);
			}
			else if (checkEntityCollisionDown(map)) {
				this->setNextMove(ALLEGRO_KEY_DOWN);
			}
			else if (checkEntityCollisionLeft(map)) {
				this->setNextMove(ALLEGRO_KEY_LEFT);
			}
		}
		else if (checkEntityCollisionUp(map) == false && blinkyX == pacX) { //parede acima, blinky na mesma coluna que o pacman
			if (checkEntityCollisionDown(map)) {
				this->setNextMove(ALLEGRO_KEY_DOWN);
			}
			else if (checkEntityCollisionRight(map)) {
				this->setNextMove(ALLEGRO_KEY_RIGHT);
			}
			else if (checkEntityCollisionLeft(map)) {
				this->setNextMove(ALLEGRO_KEY_LEFT);
			}
		}
	}
	else if (blinkyY < pacY) { //blinky acima do pacman
		if (checkEntityCollisionDown(map)) {
			this->setNextMove(ALLEGRO_KEY_DOWN);
		}
		else if (checkEntityCollisionDown(map) == false && blinkyX > pacX) { // parede abaixo, blinky a direita do pacman
			if (checkEntityCollisionLeft(map)) {
				this->setNextMove(ALLEGRO_KEY_LEFT);
			}
			else if (checkEntityCollisionUp(map)) {
				this->setNextMove(ALLEGRO_KEY_UP);
			}
			else if (checkEntityCollisionRight(map)) {
				this->setNextMove(ALLEGRO_KEY_RIGHT);
			}
		}
		else if (checkEntityCollisionDown(map) == false && blinkyX < pacX) { // parede abaixo, blinky a esquerda do pacman
			if (checkEntityCollisionRight(map)) {
				this->setNextMove(ALLEGRO_KEY_RIGHT);
			}
			else if (checkEntityCollisionUp(map)) {
				this->setNextMove(ALLEGRO_KEY_UP);
			}
			else if (checkEntityCollisionLeft(map)) {
				this->setNextMove(ALLEGRO_KEY_LEFT);
			}
		}
		else if (checkEntityCollisionDown(map) == false && blinkyX == pacX) { //parede abaixo, blinky na mesma coluna que o pacman
			if (checkEntityCollisionUp(map)) {
				this->setNextMove(ALLEGRO_KEY_UP);
			}
			else if (checkEntityCollisionLeft(map)) {
				this->setNextMove(ALLEGRO_KEY_LEFT);
			}
			else if (checkEntityCollisionRight(map)) {
				this->setNextMove(ALLEGRO_KEY_RIGHT);
			}
		}
	}
}*/

void Blinky::chasePacman(std::vector<std::vector<char>> map, int pacX, int pacY)
{
	int blinkyX = this->getEntityConvertedX();
	int blinkyY = this->getEntityConvertedY();
	int currentMove = this->getCurrentMove();  // Obtenha a direção atual do Blinky, 0 - RIGHT, 1 - DOWN, 2 - LEFT, 3 - UP

	if (blinkyX > pacX) { // Blinky à direita do Pacman
		if (currentMove != 2 && checkEntityCollisionLeft(map)) {
			this->setNextMove(ALLEGRO_KEY_LEFT);
			return;
		}
	}
	else if (blinkyX < pacX) { // Blinky à esquerda do Pacman
		if (currentMove != 0 && checkEntityCollisionRight(map)) {
			this->setNextMove(ALLEGRO_KEY_RIGHT);
			return;
		}
	}

	if (blinkyY > pacY) { // Blinky abaixo do Pacman
		if (currentMove != 3 && checkEntityCollisionUp(map)) {
			this->setNextMove(ALLEGRO_KEY_UP);
			return;
		}
	}
	else if (blinkyY < pacY) { // Blinky acima do Pacman
		if (currentMove != 1 && checkEntityCollisionDown(map)) {
			this->setNextMove(ALLEGRO_KEY_DOWN);
			return;
		}
	}

	// Caso em que o Blinky está na mesma linha ou coluna que o Pacman
	if (blinkyX != pacX) { // Blinky não está na mesma coluna que o Pacman
		if (checkEntityCollisionRight(map) && checkEntityCollisionLeft(map)) {
			// Não há parede na mesma linha do Blinky, ele pode se mover verticalmente
			if (blinkyY > pacY) {
				if (currentMove != 1 && checkEntityCollisionUp(map)) {
					this->setNextMove(ALLEGRO_KEY_UP);
					return;
				}
				else if (currentMove != 3 && checkEntityCollisionDown(map)) {
					this->setNextMove(ALLEGRO_KEY_DOWN);
					return;
				}
			}
			else if (blinkyY < pacY) {
				if (currentMove != 3 && checkEntityCollisionDown(map)) {
					this->setNextMove(ALLEGRO_KEY_DOWN);
					return;
				}
				else if (currentMove != 1 && checkEntityCollisionUp(map)) {
					this->setNextMove(ALLEGRO_KEY_UP);
					return;
				}
			}
		}
		else {
			// Há parede na mesma linha do Blinky, ele continua tentando mover-se horizontalmente
			if (checkEntityCollisionRight(map)) {
				this->setNextMove(ALLEGRO_KEY_RIGHT);
				return;
			}
			else if (checkEntityCollisionLeft(map)) {
				this->setNextMove(ALLEGRO_KEY_LEFT);
				return;
			}
		}
	}
	else if (blinkyY != pacY) { // Blinky não está na mesma linha que o Pacman
		if (checkEntityCollisionDown(map) && checkEntityCollisionUp(map)) {
			// Não há parede na mesma coluna do Blinky, ele pode se mover horizontalmente
			if (blinkyX > pacX) {
				if (currentMove != 0 && checkEntityCollisionLeft(map)) {
					this->setNextMove(ALLEGRO_KEY_LEFT);
					return;
				}
				else if (currentMove != 2 && checkEntityCollisionRight(map)) {
					this->setNextMove(ALLEGRO_KEY_RIGHT);
					return;
				}
			}
			else if (blinkyX < pacX) {
				if (currentMove != 2 && checkEntityCollisionRight(map)) {
					this->setNextMove(ALLEGRO_KEY_RIGHT);
					return;
				}
				else if (currentMove != 0 && checkEntityCollisionLeft(map)) {
					this->setNextMove(ALLEGRO_KEY_LEFT);
					return;
				}
			}
		}
		else {
			// Há parede na mesma coluna do Blinky, ele continua tentando mover-se verticalmente
			if (checkEntityCollisionDown(map)) {
				this->setNextMove(ALLEGRO_KEY_DOWN);
				return;
			}
			else if (checkEntityCollisionUp(map)) {
				this->setNextMove(ALLEGRO_KEY_UP);
				return;
			}
		}
	}
}






