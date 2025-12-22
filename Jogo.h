#ifndef JOGO_DOS_PALITOS_JOGO_H
#define JOGO_DOS_PALITOS_JOGO_H

#include "Jogador.h"

class Jogo {
public:
    Jogo(int totalDePalitos);
    ~Jogo();
    int totalDePalitos();
    Jogador *getGanhador();
    Jogador *getUltimoJogador();
    void retirarPalitos(int palitos, Jogador *jogador);

private:
    int palitosRestantes;
    Jogador *ganhador;
    Jogador *ultimoJogador;
};

#endif //JOGO_DOS_PALITOS_JOGO_H