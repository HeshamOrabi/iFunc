#include <stdio.h>
#include <stdlib.h>

/**
 * Define a struct for a linked list node.
 */
typedef struct linkedList {
    char c;
    int n;
    struct linkedList *next;
} node;

/**
 * printDataOfAll - Function to print the data of all nodes in the linked list.
 * @head: pointer to a pointer
 */
void printDataOfAll(node **head)
{
    node *temp;
    temp = *head;
    /*Iterate through the linked list and print the data of each node.*/
    while (temp)
    {
        printf("node %p [%d] that points to [%p] Data : char = %c\n", temp, temp->n, temp->next, temp->c);
        temp = temp->next;
    }
}

/**
 * createNode - Function to create a new node and add it to the end of the linked list.
 * @head: pointer to a pointer
 * @num: number of node tobe created
 */
void createNode(node **head, int num)
{
    node *temp, *help;
    int nf;
    char cf;
    
    while (num > 0)
    {
        /*Prompt the user to enter data for the new node.*/
        printf("Enter a char for the node: ");
        scanf(" %c", &cf);
        printf("Enter an int for the node: ");
        scanf(" %d", &nf);
        
        /*Allocate memory for the new node.*/
        help = malloc(sizeof(node));
        help->c = cf;
        help->n = nf;
        
        /*Find the end of the linked list and append the new node.*/
        temp = *head;
    
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = help;
        help->next = NULL;
            
        num--;

    }
}

/**
 * createNode - Function to create a new node and add it to the end of the linked list.
 * @head: pointer to a pointer
 * @num: number of node tobe created
 */
void createNodeStart(node **head, int num)
{
        node *help;
        char cf;
        int nf;
        
        while (num > 0)
        {
            /*Prompt the user to enter data for the new node.*/
            printf("Enter a char for the node: ");
            scanf(" %c", &cf);
            printf("Enter an int for the node: ");
            scanf(" %d", &nf);
            
            help = malloc(sizeof(node));
            
            help->c = cf;
            help->n = nf;
            
            help->next = *head;
            *head = help;
            
            num--;
        }
}

/**
 * main - Intialization function.
 */
int main()
{
    node *head, *temp;
    
    /*Allocate memory for the head node of the linked list.*/
    head = malloc(sizeof(node));
    head->c = 'H';
    head->n = 0;
    head->next = NULL;
    
    /*Prompt the user to create new nodes and add them to end of the linked list.*/
    createNode(&head, 4);
    
    /*Prompt the user to create new nodes and add them to start of the linked list.*/
    createNodeStart(&head, 1);

    /*Print the data of all nodes in the linked list.*/
    printDataOfAll(&head);

    /*Print a message indicating the end of the program.*/
    printf("Finish");
    
    /*Free the memory allocated for the linked list nodes.*/
    temp = head;
    while (temp)
    {
        head = head->next;
        free(temp);
        temp = head;
    }
    
    return 0;
}
