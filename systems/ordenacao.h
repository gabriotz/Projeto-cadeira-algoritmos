#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <vector>
#include <string>

// Função principal (Dispatcher)
void executarVisualizacao(std::string nomeAlgo, std::vector<int> dados);

// Algoritmos O(n^2) - Lentos
void animacaoBubble(std::vector<int> arr);
void animacaoInsertion(std::vector<int> arr);
void animacaoSelection(std::vector<int> arr);

// Algoritmos O(n log n) - Rápidos (Novos!)
void animacaoQuickSort(std::vector<int>& arr, int low, int high);
void animacaoMergeSort(std::vector<int>& arr, int left, int right);



//heaps
void animacaoHeapSort(std::vector<int>& arr);

void animacaoHeapSortMin(std::vector<int>& arr); 
void animacaoHeapTopDown(std::vector<int> arr);  

// busca binaria
void animacaoBuscaBinaria(std::vector<int> arr);

// algoritmos de menor custo
void animacaoDijkstra();       
void animacaoBellmanFord();    
void animacaoFloydWarshall();

void animacaoPrim();
void animacaoKruskal();

void printArray(const std::vector<int>& arr, int destaque1 = -1, int destaque2 = -1);

#endif