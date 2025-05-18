#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Estruturas.h"
/**
 * @brief Carrega os dados de um grafo a partir de um ficheiro de texto com matriz.
 *
 * L� o ficheiro, determina as dimens�es da matriz, identifica os v�rtices
 * e cria o grafo com base nessas informa��es.
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
 * @brief Conta o n�mero de linhas, colunas e v�rtices num ficheiro de texto.
 *
 * L� o conte�do do ficheiro caractere a caractere e atualiza os valores das dimens�es
 * da matriz, assim como o n�mero total de v�rtices detetados.
 *
 * @param grafoTXT Apontador para o ficheiro aberto.
 * @param dimensao Array onde ser�o guardadas as dimens�es (linhas e colunas).
 * @param contadorVertice Apontador para o contador de v�rtices encontrados.
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
 * @brief Encontra e extrai os v�rtices existentes num ficheiro de texto.
 *
 * Percorre o ficheiro, identifica os caracteres v�lidos como v�rtices e guarda
 * as suas posi��es e frequ�ncias na estrutura Dados.
 *
 * @param grafoTXT Apontador para o ficheiro j� aberto.
 * @param dados Array de estruturas Dados onde ser�o armazenadas as informa��es dos v�rtices.
 * @return Dados* Apontador para o array preenchido com os dados dos v�rtices.
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
 * @brief Guarda os v�rtices do grafo num ficheiro bin�rio.
 *
 * Percorre a lista de v�rtices e escreve, um a um, os seus dados e estado de visita
 * num ficheiro bin�rio especificado.
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
 * @brief Carrega os v�rtices de um ficheiro bin�rio para um grafo.
 *
 * L� os v�rtices guardados em ficheiro bin�rio e reconstr�i a lista ligada
 * de v�rtices no grafo fornecido.
 *
 * @param grafo Apontador para o grafo onde os v�rtices ser�o inseridos.
 * @param file Nome do ficheiro bin�rio.
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
 * @brief Guarda as arestas do grafo num ficheiro bin�rio.
 *
 * Para cada v�rtice do grafo, escreve todas as suas arestas num ficheiro bin�rio.
 * Cada aresta cont�m as posi��es de origem e destino, seguidas das respetivas nefastas.
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
 * @brief Carrega as arestas de um ficheiro bin�rio para o grafo.
 *
 * L� cada aresta armazenada no ficheiro bin�rio, encontra os v�rtices de origem
 * e destino, recria as liga��es e carrega tamb�m as posi��es nefastas associadas.
 *
 * @param grafo Apontador para o grafo onde as arestas ser�o inseridas.
 * @param file Nome do ficheiro bin�rio.
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
 * @brief Guarda as posi��es nefastas associadas a uma aresta num ficheiro bin�rio.
 *
 * Escreve o n�mero total de posi��es nefastas da aresta e, em seguida, cada uma
 * das posi��es com a respetiva frequ�ncia.
 *
 * @param ficheiro Apontador para o ficheiro bin�rio.
 * @param aresta Apontador para a aresta cujas posi��es nefastas ser�o guardadas.
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
 * @brief Carrega as posi��es nefastas de uma aresta a partir de um ficheiro bin�rio.
 *
 * L� a quantidade de posi��es nefastas associadas a uma aresta e insere cada uma
 * na respetiva lista ligada.
 *
 * @param ficheiro Apontador para o ficheiro bin�rio.
 * @param aresta Apontador para a aresta onde as posi��es ser�o inseridas.
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
