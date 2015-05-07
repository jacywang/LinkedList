//
//  main.c
//  LinkedLists
//
//  Created by JIAN WANG on 5/6/15.
//  Copyright (c) 2015 JWANG. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

typedef struct Node Node;

void listAll(Node *node);
Node *searchValue(Node *node, int val);
void insertToTheEnd(Node *node, Node *newNode);
void removeListItem(Node *node, Node *nodeToDelete);
Node *initListItem(int val);

int main(int argc, const char * argv[]) {
    Node *node1 = initListItem(1);
    Node *node2 = initListItem(2);
    Node *node3 = initListItem(3);
    Node *node4 = initListItem(4);
    Node *node5 = initListItem(5);
    Node *newNode = initListItem(6);
    insertToTheEnd(node1, node2);
    insertToTheEnd(node1, node3);
    insertToTheEnd(node1, node4);
    insertToTheEnd(node1, node5);

    printf("All values in the list: ");
    listAll(node1);
    
    int valueUserInput;
    printf("Input the value to find:");
    scanf("%d", &valueUserInput);
    
    Node *searchResult = searchValue(node1, valueUserInput);
    if (searchResult == NULL) {
        printf("%d is not found in this list!\n", valueUserInput);
    } else {
        printf("Search result %d found at %p\n", searchResult->value, searchResult);
    }
    
    insertToTheEnd(node1, newNode);
    listAll(node1);
    
    removeListItem(node1, newNode);
    listAll(node1);
    
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

void insertToTheEnd(Node *node, Node *newNode) {
    while (node->next != NULL) {
        node = node->next;
    }
    node->next = newNode;
    newNode->next = NULL;
}

void removeListItem(Node *node, Node *nodeToDelete) {
    if (node == nodeToDelete) {
        node->next = NULL;
    } else {
        while (node->next != nodeToDelete) {
            node = node->next;
        }
        if (nodeToDelete->next != NULL) {
            node->next = node->next->next;//nodeToDelete->next;
            nodeToDelete->next = NULL;
        } else {
            node->next = NULL;
        }
    }
}

Node *initListItem(int val) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->value = val;
    return node;
}

