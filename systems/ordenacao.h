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

// Auxiliar visual
void printArray(const std::vector<int>& arr, int destaque1 = -1, int destaque2 = -1);

#endif