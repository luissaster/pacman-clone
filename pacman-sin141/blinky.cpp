#include "blinky.h"
Blinky::Blinky(int x, int y) : Ghost() {
	entityX = x;
	entityY = y;
	this->ghostType = 1;
	auxX = auxY = 0;
}
Blinky::~Blinky(){}
void Blinky::renderGhost(ALLEGRO_BITMAP* imgBlinky, int sprite) {
	al_draw_bitmap_region(imgBlinky, direction * entityWidth, sprite * entityHeight, entityWidth, entityHeight, getEntityX(), getEntityY(), 0);
}

void Blinky::chasePacman(std::vector<std::vector<char>> map, float pacmanX, float pacmanY)
{
	int distanceFromPacmanX, distanceFromPacmanY;
	distanceFromPacmanX = pacmanX - this->getEntityX();
	distanceFromPacmanY = pacmanY - this->getEntityY();
	int directionsVet[] = { ALLEGRO_KEY_LEFT, ALLEGRO_KEY_RIGHT ,ALLEGRO_KEY_UP, ALLEGRO_KEY_DOWN };

	if (distanceFromPacmanX < distanceFromPacmanY) {
		if (distanceFromPacmanX > 0 && checkEntityCollisionRight(map)) {
			this->setNextMove(directionsVet[1]);
			//std::cout << "Movendo para a direita" << std::endl;
		}
		else if (distanceFromPacmanX >= 0) {
			if (distanceFromPacmanY >= 0 && checkEntityCollisionDown(map)) {
				this->setNextMove(directionsVet[3]);
				//std::cout << "Movendo para baixo" << std::endl;
			}
			else if(distanceFromPacmanY < 0 && checkEntityCollisionUp(map)){
				this->setNextMove(directionsVet[2]);
				//std::cout << "Movendo para cima" << std::endl;
			}
		}
		else if(distanceFromPacmanX < 0 && checkEntityCollisionLeft(map)){
			this->setNextMove(directionsVet[0]);
			//std::cout << "Movendo para a esquerda" << std::endl;
		}
	}
	else {
		if (distanceFromPacmanY > 0 && checkEntityCollisionDown(map)) {
			this->setNextMove(directionsVet[3]);
			//std::cout << "Movendo para baixo" << std::endl;
		}
		else if (distanceFromPacmanY == 0) {
			if (distanceFromPacmanX >= 0 && checkEntityCollisionRight(map)) {
				this->setNextMove(directionsVet[1]);
				//std::cout << "Movendo para a direita" << std::endl;
			}
			else if(distanceFromPacmanX < 0 && checkEntityCollisionLeft(map)){
				this->setNextMove(directionsVet[0]);
				//std::cout << "Movendo para a esquerda" << std::endl;
			}
		}
		else if(distanceFromPacmanY < 0 && checkEntityCollisionUp(map)){
			this->setNextMove(directionsVet[2]);
			//std::cout << "Movendo para cima" << std::endl;
		}
	}
	this->checkEntityMovement(this->getNextMove(), map);

}


