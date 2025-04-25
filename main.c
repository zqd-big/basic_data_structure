#include <stdio.h>
#include "hashtable.h"
#include "graph.h"

void freeTree(struct treeNode* node){
    if (node == NULL) return;
    freeTree(node->leftnode);
    freeTree(node->rightnode);
    free(node);
}

int main(){
    // ======================= 哈希表测试 =======================
    // 创建一个大小为 10 的 hashSet
    hashSet* set = createhashSet(10);
    
    // 创建一个链表头指针
    listNode* head = NULL;

    // 测试链表操作
    printf("Inserting nodes into the list:\n");
    insertlistNode(3, &head);
    insertlistNode(2, &head);
    insertlistNode(1, &head);

    // 打印链表
    listNode* current = head;
    printf("Current list: ");
    while (current != NULL) {
        printf("%d -> ", current->key);
        current = current->next;
    }
    printf("NULL\n");

    // 搜索链表
    printf("Search for 2: %s\n", searchlistNode(2, head) ? "Found" : "Not Found");
    printf("Search for 4: %s\n", searchlistNode(4, head) ? "Found" : "Not Found");

    // 删除节点
    printf("Deleting node with value 2...\n");
    deletelistNode(2, &head);

    // 打印链表
    current = head;
    printf("List after deleting 2: ");
    while (current != NULL) {
        printf("%d -> ", current->key);
        current = current->next;
    }
    printf("NULL\n");

    // 释放链表内存
    freelistNode(&head);
    
    // 插入一些值到 hashSet
    printf("\nInserting some values into hashSet:\n");
    inserthashNode(set, 5);
    inserthashNode(set, 15);
    inserthashNode(set, 25);

    // 验证是否包含某些值
    printf("Contains 5: %s\n", containhashNode(set, 5) ? "true" : "false");
    printf("Contains 15: %s\n", containhashNode(set, 15) ? "true" : "false");
    printf("Contains 25: %s\n", containhashNode(set, 25) ? "true" : "false");
    printf("Contains 35: %s\n", containhashNode(set, 35) ? "true" : "false");

    // 释放 hashSet 内存
    freehashSet(set);

    // ======================= 队列测试 =======================
    printf("\nTesting queue:\n");
    struct queue* myQueue = queuecreate();
    
    printf("Pushing elements to the queue:\n");
    pushbackqueue(myQueue, 10);
    pushbackqueue(myQueue, 20);
    pushbackqueue(myQueue, 30);
    
    printf("Front: %d\n", getfrontqueue(myQueue));
    printf("Back: %d\n", getbackqueue(myQueue));
    
    printf("Queue size: %d\n", queuesize(myQueue));
    printf("Is queue empty? %s\n", queueisempty(myQueue) ? "Yes" : "No");
    
    printf("Popping front...\n");
    popfrontqueue(myQueue);
    printf("Front after pop: %d\n", getfrontqueue(myQueue));
    
    printf("Popping back...\n");
    popbackqueue(myQueue);
    printf("Back after pop: %d\n", getbackqueue(myQueue));
    
    printf("Final Queue size: %d\n", queuesize(myQueue));
    
    queuedestroy(myQueue);
    printf("Queue destroyed.\n");
    // ======================= 二叉树测试 =======================
    printf("\nTesting Binary Tree Traversals:\n");

    // 创建测试树结构：
    //        1
    //      /   \
    //     2     3
    //    / \   /
    //   4  5 6

    // 创建节点
    struct treeNode* root = (struct treeNode*)malloc(sizeof(struct treeNode));
    root->val = 1;

    struct treeNode* node2 = (struct treeNode*)malloc(sizeof(struct treeNode));
    node2->val = 2;
    node2->leftnode = NULL;
    node2->rightnode = NULL;

    struct treeNode* node3 = (struct treeNode*)malloc(sizeof(struct treeNode));
    node3->val = 3;
    node3->leftnode = NULL;
    node3->rightnode = NULL;

    struct treeNode* node4 = (struct treeNode*)malloc(sizeof(struct treeNode));
    node4->val = 4;
    node4->leftnode = NULL;
    node4->rightnode = NULL;

    struct treeNode* node5 = (struct treeNode*)malloc(sizeof(struct treeNode));
    node5->val = 5;
    node5->leftnode = NULL;
    node5->rightnode = NULL;

    struct treeNode* node6 = (struct treeNode*)malloc(sizeof(struct treeNode));
    node6->val = 6;
    node6->leftnode = NULL;
    node6->rightnode = NULL;

    // 构建树结构
    root->leftnode = node2;
    root->rightnode = node3;
    node2->leftnode = node4;
    node2->rightnode = node5;
    node3->leftnode = node6;

    // 测试前序遍历
    printf("\nPreorder Traversal:\n");
    fronttraverse(root);

    // 测试中序遍历
    printf("\n\nInorder Traversal:\n");
    mediumtraverse(root);

    // 测试后序遍历
    printf("\n\nPostorder Traversal:\n");
    lasttraverse(root);

    // 测试层序遍历版本1
    printf("\n\nLevel Order Traversal v1:\n");
    levelOrderTraverse1(root);

    // 测试层序遍历版本2（带深度统计）
    printf("\n\nLevel Order Traversal v2 (with depth):\n");
    levelOrderTraverse2(root);

    // 测试层序遍历版本3（状态队列）
    printf("\n\nLevel Order Traversal v3 (state queue):\n");
    levelOrderTraverse3(root);

    // 释放树内存
    freeTree(root);
    printf("\n\nTree memory freed.\n");
    // ======================= 有向图测试 =======================
    printf("\n\nTesting Directed Graph:\n");

    // 创建包含5个节点的图（初始容量为2）
    struct graph* myGraph = create_graph(5, 2);

    // 测试添加边
    printf("\nAdding edges:\n");
    addEdge(myGraph, 0, 1);  // 0 -> 1
    addEdge(myGraph, 0, 2);  // 0 -> 2
    addEdge(myGraph, 1, 3);  // 1 -> 3
    addEdge(myGraph, 2, 4);  // 2 -> 4
    addEdge(myGraph, 3, 4);  // 3 -> 4

    // 测试边存在性
    printf("\nChecking edge existence:\n");
    printf("Edge 0->1 exists? %s\n", hasEdge(myGraph, 0, 1) ? "Yes" : "No");  // Yes
    printf("Edge 0->3 exists? %s\n", hasEdge(myGraph, 0, 3) ? "Yes" : "No");  // No

    // 测试获取邻居
    printf("\nNeighbors of node 0:\n");
    int neighbor_count;
    int* outside = malloc(sizeof(int));
    struct Edge* myneighbors = neighbors(myGraph, 0, outside); // 注意：直接访问内部数据仅用于测试
    for (int i = 0; i < myGraph->sizes[0]; i++) {
        printf("-> %d (weight %d)\n", myneighbors[i].to, myneighbors[i].weight);
    }

    // 测试删除边
    printf("\nRemoving edge 0->2...\n");
    removeEdge(myGraph, 0, 2);
    printf("Edge 0->2 exists now? %s\n", hasEdge(myGraph, 0, 2) ? "Yes" : "No");  // No

    // 释放图内存
    freegraph(myGraph);
    printf("\nGraph memory freed.\n");

        // ======================= DFS 遍历测试 =======================
    printf("\n\nTesting DFS Traversal:\n");

        // 重新创建图（避免之前删除边的影响）
    struct graph* dfsGraph = create_graph(5, 2);
    addEdge(dfsGraph, 0, 1);
    addEdge(dfsGraph, 0, 2);
    addEdge(dfsGraph, 1, 3);
    addEdge(dfsGraph, 2, 4);
    addEdge(dfsGraph, 3, 4);

    // 初始化访问数组
    int* visited = calloc(dfsGraph->node_count, sizeof(int));

    // 测试 dfs_traverse_node（从节点0开始遍历）
    printf("\nDFS Traversal from node 0:\n");
    dfs_traverse_node(dfsGraph, 0, visited);
    printf("\n");

    // 重置访问数组
    memset(visited, 0, dfsGraph->node_count * sizeof(int));

    // 测试 dfs_traverse_edge（查找从0到4的所有路径）
    struct queue* pathQueue = queuecreate();
    printf("\nAll paths from 0 to 4:\n");
    dfs_traverse_edge(dfsGraph, 0, 4, pathQueue, visited);

    // 释放资源
    free(visited);
    queuedestroy(pathQueue);
    freegraph(dfsGraph);
    printf("\nDFS test resources freed.\n");
    // ======================= BFS 遍历测试 =======================
    printf("\n\nTesting BFS Traversals:\n");

    // 创建测试图（示例：分层树状结构）
    struct graph* bfsGraph = create_graph(6, 2); // 6 个节点
    addEdge(bfsGraph, 0, 1);
    addEdge(bfsGraph, 0, 2);
    addEdge(bfsGraph, 1, 3);
    addEdge(bfsGraph, 1, 4);
    addEdge(bfsGraph, 2, 5);
    addEdge(bfsGraph, 3, 5); // 添加一个跨层连接以测试深度计算

    // 测试 bfs_travers1（常规 BFS）
    printf("\nBFS Traversal (Order):\n");
    bfs_travers1(bfsGraph);
    printf("\n");

    // 测试 bfs_travers2（带深度的 BFS）
    printf("\nBFS Traversal with Depth:\n");
    bfs_travers2(bfsGraph);
    printf("\n");

    // 清理图资源
    freegraph(bfsGraph);
    printf("\nBFS test resources freed.\n");

    // ======== 边界测试用例 ========
    // 测试空图
    printf("\nTesting Empty Graph:\n");
    struct graph* emptyGraph = create_graph(0, 0);
    bfs_travers1(emptyGraph); // 应输出错误信息
    bfs_travers2(emptyGraph);
    freegraph(emptyGraph);

    // 测试单节点图
    printf("\nTesting Single-Node Graph:\n");
    struct graph* singleNodeGraph = create_graph(1, 0);
    printf("BFS Travers1 Output:\n");
    bfs_travers1(singleNodeGraph); // 应输出 "visited 0"
    printf("\nBFS Travers2 Output:\n");
    bfs_travers2(singleNodeGraph); // 应输出 "visited 0, depth 1"
    freegraph(singleNodeGraph);
    // ======================= 二叉堆测试 =======================
    printf("\nTesting Min-Heap:\n");

    // 创建一个空的二叉堆，容量为10
    struct minpq* myHeap = createminpq(0, 10);

    // 向堆中插入元素
    printf("Inserting elements into the heap:\n");
    push(myHeap, 10);
    push(myHeap, 5);
    push(myHeap, 20);
    push(myHeap, 15);
    push(myHeap, 30);

    // 打印堆中的最小元素（堆顶）
    printf("Current min element (heap top): %d\n", peak(myHeap));

    // 弹出最小元素
    printf("Popped element: %d\n", pop(myHeap));

    // 打印堆中的最小元素（堆顶）
    printf("Current min element after pop: %d\n", peak(myHeap));

    // 弹出剩余元素
    printf("Popped element: %d\n", pop(myHeap));
    printf("Popped element: %d\n", pop(myHeap));
    printf("Popped element: %d\n", pop(myHeap));
    printf("Popped element: %d\n", pop(myHeap));

    // 打印空堆后的堆顶元素
    printf("Trying to pop from empty heap...\n");
    pop(myHeap);  // Should print an error

    // 释放堆内存
    destroyminpq(myHeap);
    return 0;
}
