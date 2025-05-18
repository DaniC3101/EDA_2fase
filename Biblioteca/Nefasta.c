#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Estruturas.h"
/**
 * @brief Verifica se uma posição já existe como vértice no grafo.
 *
 * Percorre a lista de vértices do grafo e verifica se alguma das posições dadas
 * corresponde à posição de um vértice já existente.
 *
 * @param grafo Apontador para o grafo.
 * @param atual Array com as coordenadas da primeira posição.
 * @param inserido Array com as coordenadas da segunda posição.
 * @return true Se alguma das posições já existir no grafo.
 */
bool ExisteVertice(Grafo* grafo, int atual[], int inserido[])
{
	Vertice* auxVertice = grafo->primVertice;

	while (auxVertice != NULL)
	{
		if (atual[0] == auxVertice->dados.posicao[0] && atual[1] == auxVertice->dados.posicao[1])
		{
			return true;
		}
		if (inserido[0] == auxVertice->dados.posicao[0] && inserido[1] == auxVertice->dados.posicao[1])
		{
			return true;
		}
		auxVertice = auxVertice->proxVertice;
	}
	return false;
}

/**
 * @brief Cria as posições com efeito nefasto entre dois vértices.
 *
 * Calcula as posições nefastas com base na distância entre os vértices.
 * Verifica se as posições já existem no grafo ou se estão fora dos limites
 * e chama a função CriarNefasta para as registar.
 *
 * @param verticeAtual Vértice de origem.
 * @param verticeInserido Vértice de destino.
 * @param grafo Apontador para o grafo.
 * @return true Se a criação das posições nefastas foi realizada com sucesso.
 */
bool CriarPosicaoNefasta(Vertice* verticeAtual, Vertice* verticeInserido, Grafo* grafo)
{
	int xDif = abs(verticeAtual->dados.posicao[0] - verticeInserido->dados.posicao[0]);
	int yDif = abs(verticeAtual->dados.posicao[1] - verticeInserido->dados.posicao[1]);
	int atual[2], inserido[2];

	if ((xDif + yDif >= 2) && (verticeAtual->dados.posicao[0] + xDif == verticeInserido->dados.posicao[0]))
	{
		atual[0] = verticeAtual->dados.posicao[0] - xDif;
		inserido[0] = verticeInserido->dados.posicao[0] + xDif;

		if (verticeAtual->dados.posicao[1] + yDif == verticeInserido->dados.posicao[1])
		{
			atual[1] = verticeAtual->dados.posicao[1] - yDif;
			inserido[1] = verticeInserido->dados.posicao[1] + yDif;
		}
		else
		{
			atual[1] = verticeAtual->dados.posicao[1] + yDif;
			inserido[1] = verticeInserido->dados.posicao[1] - yDif;
		}
	}
	else
	{
		atual[0] = verticeAtual->dados.posicao[0] + xDif;
		inserido[0] = verticeInserido->dados.posicao[0] - xDif;

		if (verticeAtual->dados.posicao[1] + yDif == verticeInserido->dados.posicao[1])
		{
			atual[1] = verticeAtual->dados.posicao[1] - yDif;
			inserido[1] = verticeInserido->dados.posicao[1] + yDif;
		}
		else
		{
			atual[1] = verticeAtual->dados.posicao[1] + yDif;
			inserido[1] = verticeInserido->dados.posicao[1] - yDif;
		}
	}

	bool atualExiste = ExisteVertice(grafo, atual, inserido);
	bool inseridoExiste = ExisteVertice(grafo, atual, inserido);

	if (atual == NULL)
	{
		CriarNefasta(verticeAtual, verticeInserido, grafo, NULL, inserido);
		return true;
	}
	if (inserido == NULL)
	{
		CriarNefasta(verticeAtual, verticeInserido, grafo, atual, NULL);
		return true;
	}
	if ((atual[0] > grafo->dimensao[0] || atual[1] > grafo->dimensao[1]) || (inserido[0] > grafo->dimensao[0] || inserido[1] > grafo->dimensao[1]))
	{
		if (atual[0] > grafo->dimensao[0] || atual[1] > grafo->dimensao[1])
		{
			CriarNefasta(verticeAtual, verticeInserido, grafo, NULL, inserido);
			return true;
		}
		if (inserido[0] > grafo->dimensao[0] || inserido[1] > grafo->dimensao[1])
		{
			CriarNefasta(verticeAtual, verticeInserido, grafo, atual, NULL);
			return true;
		}
	}
	CriarNefasta(verticeAtual, verticeInserido, grafo, atual, inserido);
	return true;
}
/**
 * @brief Cria e inicializa uma ou duas estruturas Nefasta com base nas posições indicadas.
 *
 * Verifica se as posições são válidas e dentro dos limites do grafo. Para cada posição válida,
 * aloca memória para a estrutura Nefasta, define os seus dados e chama AdicionarNefasta.
 *
 * @param verticeAtual Vértice de origem.
 * @param verticeInserido Vértice de destino.
 * @param grafo Apontador para o grafo.
 * @param atual Posição nefastamente afetada no lado do vértice atual (pode ser NULL).
 * @param inserido Posição nefastamente afetada no lado do vértice inserido (pode ser NULL).
 * @return Nefasta* Retorna true após executar a criação.
 */
