#pragma once

/**
 * @brief Mostra todos os vértices, arestas e posições nefastas do grafo.
 *
 * Chama as funções de listagem de vértices, arestas e nefastas para apresentar
 * de forma estruturada o conteúdo do grafo.
 *
 * @param grafo Apontador para o grafo a ser mostrado.
 */
void MostraGrafo(Grafo* grafo);

/**
 * @brief Lista todos os vértices do grafo.
 *
 * Apresenta a posição e a frequência de cada vértice presente no grafo.
 *
 * @param grafo Apontador para o grafo.
 */
void ListaVertices(Grafo* grafo);

/**
 * @brief Lista todas as arestas de um determinado vértice.
 *
 * Mostra os vértices adjacentes ligados por arestas ao vértice fornecido.
 *
 * @param vertice Apontador para o vértice cujas arestas serão listadas.
 */
void ListaArestas(Vertice* vertice);

/**
 * @brief Lista todas as posições nefastas associadas às arestas de um vértice.
 *
 * Percorre todas as arestas do vértice e imprime as respetivas posições nefastas.
 *
 * @param vertice Apontador para o vértice.
 */
void ListaNefastas(Vertice* vertice);

/**
 * @brief Mostra a posição atual do vértice durante um percurso.
 *
 * Utilizada para indicar os vértices visitados em travessias do grafo.
 *
 * @param vertice Apontador para o vértice atual.
 */
void MostrarCaminho(Vertice* vertice);

/**
 * @brief Mostra o grafo representado como matriz.
 *
 * Apresenta graficamente a matriz do grafo, incluindo antenas, posições nefastas e espaços vazios.
 *
 * @param grafo Apontador para o grafo a ser representado.
 */
void MostrarMatriz(Grafo* grafo);
