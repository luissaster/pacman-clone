#ifndef PACMAN_H
#define PACMAN_H
#define PLAYER_SIZE 32

#include "entidade.h"

class Pacman : public Entidade
{
public:
	Pacman();
	~Pacman();
	void movePacman();
	void renderPacman();
	bool colisaoCima;
	bool colisaoBaixo;
	bool colisaoEsquerda;
	bool colisaoDireita;
private:
	ALLEGRO_BITMAP* Pacman_sprite;
};

#endif // !PACMAN_H