#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    float x;
    float y;
} Vertice;

float calcular_area_triangulo(Vertice v1, Vertice v2, Vertice v3) {
    float base = v2.x - v1.x;
    float altura = v3.y - v1.y;
    return (base * altura) / 2;
}

int main() {
    // abrir arquivo
    FILE *arquivo_entrada = fopen("entrada.txt", "r");
    if (arquivo_entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    // leitura do numero de vertices do poligono
    int numero_vertices;
    fscanf(arquivo_entrada, "%d", &numero_vertices);

    // armazenar vertices
    Vertice vertices[MAX_VERTICES];
    for (int i = 0; i < numero_vertices; i++) {
        fscanf(arquivo_entrada, "%f %f", &vertices[i].x, &vertices[i].y);
    }

    // armazenar area 
    float area_poligono = 0;
    for (int i = 0; i < numero_vertices - 2; i++) {
        area_poligono += calcular_area_triangulo(vertices[i], vertices[i + 1], vertices[i + 2]);
    }

    // calculo da area do poligono
    for (int i = 0; i < numero_vertices - 2; i++) {
        area_poligono += calcular_area_triangulo(vertices[i], vertices[numero_vertices - 1], vertices[i + 1]);
    }

    // fechar arquivo 
    fclose(arquivo_entrada);

    // imprimir area 
    printf("a area do poligono e %.2f\n", area_poligono);

    return 0;
}
