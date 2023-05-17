#ifndef PACMAN2_H
#define PACMAN2_H

#include <iostream>
#include <vector>

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"

using namespace std;

class Pacman
{
public:
    Pacman();
    Pacman(int, int);

    ALLEGRO_BITMAP* getPacman();

    void posicaoPacman();

    bool colisaoPacman(vector<vector<char>>& mapa);

    void colisaoPacmanPirula(vector<vector<char>>& mapa);
    int getAtualPlacar();

    bool colisaoPacmanTop(vector<vector<char>>& mapa);
    bool colisaoPacmanBottom(vector<vector<char>>& mapa);
    bool colisaoPacmanRight(vector<vector<char>>& mapa);
    bool colisaoPacmanLeft(vector<vector<char>>& mapa);

    int getPacmanMatrizPosX();
    int getPacmanMatrizPosY();

    float getPacmanX();
    float getPacmanY();

    void setPacmanX(float);
    void setPacmanY(float);

    void movimentacaoPacman(int, vector<vector<char>>& mapa);
    void execusaoMovPacman(vector<vector<char>>& mapa);

    void desenhaPacman(ALLEGRO_BITMAP*);

    ~Pacman();

private:
    ALLEGRO_BITMAP* pacman;

    //Variaveis de posicao em Px
    float Player_x;
    float Player_y;

    //Posição do player
    int colisaoYPlayer;
    int colisaoXPlayer;

    //Colisão Cima
    int colisaoYC;
    int colisaoXC;
    int colisaoYCN;
    int colisaoXCN;

    //Colisão Esquerda
    int colisaoYE;
    int colisaoXE;
    int colisaoYEN;
    int colisaoXEN;

    //Colisão Direita
    int colisaoYD;
    int colisaoXD;
    int colisaoYDN;
    int colisaoXDN;

    //Colisão Baixo
    int colisaoXB;
    int colisaoYB;
    int colisaoXBN;
    int colisaoYBN;

    int placar;

    //Variaveis de Tamanho da Sprite
    int pacman_altura;
    int pacman_largura;

    //Variaveis de Dire��o
    bool top;
    bool right;
    bool bottom;
    bool left;
    int lado;

};


#endif // !PACMAN2_H
