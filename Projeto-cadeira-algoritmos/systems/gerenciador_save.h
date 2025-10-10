#ifndef GERENCIADOR_SAVE_H
#define GERENCIADOR_SAVE_H

#include <string>
#include <vector> 
#include "../gameLore/estruturas.h"

void salvarProgresso(const personagem& jogador, const std::string& caminhoArquivo);
bool carregarProgresso(personagem& jogador, const std::string& caminhoArquivo);
std::vector<std::string> listarSaves();

#endif