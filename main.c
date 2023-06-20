#include <stdio.h>
#include <stdlib.h>
#include "include/graph.h"


int main(int argc, char **argv) {
    Graph_t *graph = init_adjacency_graph(2, 4);
    generate_random_adjacency_matrix(graph);
    print_graph(graph);
    free_graph(graph);
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
