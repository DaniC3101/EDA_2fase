#pragma once
#include <stdio.h>
#include "Estruturas.h"
#include "ApoioMain.h"

/**
 * @brief Lista todos os vértices do grafo com as suas respetivas posições e frequências.
 *
 * Percorre a lista ligada de vértices do grafo e imprime a sua informação no ecrã.
 *
 * @param grafo Apontador para o grafo a ser listado.
 */
void ListaVertices(Grafo* grafo)
{
	Vertice* auxVertice = grafo->primVertice;  
	int i = 1;
	while (auxVertice != NULL)
	{
		printf("Vertice : %d \n	Coordenada: (%d, %d) \n	Frequencia: %c\n",i, auxVertice->dados.posicao[0], auxVertice->dados.posicao[1],auxVertice->dados.frequencia);
		i++;
		auxVertice = auxVertice->proxVertice;  
	}
	printf("\n");
}
/**
 * @brief Mostra todos os vértices, as arestas e as posições nefastas do grafo.
 *
 * Imprime no ecrã a lista de vértices, seguida das suas arestas e respetivas posições nefastas.
 *
 * @param grafo Apontador para o grafo a ser mostrado.
 */
void MostraGrafo(Grafo* grafo)
{
	Vertice* auxVertice = grafo->primVertice;
	ListaVertices(grafo);
	printf("\n");
	while (auxVertice != NULL)
	{
		ListaArestas(auxVertice);
		printf("\n");
		ListaNefastas(auxVertice);
		printf("\n");
		auxVertice = auxVertice->proxVertice;
	}
}
/**
 * @brief Lista todas as arestas associadas a um determinado vértice.
 *
 * Percorre a lista de arestas do vértice e imprime as posições dos vértices adjacentes.
 *
 * @param vertice Apontador para o vértice cujas arestas serão listadas.
 */
void ListaArestas(Vertice* vertice)
{
	Aresta* auxAresta = vertice->primAresta;
	int i = 1;
	printf("Vertice (%d,%d) com as seguintes arestas: \n", vertice->dados.posicao[0], vertice->dados.posicao[1]);
	while (auxAresta != NULL)
	{
		Vertice* auxVertice = auxAresta->adjVertice;
		printf("-> Aresta: (%d , %d) \n", auxVertice->dados.posicao[0], auxVertice->dados.posicao[1]);
		auxAresta = auxAresta->proxAresta;
	}
}

/**
 * @brief Lista todas as posições nefastas associadas às arestas de um vértice.
 *
 * Para cada aresta do vértice, imprime as posições consideradas nefastas.
 *
 * @param vertice Apontador para o vértice cujas posições nefastas serão listadas.
 */
void ListaNefastas(Vertice* vertice)
{
	Aresta* auxAresta = vertice->primAresta;
	while (auxAresta != NULL)
	{
		Vertice* auxVertice = auxAresta->adjVertice;
		printf("Aresta (%d, %d)\n", auxVertice->dados.posicao[0], auxVertice->dados.posicao[1]);
		Nefasta* auxNefasta = auxAresta->primNefasta;
		while (auxNefasta != NULL)
		{
			printf("-> Nefasta (%d , %d)\n", auxNefasta->dados.posicao[0], auxNefasta->dados.posicao[1]);
			auxNefasta = auxNefasta->proxNefasta;
		}
		auxAresta = auxAresta->proxAresta;
	}
}
/**
 * @brief Mostra uma etapa do caminho durante a travessia do grafo.
 *
 * Imprime no ecrã a posição do vértice visitado durante o percurso.
 *
 * @param vertice Apontador para o vértice a ser mostrado.
 */
void MostrarCaminho(Vertice* vertice)
{
	printf("-> Caminho: (%d, %d)\n", vertice->dados.posicao[0], vertice->dados.posicao[1]);
}
/**
 * @brief Mostra a representação matricial do grafo no ecrã.
 *
 * Imprime a matriz com as antenas (frequências), posições nefastas ('#') e espaços vazios ('.').
 *
 * @param grafo Apontador para o grafo a ser representado.
 */
void MostrarMatriz(Grafo* grafo)
{
	for (int i = 1; i <= grafo->dimensao[0]; i++)
	{
		for (int j = 1; j <= grafo->dimensao[1]; j++)
		{
			bool encontrado = false;

			Vertice* auxVertice = grafo->primVertice;
			while (auxVertice != NULL)
			{
				if (auxVertice->dados.posicao[0] == i && auxVertice->dados.posicao[1] == j)
				{
					printf("%c", auxVertice->dados.frequencia);
					encontrado = true;
					break;
				}
				auxVertice = auxVertice->proxVertice;
			}

			if (encontrado != true)
			{
				Vertice* v2 = grafo->primVertice;
				while (v2 != NULL && encontrado != true)
				{
					Aresta* a = v2->primAresta;
					while (a != NULL && encontrado != true)
					{
						Nefasta* n = a->primNefasta;
						while (n != NULL)
						{
							if (n->dados.posicao[0] == i && n->dados.posicao[1] == j)
							{
								printf("#");
								encontrado = true;
								break;
							}
							n = n->proxNefasta;
						}
						a = a->proxAresta;
					}
					v2 = v2->proxVertice;
				}
			}

			if (encontrado != true)
			{
				printf(".");
			}
		}
		printf("\n");
	}
}

/**
 * @brief Mostra uma interseção diagonal entre dois vértices com frequências diferentes.
 *
 * Utilizada para sinalizar a deteção de interseções diagonais no grafo.
 *
 * @param v1 Apontador para o primeiro vértice.
 * @param v2 Apontador para o segundo vértice.
 */
void MostrarIntersecao(Vertice* v1, Vertice* v2)
{
	printf("Intersecao diagonal entre '%c' (%d,%d) e '%c' (%d,%d)\n", v1->dados.frequencia, v1->dados.posicao[0], v1->dados.posicao[1], v2->dados.frequencia, v2->dados.posicao[0], v2->dados.posicao[1]);
}

