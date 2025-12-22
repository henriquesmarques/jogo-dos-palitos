#include <iostream>
#include "Jogador.h"
#include "Jogo.h"

using namespace std;

int main() {

    Jogo *jogo1 = new Jogo(21);
    Jogador *jogador1 = new Jogador("Jogador1");
    Jogador *jogador2 = new Jogador("Jogador2");

    jogo1->retirarPalitos(2, jogador1);
    jogo1->retirarPalitos(3, jogador2);
    jogo1->retirarPalitos(1, jogador1);
    jogo1->retirarPalitos(2, jogador2);
    jogo1->retirarPalitos(2, jogador1);
    jogo1->retirarPalitos(2, jogador1);

    jogo1->retirarPalitos(2, jogador2);
    jogo1->retirarPalitos(2, jogador1);
    jogo1->retirarPalitos(3, jogador2);
    jogo1->retirarPalitos(1, jogador1);
    jogo1->retirarPalitos(2, jogador2);
    jogo1->retirarPalitos(2, jogador1);

    jogo1->retirarPalitos(2, jogador2);
    cout << "Total de palitos: " << jogo1->totalDePalitos() << endl;

    cout << "Quem ganhou: " << jogo1->getGanhador()->getNome() << endl;

    return 0;
}