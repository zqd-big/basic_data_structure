#include <stdbool.h> 
#include "queue.h"

// 有向无权图
typedef struct graph{
    struct Edge** Edge_list;
    int* sizes;
    int* capacities;
    int node_count;
}graph;

typedef struct Edge{
    int to;
    int weight
}Edge;



struct graph* create_graph(int node_count, int init_cap);
void addEdge(struct graph* mygraph, int from, int to);
void removeEdge(struct graph* mygraph, int from, int to);
bool hasEdge(struct graph* mygraph, int from, int to);
struct Edge* neighbors(struct graph* mygraph, int from, int* out_size);
void freegraph(struct graph* mygraph);
void dfs_traverse_node(struct graph* mygraph, int s, int* visited);
void dfs_traverse_edge(struct graph* mygraph, int s, int dest, struct queue* myqueue, int* visited);
struct Edgequeue* Edgequeuecreate();
void Edgequeuedestroy(struct Edgequeue* thequeue);
void bfs_travers1(struct graph* mygraph);
void bfs_travers2(struct graph* mygraph);
