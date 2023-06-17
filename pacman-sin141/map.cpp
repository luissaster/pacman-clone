#include "map.h"

Map::Map() {}

Map::~Map() {}

// Load the map data from a file
void Map::loadMap(const char* archiveName, std::vector<std::vector<char>>& mapa) {
    std::ifstream arquivo(archiveName);
    std::string linha;

    if (arquivo.is_open()) {
        // Read each line from the file
        while (getline(arquivo, linha)) {
            std::vector<char> linhaMapa;

            // Process each character in the line
            for (char caractere : linha) {
                if (caractere != ' ') {
                    linhaMapa.push_back(caractere);
                }
            }
            // Add the processed line to the map
            mapa.push_back(linhaMapa);
        }
        arquivo.close();
    }
    else {
        std::cout << "Error while opening the map file." << std::endl;
    }
}

// Render the map
void Map::renderMap(std::vector<std::vector<char>>& mapa) {
    Wall wall_obj;
    Coin coin_obj;
    int height = mapa.size();
    int width = mapa[0].size();
    int i, j;

    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            // Render a wall if the cell contains '0'
            if (mapa[j][i] == '0') {
                wall_obj.renderWall(j, i);
            }
            // Render a coin if the cell contains '1'
            if (mapa[j][i] == '1') {
                coin_obj.renderCoin(j, i);
            }
        }
    }
}
