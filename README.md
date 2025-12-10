# 🧩 Uma Aventura de Sobrevivência Lógica

## 🧭 Descrição

Este projeto é um **jogo de aventura e sobrevivência em terminal**, desenvolvido em **C++**, onde o jogador precisa tomar decisões usando **Estruturas de Dados e Algoritmos**.

O cenário é um mundo pós-apocalíptico.  
Recursos são escassos.  
Eficiência é a chave para a sobrevivência.

O jogador aplica algoritmos reais dentro da narrativa, entendendo sua importância prática.

---

## 🎯 Objetivo do Projeto

Transformar o aprendizado de algoritmos em uma experiência:

- **Dinâmica**  
- **Narrativa**  
- **Interativa**  

O jogador **vive** a aplicação de cada estrutura ou algoritmo, em vez de apenas memorizá-los.

---

## ⚙️ Como Compilar e Rodar

Certifique-se de ter o compilador **g++** instalado.

### Compilação

```bash
g++ main.cpp systems/*.cpp gameLore/*.cpp -o jogo.exe
```

### Execução

```bash
./jogo.exe
```

---


## 1. 🔄 Algoritmos de Ordenação

| Algoritmo | Complexidade Média | Pior Caso | Aplicação |
|-----------|-------------------|-----------|-----------|
| **Bubble Sort** | O(n²) | O(n²) | Representa métodos arcaicos e lentos de organização manual. |
| **Insertion Sort** | O(n²) | O(n²) | Bom para listas pequenas/quase ordenadas; corrige falhas pontuais. |
| **Selection Sort** | O(n²) | O(n²) | Demonstra a ineficiência de buscas repetidas. |
| **Quick Sort** | O(n log n) | O(n²) | Indexação rápida de logs de intrusão. |
| **Merge Sort** | O(n log n) | O(n log n) | Usado para fusão estável de arquivos de sobreviventes. |

---

## 2. 🌲 Árvores e Heaps

### Heap Sort (Max-Heap)

- **Complexidade:** O(n log n)
- **Aplicação:** Sistema de triagem médica com prioridade
- **Diferencial:** Paciente mais grave sempre é atendido primeiro

O algoritmo constrói o heap e extrai a raiz repetidamente para ordenar os dados.

---

## 3. 🔍 Algoritmos de Busca

### Busca Binária

- **Requisito:** Vetor ordenado
- **Complexidade:** O(log n)
- **Aplicação:** Localizar rapidamente IDs em bancos de dados antigos

No jogo, o intervalo analisado é exibido visualmente diminuindo.

---

## 4. 🌐 Grafos e Caminhos Mínimos

Implementação com matriz de adjacência, simulando rotas e comunicação entre bases.

### Dijkstra

- **Objetivo:** Menor caminho a partir de um nó origem
- **Complexidade:** O(V²)
- **Aplicação:** Roteamento de dados (latência positiva)
- **Visualização:** Expansão progressiva das distâncias

### Bellman-Ford

- **Objetivo:** Lida com pesos negativos
- **Complexidade:** O(V × E)
- **Aplicação:** Detectar anomalias (ciclos negativos) na rede elétrica

### Floyd-Warshall

- **Objetivo:** Menor caminho entre todos os pares
- **Complexidade:** O(V³)
- **Aplicação:** Mapa global de rotas estratégicas

---

## 5. 🔗 Árvores Geradoras Mínimas (MST)

### Prim

- **Complexidade:** O(V²)
- **Estratégia:** Expande com a menor aresta conectada
- **Aplicação:** Reconstrução da rede elétrica do bunker

### Kruskal

- **Complexidade:** O(E log E)
- **Estratégia:** Ordena arestas + Union-Find para evitar ciclos
- **Aplicação:** Unir rotas de fuga seguras espalhadas pelo mapa

---

## 🧩 Detalhes de Implementação em C++

### Tipos Compostos

- **`struct`** para perguntas, itens e personagens
- **`union`** dentro dos itens para economizar memória
  - Exemplo: `pontosCura` ou `metadeDasOpcoes`

### Ponteiros e Alocação Dinâmica

- Uso de `new` / `delete`
- Inventário como `vector<item*>`
- Destrutores personalizados para evitar memory leaks

### Modularização

#### Arquivos principais:

- **`ordenacao.cpp`** — Visualização dos algoritmos
- **`gameplay.cpp`** — Mecânicas do jogo
- **`banco_perguntas.cpp`** — Dados e perguntas
- **`estruturas.h`** — Definições globais

---

## 👥 Grupo

- **Daniel Ramos**
- **Felipe Leite**
- **Gabriel Machado**
- **Matheus Henrique**
- **Matheus Stepple**

---

## 📚 Informações Acadêmicas

**Projeto acadêmico** – Cadeira de Algoritmos (C++)  
**Professora:** Juscimara Avelino

---

## 📄 Licença

Projeto desenvolvido para fins educacionais.
