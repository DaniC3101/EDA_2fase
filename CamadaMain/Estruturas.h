#pragma once
#include <stdbool.h>
#define FICHEIRO 30
typedef struct
{
	int posicao[2];
	char frequencia;
} Dados;

typedef struct
{
	struct Vertice* primVertice;
	int dimensao[2];
}Grafo;

typedef struct
{
	Dados dados;
	struct Vertice* proxVertice;
	struct Aresta* primAresta;
	bool visitado;
} Vertice;

typedef struct
{
	Vertice* adjVertice;
	struct Aresta* proxAresta;
	struct Nefasta* primNefasta;
}Aresta;

typedef struct
{
	struct Nefasta* proxNefasta;
	Dados dados;
}Nefasta;

typedef struct 
{
	Vertice* vertice;
	struct Espera* proxVertice;
} Espera;

typedef struct
{
	Dados dados;
	bool visitado;
}VerticeFile;

typedef struct 
{
	int origemPos[2];   
	int destinoPos[2];  
} ArestaFile;

typedef struct {
	int posicao[2];
	char frequencia;
} NefastaFile;

Grafo* CarregarMatriz(char* nomeFicheiro);
int ContarLinhasColunas(FILE* grafoTXT, int dimensao[], int* contadorVertice);
Dados* EncontrarVertices(FILE* grafoTXT, Dados* dados);

bool GuardarVertices(Grafo* grafo, char* file);
Grafo* CarregarVertices(Grafo* grafo, char* file);
bool GuardarArestas(Grafo* grafo, char* file);
bool CarregarArestas(Grafo* grafo, char* file);
bool GuardarNefastas(FILE* ficheiro, Aresta* aresta);
void CarregarNefastas(FILE* ficheiro, Aresta* aresta);

Grafo* CriarGrafo(int linhas, int colunas);
bool AdicionarVertice(Grafo* grafo, Vertice* verticeCriado);
bool PercorrerGrafo(Grafo* grafo, Vertice* vertice);

Vertice* CriarVertice(Grafo* grafo, int linha, int coluna, char frequencia);
Vertice* EliminarVertice(Grafo* grafo, int linha, int coluna);
Vertice* EditarVertice(Grafo* grafo, int linha, int coluna, char frequencia);
Vertice* EncontrarVertice(Grafo* grafo, int linha, int coluna);

Aresta* CriarAresta(Vertice* verticeAtual, Vertice* verticeInserido);
Aresta* EliminarAresta(Vertice* verticeOrigem, Vertice* verticeDestino);
bool AdicionarNefasta(Nefasta* nefastaAtual, Nefasta* nefastaInserida, Vertice* verticeAtual, Vertice* verticeInserido);
bool PercorrerArestasDFS(Vertice* vertice);

bool ExisteVertice(Grafo* grafo, int atual[], int inserido[]);
bool CriarPosicaoNefasta(Vertice* verticeAtual, Vertice* verticeInserido, Grafo* grafo);
Nefasta* CriarNefasta(Vertice* verticeAtual, Vertice* verticeInserido, Grafo* grafo, int atual[], int inserido[]);

bool PercorrerGrafoDFS(Grafo* grafo);
bool PercorrerVerticeDFS(Vertice* primVertice, Vertice* segVertice);

bool PercorrerVerticeBFS(Vertice* origem, Vertice* destino);
bool PercorrerGrafoBFS(Grafo* grafo);

Espera* PercorrerArestasBFS(Aresta* listaArestas, Espera* queue);