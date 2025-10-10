#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "gameLore/estruturas.h"
#include "systems/gerenciador_save.h"

using namespace std;



vector<pergunta> perguntas;
vector<pergunta> perguntasDisponiveis;

void carregarPerguntas() {
    perguntas.clear();
    
    pergunta p1;
    p1.questao = "Qual a complexidade do Bubble Sort?";
    p1.opcaoA = "O(n)";
    p1.opcaoB = "O(n^2)";
    p1.opcaoC = "O(log n)";
    p1.opcaoD = "O(1)";
    p1.resposta = 'B';
    perguntas.push_back(p1);
    
    pergunta p2;
    p2.questao = "Qual estrutura e mais rapida para busca?";
    p2.opcaoA = "Array desordenado";
    p2.opcaoB = "Lista ligada";
    p2.opcaoC = "Hash table";
    p2.opcaoD = "Pilha";
    p2.resposta = 'C';
    perguntas.push_back(p2);
    
    pergunta p3;
    p3.questao = "Qual algoritmo e mais eficiente para ordenacao?";
    p3.opcaoA = "Selection Sort";
    p3.opcaoB = "Quick Sort";
    p3.opcaoC = "Bubble Sort";
    p3.opcaoD = "Insertion Sort";
    p3.resposta = 'B';
    perguntas.push_back(p3);
    
    pergunta p4;
    p4.questao = "Qual a complexidade do Binary Search?";
    p4.opcaoA = "O(n)";
    p4.opcaoB = "O(n^2)";
    p4.opcaoC = "O(log n)";
    p4.opcaoD = "O(1)";
    p4.resposta = 'C';
    perguntas.push_back(p4);
    
    pergunta p5;
    p5.questao = "Qual estrutura usa LIFO?";
    p5.opcaoA = "Fila";
    p5.opcaoB = "Pilha";
    p5.opcaoC = "Lista";
    p5.opcaoD = "Array";
    p5.resposta = 'B';
    perguntas.push_back(p5);
    
    pergunta p6;
    p6.questao = "Qual estrutura usa FIFO?";
    p6.opcaoA = "Pilha";
    p6.opcaoB = "Arvore";
    p6.opcaoC = "Fila";
    p6.opcaoD = "Grafo";
    p6.resposta = 'C';
    perguntas.push_back(p6);
    
    pergunta p7;
    p7.questao = "Qual a complexidade do Merge Sort?";
    p7.opcaoA = "O(n^2)";
    p7.opcaoB = "O(n log n)";
    p7.opcaoC = "O(n)";
    p7.opcaoD = "O(log n)";
    p7.resposta = 'B';
    perguntas.push_back(p7);
    
    pergunta p8;
    p8.questao = "O que e DFS?";
    p8.opcaoA = "Busca em Largura";
    p8.opcaoB = "Busca em Profundidade";
    p8.opcaoC = "Busca Binaria";
    p8.opcaoD = "Busca Linear";
    p8.resposta = 'B';
    perguntas.push_back(p8);
    
    pergunta p9;
    p9.questao = "Qual estrutura permite busca rapida?";
    p9.opcaoA = "Lista ligada";
    p9.opcaoB = "Arvore Binaria de Busca";
    p9.opcaoC = "Fila";
    p9.opcaoD = "Pilha";
    p9.resposta = 'B';
    perguntas.push_back(p9);
    
    pergunta p10;
    p10.questao = "Recursao usa qual estrutura?";
    p10.opcaoA = "Fila";
    p10.opcaoB = "Array";
    p10.opcaoC = "Pilha";
    p10.opcaoD = "Hash";
    p10.resposta = 'C';
    perguntas.push_back(p10);
    
    pergunta p11;
    p11.questao = "Melhor caso do Quick Sort?";
    p11.opcaoA = "O(n^2)";
    p11.opcaoB = "O(n log n)";
    p11.opcaoC = "O(n)";
    p11.opcaoD = "O(1)";
    p11.resposta = 'B';
    perguntas.push_back(p11);
    
    pergunta p12;
    p12.questao = "O que BFS usa para travessia?";
    p12.opcaoA = "Pilha";
    p12.opcaoB = "Fila";
    p12.opcaoC = "Array";
    p12.opcaoD = "Lista";
    p12.resposta = 'B';
    perguntas.push_back(p12);
    
    pergunta p13;
    p13.questao = "Qual e O(1) para insercao?";
    p13.opcaoA = "Array ordenado";
    p13.opcaoB = "Lista ligada no inicio";
    p13.opcaoC = "Arvore";
    p13.opcaoD = "Heap";
    p13.resposta = 'B';
    perguntas.push_back(p13);
    
    pergunta p14;
    p14.questao = "Pior caso do Bubble Sort?";
    p14.opcaoA = "O(n)";
    p14.opcaoB = "O(log n)";
    p14.opcaoC = "O(n^2)";
    p14.opcaoD = "O(n log n)";
    p14.resposta = 'C';
    perguntas.push_back(p14);
    
    pergunta p15;
    p15.questao = "Grafo acilico e conectado?";
    p15.opcaoA = "Arvore";
    p15.opcaoB = "Lista";
    p15.opcaoC = "Fila";
    p15.opcaoD = "Pilha";
    p15.resposta = 'A';
    perguntas.push_back(p15);
}

