#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Estruturas.h"
/**
 * @brief Cria e inicializa um novo grafo com as dimens�es indicadas.
 *
 * Aloca mem�ria para a estrutura do grafo, define as suas dimens�es
 * e inicializa o ponteiro para o primeiro v�rtice como NULL.
 *
 * @param linhas N�mero de linhas da matriz do grafo.
 * @param colunas N�mero de colunas da matriz do grafo.
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
 * @brief Adiciona um novo v�rtice ao grafo.
 *
 * Insere o v�rtice no final da lista ligada de v�rtices do grafo.
 * Ap�s a inser��o, chama a fun��o PercorrerGrafo para atualizar
 * as liga��es entre o novo v�rtice e os existentes.
 *
 * @param grafo Apontador para o grafo onde o v�rtice ser� inserido.
 * @param verticeCriado Apontador para o v�rtice a adicionar.
 * @return true Se o v�rtice foi adicionado com sucesso.
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
 * @brief Atualiza o grafo com base nas frequ�ncias dos v�rtices.
 *
 * Percorre todos os v�rtices do grafo e, sempre que encontra um v�rtice
 * com a mesma frequ�ncia que o novo v�rtice inserido, cria uma aresta entre eles
 * e identifica posi��es nefastas.
 *
 * @param grafo Apontador para o grafo a ser percorrido.
 * @param vertice V�rtice recentemente inserido no grafo.
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
