#ifndef JOGO_DOS_PALITOS_JOGADOR_H
#define JOGO_DOS_PALITOS_JOGADOR_H

#include <iostream>

using namespace std;

class Jogador {
public:
    Jogador(string nome);
    ~Jogador();
    string getNome();

private:
    string nome;
};

#endif //JOGO_DOS_PALITOS_JOGADOR_H