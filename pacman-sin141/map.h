#ifndef MAP_H
#define MAP_H

#include "wall.h"
#include "coin.h"
#define MAP_LINHAS 21
#define MAP_COLUNAS 21

void renderMap(std::vector<std::vector<char>>& mapa) {
    // In the original map, it was needed a total of 198 walls and 151 coins to build the map
    // Just to be sure, our array is a little bit bigger than what's needed
    Wall wall_obj[200]; // Array to store Wall objects (size = qtyWall)
    Coin coin_obj[160]; // Array to store Coin objects (size = qtyCoin)
    int height = mapa.size();
    int width = mapa[0].size();
    int i, j, qtyWall = 0, qtyCoin = 0;
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            if (mapa[j][i] == '0') {
                wall_obj[qtyWall].renderWall(j, i);
                qtyWall++;
            }
            if (mapa[j][i] == '1') {
                coin_obj[qtyCoin].renderCoin(j, i);
                qtyCoin++;
            }
        }
    }
}


#endif // !MAP_H
