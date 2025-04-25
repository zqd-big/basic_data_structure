#include <stdbool.h> 

typedef struct listNode{
    int key;
    struct listNode* next;
} listNode;

listNode* createlistNode(int val);
void insertlistNode(int val, listNode** node);
bool searchlistNode(int val, listNode* node);
void deletelistNode(int val, listNode** node);
void freelistNode(listNode** node);