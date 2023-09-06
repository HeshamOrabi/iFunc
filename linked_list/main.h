#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int n;
    struct node *next;
} node;

void _free(node *head);
int print_list(node *head);
node *append_node_end(node *head, int n);
node *append_node_start(node **head, int n);
int is_cycle(node *head);
node *incert_node(node **head, int n);

#endif
