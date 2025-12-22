#include "Jogo.h"
#include <iostream>

using namespace std;

Jogo::Jogo(int totalDePalitos) {;
    this->palitosRestantes = totalDePalitos;
    this->ganhador = nullptr;
    this->ultimoJogador = nullptr;
}

Jogo::~Jogo() = default;

Jogador * Jogo::getGanhador() {
    return this->ganhador;
}

Jogador * Jogo::getUltimoJogador() {
    return this->ultimoJogador;
}

int Jogo::totalDePalitos() {
    return this->palitosRestantes;
}

void Jogo::retirarPalitos(int palitos, Jogador *jogador) {
    if (this->palitosRestantes <= 0) {
        cout << "Jogo encerrado. Não é possível retirar nenhum palito.\n";
    } else if (palitos < 0 || palitos > 3) {
        cout << "Número de palitos inválido.\n";
    } else if (this->ultimoJogador != nullptr && this->ultimoJogador == jogador) {
        cout << "Não se pode jogar duas vezes seguidas.\n";
    } else {
        this->palitosRestantes -= palitos;
        this->ultimoJogador = jogador;
        cout << "O jogador " << jogador->getNome() << " retirou " << palitos << " palitos.\n";

        if (this->palitosRestantes <= 0) {
            this->palitosRestantes = 0;
            this->ganhador = jogador;
            cout << "O jogador " << jogador->getNome() << " ganhou.\n";
        }
    }
}