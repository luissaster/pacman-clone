#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "pacman.h"

using namespace std;

Pacman::Pacman()
{
    //Posiçao do player em Px
    Player_x = 160;
    Player_y = 60;

    //Posição do player
    colisaoYPlayer = 0;
    colisaoXPlayer = 0;

    //Colisão Cima
    colisaoYC = 0;
    colisaoXC = 0;
    colisaoYCN = 0;
    colisaoXCN = 0;

    //Colisão Esquerda
    colisaoYE = 0;
    colisaoXE = 0;
    colisaoYEN = 0;
    colisaoXEN = 0;

    //Colisão Direita
    colisaoYD = 0;
    colisaoXD = 0;
    colisaoYDN = 0;
    colisaoXDN = 0;

    //Colisão Baixo
    colisaoXB = 0;
    colisaoYB = 0;
    colisaoXBN = 0;
    colisaoYBN = 0;

    pacman = NULL;

    placar = 0;

    //Altura e Largura da Sprite
    pacman_altura = 32;
    pacman_largura = 32;

    //Variaveis de Direção
    top = false;
    right = false;
    bottom = false;
    left = false;
    lado = 0;

}

Pacman::Pacman(int x, int y)
{
    //Posiçao do player em Px
    Player_x = x;
    Player_y = y;

    //Posição do player
    colisaoYPlayer = 0;
    colisaoXPlayer = 0;

    //Colisão Cima
    colisaoYC = 0;
    colisaoXC = 0;
    colisaoYCN = 0;
    colisaoXCN = 0;

    //Colisão Esquerda
    colisaoYE = 0;
    colisaoXE = 0;
    colisaoYEN = 0;
    colisaoXEN = 0;

    //Colisão Direita
    colisaoYD = 0;
    colisaoXD = 0;
    colisaoYDN = 0;
    colisaoXDN = 0;

    //Colisão Baixo
    colisaoXB = 0;
    colisaoYB = 0;
    colisaoXBN = 0;
    colisaoYBN = 0;

    pacman = NULL;

    placar = 0;

    //Altura e Largura da Sprite
    pacman_altura = 32;
    pacman_largura = 32;

    //Variaveis de Direção
    top = false;
    right = false;
    bottom = false;
    left = false;
    lado = 0;

}

void Pacman::posicaoPacman() {
    //Posi��o Player
    colisaoYPlayer = ((Player_y) / 32);
    colisaoXPlayer = ((Player_x) / 32);

    //Colis�o Cima
    colisaoYC = ceil(((Player_y) / 32));
    colisaoXC = ((Player_x) / 32);
    colisaoYCN = ceil(((Player_y) / 32));
    colisaoXCN = ceil(((Player_x) / 32));

    //Colis�o Esquerda
    colisaoYE = ceil(((Player_y) / 32));
    colisaoXE = ceil(((Player_x) / 32));
    colisaoYEN = ((Player_y) / 32);
    colisaoXEN = ceil(((Player_x) / 32));

    //Colis�o Direita
    colisaoYD = ceil(((Player_y) / 32));
    colisaoXD = ((Player_x) / 32);
    colisaoYDN = ((Player_y) / 32);
    colisaoXDN = ((Player_x) / 32);

    //Colis�o Baixo
    colisaoYB = (((Player_y) / 32));
    colisaoXB = ceil(((Player_x) / 32));
    colisaoYBN = (((Player_y) / 32));
    colisaoXBN = (((Player_x) / 32));
}

