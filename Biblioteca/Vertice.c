#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Estruturas.h"
/**
 * @brief Cria e inicializa um novo vértice com os dados fornecidos.
 *
 * Define a posição e frequência do vértice, inicializa os seus campos internos
 * e insere-o no grafo através da função AdicionarVertice.
 *
 * @param grafo Apontador para o grafo onde o vértice será inserido.
 * @param linha Linha da posição do vértice.
 * @param coluna Coluna da posição do vértice.
 * @param frequencia Frequência da antena.
 * @return Vertice* Apontador para o vértice criado.
 */
Vertice* CriarVertice(Grafo* grafo, int linha, int coluna, char frequencia)
{
	Vertice* vertice = (Vertice*)malloc(sizeof(Vertice));
	if (vertice == NULL)
	{
		return false;
	}
	vertice->dados.posicao[0] = linha;
	vertice->dados.posicao[1] = coluna;
	vertice->dados.frequencia = frequencia;
	vertice->proxVertice = NULL;
	vertice->primAresta = NULL;
	vertice->visitado = false;
	AdicionarVertice(grafo, vertice);
	return vertice;
}
/**
 * @brief Remove um vértice do grafo com base na sua posição.
 *
 * Procura o vértice na lista ligada do grafo, elimina todas as arestas
 * que apontam para ele e remove-o da lista, libertando a memória.
 *
 * @param grafo Apontador para o grafo.
 * @param linha Linha da posição do vértice.
 * @param coluna Coluna da posição do vértice.
 * @return Vertice* Apontador para o novo início da lista de vértices.
 */
Vertice* EliminarVertice(Grafo* grafo,int linha, int coluna)
{
	Vertice* auxVertice = grafo->primVertice;
	Vertice* eliminar = NULL;

	while (auxVertice != NULL)
	{
		if (auxVertice->dados.posicao[0] == linha && auxVertice->dados.posicao[1])
		{
			Vertice* outro = grafo->primVertice;
			while (outro != NULL)
			{
				if (outro != auxVertice)
				{
					EliminarAresta(outro, auxVertice);
				}
				outro = outro->proxVertice;
			}

			if (eliminar == NULL)
			{
				grafo->primVertice = auxVertice->proxVertice;
			}
			else
			{
				eliminar->proxVertice = auxVertice->proxVertice;
			}
			free(auxVertice);
			return grafo->primVertice;
		}
		eliminar = auxVertice;
		auxVertice = auxVertice->proxVertice;
	}
	return NULL;
}
/**
 * @brief Edita um vértice removendo o existente e criando um novo com nova frequência.
 *
 * Elimina o vértice atual na posição indicada e insere um novo vértice com a nova frequência.
 *
 * @param grafo Apontador para o grafo.
 * @param linha Linha da posição do vértice.
 * @param coluna Coluna da posição do vértice.
 * @param frequencia Nova frequência a atribuir.
 * @return Vertice* Apontador para o vértice editado.
 */
Vertice* EditarVertice(Grafo* grafo, int linha, int coluna, char frequencia)
{
	EliminarVertice(grafo, linha, coluna);
	Vertice* verticeEditado = CriarVertice(grafo, linha, coluna, frequencia);
	return verticeEditado;
}
/**
 * @brief Procura e devolve um vértice no grafo com base na sua posição.
 *
 * Percorre a lista ligada de vértices até encontrar um com as coordenadas especificadas.
 *
 * @param grafo Apontador para o grafo.
 * @param linha Linha da posição a procurar.
 * @param coluna Coluna da posição a procurar.
 * @return Vertice* Apontador para o vértice encontrado, ou NULL se não existir.
 */
Vertice* EncontrarVertice(Grafo* grafo, int linha, int coluna)
{
	Vertice* auxVertice = grafo->primVertice;
	while (auxVertice != NULL)
	{
		if (auxVertice->dados.posicao[0] == linha && auxVertice->dados.posicao[1])
		{
			return auxVertice;
		}
		auxVertice = auxVertice->proxVertice;
	}
	return NULL;
}

/**
 * @brief Verifica se existem interseções diagonais entre vértices com frequências diferentes.
 *
 * Percorre todas as combinações de vértices e, sempre que encontra dois com frequências diferentes,
 * calcula se existe interseção diagonal com base na distância em x e y.
 *
 * @param grafo Apontador para o grafo.
 * @return true Se existir pelo menos uma interseção.
 * @return false Se não existirem interseções diagonais.
 */
bool IntersecoesVertices(Grafo* grafo)
{
	Vertice* v1 = grafo->primVertice;

	while (v1 != NULL)
	{
		Vertice* v2 = grafo->primVertice;

		while (v2 != NULL)
		{
			if (v1 != v2 && v1->dados.frequencia != v2->dados.frequencia)
			{
				int xIntersecao = abs(v1->dados.posicao[0] - v2->dados.posicao[0]);
				int yIntersecao = abs(v1->dados.posicao[1] - v2->dados.posicao[1]);

				if (xIntersecao == yIntersecao)
				{
					MostrarIntersecao(v1, v2);
					return true;
				}
			}
			v2 = v2->proxVertice;
		}
		v1 = v1->proxVertice;
	}
	return false;
}
