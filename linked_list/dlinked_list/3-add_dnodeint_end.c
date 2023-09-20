#include "lists.h"

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *tmp = *head;

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return NULL;

	new->n = n;
	new->next = NULL;

	if (!tmp)
	{
		new->prev = NULL;
		*head = new;
	}
	else
	{

		while (tmp->next)
			tmp = tmp->next;

		new->prev = tmp;

		tmp->next = new;
	}

	return new;
}
