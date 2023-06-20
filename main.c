#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdbool.h>

typedef struct Graph {
    bool **matrix;
    int nodes;
    int edges;
} Graph_t;

Graph_t *init_incidence_graph(int nodes, int edges) {
    Graph_t *graph = (Graph_t *) malloc(sizeof(Graph_t));
    graph->nodes = nodes;
    graph->edges = edges;
    graph->matrix = (bool **) malloc(nodes * sizeof(bool *));
    for (int i = 0; i < nodes; i++) {
        graph->matrix[i] = (bool *) malloc(edges * sizeof(bool));
    }
    return graph;
}

// total_edges

void gen_random_incidence_matrix(Graph_t *incidence_graph) {
    int from, to;
    for (int i = 0; i < incidence_graph->edges; i++) {
        from = rand() % incidence_graph->nodes;
        to = rand() % incidence_graph->nodes;
        incidence_graph->matrix[from][to] = true;
    }
}

void free_graph(Graph_t *graph) {
    for (int i = 0; i < graph->nodes; i++) {
        free(graph->matrix[i]);
    }
    free(graph->matrix);
    free(graph);
}

int main(int argc, char **argv) {
    int opt;
    int nodes; // 2^64
    int edges; // 2^64
    bool adjacency_flag = false;
    bool incidence_flag = false;
    while ((opt = getopt(argc, argv, "n:e:ai")) != -1) {
        switch (opt) { //Ключи количества узлов и ребер обязательные,
                       //ключи матриц можно задать либо одну, либо обе. Сделать проверки на это.
            case 'n':
                nodes = atoi(optarg);
                break;
            case 'e':
                edges = atoi(optarg);
                break;
            case 'a':
                adjacency_flag = true;
                break;
            case 'i':
                incidence_flag = true;
                break;
            default:
                fprintf(stderr, "Usage: %s [-n: number of nodes] [-e: number of edges]"
                                "[-a generate adjacency matrix] [-i generate incidence matrix]", argv[0]);
                exit(EXIT_FAILURE);
        }
    }
    if (adjacency_flag) {
        puts("");
    }
    if (incidence_flag) {
        Graph_t *incidence_graph = init_incidence_graph(nodes, edges);
        free(incidence_graph);
    }
    return EXIT_SUCCESS;
}
