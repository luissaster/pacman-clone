#include "map.h"
Map::Map(){}
Map::~Map(){}
void Map::loadMap(const char* archiveName, std::vector<std::vector<char>>& mapa) {
    std::ifstream arquivo(archiveName);
    std::string linha;

    if (arquivo.is_open()) {
        while (getline(arquivo, linha)) {
            std::vector<char> linhaMapa;
            for (char caractere : linha) {
                if (caractere != ' ') {
                    linhaMapa.push_back(caractere);
                }
            }
            mapa.push_back(linhaMapa);
        }
        arquivo.close();
    }
    else {
        std::cout << "Error while opening the map file." << std::endl;
    }
}
void Map::renderMap(std::vector<std::vector<char>>& mapa) {
    Wall wall_obj;
    Coin coin_obj;
    int height = mapa.size();
    int width = mapa[0].size();
    int i, j;
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            if (mapa[j][i] == '0') {
                wall_obj.renderWall(j, i);
            }
            if (mapa[j][i] == '1') {
                coin_obj.renderCoin(j, i);
            }
        }
    }
}