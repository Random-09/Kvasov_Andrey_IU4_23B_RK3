#ifndef RK3_GRAPH_H
#define RK3_GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>

#define ADJ_MATRIX_PATH "../matrices/adjacency_matrix.txt"
#define INC_MATRIX_PATH "../matrices/incidence_matrix.txt"
#define DOT_FILE_PATH "../dot/graph.dot"
#define PNG_FILE_PATH "../pngs/graph.png"

typedef struct Graph {
    int **matrix;
    uint64_t nodes;
    uint64_t edges;
} Graph_t;

Graph_t *init_graph(uint64_t nodes, uint64_t edges, bool is_adjacency);

void generate_random_adj_matrix(Graph_t *adjacency_graph);

void convert_adj_to_inc(Graph_t *adjacency_graph, Graph_t *incidence_graph);

void adj_graph_to_txt(Graph_t *adj_graph);

void inc_graph_to_txt(Graph_t *inc_graph);

void draw_graph(Graph_t *adj_graph);

void free_graph(Graph_t *graph);

#endif