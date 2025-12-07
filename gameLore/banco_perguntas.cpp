#include "banco_perguntas.h"

void carregarPerguntas(std::vector<pergunta>& perguntas) {
    perguntas.clear();
    
    // P1: Bubble Sort (O(n^2)) - Todas complexidades plausiveis
    pergunta p1;
    p1.questao = "O comboio de suprimentos esta sob ataque, e a prioridade dos 500 itens (Remedios, Municao, etc.) deve ser reavaliada a todo momento. Se voce escolher um metodo de 'revisao lenta' (como o Bubble Sort, que compara vizinhos e troca) para reorganizar N itens, qual a **complexidade no pior caso**? Uma resposta lenta significa que o comboio nao estara preparado a tempo para o proximo confronto, resultando em perdas catastroficas.";
    p1.opcaoA = "O(n). Complexidade do melhor caso (lista ja ordenada), sendo irreal no pior cenario do ataque.";
    p1.opcaoB = "O(n^2). O tempo de organizacao cresce exponencialmente (quadratico) no pior cenario, a complexidade que condenaria a missao a falha critica."; // CORRETA: O(n^2)
    p1.opcaoC = "O(n log n). Seria a complexidade de um algoritmo avancado como Quick Sort, que deveria ter sido usado no lugar.";
    p1.opcaoD = "O(1). Complexidade de acesso direto, impossivel para o processamento de todos os 500 itens.";
    p1.resposta = 'B';
    perguntas.push_back(p1);

    // P2: Hash Table (Busca Rapida O(1) media) - O(1) vs O(log n)
    pergunta p2;
    p2.questao = "Um aviso critico foi criptografado em um imenso 'Registro de Sinais' (N entradas) e voce precisa do codigo de acesso para reativar as defesas em 3 segundos. Qual Estrutura de Dados oferece o **acesso e busca mais rapidos (em tempo medio O(1))**, permitindo que voce localize o codigo de forma quase instantAnea para salvar o acampamento?";
    p2.opcaoA = "arvore de Busca Balanceada (AVL). Garante busca O(log n) no pior caso, mas a exigencia e por tempo *medio* constante (O(1)).";
    p2.opcaoB = "Vetor Ordenado. Oferece busca O(log n) via Busca Binaria, mas nao atinge a velocidade quase imediata pedida.";
    p2.opcaoC = "Tabela de Mapeamento (Hash Table). Sua caracteristica de *espalhamento* permite acesso e busca em tempo medio constante, vital para a urgencia de 3 segundos."; // CORRETA: Hash Table
    p2.opcaoD = "Lista Duplamente Ligada. Permite insercao e remocao rapida, mas a busca do codigo de acesso e lenta (O(n)).";
    p2.resposta = 'C';
    perguntas.push_back(p2);

    // P3: Algoritmo de Ordenacao Eficiente (Quick Sort - O(n log n) media) - Sutileza: Merge vs Quick
    pergunta p3;
    p3.questao = "A Central de Logistica tem 10.000 unidades de suprimentos nao organizados e a zona deve ser evacuada em minutos. Voce precisa do algoritmo mais eficiente para ordenar o volume total. Qual algoritmo de 'dividir para conquistar' e geralmente o mais **eficiente e rapido em tempo medio (O(n log n))** para esta evacuacao em massa?";
    p3.opcaoA = "Merge Sort. e estavel e tem O(n log n) garantido, mas e considerado mais lento na pratica do que o Quick Sort devido ao *overhead* de juncao.";
    p3.opcaoB = "Quick Sort. Sua complexidade media O(n log n) faz com que ele exiba a melhor performance em processadores reais, sendo a melhor escolha para evacuacao rapida."; // CORRETA: Quick Sort
    p3.opcaoC = "Heap Sort. Tambem garante O(n log n) e usa menos memoria extra, mas sua performance na media e notavelmente mais lenta que a do Quick Sort.";
    p3.opcaoD = "Selection Sort. Nao pode ser considerado eficiente, pois sua complexidade O(n^2) e muito previsivel.";
    p3.resposta = 'B';
    perguntas.push_back(p3);

    // P4: Busca Binaria (O(log n)) - Busca Linear vs Binaria
    pergunta p4;
    p4.questao = "Seu objetivo e encontrar a 'Coordenada Secreta de Resgate' em um 'Atlas de Seguranca' perfeitamente ordenado (N paginas). Ao aplicar a 'Busca Binaria', eliminando metade das paginas a cada inspecao, qual a **complexidade de tempo** para achar o alvo, permitindo a localizacao mesmo em um volume de dados inimaginavel?";
    p4.opcaoA = "O(n). Complexidade da Busca Linear, que forcaria a leitura de muitas paginas antes de achar o alvo.";
    p4.opcaoB = "O(n log n). Complexidade de ordenacao, nao de busca no Atlas ja pronto.";
    p4.opcaoC = "O(log n). A busca e logaritmica, pois a eliminacao de metade do espaco de busca a cada inspecao a torna extremamente rapida."; // CORRETA: Binary Search
    p4.opcaoD = "O(1). Complexidade de busca por indice, que nao se aplica a localizacao de um valor (Coordenada) no Atlas.";
    p4.resposta = 'C';
    perguntas.push_back(p4);

    // P5: Pilha (LIFO) - Sutileza: LIFO vs FIFO no contexto de comando
    pergunta p5;
    p5.questao = "O Protocolo de Defesa 'Desfazer ultimo Comando' permite anular acões erradas (como um alarme falso). O sistema armazena comandos, mas so expõe o ultimo executado. Que principio essa estrutura de comandos usa, garantindo que o **ultimo a Entrar seja o Primeiro a Sair** (LIFO)?";
    p5.opcaoA = "FIFO. Principio de Fila, anularia o comando mais antigo e o erro recente seria mantido, causando um desastre.";
    p5.opcaoB = "LIFO. O principio ideal, pois garante que a ultima acao (o erro ou alarme falso) e a primeira a ser acessada e revertida."; // CORRETA: Pilha (LIFO)
    p5.opcaoC = "Acesso de Prioridade. Isso desfaria o comando mais importante, o que pode nao ser o ultimo executado, gerando um novo erro.";
    p5.opcaoD = "FILO. e apenas uma descricao alternativa para LIFO (First In, Last Out), mas o principio tecnico e LIFO/Pilha.";
    p5.resposta = 'B';
    perguntas.push_back(p5);

    // P6: Fila (FIFO) - Sutileza: Fila vs Heap
    pergunta p6;
    p6.questao = "A distribuicao de racões precisa ser justa, garantindo a moral da comunidade: o sobrevivente que chegou primeiro a 'linha de espera' deve ser o primeiro a ser atendido. Que principio essa 'linha de espera' (Queue) de distribuicao de recursos usa, respeitando a ordem **Primeiro a Entrar, Primeiro a Sair** (FIFO)?";
    p6.opcaoA = "LIFO. Principio de Pilha, subverteria a ordem de chegada, levando a desordem e injustica.";
    p6.opcaoB = "Prioridade de Urgencia. Principio de Heap, atenderia quem tem maior 'valor' ou 'urgencia', ignorando a ordem de chegada.";
    p6.opcaoC = "FIFO. O principio que reflete a ordem cronologica, essencial para a moral e equidade na distribuicao de recursos."; // CORRETA: Fila (FIFO)
    p6.opcaoD = "Round Robin. Um metodo de escalonamento que atende a todos em turnos ciclicos, mas nao descreve a Estrutura de Dados basica da fila.";
    p6.resposta = 'C';
    perguntas.push_back(p6);

    // P7: Merge Sort (O(n log n)) - Sutileza: Garantia do pior caso
    pergunta p7;
    p7.questao = "Sua equipe obteve dois grandes lotes de doacões que ja estao organizados individualmente (Ex: por data de validade). Qual e a sua **complexidade de tempo no pior caso**? Isso define se a uniao dos suprimentos sera feita a tempo.";
    p7.opcaoA = "O(n^2).";
    p7.opcaoB = "O(n log n). O Merge Sort garante essa eficiencia em **todos** os cenarios (melhor e pior)."; // CORRETA: Merge Sort
    p7.opcaoC = "O(n). Apenas o tempo para fazer uma varredura (merge), sem considerar as divisões.";
    p7.opcaoD = "O(n log n) apenas na media. Isso e o Quick Sort.";
    p7.resposta = 'B';
    perguntas.push_back(p7);

    // P8: DFS (Busca em Profundidade) - Sutileza: Finalidade da busca
    pergunta p8;
    p8.questao = "Voce esta explorando um perigoso labirinto de tuneis e decide seguir a regra 'va o mais fundo que puder em um tunel, so volte se for um beco sem saida'. Que tipo de estrategia de travessia de Grafos (rotas) voce esta usando para garantir que explora completamente uma rota e encontra o alvo escondido no final de um caminho longo?";
    p8.opcaoA = "Busca em Largura (BFS). Prioriza a menor quantidade de passos (nivel por nivel).";
    p8.opcaoB = "Busca em Profundidade (DFS). A estrategia que prioriza a exploracao maxima de um caminho (recursao)."; // CORRETA: DFS
    p8.opcaoC = "Busca de Menor Custo (Dijkstra). Usada para encontrar a rota mais barata/curta..";
    p8.opcaoD = "Busca Gulosa. Foca no proximo passo mais promissor, sem garantir que o caminho longo e profundo seja explorado.";
    p8.resposta = 'B';
    perguntas.push_back(p8);

    // P9: arvore Binaria de Busca (O(log n) media) - Sutileza: Ordem vs Velocidade (BST vs Hash)
    pergunta p9;
    p9.questao = "O 'Registro de Sobreviventes' cresce a cada dia e voce precisa de um sistema que armazene e recupere as 'identificacões unicas' de forma organizada e com **velocidade de busca rapida (O(log n) em media)**. Qual estrutura hierarquica e ideal para manter essa organizacao e desempenho?";
    p9.opcaoA = "Hash Table. e mais rapido para busca (O(1)).";
    p9.opcaoB = "arvore Binaria de Busca (BST). A estrutura que equilibra a velocidade de busca O(log n)."; // CORRETA: arvore Binaria de Busca
    p9.opcaoC = "Heap. Estrutura otimizada apenas para prioridade (maximo/minimo).";
    p9.opcaoD = "Vetor DinAmico Ordenado. A busca e O(log n).";
    p9.resposta = 'B';
    perguntas.push_back(p9);

    // P10: Pilha e Recursao (Call Stack) - Sutileza: Mecanismo de retorno
    pergunta p10;
    p10.questao = "O 'Protocolo de Mapeamento Recursivo' esta ativo para tracar todos os caminhos de fuga. Sempre que o sistema se aprofunda em uma nova rota (chamada recursiva), qual Estrutura de Dados ele usa internamente para registrar a ordem das chamadas e garantir que ele saiba qual e o **'ponto de retorno' seguro** de cada desvio?";
    p10.opcaoA = "Fila.";
    p10.opcaoB = "Array. Seria estatico.";
    p10.opcaoC = "Pilha de Chamadas (Call Stack)."; // CORRETA: Pilha
    p10.opcaoD = "Lista Ligada.";
    p10.resposta = 'C';
    perguntas.push_back(p10);

    // P11: Quick Sort Melhor Caso (O(n log n)) - Sutileza: Cenario ideal
    pergunta p11;
    p11.questao = "O sistema de defesa usa o Quick Sort para organizar a prontidao da equipe. Em um cenario ideal, o sistema **sempre seleciona o 'pivo' perfeito**, dividindo a lista de tarefas exatamente ao meio. Qual a **complexidade de tempo de melhor caso** para essa organizacao?";
    p11.opcaoA = "O(n^2). Este e o pior caso, indicando um pivo desequilibrado em todas as etapas.";
    p11.opcaoB = "O(n log n). A complexidade alcancada no melhor caso."; // CORRETA: Quick Sort Melhor Caso
    p11.opcaoC = "O(n). A complexidade do melhor caso para o Bubble Sort, que e atingida quando a lista esta ja ordenada.";
    p11.opcaoD = "O(1). Organizacao imediata.";
    p11.resposta = 'B';
    perguntas.push_back(p11);

    // P12: BFS (Busca em Largura) - Sutileza: BFS vs DFS vs Dijkstra
    pergunta p12;
    p12.questao = "No resgate, voce precisa explorar todos os abrigos **'vizinhos' (nivel 1) antes** de avancar para os mais distantes (nivel 2, 3, etc.), priorizando a seguranca imediata. Que Estrutura de Dados essa 'Busca em Largura' (BFS) usa para gerenciar a ordem estrita de exploracao por nivel (FIFO)?";
    p12.opcaoA = "Pilha. Usada pela Busca em Profundidade (DFS).";
    p12.opcaoB = "Fila. A estrutura FIFO e essencial para garantir que todos os nos de um nivel sejam visitados antes de avancar para o proximo, respeitando a proximidade."; // CORRETA: Fila (BFS)
    p12.opcaoC = "Heap. Estrutura de prioridade, que seria usada para o algoritmo de Dijkstra (caminho mais curto/barato)";
    p12.opcaoD = "Lista Simples. Nao impõe a ordem FIFO necessaria, resultando em exploracao desordenada.";
    p12.resposta = 'B';
    perguntas.push_back(p12);

    // P13: Lista Ligada (Insercao O(1) no Inicio) - Sutileza: Custo da Insercao O(1)
    pergunta p13;
    p13.questao = "Uma ordem de batalha emergencial deve ser adicionada **no inicio** de uma sequencia de tarefas com complexidade de tempo constante, ou seja, O(1), sem mover as tarefas existentes. Qual estrutura, ao ser inserida **no inicio**, permite essa adicao imediata e de custo fixo (troca de ponteiros)?";
    p13.opcaoA = "Vetor (Array). O(n) para insercao no inicio, pois exige o deslocamento de todos os elementos.";
    p13.opcaoB = "Lista Ligada Simples. Sua manipulacao de ponteiros permite a insercao O(1) no inicio."; // CORRETA: Lista Ligada
    p13.opcaoC = "Vetor DinAmico. Embora redimensione, a insercao no inicio ainda tem um custo O(n).";
    p13.opcaoD = "arvore (AVL). O(log n) para insercao; e rapida, mas nao a insercao *imediata* (O(1)) pedida.";
    p13.resposta = 'B';
    perguntas.push_back(p13);

    // P14: Bubble Sort Pior Caso (O(n^2)) - Sutileza: Pior caso
    pergunta p14;
    p14.questao = "O 'Protocolo de Prioridade' para feridos (Bubble Sort) recebe a lista na ordem exatamente inversa de prioridade (o mais ferido esta no fim). Esse e o pior cenario. Qual sera a **complexidade de tempo (pior caso)**, que torna essa triagem inaceitavelmente lenta para uma emergencia?";
    p14.opcaoA = "O(n log n). A complexidade de algoritmos mais rapidos, que e inatingivel para o Bubble Sort no pior cenario.";
    p14.opcaoB = "O(log n). Um otimismo irreal; esta complexidade nao se aplica a ordenacao no pior cenario.";
    p14.opcaoC = "O(n^2). O numero de trocas se maximiza quadraticamente (quadrado do numero de feridos), resultando no colapso da triagem."; // CORRETA: Bubble Sort Pior Caso
    p14.opcaoD = "O(n). A complexidade atingida apenas no melhor caso (lista ja ordenada).";
    p14.resposta = 'C';
    perguntas.push_back(p14);

    // P15: Grafo Aciclico Conectado (arvore) - Sutileza: Propriedades do Grafo
    pergunta p15;
    p15.questao = "O 'Mapa de Rotas de Suprimento' de todos os postos avancados e **totalmente conectado** (chega-se a qualquer ponto), mas o projetista garantiu que ele **nao tem 'rotas circulares'** (ciclos) para evitar que os comboios se percam. Esse tipo de Grafo (Conectado e Aciclico) e tecnicamente classificado como:";
    p15.opcaoA = "arvore. A definicao exata: um Grafo que e totalmente conectado e nao possui ciclos, o que garante a unicidade da rota."; // CORRETA: arvore
    p15.opcaoB = "Grafo Dirigido. Pode conter ciclos.";
    p15.opcaoC = "Grafo Completo. Possui a conexao.";
    p15.opcaoD = "Lista. Representa apenas uma sequencia linear de postos.";
    p15.resposta = 'A';
    perguntas.push_back(p15);

    pergunta p16;
    p16.questao = "ALERTA: Firewall sob ataque massivo de pacotes desordenados. Precisamos indexar os logs de intrusao rapidamente.\nQual algoritmo tem o melhor desempenho medio (O(n log n)) para dados aleatorios?";
    p16.opcaoA = "Bubble Sort";
    p16.opcaoB = "Quick Sort";    // Resposta Correta
    p16.opcaoC = "Insertion Sort";
    p16.opcaoD = "Selection Sort";
    p16.resposta = 'B';
    // Dados bem bagunçados para o Quick Sort brilhar
    p16.dadosTeste = { 45, 12, 89, 33, 7, 90, 21, 55 }; 
    perguntas.push_back(p16);

    // --- PERGUNTA 2: INSERTION SORT (Eficiência em quase ordenados) ---
    pergunta p17;
    p17.questao = "SISTEMA: Recuperamos uma lista de transacoes bancarias antiga. Ela esta quase toda ordenada, exceto por alguns erros.\nQual metodo e mais eficiente (O(n)) para corrigir essa lista especifica?";
    p17.opcaoA = "Merge Sort";
    p17.opcaoB = "Quick Sort";
    p17.opcaoC = "Insertion Sort"; // Resposta Correta (Ótimo p/ quase ordenados)
    p17.opcaoD = "Bubble Sort";
    p17.resposta = 'C';
    // Dados quase ordenados (apenas o 2 e 5 fora do lugar)
    p17.dadosTeste = { 1, 3, 4, 6, 2, 8, 9, 5 }; 
    perguntas.push_back(p17);

    // --- PERGUNTA 3: MERGE SORT (Estabilidade e Grandes Dados) ---
    pergunta p18;
    p18.questao = "DATABASE: Precisamos fundir dois grandes arquivos de dados de sobreviventes sem perder a ordem relativa dos registros (Estabilidade).\nQual algoritmo garante O(n log n) no pior caso e mantem a estabilidade?";
    p18.opcaoA = "Quick Sort";
    p18.opcaoB = "Selection Sort";
    p18.opcaoC = "Bubble Sort";
    p18.opcaoD = "Merge Sort";     // Resposta Correta
    p18.resposta = 'D';
    // Dados duplicados para testar estabilidade (visualização mostra a mesclagem)
    p18.dadosTeste = { 10, 5, 2, 5, 8, 10, 3, 1 }; 
    perguntas.push_back(p18);

    // --- PERGUNTA 4: SELECTION SORT (Memória Flash / Poucas Trocas) ---
    pergunta p19;
    p19.questao = "HARDWARE: O disco rigido esta danificado. A escrita e muito custosa, mas a leitura e barata.\nQual algoritmo minimiza o numero de trocas (escritas) na memoria?";
    p19.opcaoA = "Selection Sort"; // Resposta Correta (Max N trocas)
    p19.opcaoB = "Insertion Sort";
    p19.opcaoC = "Merge Sort";
    p19.opcaoD = "Quick Sort";
    p19.resposta = 'A';
    p19.dadosTeste = { 99, 88, 77, 66, 55 };
    perguntas.push_back(p19);



}