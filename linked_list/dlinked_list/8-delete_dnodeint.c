#include "lists.h"

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *curunt = *head;
	dlistint_t *next;
	unsigned int i = 0;

	if (curunt && curunt->prev)
		curunt = curunt->prev;

	while (curunt)
	{
		next = curunt->next;
		if (i == index)
		{
			if (i == 0)
			{
				if (curunt->next)
					(curunt->next)->prev = NULL;
				*head = curunt->next;
			}
			else
			{
				if (curunt->next)
					(curunt->next)->prev = curunt->prev;
				(curunt->prev)->next = curunt->next;
			}
			free(curunt);
			return (1);
		}
		i++;
		curunt = next;
	}
	return (-1);
}
