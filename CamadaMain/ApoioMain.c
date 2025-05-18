#pragma once
#include <stdio.h>
#include "Estruturas.h"
#include "ApoioMain.h"

/**
 * @brief Lista todos os v�rtices do grafo com as suas respetivas posi��es e frequ�ncias.
 *
 * Percorre a lista ligada de v�rtices do grafo e imprime a sua informa��o no ecr�.
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
 * @brief Mostra todos os v�rtices, as arestas e as posi��es nefastas do grafo.
 *
 * Imprime no ecr� a lista de v�rtices, seguida das suas arestas e respetivas posi��es nefastas.
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
 * @brief Lista todas as arestas associadas a um determinado v�rtice.
 *
 * Percorre a lista de arestas do v�rtice e imprime as posi��es dos v�rtices adjacentes.
 *
 * @param vertice Apontador para o v�rtice cujas arestas ser�o listadas.
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
 * @brief Lista todas as posi��es nefastas associadas �s arestas de um v�rtice.
 *
 * Para cada aresta do v�rtice, imprime as posi��es consideradas nefastas.
 *
 * @param vertice Apontador para o v�rtice cujas posi��es nefastas ser�o listadas.
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
 * Imprime no ecr� a posi��o do v�rtice visitado durante o percurso.
 *
 * @param vertice Apontador para o v�rtice a ser mostrado.
 */
void MostrarCaminho(Vertice* vertice)
{
	printf("-> Caminho: (%d, %d)\n", vertice->dados.posicao[0], vertice->dados.posicao[1]);
}
/**
 * @brief Mostra a representa��o matricial do grafo no ecr�.
 *
 * Imprime a matriz com as antenas (frequ�ncias), posi��es nefastas ('#') e espa�os vazios ('.').
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
 * @brief Mostra uma interse��o diagonal entre dois v�rtices com frequ�ncias diferentes.
 *
 * Utilizada para sinalizar a dete��o de interse��es diagonais no grafo.
 *
 * @param v1 Apontador para o primeiro v�rtice.
 * @param v2 Apontador para o segundo v�rtice.
 */
void MostrarIntersecao(Vertice* v1, Vertice* v2)
{
	printf("Intersecao diagonal entre '%c' (%d,%d) e '%c' (%d,%d)\n", v1->dados.frequencia, v1->dados.posicao[0], v1->dados.posicao[1], v2->dados.frequencia, v2->dados.posicao[0], v2->dados.posicao[1]);
}

