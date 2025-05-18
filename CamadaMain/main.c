/**
 * @file main.c
 * @author Dani Cruz (a23016)
 * @brief Arquivo principal do programa
 *
 * Este programa implementa um grafo orientado utilizando listas de adjacência e listas de vértices.
 * Para além da criação e manipulação do grafo, o ficheiro principal também inclui diversos testes
 * às funcionalidades desenvolvidas, como inserção, remoção, percursos (BFS e DFS), identificação de
 * posições nefastas, e operações de leitura/escrita em ficheiros binários.
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
	//------------------Carregar grafo a partir de um txt e aplicar operações de grafos e Guardar em Binário------------------//
	 
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


	//------------------Carregar grafo a partir de um ficheiro Binário------------------//
	
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