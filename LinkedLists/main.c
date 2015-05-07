//
//  main.c
//  LinkedLists
//
//  Created by JIAN WANG on 5/6/15.
//  Copyright (c) 2015 JWANG. All rights reserved.
//

#include <stdio.h>

struct Node {
    int value;
    struct Node *next;
};

typedef struct Node Node;

int main(int argc, const char * argv[]) {
    
    Node node1;
    Node node2;
    Node node3;
    Node node4;
    Node node5;
    
    node1.value = 1;
    node1.next = &node2;
    
    node2.value = 2;
    node2.next = &node3;
    
    node3.value = 3;
    node3.next = &node4;
    
    node4.value = 4;
    node4.next = &node5;
    
    node5.value = 5;
    node5.next = NULL;

    printf("node1 value is %d,\nnode2 value is %d,\nnode3 value is %d\n", node1.value, node1.next->value, node1.next->next->value);
    return 0;
}
