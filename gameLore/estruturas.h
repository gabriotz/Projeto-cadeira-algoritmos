#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#include <string>
#include <vector>

using namespace std;

// Enum para identificar o tipo de item
enum TipoItem {
    CURA,
    AJUDA_QUIZ
};

// Union para os atributos dos itens
union AtributoItem {
    int pontosCura;
    bool metadeDasOpcoes; // Apenas para identificar o tipo de ajuda
};

struct item {
    string nome;
    string descricao;
    TipoItem tipo;
    AtributoItem atributo;

    // Construtor para facilitar a criação de itens
    item(string n, string desc, TipoItem t) : nome(n), descricao(desc), tipo(t) {}
};

struct personagem {
    int vida;
    string nome;
    vector<item*> inventario; // Agora armazena ponteiros para itens

    // Destrutor para liberar a memória dos itens no inventário
    ~personagem() {
        for (item* it : inventario) {
            delete it;
        }
        inventario.clear();
    }
};

struct pergunta {
    string questao;
    string opcaoA;
    string opcaoB;
    string opcaoC;
    string opcaoD;
    char resposta;

    vector<int> dadosTeste;
};

struct Aresta {
    int origem, destino, peso;
};

struct Subconjunto {
    int pai;
    int rank;
};

#endif