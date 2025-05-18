#pragma once

/**
 * @brief Estrutura para representar os dados de um v�rtice (posi��o e frequ�ncia).
 */
typedef struct
{
	int posicao[2];
	char frequencia;
} Dados;

/**
 * @brief Estrutura que representa o grafo, com lista de v�rtices e dimens�o.
 */
typedef struct
{
	struct Vertice* primVertice;
	int dimensao[2];
} Grafo;

/**
 * @brief Estrutura de um v�rtice, com os seus dados, arestas e estado de visita.
 */
typedef struct
{
	Dados dados;
	struct Vertice* proxVertice;
	struct Aresta* primAresta;
	bool visitado;
} Vertice;

/**
 * @brief Estrutura de uma aresta, com liga��o a um v�rtice adjacente e lista de nefastas.
 */
typedef struct
{
	Vertice* adjVertice;
	struct Aresta* proxAresta;
	struct Nefasta* primNefasta;
} Aresta;

/**
 * @brief Estrutura que representa uma posi��o nefasta, associada a uma aresta.
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
 * @brief Estrutura utilizada para guardar um v�rtice em ficheiro bin�rio.
 */
typedef struct
{
	Dados dados;
	bool visitado;
} VerticeFile;

/**
 * @brief Estrutura utilizada para guardar uma aresta em ficheiro bin�rio.
 */
typedef struct
{
	int origemPos[2];
	int destinoPos[2];
} ArestaFile;

/**
 * @brief Estrutura utilizada para guardar uma posi��o nefasta em ficheiro bin�rio.
 */
typedef struct
{
	int posicao[2];
	char frequencia;
} NefastaFile;

// === Declara��es de Fun��es ===

/**
 * @brief Carrega os dados do grafo a partir de um ficheiro de texto com matriz.
 */
Grafo* CarregarMatriz(char* nomeFicheiro);

/**
 * @brief Conta o n�mero de linhas, colunas e v�rtices num ficheiro de texto.
 */
int ContarLinhasColunas(FILE* grafoTXT, int dimensao[], int* contadorVertice);

/**
 * @brief Encontra e armazena os v�rtices identificados num ficheiro de texto.
 */
Dados* EncontrarVertices(FILE* grafoTXT, Dados* dados);

/**
 * @brief Guarda os v�rtices do grafo num ficheiro bin�rio.
 */
bool GuardarVertices(Grafo* grafo, char* file);

/**
 * @brief Carrega os v�rtices de um ficheiro bin�rio para o grafo.
 */
Grafo* CarregarVertices(Grafo* grafo, char* file);

/**
 * @brief Guarda as arestas do grafo num ficheiro bin�rio.
 */
bool GuardarArestas(Grafo* grafo, char* file);

/**
 * @brief Carrega as arestas de um ficheiro bin�rio para o grafo.
 */
bool CarregarArestas(Grafo* grafo, char* file);

/**
 * @brief Guarda as posi��es nefastas associadas a uma aresta num ficheiro bin�rio.
 */
bool GuardarNefastas(FILE* ficheiro, Aresta* aresta);

/**
 * @brief Carrega as posi��es nefastas de uma aresta a partir de um ficheiro bin�rio.
 */
void CarregarNefastas(FILE* ficheiro, Aresta* aresta);

/**
 * @brief Cria um novo grafo com base nas dimens�es especificadas.
 */
Grafo* CriarGrafo(int linhas, int colunas);

/**
 * @brief Adiciona um novo v�rtice ao grafo.
 */
bool AdicionarVertice(Grafo* grafo, Vertice* verticeCriado);

/**
 * @brief Atualiza o grafo com as novas liga��es e nefastas ap�s inser��o de um v�rtice.
 */
bool PercorrerGrafo(Grafo* grafo, Vertice* vertice);

/**
 * @brief Cria um novo v�rtice com dados especificados e insere-o no grafo.
 */
Vertice* CriarVertice(Grafo* grafo, int linha, int coluna, char frequencia);

/**
 * @brief Elimina um v�rtice do grafo com base na sua posi��o.
 */
Vertice* EliminarVertice(Grafo* grafo, int linha, int coluna);

/**
 * @brief Edita um v�rtice substituindo-o por um novo com frequ�ncia alterada.
 */
Vertice* EditarVertice(Grafo* grafo, int linha, int coluna, char frequencia);

/**
 * @brief Procura e retorna um v�rtice com base na sua posi��o.
 */
Vertice* EncontrarVertice(Grafo* grafo, int linha, int coluna);

/**
 * @brief Cria uma aresta entre dois v�rtices.
 */
Aresta* CriarAresta(Vertice* verticeAtual, Vertice* verticeInserido);

/**
 * @brief Remove uma aresta entre dois v�rtices.
 */
Aresta* EliminarAresta(Vertice* verticeOrigem, Vertice* verticeDestino);

/**
 * @brief Adiciona uma ou duas posi��es nefastas a uma aresta.
 */
bool AdicionarNefasta(Nefasta* nefastaAtual, Nefasta* nefastaInserida, Vertice* verticeAtual, Vertice* verticeInserido);

/**
 * @brief Realiza uma travessia em profundidade (DFS) a partir de um v�rtice.
 */
bool PercorrerArestasDFS(Vertice* vertice);

/**
 * @brief Verifica se j� existe algum dos v�rtices em posi��es dadas.
 */
bool ExisteVertice(Grafo* grafo, int atual[], int inserido[]);

/**
 * @brief Calcula e cria posi��es nefastas com base nas posi��es de dois v�rtices.
 */
bool CriarPosicaoNefasta(Vertice* verticeAtual, Vertice* verticeInserido, Grafo* grafo);

/**
 * @brief Cria estruturas Nefasta a partir de duas posi��es.
 */
Nefasta* CriarNefasta(Vertice* verticeAtual, Vertice* verticeInserido, Grafo* grafo, int atual[], int inserido[]);

/**
 * @brief Realiza uma travessia em profundidade (DFS) sobre todo o grafo.
 */
bool PercorrerGrafoDFS(Grafo* grafo);

/**
 * @brief Executa DFS entre dois v�rtices espec�ficos.
 */
bool PercorrerVerticeDFS(Vertice* primVertice, Vertice* segVertice);

/**
 * @brief Executa BFS a partir de um v�rtice, at� encontrar (ou n�o) um destino.
 */
bool PercorrerVerticeBFS(Vertice* origem, Vertice* destino);

/**
 * @brief Realiza uma travessia em largura (BFS) sobre todo o grafo.
 */
bool PercorrerGrafoBFS(Grafo* grafo);

/**
 * @brief Percorre as arestas de um v�rtice e adiciona os adjacentes � fila (BFS).
 */
Espera* PercorrerArestasBFS(Aresta* listaArestas, Espera* queue);

/**
 * @brief Verifica a exist�ncia de interse��es diagonais entre v�rtices de frequ�ncias diferentes.
 */
bool IntersecoesVertices(Grafo* grafo);
