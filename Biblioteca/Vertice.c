#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Estruturas.h"
/**
 * @brief Cria e inicializa um novo v�rtice com os dados fornecidos.
 *
 * Define a posi��o e frequ�ncia do v�rtice, inicializa os seus campos internos
 * e insere-o no grafo atrav�s da fun��o AdicionarVertice.
 *
 * @param grafo Apontador para o grafo onde o v�rtice ser� inserido.
 * @param linha Linha da posi��o do v�rtice.
 * @param coluna Coluna da posi��o do v�rtice.
 * @param frequencia Frequ�ncia da antena.
 * @return Vertice* Apontador para o v�rtice criado.
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
 * @brief Remove um v�rtice do grafo com base na sua posi��o.
 *
 * Procura o v�rtice na lista ligada do grafo, elimina todas as arestas
 * que apontam para ele e remove-o da lista, libertando a mem�ria.
 *
 * @param grafo Apontador para o grafo.
 * @param linha Linha da posi��o do v�rtice.
 * @param coluna Coluna da posi��o do v�rtice.
 * @return Vertice* Apontador para o novo in�cio da lista de v�rtices.
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
 * @brief Edita um v�rtice removendo o existente e criando um novo com nova frequ�ncia.
 *
 * Elimina o v�rtice atual na posi��o indicada e insere um novo v�rtice com a nova frequ�ncia.
 *
 * @param grafo Apontador para o grafo.
 * @param linha Linha da posi��o do v�rtice.
 * @param coluna Coluna da posi��o do v�rtice.
 * @param frequencia Nova frequ�ncia a atribuir.
 * @return Vertice* Apontador para o v�rtice editado.
 */
Vertice* EditarVertice(Grafo* grafo, int linha, int coluna, char frequencia)
{
	EliminarVertice(grafo, linha, coluna);
	Vertice* verticeEditado = CriarVertice(grafo, linha, coluna, frequencia);
	return verticeEditado;
}
/**
 * @brief Procura e devolve um v�rtice no grafo com base na sua posi��o.
 *
 * Percorre a lista ligada de v�rtices at� encontrar um com as coordenadas especificadas.
 *
 * @param grafo Apontador para o grafo.
 * @param linha Linha da posi��o a procurar.
 * @param coluna Coluna da posi��o a procurar.
 * @return Vertice* Apontador para o v�rtice encontrado, ou NULL se n�o existir.
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
 * @brief Verifica se existem interse��es diagonais entre v�rtices com frequ�ncias diferentes.
 *
 * Percorre todas as combina��es de v�rtices e, sempre que encontra dois com frequ�ncias diferentes,
 * calcula se existe interse��o diagonal com base na dist�ncia em x e y.
 *
 * @param grafo Apontador para o grafo.
 * @return true Se existir pelo menos uma interse��o.
 * @return false Se n�o existirem interse��es diagonais.
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
