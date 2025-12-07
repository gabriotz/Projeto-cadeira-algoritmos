#include "ordenacao.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <vector>
#include <iomanip>

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
    
    // AQUI ESTÁ O SEGREDO: 1500ms = 1.5 segundos de pausa para você ver acontecer
    this_thread::sleep_for(chrono::milliseconds(1500)); 
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

// --- DISPATCHER ---
void executarVisualizacao(string nomeAlgo, vector<int> dados) {
    string upper = nomeAlgo;
    transform(upper.begin(), upper.end(), upper.begin(), ::toupper);

    cout << "\n------------------------------------------------" << endl;
    cout << "SIMULACAO VISUAL (" << upper << "):" << endl;
    cout << "Dataset Inicial: "; 
    for(int n : dados) cout << n << " ";
    cout << endl;

    if (upper.find("BUBBLE") != string::npos) {
        cout << "Algoritmo Lento O(n^2)" << endl;
        animacaoBubble(dados);
    } 
    else if (upper.find("INSERTION") != string::npos) {
        cout << "Algoritmo Adaptativo O(n)" << endl;
        animacaoInsertion(dados);
    }
    else if (upper.find("SELECTION") != string::npos) {
        cout << "Algoritmo O(n^2)" << endl;
        animacaoSelection(dados);
    }
    else if (upper.find("QUICK") != string::npos) {
        cout << "Algoritmo Rapido O(n log n)" << endl;
        animacaoQuickSort(dados, 0, dados.size() - 1);
        // Quick Sort precisa imprimir o final manualmente pois é recursivo
        cout << "\r[ "; for(int n : dados) cout << n << " "; cout << "] -> ORDENADO!" << endl << endl;
    }
    else if (upper.find("MERGE") != string::npos) {
        cout << "Algoritmo Estavel O(n log n)" << endl;
        animacaoMergeSort(dados, 0, dados.size() - 1);
        cout << "\r[ "; for(int n : dados) cout << n << " "; cout << "] -> ORDENADO!" << endl << endl;
    }
    
    cout << "------------------------------------------------\n" << endl;
    this_thread::sleep_for(chrono::seconds(2)); // Pausa final para leitura
}