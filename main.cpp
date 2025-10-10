#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "gameLore/estruturas.h"
#include "systems/gerenciador_save.h"

using namespace std;

void jogar(personagem& jogador) {
    bool gameOn = true;
    string arquivoDeSave = "saves/" + jogador.nome + ".dat"; // Define o nome do arquivo de save

    cout << "\n--- Jogo iniciado com " << jogador.nome << "! ---" << endl;

    while (gameOn) {
        cout << "\nO que voce deseja fazer? (explorar, status, salvar, sair): ";
        string comando;
        cin >> comando;

        if (comando == "salvar") {
            salvarProgresso(jogador, arquivoDeSave);
        } else if (comando == "explorar") {
            cout << "Voce explora as ruinas e o tempo passa..." << endl;
            jogador.vida -= 5;
            cout << "Sua vida agora e: " << jogador.vida << endl;
        } else if (comando == "status") {
            cout << "--- Status de " << jogador.nome << " ---" << endl;
            cout << "Vida: " << jogador.vida << endl;
            cout << "Itens: " << jogador.inventario.size() << endl;
        } else if (comando == "sair") {
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
}

int main() {
    while (true) {
        cout << "\n===== MENU PRINCIPAL =====" << endl;
        cout << "[1] Novo Jogo" << endl;
        cout << "[2] Carregar Jogo" << endl;
        cout << "[3] Sair" << endl;
        cout << "Escolha uma opcao: ";

        int escolha;
        cin >> escolha;

        if (escolha == 1) { // NOVO JOGO
            cout << "Digite o nome do seu novo personagem: ";
            string nome;
            cin >> nome;

            string caminhoDoArquivo = "saves/" + nome + ".dat";
            ifstream arquivoExistente(caminhoDoArquivo);
            if (arquivoExistente.good()) {
                cout << "Ja existe um save com esse nome. Deseja sobrescrever? (s/n): ";
                char overwrite;
                cin >> overwrite;
                if (overwrite != 's') {
                    continue; // Volta para o menu principal
                }
            }

            personagem novoPersonagem;
            novoPersonagem.nome = nome;
            novoPersonagem.vida = 100;
            novoPersonagem.inventario.push_back({"Lanterna Velha", "Ilumina um pouco"});
            
            jogar(novoPersonagem);

        } else if (escolha == 2) { // CARREGAR JOGO
            vector<string> saves = listarSaves();
            if (saves.empty()) {
                cout << "Nenhum jogo salvo encontrado." << endl;
                continue;
            }

            cout << "\n--- JOGOS SALVOS ---" << endl;
            for (int i = 0; i < saves.size(); ++i) {
                cout << "[" << i + 1 << "] " << saves[i] << endl;
            }
            cout << "Escolha qual personagem carregar: ";
            int saveEscolhido;
            cin >> saveEscolhido;

            if (saveEscolhido > 0 && saveEscolhido <= saves.size()) {
                string nomeDoPersonagem = saves[saveEscolhido - 1];
                personagem personagemCarregado;
                if (carregarProgresso(personagemCarregado, "saves/" + nomeDoPersonagem + ".dat")) {
                    jogar(personagemCarregado);
                }
            } else {
                cout << "Escolha invalida." << endl;
            }

        } else if (escolha == 3) { // SAIR
            cout << "Ate a proxima!" << endl;
            break;
        } else {
            cout << "Opcao invalida. Tente novamente." << endl;
        }
    }

    return 0;
}