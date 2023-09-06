#include "main.h"

node *incert_node(node **head, int n)
{
	node *new, *temp;

	new = malloc(sizeof(node));
	if (!new)
		return(NULL);

	new->n = n;
	new->next = NULL;

	if (!(*head) || (*head)->n > n)
	{
		new->next = *head;
		*head = new;
		return(new);
	}

	temp = *head;
	while (temp && (temp->next)->n < n)
	{
		temp = temp->next;
	}

	new->next = temp->next;
	temp->next = new;

	return(new);
}
