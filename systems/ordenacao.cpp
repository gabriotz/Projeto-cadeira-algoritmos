#include "ordenacao.h"
#include "../gameLore/estruturas.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <climits>

using namespace std;

// --- FUNÇÃO AUXILIAR DE VISUALIZAÇÃO ---
void printArray(const vector<int>& arr, int destaque1, int destaque2) {
    // \r volta ao inicio. Adicionamos espaços extras para limpar lixo de memoria visual anterior
    cout << "\r                                                                  "; 
    cout << "\r[ ";
    for (size_t i = 0; i < arr.size(); ++i) {
        if (i == destaque1 || i == destaque2) {
            // Mostra os números sendo comparados/movidos com destaque >>X<<
            cout << ">>" << arr[i] << "<< "; 
        } else {
            cout << arr[i] << " ";
        }
    }
    cout << "]"; 
    cout << flush; // Força a exibição imediata
    
    this_thread::sleep_for(chrono::milliseconds(500)); 
}

// 1. BUBBLE SORT
void animacaoBubble(vector<int> arr) {
    cout << endl << ">>> INICIANDO BUBBLE SORT <<<" << endl;
    cout << "Objetivo: Flutuar o maior elemento para o final." << endl;
    this_thread::sleep_for(chrono::seconds(1));

    for (size_t i = 0; i < arr.size() - 1; i++) {
        for (size_t j = 0; j < arr.size() - i - 1; j++) {
            printArray(arr, j, j + 1); 
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                printArray(arr, j, j + 1); // Mostra a troca
            }
        }
    }
    // Mostra o array final limpo e quebra a linha para não sumir
    cout << "\r[ ";
    for(int n : arr) cout << n << " ";
    cout << "] -> ORDENADO!" << endl << endl;
}

// 2. INSERTION SORT
void animacaoInsertion(vector<int> arr) {
    cout << endl << ">>> INICIANDO INSERTION SORT <<<" << endl;
    cout << "Objetivo: Inserir cada numero na posicao correta a esquerda." << endl;
    this_thread::sleep_for(chrono::seconds(1));

    printArray(arr, -1, -1); // Mostra estado inicial

    for (size_t i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Visualização extra para saber quem estamos movendo
        cout << "  (Movendo o " << key << "...)"; 
        
        while (j >= 0 && arr[j] > key) {
            printArray(arr, j, j+1); 
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        printArray(arr, j + 1); 
    }
    
    cout << "\r[ ";
    for(int n : arr) cout << n << " ";
    cout << "] -> ORDENADO!" << endl << endl;
}

// 3. SELECTION SORT
void animacaoSelection(vector<int> arr) {
    cout << endl << ">>> INICIANDO SELECTION SORT <<<" << endl;
    this_thread::sleep_for(chrono::seconds(1));

    for (size_t i = 0; i < arr.size() - 1; i++) {
        int min_idx = i;
        for (size_t j = i + 1; j < arr.size(); j++) {
            printArray(arr, min_idx, j); 
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(arr[min_idx], arr[i]);
        printArray(arr, i); 
    }
    
    cout << "\r[ ";
    for(int n : arr) cout << n << " ";
    cout << "] -> ORDENADO!" << endl << endl;
}

// 4. QUICK SORT
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        printArray(arr, j, high); // Compara com pivo
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            printArray(arr, i, j); // Troca
        }
    }
    swap(arr[i + 1], arr[high]);
    printArray(arr, i + 1, high);
    return (i + 1);
}

void animacaoQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        animacaoQuickSort(arr, low, pi - 1);
        animacaoQuickSort(arr, pi + 1, high);
    }
}

// 5. MERGE SORT
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        printArray(arr, k); 
        if (L[i] <= R[j]) { arr[k] = L[i]; i++; } 
        else { arr[k] = R[j]; j++; }
        k++;
    }
    while (i < n1) { arr[k] = L[i]; i++; k++; printArray(arr, k); }
    while (j < n2) { arr[k] = R[j]; j++; k++; printArray(arr, k); }
}

void animacaoMergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        animacaoMergeSort(arr, left, mid);
        animacaoMergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void animacaoBuscaBinaria(vector<int> arr) {
    if (arr.empty()) return;

    // CONVENÇÃO: O último elemento do vetor é o ALVO da busca
    int alvo = arr.back();
    arr.pop_back();

    // Busca Binária exige dados ordenados
    sort(arr.begin(), arr.end());

    cout << endl << ">>> INICIANDO BUSCA BINARIA (O(log n)) <<<" << endl;
    cout << "Alvo: " << alvo << " | Dados Ordenados: ";
    for(int x : arr) cout << x << " ";
    cout << endl;
    this_thread::sleep_for(chrono::seconds(1));

    int left = 0;
    int right = arr.size() - 1;
    bool encontrou = false;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Visualização do intervalo atual
        cout << "\r   Busca entre indices [" << left << "] e [" << right << "]... Meio: " << arr[mid] << flush;
        this_thread::sleep_for(chrono::milliseconds(1500));

        if (arr[mid] == alvo) {
            cout << "\n\n   >>> ENCONTRADO! O valor " << alvo << " esta no indice " << mid << "." << endl;
            encontrou = true;
            break;
        }

        if (arr[mid] < alvo) {
            cout << " -> (Alvo eh maior, indo para direita)";
            left = mid + 1;
        } else {
            cout << " -> (Alvo eh menor, indo para esquerda)";
            right = mid - 1;
        }
        cout << endl;
    }

    if (!encontrou) {
        cout << "\n   >>> Valor nao encontrado na base de dados." << endl;
    }
    cout << "------------------------------------------------\n" << endl;
    this_thread::sleep_for(chrono::seconds(1));
}


void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Visualiza a raiz atual sendo verificada
    cout << "\r   (Verificando no " << arr[i] << ")   "; 
    
    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        printArray(arr, i, largest); // Mostra quem vai trocar
        swap(arr[i], arr[largest]);
        printArray(arr, i, largest); // Mostra a troca feita
        
        // Recursivamente arruma a sub-árvore afetada
        heapify(arr, n, largest);
    }
}

void animacaoHeapSort(vector<int>& arr) {
    cout << endl << ">>> INICIANDO HEAP SORT (Estrutura de Arvore/Heap) <<<" << endl;
    cout << "Fase 1: Construindo o Max-Heap (Pai > Filhos)..." << endl;
    this_thread::sleep_for(chrono::seconds(1));

    int n = arr.size();

    // Constrói o heap (rearranja o array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    cout << endl << "Fase 2: Extraindo elementos da Arvore para ordenar..." << endl;
    this_thread::sleep_for(chrono::seconds(1));

    // Extrai um por um do heap
    for (int i = n - 1; i > 0; i--) {
        printArray(arr, 0, i); // Move a raiz (maior) para o final
        swap(arr[0], arr[i]);
        printArray(arr, 0, i);
        
        // Chama heapify na heap reduzida
        heapify(arr, i, 0);
    }
    cout << "\r[ "; for(int x : arr) cout << x << " "; cout << "] -> ORDENADO!" << endl << endl;
}



