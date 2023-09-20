#include "lists.h"

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *head = *h;
	dlistint_t *new;
	unsigned int i = 1;

	if (head && head->prev)
		head = head->prev;

	if (idx == 0)
		add_dnodeint(&head, n);
	else
	{
		while (head)
		{
			if (!head->next)
				add_dnodeint_end(&head, n);
			if (i == idx)
			{
				new = malloc(sizeof(dlistint_t));
				if (!new)
					return NULL;
				new->n = n;
				new->next = head->next;
				new->prev = head;

				(head->next)->prev = new;
				head->next = new;
				break;
			}
			i++;
			head = head->next;
		}
	}
	return new;
}
