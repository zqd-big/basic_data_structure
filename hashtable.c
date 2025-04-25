#include <stdio.h>
#include <stdlib.h>  
#include <stdbool.h> 
#include <math.h> 
#include "hashtable.h"


hashSet* createhashSet(int size){
    hashSet* set = (hashSet*) malloc(sizeof(hashSet));
    set->size = size;
    set->bucket = (hashNode**) malloc(size * sizeof(hashNode*));
    for (int i = 0; i < size; i++) {
        set->bucket[i] = NULL; 
    }
    return set;
}

int getIndex(int val, hashSet* set){
    return abs(val) % (set->size);
}

void inserthashNode(hashSet* set, int val){
    int index = getIndex(val, set);
    hashNode* node = (hashNode*) malloc(sizeof(hashNode));
    node->key = val;
    node->next = set->bucket[index];
    set->bucket[index] = node;
}

bool containhashNode(hashSet* set, int val){
    int index = getIndex(val, set);
    hashNode* node = set->bucket[index];
    while (node){
        if(node->key == val){
            return true;
        }
        node = node->next;
    }
    return false;
}

void freehashSet(hashSet* set){
    for(int i = 0; i < set->size; i++){
        hashNode* node = set->bucket[i];
        while (node){
            hashNode* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(set->bucket);
    free(set);
}