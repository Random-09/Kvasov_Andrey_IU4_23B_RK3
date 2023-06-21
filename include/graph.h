#ifndef RK3_GRAPH_H
#define RK3_GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdbool.h>
#include <time.h>

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

void graph_to_txt(Graph_t *graph, bool is_adjacency);

void free_graph(Graph_t *graph);

#endif