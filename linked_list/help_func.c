#include "main.h"

/**
 *
 *
*/
node *append_node_start(node **head, int n)
{
	node *new;

	new = malloc(sizeof(node));
	if (!new)
		return(NULL);

	new->n = n;
	new->next = *head;
	*head = new;

	return(new);
}

/**
 *
 *
*/
node *append_node_end(node *head, int n)
{
	node *new, *temp;

	new = malloc(sizeof(node));
	if (!new)
		return(NULL);

	new->n = n;
	
	temp = head;
	while (temp->next)
	{
		temp = temp->next;
	}

	temp->next = new;
	new->next = NULL;

	return(new);
}


int print_list(node *head)
{
	node *temp;
	int n = 0;

	temp = head;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
		n++;
	}

	return(n);
}

void _free(node *head)
{
    node *current;

    while (head != NULL)
    {
        current = head;
        head = head->next;
        free(current);
    }
}
