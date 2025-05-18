#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Estruturas.h"
/**
 * @brief Percorre as arestas de um v�rtice e adiciona os adjacentes n�o visitados � fila (BFS).
 *
 * Para cada aresta da lista, verifica se o v�rtice adjacente ainda n�o foi visitado.
 * Se n�o tiver sido, marca-o como visitado e adiciona-o � fila (estrutura Espera) para futura explora��o.
 *
 * @param listaArestas Lista de arestas do v�rtice atual.
 * @param queue Fila atual de v�rtices a visitar.
 * @return Espera* Fila atualizada com os novos v�rtices descobertos.
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