// 1. DIJKSTRA (Single Source Shortest Path)
void animacaoDijkstra() {
    cout << endl << ">>> INICIANDO ALGORITMO DE DIJKSTRA (Greedy) <<<" << endl;
    cout << "Objetivo: Encontrar rota mais curta do No 0 para todos os outros." << endl;
    this_thread::sleep_for(chrono::seconds(1));

    // Grafo Demo (5 nós)
    int n = 5;
    // Matriz de adjacência (-1 = sem conexão)
    int grafo[5][5] = {
        {0, 4, 2, -1, -1}, // 0 conecta em 1(4) e 2(2)
        {-1, 0, 3, 2, 3},  // 1 conecta em 2(3), 3(2), 4(3)
        {-1, 1, 0, 4, 5},  // 2 conecta em 1(1), 3(4), 4(5)
        {-1, -1, -1, 0, -1},
        {-1, -1, -1, 1, 0}
    };
    
    vector<int> dist(n, 999); // 999 representa Infinito visualmente
    vector<bool> visitado(n, false);
    dist[0] = 0;

    for (int i = 0; i < n; i++) {
        // Encontrar o nó não visitado com menor distância
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!visitado[j] && (u == -1 || dist[j] < dist[u]))
                u = j;
        }

        if (dist[u] == 999) break;
        visitado[u] = true;

        cout << "\n[Analise] Visitando No " << u << " (Distancia atual: " << dist[u] << ")" << endl;
        this_thread::sleep_for(chrono::milliseconds(800));

        // Relaxar vizinhos
        for (int v = 0; v < n; v++) {
            if (grafo[u][v] != -1 && grafo[u][v] != 0) {
                cout << "   -> Verificando vizinho " << v << " (Peso aresta: " << grafo[u][v] << ")... ";
                if (dist[u] + grafo[u][v] < dist[v]) {
                    dist[v] = dist[u] + grafo[u][v];
                    cout << "ATUALIZADO para " << dist[v];
                } else {
                    cout << "Mantido (" << dist[v] << ")";
                }
                cout << endl;
                this_thread::sleep_for(chrono::milliseconds(500));
            }
        }
        
        // Mostrar Estado Atual das Distâncias
        cout << "   STATUS: [ ";
        for(int d : dist) {
            if(d==999) cout << "INF "; else cout << d << " ";
        }
        cout << "]" << endl;
    }
    cout << "\n>>> ROTA OTIMIZADA CALCULADA. <<<" << endl << endl;
}

// 2. BELLMAN-FORD (Detecta pesos negativos)
void animacaoBellmanFord() {
    cout << endl << ">>> INICIANDO BELLMAN-FORD (Pesos Negativos) <<<" << endl;
    cout << "Objetivo: Relaxar arestas N-1 vezes para garantir estabilidade." << endl;
    this_thread::sleep_for(chrono::seconds(1));

    int V = 4;
    vector<Aresta> arestas = {
        {0, 1, 4}, {0, 2, 5}, 
        {1, 2, -2}, // Peso negativo aqui! (Atalho hacker)
        {2, 3, 3}
    };
    
    vector<int> dist(V, 999);
    dist[0] = 0;

    // Relaxamento repetido
    for (int i = 1; i <= V - 1; i++) {
        cout << "\n--- Iteracao " << i << " de " << V-1 << " ---" << endl;
        bool trocou = false;
        for (auto& a : arestas) {
            if (dist[a.origem] != 999 && dist[a.origem] + a.peso < dist[a.destino]) {
                cout << "   Relaxando aresta " << a.origem << "->" << a.destino 
                     << " (Peso " << a.peso << "): " 
                     << dist[a.destino] << " -> " << dist[a.origem] + a.peso << endl;
                dist[a.destino] = dist[a.origem] + a.peso;
                trocou = true;
                this_thread::sleep_for(chrono::milliseconds(600));
            }
        }
        
        cout << "   Distancias: [ ";
        for(int d : dist) if(d==999) cout << "INF "; else cout << d << " ";
        cout << "]" << endl;

        if(!trocou) break; // Otimização visual
    }
    cout << "\n>>> REDE ESTABILIZADA. <<<" << endl << endl;
}

// 3. FLOYD-WARSHALL (Matriz All-Pairs)
void animacaoFloydWarshall() {
    cout << endl << ">>> INICIANDO FLOYD-WARSHALL (Mapeamento Global) <<<" << endl;
    cout << "Objetivo: Matriz de distancias de TODOS para TODOS." << endl;
    this_thread::sleep_for(chrono::seconds(1));

    int INF = 99; // Visualmente melhor que numero grande
    int dist[4][4] = {
        {0,   3,   INF, 7},
        {8,   0,   2,   INF},
        {5,   INF, 0,   1},
        {2,   INF, INF, 0}
    };

    int V = 4;
    
    // Mostra matriz inicial
    cout << "Matriz Inicial:" << endl;
    for(int i=0; i<V; i++) {
        cout << "| ";
        for(int j=0; j<V; j++) {
            if(dist[i][j]==INF) cout << "INF "; else cout << setw(3) << dist[i][j] << " ";
        }
        cout << "|" << endl;
    }

    // Algoritmo O(N^3)
    for (int k = 0; k < V; k++) {
        cout << "\n--- Usando No intermediario [" << k << "] ---" << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
        
        bool mudou = false;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    cout << "   Atalho encontrado: " << i << "->" << j 
                         << " via " << k << " (Novo custo: " << dist[i][j] << ")" << endl;
                    mudou = true;
                    this_thread::sleep_for(chrono::milliseconds(300));
                }
            }
        }
        if(!mudou) cout << "   (Nenhuma melhoria via no " << k << ")" << endl;
    }
    cout << "\n>>> TOPOLOGIA MAPEADA. <<<" << endl << endl;
}


