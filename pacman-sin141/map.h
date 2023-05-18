#ifndef MAP_H
#define MAP_H

#include "wall.h"
#include "coin.h"
#define MAP_LINHAS 21
#define MAP_COLUNAS 21

void renderMap(std::vector<std::vector<char>>& mapa) {
    
    Wall wall_obj; 
    Coin coin_obj; 
    int height = mapa.size();
    int width = mapa[0].size();
    int i, j, qtyWall = 0, qtyCoin = 0;
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            if (mapa[j][i] == '0') {
                wall_obj.renderWall(j, i);
                qtyWall++;
            }
            if (mapa[j][i] == '1') {
                coin_obj.renderCoin(j, i);
                qtyCoin++;
            }
        }
    }
}


#endif // !MAP_H
