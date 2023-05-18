#ifndef COIN_H
#define	COIN_H
#include <allegro5/allegro.h>

class Coin
{
public:
	Coin();
	~Coin();
	void renderCoin(int linha, int coluna);
private:
	ALLEGRO_BITMAP* coin_sprite;
};

#endif // !COIN_H