void animacaoPrim() {
    cout << endl << ">>> INICIANDO ALGORITMO DE PRIM (MST) <<<" << endl;
    cout << "Objetivo: Conectar todos os nos com o menor custo total." << endl;
    this_thread::sleep_for(chrono::seconds(1));

    int n = 5;
    // Matriz de adjacência (Grafo não direcionado, simétrico)
    // 999 = Sem conexão
    int grafo[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int pai[5];      // Armazena a árvore
    int chave[5];    // Valores mínimos para incluir o nó
    bool mstSet[5];  // Nós já incluídos na MST

    // Inicialização
    for (int i = 0; i < n; i++) {
        chave[i] = 999;
        mstSet[i] = false;
    }

    // Começa pelo primeiro nó
    chave[0] = 0;
    pai[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        // Escolhe a chave mínima dos vértices ainda não incluídos
        int u = -1, min = 999;
        for (int v = 0; v < n; v++)
            if (!mstSet[v] && chave[v] < min)
                min = chave[v], u = v;

        mstSet[u] = true;
        cout << "\n[Analise] No " << u << " adicionado a Arvore (Custo conexao: " << min << ")" << endl;
        this_thread::sleep_for(chrono::milliseconds(800));

        // Atualiza o valor da chave e o pai dos vértices adjacentes
        for (int v = 0; v < n; v++) {
            if (grafo[u][v] && !mstSet[v] && grafo[u][v] < chave[v]) {
                cout << "   -> Melhor aresta encontrada para vizinho " << v 
                     << ": Peso " << grafo[u][v] << " (Era " << chave[v] << ")" << endl;
                pai[v] = u;
                chave[v] = grafo[u][v];
                this_thread::sleep_for(chrono::milliseconds(400));
            }
        }
    }

    // Exibe a árvore final
    cout << "\n>>> ARVORE GERADORA MINIMA FORMADA: <<<" << endl;
    int custoTotal = 0;
    for (int i = 1; i < n; i++) {
        cout << "Aresta: " << pai[i] << " - " << i << " \tPeso: " << grafo[i][pai[i]] << endl;
        custoTotal += grafo[i][pai[i]];
    }
    cout << "Custo Total: " << custoTotal << endl << endl;
}

// 5. ALGORITMO DE KRUSKAL


int find(Subconjunto sub[], int i) {
    if (sub[i].pai != i)
        sub[i].pai = find(sub, sub[i].pai);
    return sub[i].pai;
}

void Union(Subconjunto sub[], int x, int y) {
    int raizX = find(sub, x);
    int raizY = find(sub, y);

    if (sub[raizX].rank < sub[raizY].rank)
        sub[raizX].pai = raizY;
    else if (sub[raizX].rank > sub[raizY].rank)
        sub[raizY].pai = raizX;
    else {
        sub[raizY].pai = raizX;
        sub[raizX].rank++;
    }
}

// Comparador para ordenar arestas
bool compararArestas(Aresta a, Aresta b) {
    return a.peso < b.peso;
}

void animacaoKruskal() {
    cout << endl << ">>> INICIANDO ALGORITMO DE KRUSKAL (MST) <<<" << endl;
    cout << "Objetivo: Selecionar as arestas mais leves sem formar ciclos." << endl;
    this_thread::sleep_for(chrono::seconds(1));

    int V = 4; // 4 Vértices
    vector<Aresta> arestas = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    // 1. Ordenar arestas
    cout << "1. Ordenando todas as arestas por peso..." << endl;
    sort(arestas.begin(), arestas.end(), compararArestas);
    for(auto& a : arestas) cout << "(" << a.origem << "-" << a.destino << ": " << a.peso << ") ";
    cout << endl;
    this_thread::sleep_for(chrono::seconds(1));

    Subconjunto *subs = new Subconjunto[V];
    for (int v = 0; v < V; ++v) {
        subs[v].pai = v;
        subs[v].rank = 0;
    }

    vector<Aresta> mst;
    int i = 0; 
    
    // 2. Iterar arestas ordenadas
    while (mst.size() < V - 1 && i < arestas.size()) {
        Aresta proxima_aresta = arestas[i++];
        
        cout << "\n[Analise] Verificando aresta " << proxima_aresta.origem << "-" 
             << proxima_aresta.destino << " (Peso: " << proxima_aresta.peso << ")... ";
        
        int x = find(subs, proxima_aresta.origem);
        int y = find(subs, proxima_aresta.destino);

        if (x != y) {
            cout << "ACEITA (Nao forma ciclo)." << endl;
            mst.push_back(proxima_aresta);
            Union(subs, x, y);
        } else {
            cout << "REJEITADA (Formaria ciclo)." << endl;
        }
        this_thread::sleep_for(chrono::milliseconds(600));
    }

    cout << "\n>>> ARVORE GERADORA MINIMA FORMADA: <<<" << endl;
    int custo = 0;
    for (auto& a : mst) {
        cout << a.origem << " -- " << a.destino << " == " << a.peso << endl;
        custo += a.peso;
    }
    cout << "Custo Total: " << custo << endl << endl;
    delete[] subs;
}

void heapifyMin(vector<int>& arr, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    cout << "\r   (Min-Heap: Verificando menor entre pai " << arr[i] << " e filhos)   "; 
    
    // Procura o MENOR elemento (diferença principal para o Max-Heap)
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        printArray(arr, i, smallest); 
        swap(arr[i], arr[smallest]);
        printArray(arr, i, smallest); 
        
        heapifyMin(arr, n, smallest);
    }
}

