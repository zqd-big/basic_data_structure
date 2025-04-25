#include <stdio.h>
#include <stdlib.h>  
#include <stdbool.h> 
#include <math.h>
#include "graph.h"

// 有向无权图
struct graph* create_graph(int node_count, int init_cap){
    struct graph* my_graph = malloc(sizeof(struct graph));
    my_graph->Edge_list = malloc(node_count * sizeof(struct Edge*));
    my_graph->sizes = calloc(node_count, sizeof(int));
    my_graph->capacities = malloc(node_count * sizeof(int));
    my_graph->node_count = node_count; 
    for(int i = 0; i < node_count; i++){
        my_graph->Edge_list[i] = malloc(init_cap * sizeof(struct Edge));
        my_graph->capacities[i] = init_cap;
    }
    return my_graph;
}

void addEdge(struct graph* mygraph, int from, int to){
    if(mygraph->sizes[from] >= mygraph->capacities[from]){
        int new_cap = mygraph->capacities[from] * 2;
        struct Edge* new_arr = realloc(mygraph->Edge_list[from], new_cap * sizeof(struct Edge));
        mygraph->capacities[from] = new_cap;
        mygraph->Edge_list[from] = new_arr;
    }
    mygraph->Edge_list[from][mygraph->sizes[from]].to = to;
    mygraph->Edge_list[from][mygraph->sizes[from]].weight = 1;
    mygraph->sizes[from]++;
}

void removeEdge(struct graph* mygraph, int from, int to){
    int num = 0;
    for(int i = 0; i < mygraph->sizes[from]; i++){
        if(mygraph->Edge_list[from][i].to != to){
            mygraph->Edge_list[from][num] = mygraph->Edge_list[from][i];
            num++;
        }
    }
    mygraph->sizes[from] = num;
}

bool hasEdge(struct graph* mygraph, int from, int to){
    for(int i = 0; i < mygraph->sizes[from]; i++){
        if(mygraph->Edge_list[from][i].to == to){
            return true;
        }
    }
    return false;
}

struct Edge* neighbors(struct graph* mygraph, int from, int* out_size){
    *out_size = mygraph->sizes[from];
    return mygraph->Edge_list[from];
}

void freegraph(struct graph* mygraph){
    for(int i = 0; i < mygraph->node_count; i++){
        free(mygraph->Edge_list[i]);
    }
    free(mygraph->capacities);
    free(mygraph->Edge_list);
    free(mygraph->sizes);
    free(mygraph);
}

void dfs_traverse_node(struct graph* mygraph, int s, int* visited){
    if(s < 0 || s >= mygraph->node_count){
        return;
    }
    if(visited[s] == 1){
        return;
    }
    visited[s] = 1;
    printf("visited加上了%d节点", s);
    for(int i = 0; i < mygraph->sizes[s]; i++){
        dfs_traverse_node(mygraph, mygraph->Edge_list[s][i].to, visited);
    }

}

void dfs_traverse_edge(struct graph* mygraph, int s, int dest, struct queue* myqueue, int* visited){
    if(s < 0 || s >= mygraph->node_count || dest < 0 || dest >= mygraph->node_count){
        return;
    }
    if(visited[s] == 1){
        return;
    }
    pushbackqueue(myqueue, s);
    if(s == dest){
        int len = myqueue->len;
        listNode* temp = myqueue->head;
        for(int i = 0; i < len; i++){
            printf(" %d", temp->key);
            temp = temp->next;
        }
        printf("\n");
    }
    
    visited[s] = 1;
    for(int j = 0; j < mygraph->sizes[s]; j++){
        dfs_traverse_edge(mygraph, mygraph->Edge_list[s][j].to, dest, myqueue, visited);
    }
    visited[s] = 0;
    popbackqueue(myqueue);
}

void bfs_travers1(struct graph* mygraph){
    struct Equeue* myqueue = queuecreate();
    pushbackqueue(myqueue, 0);
    int* visited = calloc(mygraph->node_count, sizeof(int));
    visited[0] = 1;
    struct listNode* temp;
    while(!queueisempty(myqueue)){
        temp = popfrontqueue(myqueue);
        int now = temp->key;
        printf("visited %d", now);
        for(int i = 0; i < mygraph->sizes[now]; i++){
            if(!visited[mygraph->Edge_list[now][i].to]){
                pushbackqueue(myqueue, mygraph->Edge_list[now][i].to);
                visited[mygraph->Edge_list[now][i].to] = 1;
            }
        }
    }
    queuedestroy(myqueue);
    free(visited);
}

void bfs_travers2(struct graph* mygraph){
    struct Equeue* myqueue = queuecreate();
    pushbackqueue(myqueue, 0);
    int* visited = calloc(mygraph->node_count, sizeof(int));
    visited[0] = 1;
    int depth = 1;
    struct listNode* temp;
    while(!queueisempty(myqueue)){
        int size = queuesize(myqueue);
        for(int j = 0 ;j < size; j++){
            temp = popfrontqueue(myqueue);
            int now = temp->key;
            printf("visited %d, and the depth is %d", now, depth);
            for(int i = 0; i < mygraph->sizes[now]; i++){
                if(!visited[mygraph->Edge_list[now][i].to]){
                    pushbackqueue(myqueue, mygraph->Edge_list[now][i].to);
                    visited[mygraph->Edge_list[now][i].to] = 1;
                }
            }
        }
        depth += 1;
    }
    queuedestroy(myqueue);
    free(visited);
}
