#ifndef MAP_H
#define MAP_H

#include<iostream>
#include<stdio.h>
#include<allegro5/allegro5.h>
#include<allegro5/allegro_image.h>
#include "wall.h"
#include "coin.h"

using namespace std;
const int MAP_LINHAS = 21;
const int MAP_COLUNAS = 21;

char map[MAP_LINHAS][MAP_COLUNAS] = {
"0000000000000000000",
"0111111110111111110",
"0100100010100010010",
"0111111111111111110",
"0100101000001010010",
"0111101110111011110",
"0000100020200010000",
"2220102222222010222",
"0000102002002010000",
"2222122022202212222",
"0000102000002010000",
"2220102222222010222",
"0000102000002010000",
"0111111110111111110",
"0100100010100010010",
"0110111111111110110",
"0010101000001010100",
"0111101110111011110",
"0100000010100000010",
"0111111111111111110",
"0000000000000000000"
};

void draw_map() {
	Wall wall_obj[200]; // tamanho do vetor = qntdWall 
	Coin coin_obj[160]; // tamanho do vetor = qntdCoin

	int linha, coluna, qntdWall= 0 , qntdCoin = 0;
	for (linha = 0; linha < MAP_LINHAS; linha++) {
		for (coluna = 0; coluna < MAP_COLUNAS; coluna++) {
			if (map[linha][coluna] == '0') {
				wall_obj[qntdWall].draw_wall(linha, coluna);
				//printf("Parede criada em [%d][%d].\n", linha, coluna);
				qntdWall++; 
			}
			if (map[linha][coluna] == '1') {
				coin_obj[qntdCoin].draw_coin(linha, coluna);
				//printf("Moeda criada em [%d][%d].\n", linha, coluna);
				qntdCoin++;

			}
		}
	}
	cout << "Moedas criadas: " << qntdCoin << endl; //151 moedas no mapa original
	cout << "Paredes criadas: " << qntdWall << endl; //198 paredes no mapa original
}

#endif // !MAP_H


