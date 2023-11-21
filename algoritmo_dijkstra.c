#include <stdio.h>
#define Vertice 6
#define INF 99999

void imprimirSolucao(int distancia[], int numero) {
		printf("Vértice ate a distância da Origem\n");
		for (int i = 0; i < Vertice; i++)
				printf("%d \t\t %d\n", i, distancia[i]);
}

void dijkstra(int grafo[Vertice][Vertice], int origem) {
		int distancia[Vertice];
		int conjuntoSPT[Vertice];
		for (int i = 0; i < Vertice; i++) {
				distancia[i] = INF;
				conjuntoSPT[i] = 0;
		}
		distancia[origem] = 0;
		for (int contador = 0; contador < Vertice - 1; contador++) {
				int minimo = INF, indiceMinimo;
				for (int vertice = 0; vertice < Vertice; vertice++)
						if (conjuntoSPT[vertice] == 0 && distancia[vertice] <= minimo)
								minimo = distancia[vertice], indiceMinimo = vertice;
				int u = indiceMinimo;
				conjuntoSPT[u] = 1;
				for (int vertice = 0; vertice < Vertice; vertice++)
						if (!conjuntoSPT[vertice] && grafo[u][vertice] && distancia[u] != INF && distancia[u] + grafo[u][vertice] < distancia[vertice])
								distancia[vertice] = distancia[u] + grafo[u][vertice];
		}
		imprimirSolucao(distancia, Vertice);
}

int main() {
		int grafo[Vertice][Vertice] = {
				{0, 1, 4, 0, 0, 0},
				{1, 0, 4, 2, 7, 0},
				{4, 4, 0, 3, 5, 0},
				{0, 2, 3, 0, 4, 6},
				{0, 7, 5, 4, 0, 7},
				{0, 0, 0, 6, 7, 0}
		};
		dijkstra(grafo, 0);
		return 0;
}