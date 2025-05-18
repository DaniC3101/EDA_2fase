#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Estruturas.h"
/**
 * @brief Percorre as arestas de um vértice e adiciona os adjacentes não visitados à fila (BFS).
 *
 * Para cada aresta da lista, verifica se o vértice adjacente ainda não foi visitado.
 * Se não tiver sido, marca-o como visitado e adiciona-o à fila (estrutura Espera) para futura exploração.
 *
 * @param listaArestas Lista de arestas do vértice atual.
 * @param queue Fila atual de vértices a visitar.
 * @return Espera* Fila atualizada com os novos vértices descobertos.
 */
Espera* PercorrerArestasBFS(Aresta* listaArestas, Espera* queue) 
{
	Aresta* auxAresta = listaArestas;

	while (auxAresta != NULL) 
	{
		Vertice* auxVertice = auxAresta->adjVertice;
		if (auxVertice != NULL && auxVertice->visitado != true)
		{
			auxVertice->visitado = true;

			Espera* nova = (Espera*)malloc(sizeof(Espera));
			nova->vertice = auxVertice;
			nova->proxVertice = NULL;

			if (queue == NULL) 
			{
				queue = nova;
			}
			else 
			{
				Espera* auxEspera = queue;
				while (auxEspera->proxVertice != NULL)
				{
					auxEspera = auxEspera->proxVertice;
				}
				auxEspera->proxVertice = nova;
			}
		}
		auxAresta = auxAresta->proxAresta;
	}
	return queue;
}
