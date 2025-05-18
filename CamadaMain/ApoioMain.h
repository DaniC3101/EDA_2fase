#pragma once

/**
 * @brief Mostra todos os v�rtices, arestas e posi��es nefastas do grafo.
 *
 * Chama as fun��es de listagem de v�rtices, arestas e nefastas para apresentar
 * de forma estruturada o conte�do do grafo.
 *
 * @param grafo Apontador para o grafo a ser mostrado.
 */
void MostraGrafo(Grafo* grafo);

/**
 * @brief Lista todos os v�rtices do grafo.
 *
 * Apresenta a posi��o e a frequ�ncia de cada v�rtice presente no grafo.
 *
 * @param grafo Apontador para o grafo.
 */
void ListaVertices(Grafo* grafo);

/**
 * @brief Lista todas as arestas de um determinado v�rtice.
 *
 * Mostra os v�rtices adjacentes ligados por arestas ao v�rtice fornecido.
 *
 * @param vertice Apontador para o v�rtice cujas arestas ser�o listadas.
 */
void ListaArestas(Vertice* vertice);

/**
 * @brief Lista todas as posi��es nefastas associadas �s arestas de um v�rtice.
 *
 * Percorre todas as arestas do v�rtice e imprime as respetivas posi��es nefastas.
 *
 * @param vertice Apontador para o v�rtice.
 */
void ListaNefastas(Vertice* vertice);

/**
 * @brief Mostra a posi��o atual do v�rtice durante um percurso.
 *
 * Utilizada para indicar os v�rtices visitados em travessias do grafo.
 *
 * @param vertice Apontador para o v�rtice atual.
 */
void MostrarCaminho(Vertice* vertice);

/**
 * @brief Mostra o grafo representado como matriz.
 *
 * Apresenta graficamente a matriz do grafo, incluindo antenas, posi��es nefastas e espa�os vazios.
 *
 * @param grafo Apontador para o grafo a ser representado.
 */
void MostrarMatriz(Grafo* grafo);
