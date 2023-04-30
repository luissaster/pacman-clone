#include "coin.h"
#define COIN_SPRITE "sprites/coin.png"

Coin::Coin() {
	coin_sprite = al_load_bitmap(COIN_SPRITE);
}

void Coin::draw_coin(int linha, int coluna) {
	al_draw_bitmap(coin_sprite, coluna * 32, linha * 32, 0);
}

Coin::~Coin() {
	al_destroy_bitmap(coin_sprite);
}