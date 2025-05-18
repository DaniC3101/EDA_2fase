/**
 * @file main.c
 * @author Dani Cruz (a23016)
 * @brief Arquivo principal do programa
 *
 * Este programa implementa um grafo orientado utilizando listas de adjac�ncia e listas de v�rtices.
 * Para al�m da cria��o e manipula��o do grafo, o ficheiro principal tamb�m inclui diversos testes
 * �s funcionalidades desenvolvidas, como inser��o, remo��o, percursos (BFS e DFS), identifica��o de
 * posi��es nefastas, e opera��es de leitura/escrita em ficheiros bin�rios.
 *
 * @version 20.1
 * @date 2024-05-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Estruturas.h"
#include "ApoioMain.h"
int main()
{
	//------------------Carregar grafo a partir de um txt e aplicar opera��es de grafos e Guardar em Bin�rio------------------//
	 
	//Grafo* grafo = CarregarMatriz("Matriz.txt");
	//CriarVertice(grafo, 3, 3, 'C');
	//CriarVertice(grafo, 4, 4, 'D');
	//CriarVertice(grafo, 8, 9, 'E');
	//EditarVertice(grafo,2, 2, 'D');
	//EliminarVertice(grafo, 3, 3);
	//Vertice* v1 = EncontrarVertice(grafo, 8, 9);
	//Vertice* v2 = EncontrarVertice(grafo, 2, 2);
	//CriarAresta(v1, v2);
	//EliminarAresta(v1, v2);
	//GuardarVertices(grafo, "Vertices.txt");
	//GuardarArestas(grafo, "Vertices.txt");
	
	//---------------------------------------------------------------------------------------------------//


	//------------------Carregar grafo a partir de um ficheiro Bin�rio------------------//
	
	//Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
	//CarregarVertices(grafo, "Vertices.txt");
	//CarregarArestas(grafo, "Arestas.txt");
	//Vertice* v1 = EncontrarVertice(grafo, 8, 9);
	//Vertice* v2 = EncontrarVertice(grafo, 2, 2);
	//CriarAresta(v1, v2);
	//EliminarAresta(v1, v2);
	//MostraGrafo(grafo);

	//---------------------------------------------------------------------------------//
	

	//------------------Algoritmo BFS por vertice e por Grafo--------------------//

	//Grafo* grafo = CriarGrafo(12, 12);
	//CriarVertice(grafo, 1, 1, 'A');
	//CriarVertice(grafo, 2, 2, 'B');
	//CriarVertice(grafo, 3, 3, 'C');
	//CriarVertice(grafo, 4, 4, 'D');
	//CriarVertice(grafo, 5, 5, 'E');
	//Vertice* v1 = EncontrarVertice(grafo, 1, 1);
	//Vertice* v2 = EncontrarVertice(grafo, 2, 2);
	//Vertice* v3 = EncontrarVertice(grafo, 3, 3);
	//Vertice* v4 = EncontrarVertice(grafo, 4, 4);
	//Vertice* v5 = EncontrarVertice(grafo, 5, 5);
	//CriarAresta(v1, v2);
	//CriarAresta(v1, v3);
	//CriarAresta(v2, v4);
	//CriarAresta(v3, v4);
	//CriarAresta(v4, v5);
	//ListaVertices(grafo);
	//PercorrerGrafoBFS(grafo);
	///*PercorrerVerticeBFS(v1, v5);*/

	//--------------------------------------------------------------------------//

	//------------------Algoritmo DFS por vertice e por Grafo--------------------//

	//Grafo* grafo = CriarGrafo(12, 12);
	//CriarVertice(grafo, 1, 1, 'A');
	//CriarVertice(grafo, 2, 2, 'B');
	//CriarVertice(grafo, 3, 3, 'C');
	//CriarVertice(grafo, 4, 4, 'D');
	//CriarVertice(grafo, 5, 5, 'E');
	//Vertice* v1 = EncontrarVertice(grafo, 1, 1);
	//Vertice* v2 = EncontrarVertice(grafo, 2, 2);
	//Vertice* v3 = EncontrarVertice(grafo, 3, 3);
	//Vertice* v4 = EncontrarVertice(grafo, 4, 4);
	//Vertice* v5 = EncontrarVertice(grafo, 5, 5);
	//CriarAresta(v1, v2);
	//CriarAresta(v1, v3);
	//CriarAresta(v2, v4);
	//CriarAresta(v3, v4);
	//CriarAresta(v4, v5);
	//ListaVertices(grafo);
	//PercorrerGrafoDFS(grafo);
	///*PercorrerVerticeDFS(v1, v5);*/

	//---------------------------------------------------------------------------//
}