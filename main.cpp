#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <limits>

#include "gameLore/estruturas.h"
#include "systems/gerenciador_save.h"
#include "gameLore/banco_perguntas.h"
#include "gameLore/itens.h"
#include "systems/gameplay.h"

using namespace std;

// Definição das variáveis globais
vector<item*> itensDoJogo;
vector<pergunta> perguntas;
vector<pergunta> perguntasDisponiveis;

int main() {
    srand(time(0));
    carregarPerguntas(perguntas);
    inicializarItens(itensDoJogo); 
    
    while (true) {
        cout << "\n===== O apocalipse comecou. A jornada, agora. =====" << endl;
        cout << "[1] Novo Jogo" << endl;
        cout << "[2] Carregar Jogo" << endl;
        cout << "[3] Sair" << endl;
        cout << "Escolha uma opcao: ";

        int escolha;
        cin >> escolha;

        if (cin.fail()) {
            cout << "Opcao invalida. Por favor, insira um numero." << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (escolha == 1) {
            cout << "Digite o nome do seu personagem: ";
            string nome;
            cin >> nome;

            if (verificarSaveExistente(nome)) {
                cout << "Ja existe um save com esse nome. Deseja sobrescrever? (s/n): ";
                char overwrite;
                cin >> overwrite;
                if (overwrite != 's') {
                    continue;
                }
            }
            
            personagem* novoPersonagem = criarNovoPersonagem(nome);
            jogar(novoPersonagem);
            
            delete novoPersonagem;

        } else if (escolha == 2) {
            vector<string> saves = listarSaves();
            if (saves.empty()) {
                cout << "Nenhum jogo salvo encontrado." << endl;
                continue;
            }

            cout << "\n--- JOGOS SALVOS ---" << endl;
            for (size_t i = 0; i < saves.size(); ++i) {
                cout << "[" << i + 1 << "] " << saves[i] << endl;
            }
            cout << "Escolha qual personagem carregar: ";
            int saveEscolhido;
            cin >> saveEscolhido;

            if (cin.fail()) {
                cout << "Opcao invalida. Por favor, insira um numero." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (saveEscolhido > 0 && saveEscolhido <= static_cast<int>(saves.size())) {
                string nomeDoPersonagem = saves[saveEscolhido - 1];
                personagem* personagemCarregado = nullptr;
                
                if (carregarProgresso(&personagemCarregado, "saves/" + nomeDoPersonagem + ".dat")) {
                    jogar(personagemCarregado);
                    delete personagemCarregado;
                }
            } else {
                cout << "Escolha invalida." << endl;
            }

        } else if (escolha == 3) {
            cout << "A base esta segura..." << endl;
            cout << "Por enquanto..." << endl;
            break;
        } else {
            cout << "Opcao invalida. Tente novamente." << endl;
        }
    }
    
    limparItens(itensDoJogo);

    return 0;
}