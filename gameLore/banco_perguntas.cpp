#include "banco_perguntas.h"

void carregarPerguntas(std::vector<pergunta>& perguntas) {
    perguntas.clear();

    // =================================================================================
    // PARTE 1: ORDENAÇÃO E BUSCA (Visualizações Reais)
    // =================================================================================

    // P1: QUICK SORT (Eficiência em dados aleatórios)
    pergunta p1;
    p1.questao = "ALERTA: Firewall sob ataque massivo de pacotes desordenados. Precisamos indexar os logs de intrusao rapidamente.\nQual algoritmo tem o melhor desempenho medio (O(n log n)) para dados aleatorios?";
    p1.opcaoA = "Bubble Sort";
    p1.opcaoB = "Quick Sort";    // Resposta Correta (Visualização Otimizada)
    p1.opcaoC = "Insertion Sort";
    p1.opcaoD = "Selection Sort";
    p1.resposta = 'B';
    p1.dadosTeste = { 45, 12, 89, 33, 7, 90, 21, 55 }; 
    perguntas.push_back(p1);

    // P2: INSERTION SORT (Eficiência em quase ordenados)
    pergunta p2;
    p2.questao = "SISTEMA: Recuperamos uma lista de transacoes bancarias antiga. Ela esta quase toda ordenada, exceto por alguns erros.\nQual metodo e mais eficiente (O(n)) para corrigir essa lista especifica?";
    p2.opcaoA = "Merge Sort";
    p2.opcaoB = "Quick Sort";
    p2.opcaoC = "Insertion Sort"; // Resposta Correta (Visualização Otimizada)
    p2.opcaoD = "Bubble Sort";
    p2.resposta = 'C';
    p2.dadosTeste = { 1, 3, 4, 6, 2, 8, 9, 5 };
    perguntas.push_back(p2);

    // P3: MERGE SORT (Estabilidade)
    pergunta p3;
    p3.questao = "DATABASE: Precisamos fundir dois grandes arquivos de dados de sobreviventes sem perder a ordem relativa dos registros (Estabilidade).\nQual algoritmo garante O(n log n) no pior caso e mantem a estabilidade?";
    p3.opcaoA = "Quick Sort";
    p3.opcaoB = "Selection Sort";
    p3.opcaoC = "Bubble Sort";
    p3.opcaoD = "Merge Sort";     // Resposta Correta (Visualização Otimizada)
    p3.resposta = 'D';
    p3.dadosTeste = { 10, 5, 2, 5, 8, 10, 3, 1 }; 
    perguntas.push_back(p3);

    // P4: HEAP SORT (Pior Caso Garantido)
    pergunta p4;
    p4.questao = "SEGURANCA CRITICA: O Quick Sort e rapido, mas tem um pior caso de O(n^2) que pode travar o sistema.\nQual algoritmo de ordenacao baseado em arvores garante O(n log n) mesmo no pior caso absoluto?";
    p4.opcaoA = "Heap Sort"; // Resposta Correta (Visualização de Árvore)
    p4.opcaoB = "Quick Sort";
    p4.opcaoC = "Insertion Sort";
    p4.opcaoD = "Bubble Sort";
    p4.resposta = 'A';
    p4.dadosTeste = { 100, 90, 80, 70, 60, 50 };
    perguntas.push_back(p4);

    // P5: BUSCA BINÁRIA (Dados Ordenados)
    pergunta p5;
    p5.questao = "SEGURANCA: Precisamos encontrar o ID 42 em um banco de dados de logs que JA ESTA ORDENADO.\nQual o algoritmo mais rapido (O(log n)) que divide o espaco de busca pela metade a cada passo?";
    p5.opcaoA = "Busca Linear";
    p5.opcaoB = "Busca Binaria"; // Resposta Correta (Visualização de Busca)
    p5.opcaoC = "Hash Table";
    p5.opcaoD = "Busca em Profundidade";
    p5.resposta = 'B';
    // O ultimo numero (42) é o alvo.
    p5.dadosTeste = { 10, 23, 35, 42, 50, 68, 80, 99, 100, 112, 115, 144, 200, 400, 401, 405, 408, 410, 440, 500, 42 }; 
    perguntas.push_back(p5);


    // =================================================================================
    // PARTE 2: GRAFOS E CAMINHO MÍNIMO (Visualizações de Matriz/Grafo)
    // =================================================================================
    // NOTA: Aqui removi opções como "Busca Binária" ou "Quick Sort" para evitar bugs visuais.

    // P6: DIJKSTRA (Caminho Mínimo Guloso)
    pergunta p6;
    p6.questao = "REDE DE COMUNICACAO: Precisamos rotear dados do QG ate os postos avancados. A latencia entre os postos e sempre positiva.\nQual algoritmo 'guloso' encontra o caminho mais curto de um ponto para todos os outros?";
    p6.opcaoA = "Busca em Profundidade (DFS)";
    p6.opcaoB = "Algoritmo de Dijkstra"; // Resposta Correta (Visualização de Grafo)
    p6.opcaoC = "Algoritmo de Floyd-Warshall";
    p6.opcaoD = "Algoritmo de Prim";
    p6.resposta = 'B';
    p6.dadosTeste = { 1 }; 
    perguntas.push_back(p6);

    // P7: BELLMAN-FORD (Pesos Negativos)
    pergunta p7;
    p7.questao = "ANOMALIA DETECTADA: Alguns cabos da rede estao gerando 'ganho de energia' (latencia negativa), criando riscos de loops.\nQual algoritmo consegue lidar com arestas de peso negativo e detectar esses ciclos?";
    p7.opcaoA = "Dijkstra";
    p7.opcaoB = "Bellman-Ford"; // Resposta Correta (Visualização de Relaxamento)
    p7.opcaoC = "Busca em Largura (BFS)";
    p7.opcaoD = "Algoritmo de Kruskal";
    p7.resposta = 'B';
    p7.dadosTeste = { 1 }; // Dummy data
    perguntas.push_back(p7);

    // P8: FLOYD-WARSHALL (Todos para Todos)
    pergunta p8;
    p8.questao = "MAPEAMENTO GLOBAL: O general precisa de uma tabela completa de distancias entre TODOS os pares de bases aliadas.\nQual algoritmo, baseado em Programacao Dinamica, calcula a matriz de distancias completa?";
    p8.opcaoA = "Floyd-Warshall"; // Resposta Correta (Visualização de Matriz)
    p8.opcaoB = "Dijkstra";
    p8.opcaoC = "Algoritmo de Prim";
    p8.opcaoD = "Merge Sort"; 
    p8.resposta = 'A';
    p8.dadosTeste = { 1 }; 
    perguntas.push_back(p8);


    // =================================================================================
    // PARTE 3: TEÓRICAS (Sem animação, respostas seguras)
    // =================================================================================

    // P9: HASH TABLE
    pergunta p9;
    p9.questao = "Um aviso critico foi criptografado. Voce precisa do codigo de acesso em 3 segundos.\nQual Estrutura de Dados oferece o acesso e busca mais rapidos (em tempo medio O(1))?";
    p9.opcaoA = "Arvore AVL";
    p9.opcaoB = "Vetor Ordenado";
    p9.opcaoC = "Tabela Hash"; // Resposta Correta
    p9.opcaoD = "Lista Ligada";
    p9.resposta = 'C';
    perguntas.push_back(p9);

    // P10: HEAP (Estrutura)
    pergunta p10;
    p10.questao = "TRIAGEM MEDICA: Nao podemos atender por ordem de chegada, mas sim pela gravidade.\nQual estrutura e mais eficiente para sempre remover o elemento de MAIOR prioridade (O(log n))?";
    p10.opcaoA = "Pilha (Stack)";
    p10.opcaoB = "Lista Ordenada";
    p10.opcaoC = "Heap / Fila Prioridade"; // Resposta Correta
    p10.opcaoD = "Tabela Hash";
    p10.resposta = 'C';
    p10.dadosTeste = { 10, 50, 30, 20, 90, 60, 40 }; 
    perguntas.push_back(p10);
    
    // P11: ÁRVORE (Definição)
    pergunta p11;
    p11.questao = "ESTRUTURA: O Mapa de Rotas e totalmente conectado mas nao tem 'rotas circulares' (ciclos).\nEsse tipo de Grafo e classificado como:";
    p11.opcaoA = "Arvore"; // Resposta Correta
    p11.opcaoB = "Grafo Dirigido";
    p11.opcaoC = "Grafo Completo";
    p11.opcaoD = "Lista";
    p11.resposta = 'A';
    perguntas.push_back(p11);

    pergunta pBubble;
    pBubble.questao = "MODO DE SEGURANCA: O processador auxiliar esta danificado e nao suporta recursao (como Quick/Merge). Precisamos organizar as celulas de energia usando um metodo puramente iterativo que compare APENAS pares de vizinhos adjacentes.\nQual e esse algoritmo, conhecido por sua lentidao (O(n^2)) mas simplicidade de implementacao?";
    pBubble.opcaoA = "Quick Sort";
    pBubble.opcaoB = "Merge Sort";
    pBubble.opcaoC = "Bubble Sort"; // Resposta Correta (Vai acionar a animação)
    pBubble.opcaoD = "Heap Sort";
    pBubble.resposta = 'C';
    pBubble.dadosTeste = { 50, 40, 30, 20, 10 }; 
    perguntas.push_back(pBubble);
}