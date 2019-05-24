#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void initGraph(int ** G, unsigned size) {
for (unsigned i = 0; i < size; ++i) {
G[i] = malloc(size * sizeof(int));
}
}

void inputMatrix(int ** G, unsigned size) {
int temp;
for (unsigned i = 0; i < size; ++i) {
G[i][i] = 0;
for (unsigned j = i + 1; j < size; ++j) {
printf("Введите расстояние между городами %d - %d: ", i + 1, j + 1);
scanf("%d: ", &temp);
G[i][j] = temp;
G[j][i] = temp;
}
}
}

void outputMatrix(int ** G, unsigned size) {
printf("Матрица смежности графа:\n");
for (unsigned i = 0; i < size; ++i) {for (unsigned j = 0; j < size; ++j) {
printf("%5d", G[i][j]);
}
printf("\n");
}
}

int travellingSalesmanProblem(int *cost, int ** G, int c, unsigned size, int *vc) {
int nearest_city = INT_MAX;
int minCost = INT_MAX;
int temp = 0;

for(unsigned i = 0; i < size; ++i) {
if((G[c][i] != 0) && (vc[i] == 0)) {
if(G[c][i] < minCost) {
minCost = G[i][0] + G[c][i];
}

temp = G[c][i];
nearest_city = (int)i;
}
}

if(minCost != INT_MAX) {
*cost += temp;
}

return nearest_city;
}

int minimumCost(int ** G, unsigned size, int city, int *vc) {
if (vc == NULL) {
vc = calloc(size, sizeof(int));
}

int cost = 0;
const int INF = INT_MAX;
vc[city] = 1;
printf("%d: ", city + 1);
int nearest_city = travellingSalesmanProblem(&cost, G, city, size, vc);
if(nearest_city == INF) {
nearest_city = 0;
printf("%d: ", nearest_city + 1);
cost += G[city][nearest_city];
return cost;
}

cost += minimumCost(G, size, nearest_city, vc);
return cost;
}

void inputShortestDistances(int *d, unsigned size) {
printf("\nnКратчайшие расстояния до вершин:");
for (unsigned i = 0; i < size; i++) {
printf("%5d ", d[i]);
}
}

int main() {
int** G;
unsigned n;
printf("Введите количество городов:\t");
scanf("%d:", &n);
G = malloc(n * sizeof(int*));
initGraph(G, n);
inputMatrix(G, n);
outputMatrix(G, n);
printf("\n\nКратчайший путь:\n");
int cost = minimumCost(G, n, 0, NULL);
printf("\n\nМинимальное расстояние:\t");
printf( "%d\n", cost);

return 0;
}
