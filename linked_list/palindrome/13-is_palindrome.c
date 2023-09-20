#include "lists.h"

int is_palindrome(listint_t **head)
{
	listint_t *fast = *head;
	listint_t *slow = *head;
	listint_t *next = NULL;
	listint_t *prev = NULL;

	while (fast && fast->next)
	{
		fast = (fast->next)->next;

		next = slow->next;
		slow->next = prev;
		prev = slow;
		slow = next;
	}

	if (fast)
		slow = slow->next;

	while (prev && slow)
	{
		if (prev->n != slow->n)
			return 0;
		prev = prev->next;
		slow = slow->next;
	}
	return 1;
}
