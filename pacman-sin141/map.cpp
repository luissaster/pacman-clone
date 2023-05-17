#include"map.h"
#include "wall.h"
#include "coin.h"
Map::Map() {

}
Map::~Map() {

}
void Map::draw_map() {
		Wall wall_obj[200]; // tamanho do vetor = qntdWall 
		Coin coin_obj[160]; // tamanho do vetor = qntdCoin

		int linha, coluna, qntdWall = 0, qntdCoin = 0;
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
		//cout << "Moedas criadas: " << qntdCoin << endl; //151 moedas no mapa original
		//cout << "Paredes criadas: " << qntdWall << endl; //198 paredes no mapa original
}
