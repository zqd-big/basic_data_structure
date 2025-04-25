#include <stdio.h>
#include <stdlib.h>  
#include <stdbool.h> 
#include <math.h>
#include "listnode.h"

listNode* createlistNode(int val){
    listNode* node = (listNode*) malloc(sizeof(listNode));
    node->key = val;
    node->next = NULL;
    return node;
}

void insertlistNode(int val, listNode** node){
    listNode* now = (listNode*) malloc(sizeof(listNode));
    now->key = val;
    now->next = *node;
    *node = now;
}

bool searchlistNode(int val, listNode* node){
    listNode* now = node;
    while(now != NULL){
        if(now->key == val){
            return true;
        }
        now = now->next;
    }
    return false;
}

void deletelistNode(int val, listNode** node){
    if(*node == NULL){
        return;
    }
    if((*node)->key == val){
        listNode* temp = *node;
        *node = (*node)->next;
        free(temp);
    }
    listNode* now = *node;
    while(now != NULL && now->next != NULL){
        if(now->next->key == val){
            listNode* temp = now->next;
            now->next = now->next->next;
            free(temp);
        }else{
            now = now->next;
        }
    }   
}

void freelistNode(listNode** node){
    listNode* now = *node;
    while(now != NULL){
        listNode* temp = now;
        now = now->next;
        free(temp);
    }
    *node = NULL;
}