#ifndef RK3_GRAPH_H
#define RK3_GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdbool.h>
#include <time.h>

#define DOT_FILE_PATH "../dot/graph.dot"
#define PNG_FILE_PATH "../pngs/graph.png"

typedef struct Graph {
    int **matrix;
    int nodes;
    int edges;
} Graph_t;

Graph_t *init_graph(int nodes, int edges, bool is_adjacency);

void generate_adjacency_matrix(Graph_t *adjacency_graph);

void convert_to_incidence_matrix(Graph_t *adjacency_graph, Graph_t *incidence_graph);

void print_graph(Graph_t *adjacency_graph);

void print_incidence_graph(Graph_t *incidence_graph);

void adj_graph_to_txt(Graph_t *adj_graph);

void inc_graph_to_txt(Graph_t *inc_graph);

void draw_graph(Graph_t *adj_graph);

void free_graph(Graph_t *graph);

#endif