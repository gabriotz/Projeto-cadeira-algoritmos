#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <string>
#include "../gameLore/estruturas.h"

// Funções principais do jogo
void jogar(personagem* jogador);
void menuPrincipal();

// Funções de exploração
void explorarArea(personagem* jogador, area* area);
void combate(personagem* jogador, int dificuldade);
void encontrarTesouro(personagem* jogador, area* area);

// Funções de gerenciamento de personagem
void subirNivel(personagem* jogador);
void usarItem(personagem* jogador, int indice);
void mostrarStatusCompleto(const personagem* jogador);

// Funções de criação de personagem
personagem* criarNovoPersonagem(const std::string& nome);
void personalizarPersonagem(personagem* jogador);

// Funções de loja (futuro)
void abrirLoja(personagem* jogador);

#endif
