#include <iostream>
#include "Jogador.h"
#include "Jogo.h"

using namespace std;

const int VITORIA_IA = 10;
const int DERROTA_IA = -10;

/**
 * Função auxiliar para desenhar a indentação da árvore
 */
void imprimirIndentacao(int profundidade) {
    for (int i = 0; i < profundidade; ++i) {
        cout << "    |";
    }
    cout << "-- ";
}

/**
 * Função Minimax
 */
int minimax(int palitos, bool ehVezDaIA, int profundidade) {

    // Imprime o nó atual
    imprimirIndentacao(profundidade);
    cout << (ehVezDaIA ? "[MAX]" : "[MIN]")
         << " Palitos: " << palitos << endl;

    // 1. Caso Base
    if (palitos == 0) {
        int score;
        if (ehVezDaIA) {
            score = DERROTA_IA; // Humano pegou o último
        } else {
            score = VITORIA_IA; // IA pegou o último
        }

        // Imprime o valor da folha
        imprimirIndentacao(profundidade);
        cout << "-> FIM (Score: " << score << ")" << endl;

        return score;
    }

    // 2. Lógica do MAXIMIZADOR (IA)
    if (ehVezDaIA) {
        int melhorScore = -1000;

        for (int jogada = 1; jogada <= 3; jogada++) {
            if (palitos - jogada >= 0) {
                // Chama recursivamente com profundidade + 1
                int score = minimax(palitos - jogada, false, profundidade + 1);

                // Atualiza e mostra comparação
                if (score > melhorScore) {
                    melhorScore = score;
                }
            }
        }

        // Imprime o valor decidido para este nó
        imprimirIndentacao(profundidade);
        cout << "<- MAX retorna: " << melhorScore << endl;

        return melhorScore;
    }

    // 3. Lógica do MINIMIZADOR (Humano)
    else {
        int piorScore = 1000;

        for (int jogada = 1; jogada <= 3; jogada++) {
            if (palitos - jogada >= 0) {
                // Chama recursivamente com profundidade + 1
                int score = minimax(palitos - jogada, true, profundidade + 1);

                if (score < piorScore) {
                    piorScore = score;
                }
            }
        }

        // Imprime o valor decidido para este nó
        imprimirIndentacao(profundidade);
        cout << "<- MIN retorna: " << piorScore << endl;

        return piorScore;
    }
}

/**
 * Wrapper para chamar o Minimax
 */
int calcularMelhorJogada(int palitosRestantes) {
    int melhorJogada = 1;
    int melhorValor = -1000;

    cout << "\n--- INICIO ANALISE MINIMAX (" << palitosRestantes << " palitos) ---" << endl;

    for (int jogada = 1; jogada <= 3; jogada++) {
        if (palitosRestantes - jogada >= 0) {

            cout << "Raiz avalia tirar " << jogada << ":" << endl;

            // Inicia o minimax com profundidade 1 (pois a raiz é 0)
            int valorDaJogada = minimax(palitosRestantes - jogada, false, 1);

            cout << ">>> Valor da jogada " << jogada << " = " << valorDaJogada << endl;

            if (valorDaJogada > melhorValor) {
                melhorValor = valorDaJogada;
                melhorJogada = jogada;
            }
        }
    }
    cout << "--- FIM ANALISE ---\n" << endl;

    return melhorJogada;
}

int main() {
    Jogo *jogo = new Jogo(7);
    Jogador *humano = new Jogador("Humano");
    Jogador *ia = new Jogador("IA Clássica");

    cout << "--- Jogo dos Palitos (Minimax Visual) ---" << endl;

    while (jogo->getGanhador() == nullptr) {
        cout << "\nPalitos na mesa: " << jogo->totalDePalitos() << endl;

        // --- Vez do Humano ---
        int jogadaHumano;
        cout << "A sua vez (1, 2 ou 3): ";
        cin >> jogadaHumano;

        if (jogadaHumano < 1 || jogadaHumano > 3 || jogo->totalDePalitos() - jogadaHumano < 0) {
            cout << "Jogada invalida! Tente novamente." << endl;
            continue;
        }

        jogo->retirarPalitos(jogadaHumano, humano);
        if (jogo->getGanhador() != nullptr) break;

        // --- Vez da IA ---
        int jogadaIA = calcularMelhorJogada(jogo->totalDePalitos());
        cout << "IA pensou e retirou: " << jogadaIA << endl;

        jogo->retirarPalitos(jogadaIA, ia);
    }

    cout << "\n-----------------------------------" << endl;
    cout << "VENCEDOR: " << jogo->getGanhador()->getNome() << endl;
    cout << "-----------------------------------" << endl;

    delete jogo;
    delete humano;
    delete ia;

    return 0;
}