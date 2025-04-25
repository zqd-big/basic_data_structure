#include <stdio.h>
#include <stdlib.h>  
#include <stdbool.h> 
#include <math.h>
#include "queue.h"

void fronttraverse(struct treeNode* tree){
    if(tree == NULL){
        return;
    }
    printf("tree node is %d", tree->val);
    if(tree->leftnode != NULL){
        fronttraverse(tree->leftnode);
    }
    if(tree->rightnode != NULL){
        fronttraverse(tree->rightnode);
    }
}

void mediumtraverse(struct treeNode* tree){
    if(tree == NULL){
        return;
    }
    if(tree->leftnode != NULL){
        mediumtraverse(tree->leftnode);
    }
    printf("tree node is %d", tree->val);
    if(tree->rightnode != NULL){
        mediumtraverse(tree->rightnode);
    }
}

void lasttraverse(struct treeNode* tree){
    if(tree == NULL){
        return;
    }
    if(tree->leftnode != NULL){
        lasttraverse(tree->leftnode);
    }
    if(tree->rightnode != NULL){
        lasttraverse(tree->rightnode);
    }
    printf("tree node is %d", tree->val);
}

void levelOrderTraverse1(struct treeNode* tree){
    if(tree == NULL){
        return;
    }
    struct treequeue* queue1 = treequeuecreate();
    queue1 = treepushbackqueue(queue1, tree);
    while(!treequeueisempty(queue1)){
        int len = treequeuesize(queue1);
        for(int i = 0; i < len; i++){
            struct treeNode* cur = treepopfrontqueue(queue1);
            printf("tree node is %d", cur->val);
            if(cur->leftnode != NULL){
                queue1 = treepushbackqueue(queue1, cur->leftnode);
            }
            if(cur->rightnode != NULL){
                queue1 = treepushbackqueue(queue1, cur->rightnode);
            }
        }
    }
    treequeuedestroy(queue1);
}

void levelOrderTraverse2(struct treeNode* tree){
    if(tree == NULL){
        return;
    }
    struct treequeue* queue2 = treequeuecreate();
    queue2 = treepushbackqueue(queue2, tree);
    int depth = 1;
    while(!treequeueisempty(queue2)){
        int len = treequeuesize(queue2);
        for(int i = 0; i < len; i++){
            struct treeNode* cur = treepopfrontqueue(queue2);
            printf("tree node is %d, depth = %d", cur->val, depth);
            if(cur->leftnode != NULL){
                queue2 = treepushbackqueue(queue2, cur->leftnode);
            }
            if(cur->rightnode != NULL){
                queue2 = treepushbackqueue(queue2, cur->rightnode);
            }
        }
        depth++;
    }
    treequeuedestroy(queue2);
}

void levelOrderTraverse3(struct treeNode* tree){
    if(tree == NULL){
        return;
    }
    struct statequeue* queue3 = statequeuecreate();
    struct stateNode* state = (struct stateNode*) malloc(sizeof(struct stateNode));
    state->depth = 1;
    state->root = tree;
    queue3 = statepushbackqueue(queue3, state);
    while(!statequeueisempty(queue3)){
        int len = statequeuesize(queue3);
        for(int i = 0; i < len; i++){
            struct stateNode* cur = statepopfrontqueue(queue3);
            printf("tree node is %d, depth = %d", cur->root->val, cur->depth);
            if(cur->root->leftnode != NULL){
                struct stateNode* leftstate = malloc(sizeof(struct stateNode));
                leftstate->depth = cur->depth + 1;
                leftstate->root = cur->root->leftnode;
                queue3 = statepushbackqueue(queue3, leftstate);
            }
            if(cur->root->rightnode != NULL){
                struct stateNode* rightstate = malloc(sizeof(struct stateNode));
                rightstate->depth = cur->depth + 1;
                rightstate->root = cur->root->rightnode;
                queue3 = statepushbackqueue(queue3, rightstate);
            }
            free(cur);
        }
    }
    statequeuedestroy(queue3);
}

struct minpq* createminpq(int size, int cap){
    struct minpq* mypq = malloc(sizeof(struct minpq));
    mypq->list = malloc(cap * sizeof(int));
    mypq->capacity = cap;
    mypq->len = size;
    return mypq;
}

void destroyminpq(struct minpq* mypq){
    free(mypq->list);
    free(mypq);
}

int parent(int node){
    if(node == 0){
        printf("it is root, no parent");
        return 0;
    }else if (node < 0)
    {
        printf("error node");
        return -1;
    }else if(node > 0){
        return ((node - 1) / 2);
    }
    
}

int left(int node){
    if(node < 0){
        printf("error node");
        return -1;
    }else if(node >= 0){
        return (node * 2 + 1);
    }
}

int right(int node){
    if(node < 0){
        printf("error node");
        return -1;
    }else if(node >= 0){
        return (node * 2 + 2);
    }
}

void swap(struct minpq* mypq, int i, int j){
    int temp = mypq->list[i];
    mypq->list[i] = mypq->list[j];
    mypq->list[j] = temp;
}

int peak(struct minpq* mypq){
    return mypq->list[0];
}

struct minpq* swim(struct minpq* mypq, int node){
    while(node > 0 && mypq->list[parent(node)] > mypq->list[node]){
        swap(mypq, parent(node), node);
        node = parent(node);
    }
    return mypq;
}

void push(struct minpq* mypq, int val){
    mypq->list[mypq->len] = val;
    mypq->len++;
    swim(mypq, mypq->len - 1);
}

struct minpq* sink(struct minpq* mypq, int node){
    while(left(node) < mypq->len || right(node) < mypq->len){
        int min = node;
        if(left(node) < mypq->len && mypq->list[left(node)] < mypq->list[min]){
            min = left(node);
        }
        if(right(node) < mypq->len && mypq->list[right(node)] < mypq->list[min]){
            min = right(node);
        }
        if(min == node){
            break;
        }
        swap(mypq, min, node);
        node = min;  
    }
    return mypq;
}

int pop(struct minpq* mypq){
    if(mypq->len == 0){
        printf("error! the heap is empty!");
        return -1;
    }
    int result = peak(mypq);
    mypq->list[0] = mypq->list[mypq->len - 1];
    mypq->len--;
    mypq = sink(mypq, 0);
    return result;
}