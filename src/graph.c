#include "../include/graph.h"

Graph_t *init_graph(int nodes, int edges, bool is_adjacency) {
    Graph_t *graph = (Graph_t *) malloc(sizeof(Graph_t));
    graph->nodes = nodes;
    graph->edges = edges;
    graph->matrix = (int **) malloc(nodes * sizeof(int *));
    for (int i = 0; i < nodes; i++) {
        if (is_adjacency)
            graph->matrix[i] = (int *) calloc(nodes, sizeof(int));
        else
            graph->matrix[i] = (int *) calloc(edges, sizeof(int));
    }
    return graph;
}

void generate_adjacency_matrix(Graph_t *adjacency_graph) {
    srand(time(NULL));
    int from, to;
    for (int i = 0; i < adjacency_graph->edges; ++i) {
        from = rand() % adjacency_graph->nodes;
        to = rand() % adjacency_graph->nodes;
        adjacency_graph->matrix[from][to] += 1;
        if (from != to)
            adjacency_graph->matrix[to][from] += 1;
    }
}

void convert_to_incidence_matrix(Graph_t *adjacency_graph, Graph_t *incidence_graph) {
    int col = 0;
    for (int i = 0; i < adjacency_graph->nodes; i++) {
        for (int j = i; j < adjacency_graph->nodes; j++) {
            int connections = adjacency_graph->matrix[i][j];
            for (int k = 0; k < connections; k++) {
                incidence_graph->matrix[i][col] = 1;
                incidence_graph->matrix[j][col] = 1;
                col++;
            }
        }
    }
}

void adj_graph_to_txt(Graph_t *adj_graph) {
    FILE *adj_matrix_file_ptr = fopen("../matrices/adjacency_matrix.txt", "w");
    for (int i = 0; i < adj_graph->nodes; i++) {
        for (int j = 0; j < adj_graph->nodes; j++)
            fprintf(adj_matrix_file_ptr, "%d ", adj_graph->matrix[i][j]);
        fputs("\n", adj_matrix_file_ptr);
    }
    fclose(adj_matrix_file_ptr);
}

void inc_graph_to_txt(Graph_t *inc_graph) {
    FILE *inc_matrix_file_ptr = fopen("../matrices/incidence_matrix.txt", "w");
    for (int i = 0; i < inc_graph->nodes; i++) {
        for (int j = 0; j < inc_graph->edges; j++)
            fprintf(inc_matrix_file_ptr, "%d ", inc_graph->matrix[i][j]);
        fputs("\n", inc_matrix_file_ptr);
    }
    fclose(inc_matrix_file_ptr);
}

void draw_graph(Graph_t *adj_graph) {
    FILE *dot_file_ptr = fopen(DOT_FILE_PATH, "w");
    fputs("digraph G {\n", dot_file_ptr);
    fputs("\tedge[dir=none]\n", dot_file_ptr);
    for (int i = 0; i < adj_graph->nodes; i++) {
        for (int j = i; j < adj_graph->nodes; j++) {
            int connections = adj_graph->matrix[i][j];
            for (int k = 0; k < connections; k++)
                fprintf(dot_file_ptr, "\t%d -> %d\n", i, j);
        }
    }
    fputs("}", dot_file_ptr);
    fclose(dot_file_ptr);
    char str[50];
    sprintf(str, "dot -Tpng %s -o %s", DOT_FILE_PATH, PNG_FILE_PATH);
    system(str);
}

void free_graph(Graph_t *graph) {
    for (int i = 0; i < graph->nodes; i++)
        free(graph->matrix[i]);
    free(graph->matrix);
    free(graph);
}