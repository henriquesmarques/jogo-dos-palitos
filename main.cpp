#include <iostream>
#include <vector>
#include "Jogador.h"
#include "Jogo.h"

using namespace std;

// Memória simples para guardar resultados (0 = não calculado, 1 = vitória, -1 = derrota)
int memoria[30];

// Função Reset: Limpa a memória antes de cada cálculo
void limparMemoria() {
    for (int i = 0; i < 30; i++) memoria[i] = 0;
}

// Função Recursiva: Retorna 1 se o jogador atual consegue garantir a vitória, -1 se não.
int possoVencer(int palitos) {
    // 1. Caso Base: Se não há palitos, o jogador anterior tirou o último e ganhou.
    if (palitos == 0) return -1;

    // 2. Verifica a memória (Cache)
    if (memoria[palitos] != 0) return memoria[palitos];

    // 3. Tenta todas as jogadas possíveis (1, 2 ou 3 palitos)
    for (int jogada = 1; jogada <= 3; jogada++) {
        if (palitos - jogada >= 0) {

            // Se eu fizer esta jogada, será a vez do oponente com (palitos - jogada).
            // Se o oponente NÃO puder vencer (resultado -1) a partir daí, significa que EU venci.
            if (possoVencer(palitos - jogada) == -1) {
                memoria[palitos] = 1; // Marcar que este estado é vitorioso para mim
                return 1;
            }
        }
    }

    // 4. Se tentei todas as opções e o oponente ganha em todas, então eu perco.
    memoria[palitos] = -1;
    return -1;
}

// Função que escolhe o melhor movimento para a IA
int calcularMelhorJogada(int palitosRestantes) {
    limparMemoria();

    // Tenta tirar 1, 2 ou 3 para ver qual leva à vitória
    for (int jogada = 1; jogada <= 3; jogada++) {
        if (palitosRestantes - jogada >= 0) {

            // Simula a jogada. Se o resultado para o oponente for derrota (-1), essa é a minha jogada!
            // Caso especial: Se deixar 0 palitos, eu ganho imediatamente (regra do jogo).
            if (palitosRestantes - jogada == 0) {
                return jogada;
            }

            if (possoVencer(palitosRestantes - jogada) == -1) {
                return jogada;
            }
        }
    }

    // Se não houver jogada vencedora (IA vai perder se o humano jogar bem), tira 1 palito apenas para prolongar o jogo.
    return 1;
}

int main() {
    // Inicialização usando as suas classes
    Jogo *jogo = new Jogo(21);
    Jogador *humano = new Jogador("Humano");
    Jogador *ia = new Jogador("IA");

    cout << "--- Jogo dos Palitos (Algoritmo Min-Max) ---" << endl;

    // Enquanto ninguém ganhou
    while (jogo->getGanhador() == nullptr) {

        cout << "\nPalitos na mesa: " << jogo->totalDePalitos() << endl; //

        // Vez do Jogador (Humano)
        int jogadaHumano;
        cout << "A sua vez (1, 2 ou 3): ";
        cin >> jogadaHumano;

        // Validação simples
        if (jogadaHumano < 1 || jogadaHumano > 3 || jogo->totalDePalitos() - jogadaHumano < 0) {
            cout << "Jogada invalida! Tente novamente." << endl;
            continue;
        }

        jogo->retirarPalitos(jogadaHumano, humano);
        if (jogo->getGanhador() != nullptr) break;  // Se ganhou, sai do loop

        // --- Vez da IA ---
        int jogadaIA = calcularMelhorJogada(jogo->totalDePalitos());

        jogo->retirarPalitos(jogadaIA, ia); //
    }

    // Exibe o vencedor final
    cout << "\n-----------------------------------" << endl;
    cout << "VENCEDOR: " << jogo->getGanhador()->getNome() << endl; //
    cout << "-----------------------------------" << endl;

    delete jogo;
    delete humano;
    delete ia;

    return 0;
}