#include "gameplay.h"
#include "gerenciador_save.h"
#include "../gameLore/config.h"
#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

void jogar(personagem* jogador) {
    if (!jogador) return;

    bool gameOn = true;
    string arquivoDeSave = "saves/" + jogador->nome + ".dat";

    cout << "\n--- Jogo iniciado com " << jogador->nome << "! ---" << endl;
    logEvento("Jogo iniciado para: " + jogador->nome);

    while (gameOn) {
        cout << "\nO que voce deseja fazer?" << endl;
        cout << "[1] Explorar" << endl;
        cout << "[2] Status" << endl;
        cout << "[3] Inventário" << endl;
        cout << "[4] Salvar" << endl;
        cout << "[5] Sair" << endl;
        cout << "Escolha: ";

        int escolha;
        cin >> escolha;

        switch (escolha) {
            case 1: {
                // Selecionar área para explorar
                cout << "\n=== ÁREAS DISPONÍVEIS ===" << endl;
                for (size_t i = 0; i < areasDisponiveis.size(); ++i) {
                    cout << "[" << i + 1 << "] " << areasDisponiveis[i]->nome;
                    cout << " (Dificuldade: " << areasDisponiveis[i]->dificuldade << ")";
                    if (areasDisponiveis[i]->explorada) {
                        cout << " [EXPLORADA]";
                    }
                    cout << endl;
                }
                cout << "Escolha uma área (0 para voltar): ";
                int areaEscolhida;
                cin >> areaEscolhida;
                
                if (areaEscolhida > 0 && areaEscolhida <= static_cast<int>(areasDisponiveis.size())) {
                    explorarArea(jogador, areasDisponiveis[areaEscolhida - 1]);
                }
                break;
            }
            case 2:
                mostrarStatusCompleto(jogador);
                break;
            case 3:
                mostrarInventario(jogador);
                break;
            case 4:
                salvarProgresso(jogador, arquivoDeSave);
                break;
            case 5:
                cout << "Deseja salvar antes de sair? (s/n): ";
                char escolhaSalvar;
                cin >> escolhaSalvar;
                if (escolhaSalvar == 's') {
                    salvarProgresso(jogador, arquivoDeSave);
                }
                gameOn = false;
                break;
            default:
                cout << "Opção inválida." << endl;
        }
    }
}

void explorarArea(personagem* jogador, area* area) {
    if (!jogador || !area) return;

    cout << "\n=== EXPLORANDO: " << area->nome << " ===" << endl;
    cout << area->descricao << endl;

    // Chance de combate baseada na dificuldade
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10);
    
    int chanceCombate = area->dificuldade * 2;
    if (dis(gen) <= chanceCombate) {
        cout << "\nVocê encontrou inimigos!" << endl;
        combate(jogador, area->dificuldade);
    } else {
        cout << "\nA área está calma..." << endl;
    }

    // Chance de encontrar tesouro
    if (dis(gen) <= 3) {
        encontrarTesouro(jogador, area);
    }

    area->explorada = true;
    jogador->stats.experiencia += area->dificuldade * 10;
    
    // Verifica se pode subir de nível
    if (jogador->stats.experiencia >= EXPERIENCIA_POR_NIVEL) {
        subirNivel(jogador);
    }

    logEvento("Área explorada: " + area->nome + " por " + jogador->nome);
}

void combate(personagem* jogador, int dificuldade) {
    if (!jogador) return;

    int vidaInimigo = dificuldade * 20;
    int danoInimigo = dificuldade * 5;

    cout << "\n=== COMBATE ===" << endl;
    cout << "Inimigo com " << vidaInimigo << " de vida!" << endl;

    while (jogador->vida > 0 && vidaInimigo > 0) {
        cout << "\nSua vida: " << jogador->vida << " | Vida do inimigo: " << vidaInimigo << endl;
        cout << "[1] Atacar [2] Usar item [3] Fugir: ";
        
        int escolha;
        cin >> escolha;

        switch (escolha) {
            case 1: {
                // Calcula dano do jogador
                int danoJogador = calcularDano(*jogador, *jogador->inventario[0]);
                if (!jogador->inventario.empty()) {
                    for (const item* itemPtr : jogador->inventario) {
                        if (itemPtr && itemPtr->tipo == ARMA) {
                            danoJogador = calcularDano(*jogador, *itemPtr);
                            break;
                        }
                    }
                }
                
                vidaInimigo -= danoJogador;
                cout << "Você causou " << danoJogador << " de dano!" << endl;
                break;
            }
            case 2:
                mostrarInventario(jogador);
                cout << "Escolha um item para usar (índice): ";
                int indiceItem;
                cin >> indiceItem;
                usarItem(jogador, indiceItem);
                continue;
            case 3:
                cout << "Você fugiu do combate!" << endl;
                jogador->vida -= danoInimigo / 2; // Dano reduzido por fugir
                return;
        }

        // Ataque do inimigo
        if (vidaInimigo > 0) {
            jogador->vida -= danoInimigo;
            cout << "O inimigo causou " << danoInimigo << " de dano!" << endl;
        }
    }

    if (jogador->vida > 0) {
        cout << "\nVocê venceu o combate!" << endl;
        jogador->stats.experiencia += dificuldade * 15;
        jogador->ouro += dificuldade * 10;
        logEvento("Combate vencido por " + jogador->nome);
    } else {
        cout << "\nVocê foi derrotado!" << endl;
        jogador->vida = 1; // Não morre completamente
        logEvento("Combate perdido por " + jogador->nome);
    }
}