bool fazerPergunta(personagem& jogador) {
    if (perguntasDisponiveis.empty()) {
        return false;
    }
    
    int indice = rand() % perguntasDisponiveis.size();
    pergunta p = perguntasDisponiveis[indice];
    perguntasDisponiveis.erase(perguntasDisponiveis.begin() + indice);
    
    cout << "\n=== PERGUNTA ===" << endl;
    cout << "Perguntas restantes: " << perguntasDisponiveis.size() + 1 << endl;
    cout << p.questao << endl;
    cout << "A) " << p.opcaoA << endl;
    cout << "B) " << p.opcaoB << endl;
    cout << "C) " << p.opcaoC << endl;
    cout << "D) " << p.opcaoD << endl;
    cout << "Sua resposta: ";
    
    char resposta;
    cin >> resposta;
    
    if (toupper(resposta) == toupper(p.resposta)) {
        cout << "Correto! +10 de vida!" << endl;
        jogador.vida += 10;
    } else {
        cout << "Errado! Resposta correta: " << p.resposta << endl;
        cout << "Voce perdeu 50 de vida!" << endl;
        jogador.vida -= 50;
    }
    
    return true;
}

void jogar(personagem& jogador) {
    bool gameOn = true;
    string arquivoDeSave = "saves/" + jogador.nome + ".dat";
    perguntasDisponiveis = perguntas;

    cout << "\n--- Quiz de Algoritmos iniciado com " << jogador.nome << "! ---" << endl;

    while (gameOn && jogador.vida > 0) {
        cout << "\nVida: " << jogador.vida << endl;
        cout << "[1] Responder pergunta [2] Salvar [3] Sair: ";
        string comando;
        cin >> comando;

        if (comando == "1") {
            bool temPergunta = fazerPergunta(jogador);
            if (!temPergunta) {
                cout << "\n========================================" << endl;
                cout << "    PARABENS! VOCE VENCEU O QUIZ!" << endl;
                cout << "========================================" << endl;
                cout << "Todas as perguntas foram respondidas!" << endl;
                cout << "Vida final: " << jogador.vida << endl;
                cout << "========================================" << endl;
                gameOn = false;
            }
        } else if (comando == "2") {
            salvarProgresso(jogador, arquivoDeSave);
        } else if (comando == "3") {
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
    
    if (jogador.vida <= 0) {
        cout << "\n========================================" << endl;
        cout << "         GAME OVER!" << endl;
        cout << "========================================" << endl;
        cout << "Sua vida chegou a zero!" << endl;
        cout << "========================================" << endl;
    }
}

int main() {
    srand(time(0));
    carregarPerguntas();
    
    while (true) {
        cout << "\n===== QUIZ DE ALGORITMOS =====" << endl;
        cout << "[1] Novo Jogo" << endl;
        cout << "[2] Carregar Jogo" << endl;
        cout << "[3] Sair" << endl;
        cout << "Escolha uma opcao: ";

        int escolha;
        cin >> escolha;

        if (escolha == 1) {
            cout << "Digite o nome do seu personagem: ";
            string nome;
            cin >> nome;

            string caminhoDoArquivo = "saves/" + nome + ".dat";
            ifstream arquivoExistente(caminhoDoArquivo);
            if (arquivoExistente.good()) {
                cout << "Ja existe um save com esse nome. Deseja sobrescrever? (s/n): ";
                char overwrite;
                cin >> overwrite;
                if (overwrite != 's') {
                    continue;
                }
            }

            personagem novoPersonagem;
            novoPersonagem.nome = nome;
            novoPersonagem.vida = 100;
            
            jogar(novoPersonagem);

        } else if (escolha == 2) {
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

        } else if (escolha == 3) {
            cout << "Ate a proxima!" << endl;
            break;
        } else {
            cout << "Opcao invalida. Tente novamente." << endl;
        }
    }

    return 0;
}