#include <stdbool.h> 

typedef struct hashNode {
    int key;
    struct hashNode* next;
} hashNode;

typedef struct hashSet {
    int size;
    struct hashNode** bucket;
} hashSet;

// 函数声明
hashSet* createhashSet(int size);
int getIndex(int val, hashSet* set);
void inserthashNode(hashSet* set, int val);
bool containhashNode(hashSet* set, int val);
void freehashSet(hashSet* set);


