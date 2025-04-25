#include <stdio.h>
#include <stdlib.h>  
#include <stdbool.h> 
#include <math.h>
#include "queue.h"



struct queue* queuecreate(){
    struct queue* result = (struct queue*) malloc(sizeof(struct queue));
    result->head = NULL;
    result->rear = NULL;
    result->len = 0;
    return result;
}

struct treequeue* treequeuecreate(){
    struct treequeue* result = (struct treequeue*) malloc(sizeof(struct treequeue));
    result->head = NULL;
    result->rear = NULL;
    result->len = 0;
    return result;
}

struct statequeue* statequeuecreate(){
    struct statequeue* result = (struct statequeue*) malloc(sizeof(struct statequeue));
    result->head = NULL;
    result->rear = NULL;
    result->len = NULL;
    return result;
}

void queuedestroy(struct queue* thequeue){
    if(thequeue == NULL){
        return;
    }
    while(thequeue->head != NULL){
        struct listNode* temp = thequeue->head;
        thequeue->head = thequeue->head->next;
        free(temp);
    }
    thequeue->rear = NULL;
    free(thequeue);
}

void treequeuedestroy(struct treequeue* thequeue){
    if(thequeue == NULL){
        return;
    }
    while(thequeue->head != NULL){
        struct listNode* temp = thequeue->head;
        thequeue->head = thequeue->head->next;
        free(temp);
    }
    thequeue->rear = NULL;
    free(thequeue);
}

void statequeuedestroy(struct statequeue* thequeue){
    if(thequeue == NULL){
        return;
    }
    while(thequeue->head != NULL){
        struct statelistNode* temp = thequeue->head;
        thequeue->head = thequeue->head->next;
        free(temp);
    }
    thequeue->rear = NULL;
    free(thequeue);
}



struct queue* pushfrontqueue(struct queue* thequeue, int val){
    if(thequeue == NULL){
        return NULL;
    }
    struct listNode* temp = createlistNode(val);
    temp->next = thequeue->head;
    thequeue->head = temp;
    if(thequeue->rear == NULL){
        thequeue->rear = temp;
    }
    thequeue->len += 1;
    return thequeue;
}

struct treequeue* treepushfrontqueue(struct treequeue* thequeue, struct treeNode* root){
    if(thequeue == NULL){
        return NULL;
    }
    struct treelistNode* temp = (struct treelistNode*) malloc(sizeof(struct treelistNode));
    temp->key = root;
    temp->next = thequeue->head;
    thequeue->head = temp;
    if(thequeue->rear == NULL){
        thequeue->rear = temp;
    }
    thequeue->len += 1;
    return thequeue;
}

struct statequeue* statepushfrontqueue(struct statequeue* thequeue, struct stateNode* stateNd){
    if(thequeue == NULL){
        return NULL;
    }
    struct statelistNode* temp = (struct statelistNode*) malloc(sizeof(struct statelistNode));
    temp->state = stateNd;
    temp->next = thequeue->head;
    thequeue->head = temp;
    if(thequeue->rear == NULL){
        thequeue->rear = temp;
    }
    thequeue->len += 1;
    return thequeue;
}



struct queue* pushbackqueue(struct queue* thequeue, int val){
    if(thequeue == NULL){
        return NULL;
    }
    struct listNode* temp = createlistNode(val);
    if(thequeue->rear == NULL){
        thequeue->head = temp;
        thequeue->rear = temp;
    }else{
        thequeue->rear->next = temp;
        thequeue->rear = temp;
    }
    thequeue->len += 1;
    return thequeue;
}

struct treequeue* treepushbackqueue(struct treequeue* thequeue, struct treeNode* root){
    if(thequeue == NULL){
        return NULL;
    }
    struct treelistNode* temp = (struct treelistNode*) malloc(sizeof(struct treelistNode));
    temp->key = root;
    temp->next = NULL;
    if(thequeue->rear == NULL){
        thequeue->head = temp;
        thequeue->rear = temp;
    }else{
        thequeue->rear->next = temp;
        thequeue->rear = temp;
    }
    thequeue->len += 1;
    return thequeue;
}

struct statequeue* statepushbackqueue(struct statequeue* thequeue, struct stateNode* root){
    if(thequeue == NULL){
        return NULL;
    }
    struct statelistNode* temp = (struct statelistNode*) malloc(sizeof(struct statelistNode));
    temp->state = root;
    temp->next = NULL;
    if(thequeue->rear == NULL){
        thequeue->head = temp;
        thequeue->rear = temp;
    }else{
        thequeue->rear->next = temp;
        thequeue->rear = temp;
    }
    thequeue->len += 1;
    return thequeue;
}


struct listNode* popfrontqueue(struct queue* listqueue){
    if(listqueue == NULL || listqueue->head == NULL){
        return listqueue;
    }
    struct listNode* temp = listqueue->head;
    listqueue->head = listqueue->head->next;
    temp->next = NULL;
    if(listqueue->head == NULL){
        listqueue->rear = NULL;
    }
    listqueue->len -= 1;
    return temp;
}