Nefasta* CriarNefasta(Vertice* verticeAtual, Vertice* verticeInserido, Grafo* grafo, int atual[], int inserido[])
{
	if (atual != NULL && atual[0] > 0 && atual[0] <= grafo->dimensao[0] && atual[1] > 0 && atual[1] <= grafo->dimensao[1])
	{
		Nefasta* nefastaAtual = (Nefasta*)malloc(sizeof(Nefasta));
		nefastaAtual->dados.posicao[0] = atual[0];
		nefastaAtual->dados.posicao[1] = atual[1];
		nefastaAtual->dados.frequencia = verticeAtual->dados.frequencia;
		nefastaAtual->proxNefasta = NULL;
		AdicionarNefasta(nefastaAtual, NULL, verticeAtual, verticeInserido);
	}
	if (inserido != NULL && inserido[0] > 0 && inserido[0] <= grafo->dimensao[0] && inserido[1] > 0 && inserido[1] <= grafo->dimensao[1])
	{
		Nefasta* nefastaInserida = (Nefasta*)malloc(sizeof(Nefasta));
		nefastaInserida->proxNefasta = NULL;
		nefastaInserida->dados.posicao[0] = inserido[0];
		nefastaInserida->dados.posicao[1] = inserido[1];
		nefastaInserida->dados.frequencia = verticeAtual->dados.frequencia;
		AdicionarNefasta(NULL, nefastaInserida, verticeAtual, verticeInserido);
	}
	return true;
}
/**
 * @brief Adiciona uma ou duas posições nefastas a uma aresta entre dois vértices.
 *
 * Percorre a lista de arestas do vértice atual até encontrar a que liga ao vértice inserido
 * e adiciona as estruturas Nefasta no fim da lista correspondente.
 *
 * @param nefastaAtual Estrutura Nefasta associada à posição do vértice atual (pode ser NULL).
 * @param nefastaInserida Estrutura Nefasta associada à posição do vértice inserido (pode ser NULL).
 * @param verticeAtual Vértice de origem.
 * @param verticeInserido Vértice de destino.
 * @return true Se a inserção foi realizada com sucesso.
 */
bool AdicionarNefasta(Nefasta* nefastaAtual, Nefasta* nefastaInserida, Vertice* verticeAtual, Vertice* verticeInserido)
{
	Aresta* auxAresta = verticeAtual->primAresta;
	while (auxAresta != NULL)
	{
		if (auxAresta->adjVertice == verticeInserido)
		{
			if (nefastaAtual != NULL)
			{
				nefastaAtual->proxNefasta = NULL;
				if (auxAresta->primNefasta == NULL)
				{
					auxAresta->primNefasta = nefastaAtual;
				}
				else
				{
					Nefasta* auxNefasta = auxAresta->primNefasta;
					while (auxNefasta->proxNefasta != NULL)
					{
						auxNefasta = auxNefasta->proxNefasta;
					}
					auxNefasta->proxNefasta = nefastaAtual;
				}
			}
			if (nefastaInserida != NULL)
			{
				nefastaInserida->proxNefasta = NULL;
				if (auxAresta->primNefasta == NULL)
				{
					auxAresta->primNefasta = nefastaInserida;
				}
				else
				{
					Nefasta* auxNefasta = auxAresta->primNefasta;
					while (auxNefasta->proxNefasta != NULL)
					{
						auxNefasta = auxNefasta->proxNefasta;
					}
					auxNefasta->proxNefasta = nefastaInserida;
				}
			}
		}
		auxAresta = auxAresta->proxAresta;
	}
	return true;
}
