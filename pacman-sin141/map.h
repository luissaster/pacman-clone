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

void draw_map(vector<vector<char >> &mapa) {
	Wall wall_obj[200]; // tamanho do vetor = qntdWall 
	Coin coin_obj[160]; // tamanho do vetor = qntdCoin
	int altura = mapa.size();
	int largura = mapa[0].size();
	int linha, coluna, qntdWall= 0 , qntdCoin = 0;
	for (linha = 0; linha < largura; linha++) {
		for (coluna = 0; coluna < altura; coluna++) {
			if (mapa[coluna][linha] == '0') {
				wall_obj[qntdWall].draw_wall(coluna, linha);
				//printf("Parede criada em [%d][%d].\n", linha, coluna);
				qntdWall++; 
			}
			if (mapa[coluna][linha] == '1') {
				coin_obj[qntdCoin].draw_coin(coluna, linha);
				//printf("Moeda criada em [%d][%d].\n", linha, coluna);
				qntdCoin++;

			}
		}
	}
	//cout << "Moedas criadas: " << qntdCoin << endl; //151 moedas no mapa original
	//cout << "Paredes criadas: " << qntdWall << endl; //198 paredes no mapa original
}

#endif // !MAP_H


