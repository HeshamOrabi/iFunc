#include "main.h"

int is_cycle(node *head)
{
	node *fast = head, *slow = head;

	if (!head)
		return(0);

	while (fast && fast->next)
	{
		fast = (fast->next)->next;
		slow = slow->next;

		if (fast == slow)
		{
			return(1);
		}
	}
	return(0);
}
