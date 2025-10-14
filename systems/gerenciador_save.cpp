#define _HAS_STD_BYTE 0

#ifdef _WIN32
    #include <windows.h>
#else
    #include <dirent.h>
#endif

#include "gerenciador_save.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <sys/stat.h>
#include <direct.h>
void salvarProgresso(const personagem* jogador, const std::string& caminhoArquivo) {
    if (!jogador) return;

    std::string caminhoDaPasta = "saves";

    struct stat info;
    if (stat(caminhoDaPasta.c_str(), &info) != 0) {
        _mkdir(caminhoDaPasta.c_str());
        std::cout << "Pasta 'saves' criada." << std::endl;
    }

    std::ofstream arquivo(caminhoArquivo);

    if (!arquivo.is_open()) {
        std::cerr << "Erro: Nao foi possivel criar o arquivo de save em " << caminhoArquivo << std::endl;
        return;
    }

    arquivo << jogador->nome << std::endl;
    arquivo << jogador->vida << std::endl;
    arquivo << jogador->inventario.size() << std::endl;

    for (const item* itemPtr : jogador->inventario) {
        arquivo << itemPtr->nome << std::endl;
        arquivo << itemPtr->descricao << std::endl;
        arquivo << static_cast<int>(itemPtr->tipo) << std::endl;
        if (itemPtr->tipo == CURA) {
            arquivo << itemPtr->atributo.pontosCura << std::endl;
        }
    }

    arquivo.close();
    std::cout << "Jogo salvo com sucesso!" << std::endl;
}

bool carregarProgresso(personagem** jogador, const std::string& caminhoArquivo) {
    std::ifstream arquivo(caminhoArquivo);

    if (!arquivo.is_open()) {
        std::cerr << "Erro: Nao foi possivel encontrar o arquivo de save em " << caminhoArquivo << std::endl;
        return false;
    }

    // Aloca um novo personagem
    *jogador = new personagem();

    std::getline(arquivo, (*jogador)->nome);
    arquivo >> (*jogador)->vida;

    int numItens;
    arquivo >> numItens;

    arquivo.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    (*jogador)->inventario.clear();

    for (int i = 0; i < numItens; ++i) {
        string nome, descricao;
        int tipoInt;

        std::getline(arquivo, nome);
        std::getline(arquivo, descricao);
        arquivo >> tipoInt;
        arquivo.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        TipoItem tipo = static_cast<TipoItem>(tipoInt);
        item* itemCarregado = new item(nome, descricao, tipo);

        if (tipo == CURA) {
            arquivo >> itemCarregado->atributo.pontosCura;
            arquivo.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (tipo == AJUDA_QUIZ) {
            itemCarregado->atributo.metadeDasOpcoes = true;
        }
        (*jogador)->inventario.push_back(itemCarregado);
    }

    arquivo.close();
    std::cout << "Jogo carregado com sucesso!" << std::endl;
    return true;
}

std::vector<std::string> listarSaves() {
    std::vector<std::string> nomesDosSaves;
    std::string caminhoDaPasta = "saves";

    struct stat info;
    if (stat(caminhoDaPasta.c_str(), &info) != 0) {
        _mkdir(caminhoDaPasta.c_str());
        std::cout << "Pasta 'saves' criada." << std::endl;
    }

    #ifdef _WIN32
    WIN32_FIND_DATA findData;
    HANDLE hFind = FindFirstFile("saves\\*.dat", &findData);
    
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            std::string nomeArquivo = findData.cFileName;
            if (nomeArquivo.length() > 4) {
                nomeArquivo = nomeArquivo.substr(0, nomeArquivo.length() - 4);
                nomesDosSaves.push_back(nomeArquivo);
            }
        } while (FindNextFile(hFind, &findData) != 0);
        FindClose(hFind);
    }
    #endif

    return nomesDosSaves;
}

bool verificarSaveExistente(const std::string& nome) {
    string caminhoArquivo = "saves/" + nome + ".dat";
    ifstream arquivo(caminhoArquivo);
    return arquivo.good();
}