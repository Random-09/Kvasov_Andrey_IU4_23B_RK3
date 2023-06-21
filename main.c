#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "include/graph.h"

int main(int argc, char **argv) {
    int opt;
    uint64_t nodes;
    uint64_t edges;
    bool nodes_entered = false;
    bool edges_entered = false;
    bool create_adjacency = false;
    bool create_incidence = false;
    while ((opt = getopt(argc, argv, "n:e:ai")) != -1) {
        switch (opt) {
            case 'n':
                nodes = strtoull(optarg, NULL, 10);
                if (nodes == -1) {
                    puts("Too many nodes!");
                    exit(EXIT_FAILURE);
                }
                nodes_entered = true;
                break;
            case 'e':
                edges = strtoull(optarg, NULL, 10);
                if (edges == -1) {
                    puts("Too many edges!");
                    exit(EXIT_FAILURE);
                }
                edges_entered = true;
                break;
            case 'a':
                create_adjacency = true;
                break;
            case 'i':
                create_incidence = true;
                break;
            default:
                fprintf(stderr, "Usage: %s [-n: number of nodes] [-e: number of edges]"
                                "[-a generate adjacency matrix] [-i generate incidence matrix]", argv[0]);
                exit(EXIT_FAILURE);
        }
    }
    if (!nodes_entered || !edges_entered) {
        puts("You must enter edges and nodes arguments!");
        exit(EXIT_FAILURE);
    }
    if (!create_adjacency && !create_incidence) {
        puts("You should choose at least one matrix!");
        exit(EXIT_FAILURE);
    }
    Graph_t *adj_graph = init_graph(nodes, edges, true);
    generate_random_adj_matrix(adj_graph);
    if (create_adjacency) {
        adj_graph_to_txt(adj_graph);
    }
    if (create_incidence) {
        Graph_t *inc_graph = init_graph(nodes, edges, false);
        convert_adj_to_inc(adj_graph, inc_graph);
        inc_graph_to_txt(inc_graph);
        free_graph(inc_graph);
    }
    draw_graph(adj_graph);
    free_graph(adj_graph);
    return EXIT_SUCCESS;
}


