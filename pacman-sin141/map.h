#ifndef MAP_H
#define MAP_H
#include "wall.h"
#include "coin.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Map
{
public:
    Map();
    ~Map();
    void loadMap(const char* archiveName, std::vector<std::vector<char>>& mapa);
    void renderMap(std::vector<std::vector<char>>& mapa);

private:

};

#endif // !MAP_H
