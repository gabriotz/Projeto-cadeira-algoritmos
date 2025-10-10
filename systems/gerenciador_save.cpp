
#include "gerenciador_save.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <filesystem> 

void salvarProgresso(const personagem& jogador, const std::string& caminhoArquivo) {
    // cria a pasta dos saves
    std::string caminhoDaPasta = "saves";

    // Checa se a pasta 'saves' existe
    if (!std::filesystem::exists(caminhoDaPasta)) {
        std::filesystem::create_directory(caminhoDaPasta); // Cria a pasta se não existir
        std::cout << "Pasta 'saves' criada." << std::endl;
    }

    // ofstream significa "output file stream" - para escrever em arquivos
    std::ofstream arquivo(caminhoArquivo);

    if (!arquivo.is_open()) {
        std::cerr << "Erro: Nao foi possivel criar o arquivo de save em " << caminhoArquivo << std::endl;
        return;
    }

    // 1. Escreve os dados do personagem
    arquivo << jogador.nome << std::endl;
    arquivo << jogador.vida << std::endl;

    // 2. Escreve o número de itens (muito importante para o carregamento)
    arquivo << jogador.inventario.size() << std::endl;

    // 3. Escreve cada item do inventário
    for (const item& item : jogador.inventario) {
        arquivo << item.nome << std::endl;
        arquivo << item.atributo << std::endl;
    }

    arquivo.close();
    std::cout << "Jogo salvo com sucesso!" << std::endl;
}

bool carregarProgresso(personagem& jogador, const std::string& caminhoArquivo) {
    // ifstream significa "input file stream" - para ler de arquivos
    std::ifstream arquivo(caminhoArquivo);

    if (!arquivo.is_open()) {
        std::cerr << "Erro: Nao foi possivel encontrar o arquivo de save em " << caminhoArquivo << std::endl;
        return false;
    }

    // 1. Lê os dados do personagem
    std::getline(arquivo, jogador.nome);
    arquivo >> jogador.vida;

    // 2. Lê o número de itens
    int numItens;
    arquivo >> numItens;

    // !!! IMPORTANTE: Consumir a quebra de linha que sobrou depois de ler um número
    arquivo.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // 3. Limpa o inventário atual antes de carregar o novo
    jogador.inventario.clear();

    // 4. Lê cada item do arquivo e adiciona ao inventário
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

    // Checa se a pasta 'saves' existe
    if (!std::filesystem::exists(caminhoDaPasta)) {
        std::filesystem::create_directory(caminhoDaPasta); // Cria a pasta se não existir
        std::cout << "Pasta 'saves' criada." << std::endl;
    }

    // Itera por todos os arquivos dentro da pasta "saves"
    for (const auto& entry : std::filesystem::directory_iterator(caminhoDaPasta)) {
        // Pega o caminho do arquivo
        std::string caminhoDoArquivo = entry.path().string();
        
        // Checa se o arquivo tem a extensão ".dat"
        if (entry.is_regular_file() && entry.path().extension() == ".dat") {
            // Extrai apenas o nome do arquivo, sem a extensão
            std::string nomeDoPersonagem = entry.path().stem().string();
            nomesDosSaves.push_back(nomeDoPersonagem);
        }
    }

    return nomesDosSaves;
}