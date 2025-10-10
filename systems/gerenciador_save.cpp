#include "gerenciador_save.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <sys/stat.h>
#include <direct.h>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <dirent.h>
#endif

void salvarProgresso(const personagem& jogador, const std::string& caminhoArquivo) {
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

    arquivo << jogador.nome << std::endl;
    arquivo << jogador.vida << std::endl;
    arquivo << jogador.inventario.size() << std::endl;

    for (const item& item : jogador.inventario) {
        arquivo << item.nome << std::endl;
        arquivo << item.atributo << std::endl;
    }

    arquivo.close();
    std::cout << "Jogo salvo com sucesso!" << std::endl;
}

bool carregarProgresso(personagem& jogador, const std::string& caminhoArquivo) {
    std::ifstream arquivo(caminhoArquivo);

    if (!arquivo.is_open()) {
        std::cerr << "Erro: Nao foi possivel encontrar o arquivo de save em " << caminhoArquivo << std::endl;
        return false;
    }

    std::getline(arquivo, jogador.nome);
    arquivo >> jogador.vida;

    int numItens;
    arquivo >> numItens;

    arquivo.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    jogador.inventario.clear();

    for (int i = 0; i < numItens; ++i) {
        item itemCarregado;
        std::getline(arquivo, itemCarregado.nome);
        std::getline(arquivo, itemCarregado.atributo);
        jogador.inventario.push_back(itemCarregado);
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