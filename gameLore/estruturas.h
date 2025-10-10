#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#include <string>
#include <vector> 

using namespace std;

struct item {
    string nome;
    string atributo; 
};

struct personagem {
    int vida;
    string nome;
    
    vector<item> inventario; 
};

#endif 