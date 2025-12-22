#include "Jogador.h"

Jogador::Jogador(string nome) {
    this->nome = nome;
}

Jogador::~Jogador() = default;

string Jogador::getNome() {
    return this->nome;
}
