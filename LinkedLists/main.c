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

void listAll(Node *node);
Node * searchValue(Node *node, int val);

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

    printf("All values in the list: ");
    listAll(&node1);
    
    int valueUserInput;
    printf("Input the value to find:");
    scanf("%d", &valueUserInput);
    
    Node *searchResult = searchValue(&node1, valueUserInput);
    if (searchResult == NULL) {
        printf("%d is not found in this list!\n", valueUserInput);
    } else {
        printf("Search result %d found at %p\n", searchResult->value, searchResult);
    }
    
    return 0;
}

void listAll(Node *node) {
    while (node->next != NULL) {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("%d\n", node->value);
}

Node * searchValue(Node *node, int val){
    while (node->value != val) {
        node = node->next;
        if (node == NULL) {
            break;
        }
    }
    return node;
}