void animacaoHeapSortMin(vector<int>& arr) {
    cout << endl << ">>> INICIANDO MIN-HEAP SORT (Decrescente) <<<" << endl;
    cout << "Objetivo: O MENOR elemento fica na raiz (Min-Heap)." << endl;
    this_thread::sleep_for(chrono::seconds(1));

    int n = arr.size();

    // 1. Constrói o Min-Heap (Bottom-Up)
    cout << "Fase 1: Construindo Min-Heap (Pai < Filhos)..." << endl;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyMin(arr, n, i);

    // 2. Extrai elementos
    cout << endl << "Fase 2: Extraindo (Menor vai pro final)..." << endl;
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // Move o menor (raiz) para o final "inativo"
        printArray(arr, 0, i);
        heapifyMin(arr, i, 0); // Reorganiza o restante
    }
    cout << "\r[ "; for(int x : arr) cout << x << " "; cout << "] -> ORDENADO (Decrescente)! " << endl << endl;
}

// --- 7. CONSTRUÇÃO TOP-DOWN (Inserção Item a Item) ---
void siftUp(vector<int>& arr, int i) {
    // Enquanto o nó atual for MAIOR que o pai, sobe (Max-Heap)
    // Índice do Pai = (i - 1) / 2
    while (i > 0 && arr[i] > arr[(i - 1) / 2]) {
        int pai = (i - 1) / 2;
        printArray(arr, i, pai); // Mostra comparação com o pai
        swap(arr[i], arr[pai]);
        printArray(arr, i, pai); // Mostra a troca
        i = pai; // Continua subindo
    }
}

