#include <stdbool.h> 
#include "listnode.h"
#include "tree.h"


typedef struct queue{
    int len;
    struct listNode* head;
    struct listNode* rear;
};

typedef struct treequeue{
    int len;
    struct treelistNode* head;
    struct treelistNode* rear;
};

typedef struct statequeue{
    int len;
    struct statelistNode* head;
    struct statelistNode* rear;
};



struct queue* queuecreate();
struct treequeue* treequeuecreate();
struct statequeue* statequeuecreate();
void queuedestroy(struct queue* thequeue);
void treequeuedestroy(struct treequeue* thequeue);
void statequeuedestroy(struct statequeue* thequeue);
struct queue* pushfrontqueue(struct queue* thequeue, int val);
struct treequeue* treepushfrontqueue(struct treequeue* thequeue, struct treeNode* root);
struct statequeue* statepushfrontqueue(struct statequeue* thequeue, struct stateNode* stateNd);
struct queue* pushbackqueue(struct queue* thequeue, int val);
struct treequeue* treepushbackqueue(struct treequeue* thequeue, struct treeNode* root);
struct statequeue* statepushbackqueue(struct statequeue* thequeue, struct stateNode* root);
struct listNode* popfrontqueue(struct queue* listqueue);
struct treeNode* treepopfrontqueue(struct treequeue* thequeue);
struct stateNode* statepopfrontqueue(struct statequeue* thequeue);
struct listNode* popbackqueue(struct queue* thequeue);
struct treeNode* treepopbackqueue(struct treequeue* thequeue);
struct stateNode* statepopbackqueue(struct statequeue* thequeue);
int getfrontqueue(struct queue* thequeue);
struct treeNode* getfronttreequeue(struct treequeue* thequeue);
struct stateNode* getfrontstatequeue(struct statequeue* thequeue);
int getbackqueue(struct queue* thequeue);
struct treeNode* getbacktreequeue(struct treequeue* thequeue);
struct stateNode* getbackstatequeue(struct statequeue* thequeue);
bool queueisempty(struct queue* thequeue);
bool treequeueisempty(struct treequeue* thequeue);
bool statequeueisempty(struct statequeue* thequeue);
int queuesize(struct queue* thequeue);
int treequeuesize(struct treequeue* thequeue);
int statequeuesize(struct statequeue* thequeue);
