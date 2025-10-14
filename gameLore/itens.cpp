#include "itens.h"

void inicializarItens(std::vector<item*>& itensDoJogo) {
    limparItens(itensDoJogo);

    item* itemCura = new item("Kit de Primeiros Socorros", "Recupera 25 de vida.", CURA);
    itemCura->atributo.pontosCura = 25;
    itensDoJogo.push_back(itemCura);

    item* itemAjuda = new item("Analisador Logico", "Remove metade das opcoes de uma pergunta.", AJUDA_QUIZ);
    itemAjuda->atributo.metadeDasOpcoes = true;
    itensDoJogo.push_back(itemAjuda);
}

void limparItens(std::vector<item*>& itensDoJogo) {
    for (item* it : itensDoJogo) {
        delete it;
    }
    itensDoJogo.clear();
}