#include <stdio.h>
#include <stdlib.h>
#include "include/graph.h"


int main(int argc, char **argv) {
    Graph_t *adjacency_graph = init_adjacency_graph(4, 3);
    Graph_t *incidence_graph = init_incidence_graph(4, 3);
    generate_adjacency_matrix(adjacency_graph);
    print_graph(adjacency_graph);
    puts("");
    convert_to_incidence_matrix(adjacency_graph, incidence_graph);
    print_incidence_graph(incidence_graph);
    free_graph(adjacency_graph);
    free_graph(incidence_graph);
//    int opt;
//    int nodes; // 2^64
//    int edges; // 2^64
//    bool adjacency_flag = false;
//    bool incidence_flag = false;
//    while ((opt = getopt(argc, argv, "n:e:ai")) != -1) {
//        switch (opt) { //Ключи количества узлов и ребер обязательные,
//                       //ключи матриц можно задать либо одну, либо обе. Сделать проверки на это.
//            case 'n':
//                nodes = atoi(optarg);
//                break;
//            case 'e':
//                edges = atoi(optarg);
//                break;
//            case 'a':
//                adjacency_flag = true;
//                break;
//            case 'i':
//                incidence_flag = true;
//                break;
//            default:
//                fprintf(stderr, "Usage: %s [-n: number of nodes] [-e: number of edges]"
//                                "[-a generate adjacency matrix] [-i generate incidence matrix]", argv[0]);
//                exit(EXIT_FAILURE);
//        }
//    }
//    if (adjacency_flag) {
//        puts("");
//    }
//    if (incidence_flag) {
//        Graph_t *adjacency_graph = init_adjacency_graph(nodes, edges);
//        free(adjacency_graph);
//    }
    return EXIT_SUCCESS;
}
