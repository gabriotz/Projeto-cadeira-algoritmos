#include "gameplay.h"
#include "gerenciador_save.h"
#include "../gameLore/itens.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <limits>

using namespace std;

extern vector<pergunta> perguntas;
extern vector<pergunta> perguntasDisponiveis;
extern vector<item*> itensDoJogo;

bool fazerPergunta(personagem* jogador, bool modoAjuda);
void usarItem(personagem* jogador);

bool fazerPergunta(personagem* jogador, bool modoAjuda) {
    if (perguntasDisponiveis.empty()) {
        return false;
    }

    int indice = rand() % perguntasDisponiveis.size();
    pergunta p = perguntasDisponiveis[indice];
    perguntasDisponiveis.erase(perguntasDisponiveis.begin() + indice);

    cout << "\nNao ha tempo para erros. Escolha o protocolo mais eficiente:" << endl;
    cout << "Protocolos restantes: " << perguntasDisponiveis.size() + 1 << endl;
    cout << p.questao << endl;

    if (modoAjuda) {
        // ... (código da função fazerPergunta como estava no main.cpp)
    } else {
        cout << "A) " << p.opcaoA << endl;
        cout << "B) " << p.opcaoB << endl;
        cout << "C) " << p.opcaoC << endl;
        cout << "D) " << p.opcaoD << endl;
    }

    cout << "Sua resposta: ";
    char resposta;
    cin >> resposta;

    if (toupper(resposta) == toupper(p.resposta)) {
        cout << "CORRETO! A ordem foi mantida. Sobrevivemos a mais um dia." << endl;
        if (jogador->vida > 100) jogador->vida = 100;

        if (rand() % 2 == 0) {
            int itemAleatorioIdx = rand() % itensDoJogo.size();
            item* itemOriginal = itensDoJogo[itemAleatorioIdx];
            item* novoItem = new item(itemOriginal->nome, itemOriginal->descricao, itemOriginal->tipo);
            novoItem->atributo = itemOriginal->atributo;
            jogador->inventario.push_back(novoItem);
            cout << "Voce encontrou um item: " << novoItem->nome << "!" << endl;
        }
    } else {
        cout << "FALHA LOGICA. O recurso foi mal gerenciado. A ineficiencia custou-nos problemas...Resposta correta: " << p.resposta << endl;
        cout << "Voce perdeu 25 de vida!" << endl;
        jogador->vida -= 25;
    }
    return true;
}

void usarItem(personagem* jogador) {
if (jogador->inventario.empty()) {
        cout << "Inventario vazio." << endl;
        return;
    }

    cout << "\n--- SEU INVENTARIO ---" << endl;
    for (size_t i = 0; i < jogador->inventario.size(); ++i) {
        cout << "[" << i << "] " << jogador->inventario[i]->nome << " - " << jogador->inventario[i]->descricao << endl;
    }
    cout << "Escolha um item para usar (ou -1 para voltar): ";
    int indice;
    cin >> indice;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada invalida." << endl;
        return;
    }

    if (indice < 0 || indice >= static_cast<int>(jogador->inventario.size())) {
        return;
    }

    item* itemEscolhido = jogador->inventario[indice];
    switch (itemEscolhido->tipo) {
        case CURA:
            jogador->vida += itemEscolhido->atributo.pontosCura;
            if (jogador->vida > 100) {
                jogador->vida = 100;
            }
            cout << "Voce usou " << itemEscolhido->nome << " e sua vida agora e " << jogador->vida << "." << endl;
            // Remove o item do inventário e libera a memória
            delete itemEscolhido;
            jogador->inventario.erase(jogador->inventario.begin() + indice);
            break;
        case AJUDA_QUIZ:
            if (perguntasDisponiveis.empty()) {
                cout << "Nao ha mais perguntas para usar este item." << endl;
                return;
            }
            cout << "Voce usou " << itemEscolhido->nome << ". A proxima pergunta tera duas opcoes removidas." << endl;
            fazerPergunta(jogador, true); // Chama a pergunta em modo de ajuda
            // Remove o item e libera a memória
            delete itemEscolhido;
            jogador->inventario.erase(jogador->inventario.begin() + indice);
            break;
    }}

void jogar(personagem* jogador) {
bool gameOn = true;
    string arquivoDeSave = "saves/" + jogador->nome + ".dat";
    perguntasDisponiveis = perguntas;
    
    
    std::random_device rd;
    std::mt19937 g(rd());
    
    shuffle(perguntasDisponiveis.begin(), perguntasDisponiveis.end(), g);

    cout << "\n--- Apocalipse iniciado com " << jogador->nome << "! ---" << endl;

    while (gameOn && jogador->vida > 0) {
        cout << "\nVida: " << jogador->vida << endl;
        cout << "[1] Responder protocolo [2] Usar item [3] Salvar [4] Sair: ";
        string comando;
        cin >> comando;

        if (comando == "1") {
            bool temPergunta = fazerPergunta(jogador, false); // false = sem ajuda
            if (!temPergunta) {
                cout << "\n========================================" << endl;
                cout << "    TODOS OS SISTEMAS ESTAO SEGUROS" << endl;
                cout << "==========================================" << endl;
                cout << "O ultimo comboio chegou. Voce provou que, mesmo no apocalipse, a eficiencia e a arma mais poderosa." << endl;
                cout << "Todas os protocolos foram resolvidos!" << endl;
                cout << "Vida final: " << jogador->vida << endl;
                cout << "========================================" << endl;
                gameOn = false;
            }
        } else if (comando == "2") {
            usarItem(jogador);
        }
        else if (comando == "3") {
            salvarProgresso(jogador, arquivoDeSave);
        } else if (comando == "4") {
            cout << "Deseja salvar antes de sair? (s/n): ";
            char escolha;
            cin >> escolha;
            if (escolha == 's') {
                salvarProgresso(jogador, arquivoDeSave);
            }
            gameOn = false;
        } else {
            cout << "Comando invalido." << endl;
        }
    }
    
    if (jogador->vida <= 0) {
        cout << "\n=======================================================" << endl;
        cout << "  CENARIO CRITICO. A ordem se desfez. O caos se instalou." << endl;
        cout << "=========================================================" << endl;
        cout << "Voce se afogou na ineficiencia. Os piores casos dos algoritmos se tornaram realidade e a base caiu." << endl;
        cout << "GAME OVER" << endl;
    }
}

personagem* criarNovoPersonagem(const string& nome) {
    personagem* novoJogador = new personagem();
    novoJogador->nome = nome;
    novoJogador->vida = 100;
    
    cout << "Personagem '" << nome << "' criado com sucesso!" << endl;
    return novoJogador;
}