struct treeNode* treepopfrontqueue(struct treequeue* thequeue){
    if(thequeue == NULL || thequeue->head == NULL){
        return NULL;
    }
    struct treelistNode* temp = thequeue->head;
    struct treeNode* result = temp->key;
    thequeue->head = thequeue->head->next;
    if(thequeue->head == NULL){
        thequeue->rear = NULL;
    }
    thequeue->len -= 1;
    free(temp);
    return result;
}

struct stateNode* statepopfrontqueue(struct statequeue* thequeue){
    if(thequeue == NULL || thequeue->head == NULL){
        return NULL;
    }
    struct statelistNode* temp = thequeue->head;
    struct stateNode* result = temp->state;
    thequeue->head = thequeue->head->next;
    if(thequeue->head == NULL){
        thequeue->rear = NULL;
    }
    thequeue->len -= 1;
    free(temp);
    return result;
}

struct listNode* popbackqueue(struct queue* thequeue) {
    if (!thequeue || !thequeue->head) return NULL;

    struct listNode* popped_node = thequeue->rear;
    
    if (thequeue->len == 1) {
        thequeue->head = NULL;
        thequeue->rear = NULL;
    } else {
        struct listNode* temp = thequeue->head;
        // 找到尾节点的前一个节点
        while (temp->next != thequeue->rear) {
            temp = temp->next;
        }
        temp->next = NULL;       // 断开旧尾节点
        thequeue->rear = temp;   // 更新尾指针
    }

    thequeue->len--;
    popped_node->next = NULL;    // 确保返回的节点独立
    return popped_node;          // 调用者需负责释放此节点
}

struct treeNode* treepopbackqueue(struct treequeue* thequeue){
    if(thequeue == NULL || thequeue->head == NULL){
        return NULL;
    }
    if(thequeue->len == 1){
        struct treelistNode* temp = thequeue->head;
        struct treeNode* result = temp->key;
        thequeue->head = NULL;
        thequeue->rear = NULL;
        free(temp);
        thequeue->len -= 1;
        return result;
    }
    struct treelistNode* temp = thequeue->head;
    while (temp->next != thequeue->rear) { 
        temp = temp->next;
    }
    struct treeNode* result = thequeue->rear->key;
    free(thequeue->rear);
    thequeue->rear = temp;
    thequeue->rear->next = NULL;
    thequeue->len -= 1;
    return result;
}

struct stateNode* statepopbackqueue(struct statequeue* thequeue){
    if(thequeue == NULL || thequeue->head == NULL){
        return NULL;
    }
    if(thequeue->len == 1){
        struct statelistNode* temp = thequeue->head;
        struct stateNode* result = temp->state;
        thequeue->head = NULL;
        thequeue->rear = NULL;
        free(temp);
        thequeue->len -= 1;
        return result;
    }
    struct statelistNode* temp = thequeue->head;
    while (temp->next != thequeue->rear) { 
        temp = temp->next;
    }
    struct stateNode* result = thequeue->rear->state;
    free(thequeue->rear);
    thequeue->rear = temp;
    thequeue->rear->next = NULL;
    thequeue->len -= 1;
    return result;
}

int getfrontqueue(struct queue* thequeue){
    if(thequeue == NULL || thequeue->head == NULL){
        return NULL;
    }
    return thequeue->head->key;
}

struct treeNode* getfronttreequeue(struct treequeue* thequeue){
    if(thequeue == NULL || thequeue->head == NULL){
        return NULL;
    }
    return thequeue->head->key;
}

struct stateNode* getfrontstatequeue(struct statequeue* thequeue){
    if(thequeue == NULL || thequeue->head == NULL){
        return NULL;
    }
    return thequeue->head->state;
}

int getbackqueue(struct queue* thequeue){
    if(thequeue == NULL || thequeue->rear == NULL){
        return NULL;
    }
    return thequeue->rear->key;
}

struct treeNode* getbacktreequeue(struct treequeue* thequeue){
    if(thequeue == NULL || thequeue->rear == NULL){
        return NULL;
    }
    return thequeue->rear->key;
}

struct stateNode* getbackstatequeue(struct statequeue* thequeue){
    if(thequeue == NULL || thequeue->rear == NULL){
        return NULL;
    }
    return thequeue->rear->state;
}

bool queueisempty(struct queue* thequeue){
    if(thequeue == NULL){
        printf("该队列为NULL");
        return true;
    }
    if(thequeue->head == NULL){
        return true;
    }else{
        return false;
    }
}

bool treequeueisempty(struct treequeue* thequeue){
    if(thequeue == NULL){
        printf("该队列为NULL");
        return true;
    }
    if(thequeue->head == NULL){
        return true;
    }else{
        return false;
    }
}

bool statequeueisempty(struct statequeue* thequeue){
    if(thequeue == NULL){
        printf("该队列为NULL");
        return true;
    }
    if(thequeue->head == NULL){
        return true;
    }else{
        return false;
    }
}

int queuesize(struct queue* thequeue){
    if(thequeue == NULL){
        printf("该队列为NULL");
        return -1;
    }
    return thequeue->len;
}

int treequeuesize(struct treequeue* thequeue){
    if(thequeue == NULL){
        printf("该队列为NULL");
        return -1;
    }
    return thequeue->len;
}

int statequeuesize(struct statequeue* thequeue){
    if(thequeue == NULL){
        printf("该队列为NULL");
        return -1;
    }
    return thequeue->len;
}