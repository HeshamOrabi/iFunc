#include "main.h"

/**
 *
 *
*/
int main()
{
	node *head, *temp, *containar;
	int i;

	head = malloc(sizeof(node));
	if (!head)
		return (0);

	head->n = 0;
	head->next = NULL;

	append_node_start(&head, 1);
	append_node_start(&head, 8);
	append_node_start(&head, 16);
	append_node_start(&head, 64);
	append_node_end(head, 128);
	append_node_end(head, 256);
	append_node_end(head, 512);
	append_node_end(head, 1024);
	append_node_end(head, 2048);

	print_list(head);
	printf("\n----------------\n");

	if (is_cycle(head))
		printf("is_cycle\n");
	else
		printf("not_cycle\n");

	printf("\n----------------\n");

	temp = head;
	i = 0;
	while (temp->next)
	{
		if (i == 2)
			containar = temp;
		temp = temp->next;
		i++;
	}
	temp->next = containar;

	if (is_cycle(head))
		printf("is_cycle\n");
	else
		printf("not_cycle\n");

	printf("\n----------------\n");
	
	temp->next = NULL;

	print_list(head);

	printf("\n----------------\n");
	incert_node(&head, 100);

	print_list(head);
	printf("\n----------------\n");

	_free(head);

	return (0);

}