void animacaoHeapTopDown(vector<int> dadosOriginais) {
    cout << endl << ">>> CONSTRUCAO HEAP TOP-DOWN (Insercao) <<<" << endl;
    cout << "Objetivo: Construir o Heap inserindo um elemento por vez." << endl;
    this_thread::sleep_for(chrono::seconds(1));

    vector<int> heapConstruido;
    
    for (int val : dadosOriginais) {
        cout << "\n-> Inserindo elemento " << val << " no final..." << endl;
        heapConstruido.push_back(val);
        
        // Visualiza a inserção antes de arrumar
        printArray(heapConstruido, heapConstruido.size()-1); 
        this_thread::sleep_for(chrono::milliseconds(500));

        // Faz o elemento "subir" (Sift-Up / Swim) até a posição correta
        siftUp(heapConstruido, heapConstruido.size() - 1);
    }
    
    cout << "\n>>> HEAP COMPLETO (Top-Down): <<<" << endl;
    cout << "[ "; for(int x : heapConstruido) cout << x << " "; cout << "]" << endl << endl;
}





// dispatcher
void executarVisualizacao(string nomeAlgo, vector<int> dados) {
    string upper = nomeAlgo;
    transform(upper.begin(), upper.end(), upper.begin(), ::toupper);

    // 1. LISTA DE PERMITIDOS (Whitelist)
    if (upper.find("DIJKSTRA") != string::npos) {
        animacaoDijkstra();
        return;
    }
    if (upper.find("BELLMAN") != string::npos) {
        animacaoBellmanFord();
        return;
    }
    if (upper.find("FLOYD") != string::npos) {
        animacaoFloydWarshall();
        return;
    }
    if (upper.find("PRIM") != string::npos) {
        animacaoPrim();
        return;
    }
    if (upper.find("KRUSKAL") != string::npos) {
        animacaoKruskal();
        return;
    }
    if (upper.find("MIN") != string::npos && upper.find("HEAP") != string::npos) {
        animacaoHeapSortMin(dados);
        return;
    }
    if (upper.find("TOP") != string::npos || upper.find("DOWN") != string::npos) {
        animacaoHeapTopDown(dados);
        return;
    }
    bool suportado = false;
    if (upper.find("BUBBLE") != string::npos) suportado = true;
    else if (upper.find("INSERTION") != string::npos) suportado = true;
    else if (upper.find("SELECTION") != string::npos) suportado = true;
    else if (upper.find("QUICK") != string::npos) suportado = true;
    else if (upper.find("MERGE") != string::npos) suportado = true;
    else if (upper.find("HEAP") != string::npos) suportado = true;
    // Detecta "Binaria" ou "Binary"
    else if (upper.find("BINARIA") != string::npos || upper.find("BINARY") != string::npos) suportado = true;

    if (!suportado) return; 

    // 2. EXECUTANDO A VISUALIZAÇÃO
    cout << "\n------------------------------------------------" << endl;
    cout << "SIMULACAO VISUAL (" << upper << "):" << endl;
    
    // Mostra dataset apenas se NÃO for busca (pois busca trata os dados diferente)
    if (upper.find("BINARIA") == string::npos && upper.find("BINARY") == string::npos) {
        cout << "Dataset: "; for(int n : dados) cout << n << " "; cout << endl;
    }

    if (upper.find("BUBBLE") != string::npos) animacaoBubble(dados);
    else if (upper.find("INSERTION") != string::npos) animacaoInsertion(dados);
    else if (upper.find("SELECTION") != string::npos) animacaoSelection(dados);
    else if (upper.find("QUICK") != string::npos) {
        animacaoQuickSort(dados, 0, dados.size() - 1);
        cout << "\r[ "; for(int n : dados) cout << n << " "; cout << "] -> ORDENADO!" << endl << endl;
    }
    else if (upper.find("MERGE") != string::npos) {
        animacaoMergeSort(dados, 0, dados.size() - 1);
        cout << "\r[ "; for(int n : dados) cout << n << " "; cout << "] -> ORDENADO!" << endl << endl;
    }
    else if (upper.find("HEAP") != string::npos) {
        animacaoHeapSort(dados);
    }
    else if (upper.find("BINARIA") != string::npos || upper.find("BINARY") != string::npos) {
        animacaoBuscaBinaria(dados);
    }
    
    this_thread::sleep_for(chrono::seconds(1));
}