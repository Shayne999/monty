#include "monty.h"

/**
 * _add - adds atack elements
 * @head: pointer to head pointer
 * @counter: line count
*/

void _add(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int temp;
	int l = 0;

	h = *head;

	while (h)
	{
		h = h->next;
		l++;
	}
	if (l < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	temp = h->n + h->next->n;
	h->next->n = temp;
	*head = h->next;
	free(h);
}
