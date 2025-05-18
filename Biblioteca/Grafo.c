#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Estruturas.h"
/**
 * @brief Cria e inicializa um novo grafo com as dimensões indicadas.
 *
 * Aloca memória para a estrutura do grafo, define as suas dimensões
 * e inicializa o ponteiro para o primeiro vértice como NULL.
 *
 * @param linhas Número de linhas da matriz do grafo.
 * @param colunas Número de colunas da matriz do grafo.
 * @return Grafo* Apontador para o grafo criado, ou NULL em caso de falha.
 */
Grafo* CriarGrafo(int linhas, int colunas)
{
	Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
	if (grafo == NULL)
	{
		return false;
	}
	grafo->dimensao[0] = linhas;
	grafo->dimensao[1] = colunas;
	grafo->primVertice = NULL;
	return grafo;
}
/**
 * @brief Adiciona um novo vértice ao grafo.
 *
 * Insere o vértice no final da lista ligada de vértices do grafo.
 * Após a inserção, chama a função PercorrerGrafo para atualizar
 * as ligações entre o novo vértice e os existentes.
 *
 * @param grafo Apontador para o grafo onde o vértice será inserido.
 * @param verticeCriado Apontador para o vértice a adicionar.
 * @return true Se o vértice foi adicionado com sucesso.
 */
bool AdicionarVertice(Grafo* grafo, Vertice* verticeCriado)
{
	if (grafo->primVertice == NULL)
	{
		grafo->primVertice = verticeCriado;
		return true;
	}
	else
	{
		Vertice* auxVertice = grafo->primVertice;
		while (auxVertice->proxVertice != NULL)
		{
			auxVertice = auxVertice->proxVertice;
		}
		auxVertice->proxVertice = verticeCriado;
		PercorrerGrafo(grafo, verticeCriado);
		return true;
	}
}
/**
 * @brief Atualiza o grafo com base nas frequências dos vértices.
 *
 * Percorre todos os vértices do grafo e, sempre que encontra um vértice
 * com a mesma frequência que o novo vértice inserido, cria uma aresta entre eles
 * e identifica posições nefastas.
 *
 * @param grafo Apontador para o grafo a ser percorrido.
 * @param vertice Vértice recentemente inserido no grafo.
 * @return true Se o processo foi realizado com sucesso.
 */
bool PercorrerGrafo(Grafo* grafo, Vertice* vertice)
{
	Vertice* auxVertice = grafo->primVertice;
	while (auxVertice != NULL)
	{
		if (auxVertice->dados.frequencia == vertice->dados.frequencia && auxVertice != vertice)
		{
			CriarAresta(auxVertice, vertice);
			CriarPosicaoNefasta(auxVertice, vertice, grafo);
		}
		auxVertice = auxVertice->proxVertice;
	}
	return true;
}