void encontrarTesouro(personagem* jogador, area* area) {
    if (!jogador || !area || !area->recompensa) return;

    cout << "\nVocê encontrou um tesouro!" << endl;
    cout << "Item encontrado: " << area->recompensa->nome << endl;

    // Cria uma cópia do item para o inventário
    item* novoItem = new item(*area->recompensa);
    adicionarItemInventario(jogador, novoItem);

    // Adiciona ouro extra
    int ouroExtra = area->dificuldade * 5;
    jogador->ouro += ouroExtra;
    cout << "Você também encontrou " << ouroExtra << " ouros!" << endl;

    logEvento("Tesouro encontrado por " + jogador->nome + ": " + area->recompensa->nome);
}

void subirNivel(personagem* jogador) {
    if (!jogador) return;

    jogador->stats.nivel++;
    jogador->stats.experiencia -= EXPERIENCIA_POR_NIVEL;
    jogador->vidaMaxima += 20;
    jogador->vida = jogador->vidaMaxima; // Cura ao subir de nível

    cout << "\n*** PARABÉNS! ***" << endl;
    cout << "Você subiu para o nível " << jogador->stats.nivel << "!" << endl;
    cout << "Vida máxima aumentou para " << jogador->vidaMaxima << "!" << endl;

    logEvento(jogador->nome + " subiu para o nível " + to_string(jogador->stats.nivel));
}

void usarItem(personagem* jogador, int indice) {
    if (!jogador || indice < 0 || indice >= static_cast<int>(jogador->inventario.size())) {
        cout << "Índice inválido!" << endl;
        return;
    }

    item* itemPtr = jogador->inventario[indice];
    if (!itemPtr) return;

    switch (itemPtr->tipo) {
        case CONSUMIVEL:
            jogador->vida += itemPtr->atributo.cura;
            if (jogador->vida > jogador->vidaMaxima) {
                jogador->vida = jogador->vidaMaxima;
            }
            cout << "Você se curou em " << itemPtr->atributo.cura << " pontos!" << endl;
            cout << "Vida atual: " << jogador->vida << "/" << jogador->vidaMaxima << endl;
            
            // Remove o item do inventário
            removerItemInventario(jogador, indice);
            break;
        case QUEST:
            cout << "Item de quest usado: " << itemPtr->nome << endl;
            itemPtr->atributo.questAtiva = true;
            break;
        default:
            cout << "Este item não pode ser usado diretamente." << endl;
    }
}

void mostrarStatusCompleto(const personagem* jogador) {
    if (!jogador) return;

    mostrarEstatisticas(*jogador);
    cout << "\n=== INVENTÁRIO ===" << endl;
    if (jogador->inventario.empty()) {
        cout << "Inventário vazio." << endl;
    } else {
        cout << "Total de itens: " << jogador->inventario.size() << endl;
    }
}

personagem* criarNovoPersonagem(const string& nome) {
    personagem* novoJogador = new personagem(nome);
    
    // Adiciona item inicial
    item* itemInicial = new item("Espada de Madeira", ARMA, 10);
    itemInicial->atributo.dano = 5;
    novoJogador->inventario.push_back(itemInicial);

    // Adiciona poção de cura
    item* pocao = new item("Poção de Cura", CONSUMIVEL, 5);
    pocao->atributo.cura = 25;
    novoJogador->inventario.push_back(pocao);

    cout << "Personagem '" << nome << "' criado com sucesso!" << endl;
    logEvento("Novo personagem criado: " + nome);
    
    return novoJogador;
}

void personalizarPersonagem(personagem* jogador) {
    if (!jogador) return;

    cout << "\n=== PERSONALIZAÇÃO ===" << endl;
    cout << "Distribua 10 pontos entre suas características:" << endl;
    
    int pontosRestantes = 10;
    int forcaExtra = 0, agilidadeExtra = 0, inteligenciaExtra = 0;

    while (pontosRestantes > 0) {
        cout << "Pontos restantes: " << pontosRestantes << endl;
        cout << "[1] Força (+1) [2] Agilidade (+1) [3] Inteligência (+1): ";
        
        int escolha;
        cin >> escolha;
        
        switch (escolha) {
            case 1:
                forcaExtra++;
                pontosRestantes--;
                break;
            case 2:
                agilidadeExtra++;
                pontosRestantes--;
                break;
            case 3:
                inteligenciaExtra++;
                pontosRestantes--;
                break;
            default:
                cout << "Opção inválida!" << endl;
        }
    }

    jogador->stats.forca += forcaExtra;
    jogador->stats.agilidade += agilidadeExtra;
    jogador->stats.inteligencia += inteligenciaExtra;

    cout << "Personalização concluída!" << endl;
    mostrarEstatisticas(*jogador);
}

void menuPrincipal() {
    while (true) {
        cout << "\n===== MENU PRINCIPAL =====" << endl;
        cout << "[1] Novo Jogo" << endl;
        cout << "[2] Carregar Jogo" << endl;
        cout << "[3] Sair" << endl;
        cout << "Escolha uma opcao: ";

        int escolha;
        cin >> escolha;

        switch (escolha) {
            case 1: {
                cout << "Digite o nome do seu novo personagem: ";
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
                personalizarPersonagem(novoPersonagem);
                jogar(novoPersonagem);
                
                // Libera memória ao sair do jogo
                delete novoPersonagem;
                break;
            }
            case 2: {
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

                if (saveEscolhido > 0 && saveEscolhido <= static_cast<int>(saves.size())) {
                    string nomeDoPersonagem = saves[saveEscolhido - 1];
                    personagem* personagemCarregado = nullptr;
                    
                    if (carregarProgresso(personagemCarregado, "saves/" + nomeDoPersonagem + ".dat")) {
                        jogar(personagemCarregado);
                        delete personagemCarregado; // Libera memória
                    }
                } else {
                    cout << "Escolha invalida." << endl;
                }
                break;
            }
            case 3:
                cout << "Ate a proxima!" << endl;
                return;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }
    }
}