bool Pacman::colisaoPacman(vector<vector<char>>& mapa) {
    if (mapa[colisaoYPlayer][colisaoXPlayer] != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Pacman::colisaoPacmanPirula(vector<vector<char>>& mapa) {
    if (mapa[getPacmanMatrizPosY()][getPacmanMatrizPosX()] == '1')
    {
        mapa[getPacmanMatrizPosY()][getPacmanMatrizPosX()] = '2';
        placar++;
    }

}

int Pacman::getAtualPlacar() {
    return placar;
}

bool Pacman::colisaoPacmanTop(vector<vector<char>>& mapa) {
    if (mapa[colisaoYC - 1][colisaoXC] != '0' && mapa[colisaoYCN - 1][colisaoXCN] != '0')
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Pacman::colisaoPacmanBottom(vector<vector<char>>& mapa) {
    if (mapa[colisaoYB + 1][colisaoXB] != '0' && mapa[colisaoYBN + 1][colisaoXBN] != '0')
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Pacman::colisaoPacmanRight(vector<vector<char>>& mapa) {
    if (mapa[colisaoYD][colisaoXD + 1] != '0' && mapa[colisaoYDN][colisaoXDN + 1] != '0')
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Pacman::colisaoPacmanLeft(vector<vector<char>>& mapa) {
    if (mapa[colisaoYE][colisaoXE - 1] != '0' && mapa[colisaoYEN][colisaoXEN - 1] != '0')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Pacman::getPacmanMatrizPosX() {
    return colisaoXPlayer;
}
int Pacman::getPacmanMatrizPosY() {
    return colisaoYPlayer;
}

float Pacman::getPacmanX() {
    return Player_x;
}
float Pacman::getPacmanY() {
    return Player_y;
}
void Pacman::setPacmanX(float x) {
    Player_x = x;
}
void Pacman::setPacmanY(float y) {
    Player_y = y;
}

void Pacman::movimentacaoPacman(int Instrucao, vector<vector<char>>& mapa) {
    //Verifica se o camando pode ser executado e define as variaveis para que isso aconteça

    //Top
    if (Instrucao == ALLEGRO_KEY_UP && colisaoPacmanTop(mapa) == true)
    {
        top = true;
        bottom = false;
        left = false;
        right = false;
        lado = 3;
    }
    //Bottom
    if (Instrucao == ALLEGRO_KEY_DOWN && colisaoPacmanBottom(mapa) == true)
    {
        bottom = true;
        top = false;
        left = false;
        right = false;
        lado = 1;
    }
    //Left
    if (Instrucao == ALLEGRO_KEY_LEFT && colisaoPacmanLeft(mapa) == true)
    {
        left = true;
        top = false;
        bottom = false;
        right = false;
        lado = 2;
    }
    //Right
    if (Instrucao == ALLEGRO_KEY_RIGHT && colisaoPacmanRight(mapa) == true)
    {
        right = true;
        top = false;
        bottom = false;
        left = false;
        lado = 0;
    }
}

void Pacman::execusaoMovPacman(vector<vector<char>>& mapa) {

    //Executa a movimentação

    if (top == true && colisaoPacmanTop(mapa) == true) { //para cima
        setPacmanY(getPacmanY() - 1.0);
        //darth_y -= 2.0;
    }

    if (bottom == true && colisaoPacmanBottom(mapa) == true) { //para baixo
        setPacmanY(getPacmanY() + 1.0);
        //darth_y += 2.0;
    }

    if (left == true && colisaoPacmanLeft(mapa) == true) { //para esquerda
        setPacmanX(getPacmanX() - 1.0);
        //darth_x -= 2.0;
    }

    if (right == true && colisaoPacmanRight(mapa) == true) { //para direita
        setPacmanX(getPacmanX() + 1.0);
        //darth_x += 2.0;
    }
}

void Pacman::desenhaPacman(ALLEGRO_BITMAP* ImgPacman, int sprite) {
    al_draw_bitmap_region(ImgPacman, lado * pacman_largura, sprite * pacman_altura, pacman_largura, pacman_altura, getPacmanX(), getPacmanY(), 0);
}

ALLEGRO_BITMAP* Pacman::getPacman() {
    return pacman;
}

Pacman::~Pacman()
{
    al_destroy_bitmap(pacman);
}

