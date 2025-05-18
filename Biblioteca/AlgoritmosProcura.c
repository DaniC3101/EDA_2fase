#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Estruturas.h"

/**
 * @brief Realiza uma travessia em profundidade (DFS) em todo o grafo.
 *
 * Percorre todos os v�rtices do grafo e, para cada um que ainda n�o tenha sido visitado,
 * inicia a procura em profundidade atrav�s da fun��o PercorrerArestasDFS.
 *
 * @param grafo Apontador para o grafo a ser percorrido.
 * @return true Se a travessia foi realizada com sucesso.
 */
bool PercorrerGrafoDFS(Grafo* grafo)
{
	Vertice* auxVertice = grafo->primVertice;

	while (auxVertice != NULL)
	{
		if (auxVertice->visitado != true)
		{
			PercorrerArestasDFS(auxVertice);
		}
		auxVertice = auxVertice->proxVertice;
	}
	return true;
}

/**
 * @brief Procura recursivamente um caminho entre dois v�rtices utilizando DFS.
 *
 * Marca o v�rtice atual como visitado, imprime o caminho e verifica se corresponde ao v�rtice de destino.
 * Caso n�o corresponda, continua a procurar recursivamente pelas arestas adjacentes.
 *
 * @param primVertice V�rtice de origem.
 * @param segVertice V�rtice de destino.
 * @return true Se o caminho entre os dois v�rtices for encontrado.
 */
bool PercorrerVerticeDFS(Vertice* primVertice, Vertice* segVertice)
{
	// C�digo mantido conforme pedido
}

/**
 * @brief Realiza uma travessia em largura (BFS) em todo o grafo.
 *
 * Percorre todos os v�rtices do grafo e inicia a procura em largura (BFS) a partir
 * de cada v�rtice ainda n�o visitado, utilizando a fun��o PercorrerVerticeBFS.
 *
 * @param grafo Apontador para o grafo a ser percorrido.
 * @return true Se a travessia foi realizada com sucesso.
 */
bool PercorrerGrafoBFS(Grafo* grafo)
{
	// C�digo mantido conforme pedido
}

/**
 * @brief Realiza uma procura em largura (BFS) a partir de um v�rtice de origem.
 *
 * Utiliza uma fila para visitar os v�rtices de forma sequencial e marca-os como visitados.
 * Se um v�rtice de destino for especificado, a procura termina quando esse v�rtice � alcan�ado.
 *
 * @param origem V�rtice de partida.
 * @param destino V�rtice de destino (opcional).
 * @return true Se o destino for alcan�ado ou a travessia for conclu�da.
 */
bool PercorrerVerticeBFS(Vertice* origem, Vertice* destino)
{
	// C�digo mantido conforme pedido
}
