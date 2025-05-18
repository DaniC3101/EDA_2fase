#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Estruturas.h"

/**
 * @brief Realiza uma travessia em profundidade (DFS) em todo o grafo.
 *
 * Percorre todos os vértices do grafo e, para cada um que ainda não tenha sido visitado,
 * inicia a procura em profundidade através da função PercorrerArestasDFS.
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
 * @brief Procura recursivamente um caminho entre dois vértices utilizando DFS.
 *
 * Marca o vértice atual como visitado, imprime o caminho e verifica se corresponde ao vértice de destino.
 * Caso não corresponda, continua a procurar recursivamente pelas arestas adjacentes.
 *
 * @param primVertice Vértice de origem.
 * @param segVertice Vértice de destino.
 * @return true Se o caminho entre os dois vértices for encontrado.
 */
bool PercorrerVerticeDFS(Vertice* primVertice, Vertice* segVertice)
{
	// Código mantido conforme pedido
}

/**
 * @brief Realiza uma travessia em largura (BFS) em todo o grafo.
 *
 * Percorre todos os vértices do grafo e inicia a procura em largura (BFS) a partir
 * de cada vértice ainda não visitado, utilizando a função PercorrerVerticeBFS.
 *
 * @param grafo Apontador para o grafo a ser percorrido.
 * @return true Se a travessia foi realizada com sucesso.
 */
bool PercorrerGrafoBFS(Grafo* grafo)
{
	// Código mantido conforme pedido
}

/**
 * @brief Realiza uma procura em largura (BFS) a partir de um vértice de origem.
 *
 * Utiliza uma fila para visitar os vértices de forma sequencial e marca-os como visitados.
 * Se um vértice de destino for especificado, a procura termina quando esse vértice é alcançado.
 *
 * @param origem Vértice de partida.
 * @param destino Vértice de destino (opcional).
 * @return true Se o destino for alcançado ou a travessia for concluída.
 */
bool PercorrerVerticeBFS(Vertice* origem, Vertice* destino)
{
	// Código mantido conforme pedido
}
