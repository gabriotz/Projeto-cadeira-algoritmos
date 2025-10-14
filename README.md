# Uma Aventura de Sobrevivência Lógica

# Descrição e Objetivos

O nosso projeto é um jogo de **aventura e sobrevivência em terminal**, desenvolvido em **C++**, que desafia o jogador a tomar decisões críticas baseadas em **Estruturas de Dados e Algoritmos**.

Em um cenário pós-apocalíptico, cada recurso é escasso e a eficiência é a chave para a sobrevivência.  
O jogador deve responder a perguntas que simulam problemas logísticos e estratégicos, escolhendo a **estrutura de dados** ou o **algoritmo** mais adequado para cada situação.

### Objetivo Principal

Transformar o aprendizado de temas complexos e abstratos em uma **experiência dinâmica e interativa**.  
Em vez de apenas memorizar conceitos, o jogador os **aplica em um contexto narrativo**, reforçando a importância e a utilidade prática de cada algoritmo.

---

## Estrutura e Funcionalidades Implementadas

O código foi arquitetado de forma **modular**, aplicando conceitos fundamentais de **C++** para garantir **eficiência e clareza**.

---

### Tipos Compostos: `struct` e `union`

Para modelar os dados do jogo, foram utilizados **tipos compostos** que agrupam informações relacionadas.

#### `struct` (Registros)

São a base da modelagem:

- **`pergunta`**: Armazena a lógica de uma questão do quiz (enunciado, opções e resposta correta).  
- **`item`**: Representa um item do inventário (nome, descrição e tipo).  
- **`personagem`**: Consolida o estado completo do jogador (nome, vida e inventário).

#### `union` (União)

Dentro da `struct item`, há uma `union` para atributos específicos de cada tipo de item:

- Um item pode **curar (`pontosCura`)** ou **ajudar no quiz (`metadeDasOpcoes`)**.  
- O uso de `union` **otimiza o uso de memória**, alocando espaço suficiente apenas para o maior membro, compartilhado por todos.

---

### Variáveis Globais e Locais

#### Globais
O jogo utiliza um conjunto de variáveis globais, como `perguntas` e `itensDoJogo`, que funcionam como um “banco de dados” central.  
São declaradas em `main.cpp` e acessadas em outros arquivos com `extern`.

#### Variáveis Locais
A maioria das variáveis é local, existindo apenas dentro do escopo de suas funções.  
Isso garante **melhor controle de estado** e evita efeitos colaterais.

---

### Modularização

A complexidade do jogo é controlada por uma **forte modularização**.  
Cada função tem uma **responsabilidade única**, tornando o código legível e de fácil alterações.

#### Funções Principais

- **`main()`** → Ponto de entrada; inicializa o jogo e o menu.  
- **`jogar()`** → Executa o loop principal da partida.  
- **`salvarProgresso()` / `carregarProgresso()`** → Manipulam os arquivos de save.

---

### Ponteiros e Alocação Dinâmica de Memória

O jogo utiliza **alocação dinâmica** para gerenciar objetos que precisam existir além do escopo de uma função (como o personagem e os itens).

- **`new`** → Aloca memória no *heap*.  
  Exemplo: criação de um novo personagem ao iniciar o jogo.  
- **`delete`** → Libera memória para evitar *memory leaks*.  
  Exemplo: quando um item é consumido ou o jogo termina.

#### Ponteiros

O inventário do jogador é um `vector<item*>`, armazenando ponteiros para objetos `item`.  
Em `carregarProgresso`, é usado um **ponteiro para ponteiro (`personagem**`)** para modificar o endereço original e atualizar a referência do jogador carregado do arquivo.

---

### Entrada e Saída (E/S) de Arquivos

O sistema de **persistência de dados** permite salvar e carregar o progresso do jogador.

#### Fluxo de Saída

A função `salvarProgresso()` usa `ofstream` para criar/sobrescrever um arquivo `.dat`, gravando:

- Vida do jogador  
- Inventário  
- Outros dados de progresso  

#### Fluxo de Entrada

A função `carregarProgresso()` utiliza `ifstream` para ler o arquivo e reconstruir o estado do personagem na memória,  
permitindo continuar a aventura de onde parou.

---

## Tecnologias Utilizadas

- **Linguagem:** C++  
- **Paradigma:** Programação estruturada e modular  
- **Conceitos aplicados:**  
  - `struct`, `union`;
  - Ponteiros e alocação dinâmica de memória;
  - E/S de arquivos;
  - Modularização;
  - Vetores de ponteiros (`vector<item*>`);

---

## Grupo

**Daniel Ramos**  
**Felipe Leite**  
**Gabriel Machado**  
**Matheus Henrique**  
**Matheus Stepple**  
Projeto acadêmico da cadeira de **Algoritmos** em C++. 
Professora: Juscimara Avelino.
