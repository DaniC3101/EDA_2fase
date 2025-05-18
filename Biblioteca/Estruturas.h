#pragma once

/**
 * @brief Estrutura para representar os dados de um vértice (posição e frequência).
 */
typedef struct
{
	int posicao[2];
	char frequencia;
} Dados;

/**
 * @brief Estrutura que representa o grafo, com lista de vértices e dimensão.
 */
typedef struct
{
	struct Vertice* primVertice;
	int dimensao[2];
} Grafo;

/**
 * @brief Estrutura de um vértice, com os seus dados, arestas e estado de visita.
 */
typedef struct
{
	Dados dados;
	struct Vertice* proxVertice;
	struct Aresta* primAresta;
	bool visitado;
} Vertice;

/**
 * @brief Estrutura de uma aresta, com ligação a um vértice adjacente e lista de nefastas.
 */
typedef struct
{
	Vertice* adjVertice;
	struct Aresta* proxAresta;
	struct Nefasta* primNefasta;
} Aresta;

/**
 * @brief Estrutura que representa uma posição nefasta, associada a uma aresta.
 */
typedef struct
{
	struct Nefasta* proxNefasta;
	Dados dados;
} Nefasta;

/**
 * @brief Estrutura auxiliar utilizada na travessia em largura (BFS).
 */
typedef struct
{
	Vertice* vertice;
	struct Espera* proxVertice;
} Espera;

/**
 * @brief Estrutura utilizada para guardar um vértice em ficheiro binário.
 */
typedef struct
{
	Dados dados;
	bool visitado;
} VerticeFile;

/**
 * @brief Estrutura utilizada para guardar uma aresta em ficheiro binário.
 */
typedef struct
{
	int origemPos[2];
	int destinoPos[2];
} ArestaFile;

/**
 * @brief Estrutura utilizada para guardar uma posição nefasta em ficheiro binário.
 */
typedef struct
{
	int posicao[2];
	char frequencia;
} NefastaFile;

// === Declarações de Funções ===

/**
 * @brief Carrega os dados do grafo a partir de um ficheiro de texto com matriz.
 */
Grafo* CarregarMatriz(char* nomeFicheiro);

/**
 * @brief Conta o número de linhas, colunas e vértices num ficheiro de texto.
 */
int ContarLinhasColunas(FILE* grafoTXT, int dimensao[], int* contadorVertice);

/**
 * @brief Encontra e armazena os vértices identificados num ficheiro de texto.
 */
Dados* EncontrarVertices(FILE* grafoTXT, Dados* dados);

/**
 * @brief Guarda os vértices do grafo num ficheiro binário.
 */
bool GuardarVertices(Grafo* grafo, char* file);

/**
 * @brief Carrega os vértices de um ficheiro binário para o grafo.
 */
Grafo* CarregarVertices(Grafo* grafo, char* file);

/**
 * @brief Guarda as arestas do grafo num ficheiro binário.
 */
bool GuardarArestas(Grafo* grafo, char* file);

/**
 * @brief Carrega as arestas de um ficheiro binário para o grafo.
 */
bool CarregarArestas(Grafo* grafo, char* file);

/**
 * @brief Guarda as posições nefastas associadas a uma aresta num ficheiro binário.
 */
bool GuardarNefastas(FILE* ficheiro, Aresta* aresta);

/**
 * @brief Carrega as posições nefastas de uma aresta a partir de um ficheiro binário.
 */
void CarregarNefastas(FILE* ficheiro, Aresta* aresta);

/**
 * @brief Cria um novo grafo com base nas dimensões especificadas.
 */
Grafo* CriarGrafo(int linhas, int colunas);

/**
 * @brief Adiciona um novo vértice ao grafo.
 */
bool AdicionarVertice(Grafo* grafo, Vertice* verticeCriado);

/**
 * @brief Atualiza o grafo com as novas ligações e nefastas após inserção de um vértice.
 */
bool PercorrerGrafo(Grafo* grafo, Vertice* vertice);

/**
 * @brief Cria um novo vértice com dados especificados e insere-o no grafo.
 */
Vertice* CriarVertice(Grafo* grafo, int linha, int coluna, char frequencia);

/**
 * @brief Elimina um vértice do grafo com base na sua posição.
 */
Vertice* EliminarVertice(Grafo* grafo, int linha, int coluna);

/**
 * @brief Edita um vértice substituindo-o por um novo com frequência alterada.
 */
Vertice* EditarVertice(Grafo* grafo, int linha, int coluna, char frequencia);

/**
 * @brief Procura e retorna um vértice com base na sua posição.
 */
Vertice* EncontrarVertice(Grafo* grafo, int linha, int coluna);

/**
 * @brief Cria uma aresta entre dois vértices.
 */
Aresta* CriarAresta(Vertice* verticeAtual, Vertice* verticeInserido);

/**
 * @brief Remove uma aresta entre dois vértices.
 */
Aresta* EliminarAresta(Vertice* verticeOrigem, Vertice* verticeDestino);

/**
 * @brief Adiciona uma ou duas posições nefastas a uma aresta.
 */
bool AdicionarNefasta(Nefasta* nefastaAtual, Nefasta* nefastaInserida, Vertice* verticeAtual, Vertice* verticeInserido);

/**
 * @brief Realiza uma travessia em profundidade (DFS) a partir de um vértice.
 */
bool PercorrerArestasDFS(Vertice* vertice);

/**
 * @brief Verifica se já existe algum dos vértices em posições dadas.
 */
bool ExisteVertice(Grafo* grafo, int atual[], int inserido[]);

/**
 * @brief Calcula e cria posições nefastas com base nas posições de dois vértices.
 */
bool CriarPosicaoNefasta(Vertice* verticeAtual, Vertice* verticeInserido, Grafo* grafo);

/**
 * @brief Cria estruturas Nefasta a partir de duas posições.
 */
Nefasta* CriarNefasta(Vertice* verticeAtual, Vertice* verticeInserido, Grafo* grafo, int atual[], int inserido[]);

/**
 * @brief Realiza uma travessia em profundidade (DFS) sobre todo o grafo.
 */
bool PercorrerGrafoDFS(Grafo* grafo);

/**
 * @brief Executa DFS entre dois vértices específicos.
 */
bool PercorrerVerticeDFS(Vertice* primVertice, Vertice* segVertice);

/**
 * @brief Executa BFS a partir de um vértice, até encontrar (ou não) um destino.
 */
bool PercorrerVerticeBFS(Vertice* origem, Vertice* destino);

/**
 * @brief Realiza uma travessia em largura (BFS) sobre todo o grafo.
 */
bool PercorrerGrafoBFS(Grafo* grafo);

/**
 * @brief Percorre as arestas de um vértice e adiciona os adjacentes à fila (BFS).
 */
Espera* PercorrerArestasBFS(Aresta* listaArestas, Espera* queue);

/**
 * @brief Verifica a existência de interseções diagonais entre vértices de frequências diferentes.
 */
bool IntersecoesVertices(Grafo* grafo);
