#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Estruturas.h"
/**
 * @brief Carrega os dados de um grafo a partir de um ficheiro de texto com matriz.
 *
 * Lê o ficheiro, determina as dimensões da matriz, identifica os vértices
 * e cria o grafo com base nessas informações.
 *
 * @param nomeFicheiro Nome do ficheiro a ser lido.
 * @return Grafo* Apontador para o grafo carregado.
 */
Grafo* CarregarMatriz(char* nomeFicheiro)
{
	int dimensao[2], contadorVertice;
	FILE* grafoTXT = fopen(nomeFicheiro, "r");
	if (grafoTXT == NULL)
	{
		return NULL;
	}
	ContarLinhasColunas(grafoTXT, dimensao, &contadorVertice);
	Grafo* grafo = CriarGrafo(dimensao[0], dimensao[1]);

	Dados* dados = malloc(30 * sizeof(Dados));
	EncontrarVertices(grafoTXT, dados);
	for (int i = 0; i < contadorVertice; i++)
	{
		CriarVertice(grafo, dados[i].posicao[0], dados[i].posicao[1], dados[i].frequencia);
	}

	fclose(grafoTXT);
	return grafo;
}
/**
 * @brief Conta o número de linhas, colunas e vértices num ficheiro de texto.
 *
 * Lê o conteúdo do ficheiro caractere a caractere e atualiza os valores das dimensões
 * da matriz, assim como o número total de vértices detetados.
 *
 * @param grafoTXT Apontador para o ficheiro aberto.
 * @param dimensao Array onde serão guardadas as dimensões (linhas e colunas).
 * @param contadorVertice Apontador para o contador de vértices encontrados.
 * @return int Retorna 1 no fim do processamento.
 */
int ContarLinhasColunas(FILE* grafoTXT, int dimensao[2], int* contadorVertice)
{
	char letra;
	int auxColuna = 0;
	dimensao[0] = 0;
	dimensao[1] = 0;
	*contadorVertice = 0;

	while ((letra = fgetc(grafoTXT)) != EOF)
	{

		if (letra == '\n')
		{
			dimensao[0]++;
			if (auxColuna > dimensao[1])
			{
				dimensao[1] = auxColuna;
			}
			auxColuna = 0;
		}
		else if (letra != ' ' && letra != '.')
		{
			(*contadorVertice)++;
		}
		else if (letra != ' ')
		{
			auxColuna++;
		}
	}
	if (auxColuna > 0)
	{
		dimensao[0]++;
		if (auxColuna > dimensao[1])
		{
			dimensao[1] = auxColuna;
		}
	}
	fseek(grafoTXT, 0, SEEK_SET);
	return 1;
}
/**
 * @brief Encontra e extrai os vértices existentes num ficheiro de texto.
 *
 * Percorre o ficheiro, identifica os caracteres válidos como vértices e guarda
 * as suas posições e frequências na estrutura Dados.
 *
 * @param grafoTXT Apontador para o ficheiro já aberto.
 * @param dados Array de estruturas Dados onde serão armazenadas as informações dos vértices.
 * @return Dados* Apontador para o array preenchido com os dados dos vértices.
 */
Dados* EncontrarVertices(FILE* grafoTXT, Dados* dados)
{
	char letra;
	int auxLinha = 1, auxColuna = 0, i = 0;

	if (dados == NULL) 
	{
		return NULL;
	}

	while ((letra = fgetc(grafoTXT)) != EOF)
	{
		if (letra == '\n')
		{
			auxLinha++;
			auxColuna = 1;
		}
		else
		{
			if (letra != ' ' && letra != '.')
			{
				dados[i].posicao[0] = auxLinha;
				dados[i].posicao[1] = auxColuna;
				dados[i].frequencia = letra;
				i++;
			}
			if (letra != ' ')
			{
				auxColuna++;
			}
		}
	}
	return dados;
}
/**
 * @brief Guarda os vértices do grafo num ficheiro binário.
 *
 * Percorre a lista de vértices e escreve, um a um, os seus dados e estado de visita
 * num ficheiro binário especificado.
 *
 * @param grafo Apontador para o grafo.
 * @param file Nome do ficheiro de destino.
 * @return true Se os dados foram guardados com sucesso.
 */
bool GuardarVertices(Grafo* grafo, char* file)
{
	FILE* ficheiro = fopen(file, "wb");
	if (ficheiro == NULL)
	{
		return false;
	}
	Vertice* auxVertice = grafo->primVertice;
	VerticeFile vfile;

	while (auxVertice != NULL)
	{
		vfile.dados = auxVertice->dados;
		vfile.visitado = auxVertice->visitado;
		fwrite(&vfile, sizeof(VerticeFile), 1, ficheiro);
		auxVertice = auxVertice->proxVertice;
	}
	fclose(ficheiro);
	return true;
}
/**
 * @brief Carrega os vértices de um ficheiro binário para um grafo.
 *
 * Lê os vértices guardados em ficheiro binário e reconstrói a lista ligada
 * de vértices no grafo fornecido.
 *
 * @param grafo Apontador para o grafo onde os vértices serão inseridos.
 * @param file Nome do ficheiro binário.
 * @return Grafo* Apontador para o grafo atualizado.
 */
