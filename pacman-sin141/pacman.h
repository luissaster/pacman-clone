#ifndef PACMAN_H
#define PACMAN_H

#include "entidade.h"

class Pacman : public Entidade
{
public:
	Pacman();	
	~Pacman();
	void movePacman();
	void renderPacman();

private:
	ALLEGRO_BITMAP* Pacman_sprite;
};

#endif // !PACMAN_H