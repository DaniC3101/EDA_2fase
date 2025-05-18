#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Estruturas.h"

/**
 * @brief Cria uma nova aresta entre dois v�rtices.
 *
 * Aloca mem�ria para uma nova aresta, liga-a ao v�rtice de destino e insere-a no final
 * da lista de adjac�ncias do v�rtice de origem. Inicializa os campos da aresta.
 *
 * @param verticeAtual Apontador para o v�rtice de origem.
 * @param verticeInserido Apontador para o v�rtice de destino.
 * @return Aresta* Apontador para a aresta criada.
 */
Aresta* CriarAresta(Vertice* verticeAtual, Vertice* verticeInserido)
{
	Aresta* arestaCriada = (Aresta*)malloc(sizeof(Aresta));
	if (arestaCriada == NULL)
	{
		return false;
	}

	arestaCriada->adjVertice = verticeInserido;
	arestaCriada->proxAresta = NULL;
	arestaCriada->primNefasta = NULL;
	if (verticeAtual->primAresta == NULL)
	{
		verticeAtual->primAresta = arestaCriada;
	}
	else
	{
		Aresta* auxAresta = verticeAtual->primAresta;
		while (auxAresta->proxAresta != NULL)
		{
			auxAresta = auxAresta->proxAresta;
		}
		auxAresta->proxAresta = arestaCriada;
	}
	return arestaCriada;
}
/**
 * @brief Remove uma aresta entre dois v�rtices.
 *
 * Percorre a lista de adjac�ncias do v�rtice de origem e remove a liga��o para o v�rtice de destino,
 * se existir. Liberta a mem�ria da aresta eliminada.
 *
 * @param verticeOrigem Apontador para o v�rtice de origem.
 * @param verticeDestino Apontador para o v�rtice de destino.
 * @return Aresta* Apontador para o in�cio atualizado da lista de arestas do v�rtice de origem.
 */
Aresta* EliminarAresta(Vertice* verticeOrigem, Vertice* verticeDestino)
{
	Aresta* auxAresta = verticeOrigem->primAresta;
	Aresta* eliminar = NULL;

	while (auxAresta != NULL)
	{
		if (auxAresta->adjVertice == verticeDestino)
		{
			if (eliminar == NULL)
			{
				verticeOrigem->primAresta = auxAresta->proxAresta;
			}
			else
			{
				eliminar->proxAresta = auxAresta->proxAresta;
			}
			free(auxAresta);
			return verticeOrigem->primAresta;
		}
		eliminar = auxAresta;
		auxAresta = auxAresta->proxAresta;
	}
	return NULL;
}
/**
 * @brief Percorre recursivamente as arestas de um v�rtice utilizando DFS.
 *
 * Marca o v�rtice atual como visitado, imprime-o, e continua a travessia em profundidade
 * para todos os v�rtices adjacentes ainda n�o visitados.
 *
 * @param vertice Apontador para o v�rtice inicial da travessia.
 * @return true Se a travessia foi realizada com sucesso.
 */
bool PercorrerArestasDFS(Vertice* vertice)
{
	if (vertice->visitado == true)
	{
		return false;
	}
	else
	{
		vertice->visitado = true;

		Aresta* auxAresta = vertice->primAresta;
		MostrarCaminho(vertice);
		while (auxAresta != NULL)
		{
			Vertice* auxVertice = auxAresta->adjVertice;
			if (auxVertice->visitado != true)
			{
				PercorrerArestasDFS(auxAresta->adjVertice);
			}
			auxAresta = auxAresta->proxAresta;
		}
	}
	return true;
}