Grafo* CarregarVertices(Grafo* grafo,char* file)
{
	FILE* ficheiro = fopen(file, "rb");
	if (ficheiro == NULL) 
	{
		return false;
	}

	VerticeFile vfile;
	Vertice* novo = NULL;
	Vertice* anterior = NULL;

	grafo->primVertice = NULL;

	while (fread(&vfile, sizeof(VerticeFile), 1, ficheiro) == 1)
	{
		novo = (Vertice*)malloc(sizeof(Vertice));
		novo->dados = vfile.dados;
		novo->visitado = vfile.visitado;
		novo->primAresta = NULL;
		novo->proxVertice = NULL;

		if (grafo->primVertice == NULL) 
		{
			grafo->primVertice = novo;
		}
		else 
		{
			anterior->proxVertice = novo;
		}

		anterior = novo;
	}
	fclose(ficheiro);
	return true;
}
/**
 * @brief Guarda as arestas do grafo num ficheiro binário.
 *
 * Para cada vértice do grafo, escreve todas as suas arestas num ficheiro binário.
 * Cada aresta contém as posições de origem e destino, seguidas das respetivas nefastas.
 *
 * @param grafo Apontador para o grafo.
 * @param file Nome do ficheiro de destino.
 * @return true Se os dados foram guardados com sucesso.
 */
bool GuardarArestas(Grafo* grafo, char* file)
{
	FILE* ficheiro = fopen(file, "wb");
	if (ficheiro == NULL)
	{
		return false;
	}

	Vertice* auxVertice = grafo->primVertice;
	while (auxVertice != NULL)
	{
		Aresta* auxAresta = auxVertice->primAresta;
		while (auxAresta != NULL)
		{
			ArestaFile afile;
			afile.origemPos[0] = auxVertice->dados.posicao[0];
			afile.origemPos[1] = auxVertice->dados.posicao[1];
			afile.destinoPos[0] = auxAresta->adjVertice->dados.posicao[0];
			afile.destinoPos[1] = auxAresta->adjVertice->dados.posicao[1];

			fwrite(&afile, sizeof(ArestaFile), 1, ficheiro);
			GuardarNefastas(ficheiro, auxAresta);

			auxAresta = auxAresta->proxAresta;
		}
		auxVertice = auxVertice->proxVertice;
	}

	fclose(ficheiro);
	return true;
}
/**
 * @brief Carrega as arestas de um ficheiro binário para o grafo.
 *
 * Lê cada aresta armazenada no ficheiro binário, encontra os vértices de origem
 * e destino, recria as ligações e carrega também as posições nefastas associadas.
 *
 * @param grafo Apontador para o grafo onde as arestas serão inseridas.
 * @param file Nome do ficheiro binário.
 * @return true Se os dados foram carregados com sucesso.
 */
bool CarregarArestas(Grafo* grafo, char* file)
{
	FILE* ficheiro = fopen(file, "rb");
	if (ficheiro == NULL)
	{
		return false;
	}

	ArestaFile afile;

	while (fread(&afile, sizeof(ArestaFile), 1, ficheiro) == 1)
	{
		Vertice* origem = EncontrarVertice(grafo, afile.origemPos[0], afile.origemPos[1]);
		Vertice* destino = EncontrarVertice(grafo, afile.destinoPos[0], afile.destinoPos[1]);

		Aresta* nova = (Aresta*)malloc(sizeof(Aresta));
		nova->adjVertice = destino;
		nova->primNefasta = NULL;
		nova->proxAresta = origem->primAresta;
		origem->primAresta = nova;

		CarregarNefastas(ficheiro, nova);
	}

	fclose(ficheiro);
	return true;
}
/**
 * @brief Guarda as posições nefastas associadas a uma aresta num ficheiro binário.
 *
 * Escreve o número total de posições nefastas da aresta e, em seguida, cada uma
 * das posições com a respetiva frequência.
 *
 * @param ficheiro Apontador para o ficheiro binário.
 * @param aresta Apontador para a aresta cujas posições nefastas serão guardadas.
 * @return true Se os dados foram guardados com sucesso.
 */
bool GuardarNefastas(FILE* ficheiro, Aresta* aresta)
{
	int contador = 0;
	Nefasta* auxNefasta = aresta->primNefasta;

	// Contar nefastas
	while (auxNefasta != NULL) 
	{
		contador++;
		auxNefasta = auxNefasta->proxNefasta;
	}

	fwrite(&contador, sizeof(int), 1, ficheiro);

	auxNefasta = aresta->primNefasta;
	while (auxNefasta != NULL)
	{
		NefastaFile nfile;
		nfile.posicao[0] = auxNefasta->dados.posicao[0];
		nfile.posicao[1] = auxNefasta->dados.posicao[1];
		nfile.frequencia = auxNefasta->dados.frequencia;
		fwrite(&nfile, sizeof(NefastaFile), 1, ficheiro);
		auxNefasta = auxNefasta->proxNefasta;
	}
	return true;
}
/**
 * @brief Carrega as posições nefastas de uma aresta a partir de um ficheiro binário.
 *
 * Lê a quantidade de posições nefastas associadas a uma aresta e insere cada uma
 * na respetiva lista ligada.
 *
 * @param ficheiro Apontador para o ficheiro binário.
 * @param aresta Apontador para a aresta onde as posições serão inseridas.
 */
void CarregarNefastas(FILE* ficheiro, Aresta* aresta)
{
	int count;
	if (fread(&count, sizeof(int), 1, ficheiro) != 1) return;

	for (int i = 0; i < count; i++)
	{
		NefastaFile nf;
		if (fread(&nf, sizeof(NefastaFile), 1, ficheiro) != 1) break;

		Nefasta* nova = (Nefasta*)malloc(sizeof(Nefasta));
		nova->dados.posicao[0] = nf.posicao[0];
		nova->dados.posicao[1] = nf.posicao[1];
		nova->dados.frequencia = nf.frequencia;

		nova->proxNefasta = aresta->primNefasta;
		aresta->primNefasta = nova;
	}
}
