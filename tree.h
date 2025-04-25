#include <stdbool.h> 

typedef struct treeNode{
    int val;
    struct treeNode* leftnode;
    struct treeNode* rightnode;
};

struct treelistNode {
    struct treeNode* key; 
    struct treelistNode* next;
};

typedef struct stateNode{
    int depth;
    struct treeNode* root;
};

typedef struct statelistNode{
    struct stateNode* state;
    struct statelistNode* next;
};

typedef struct minpq{
    int* list;
    int len;
    int capacity;
}minpq;

void fronttraverse(struct treeNode* tree);
void mediumtraverse(struct treeNode* tree);
void lasttraverse(struct treeNode* tree);
void levelOrderTraverse1(struct treeNode* tree);
void levelOrderTraverse2(struct treeNode* tree);
void levelOrderTraverse3(struct treeNode* tree);

struct minpq* createminpq(int size, int cap);
void destroyminpq(struct minpq* mypq);
int parent(int node);
int left(int node);
int right(int node);
void swap(struct minpq* mypq, int i, int j);
int peak(struct minpq* mypq);
struct minpq* swim(struct minpq* mypq, int node);
void push(struct minpq* mypq, int val);
struct minpq* sink(struct minpq* mypq, int node);
int pop(struct minpq* mypq);


