#include "monty.h"

/**
 * _swap - adds the top two elements of the stack.
 * @head: pointer to head pointer
 * @counter: line count
*/

void _swap(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	h = *head;
	temp = h->n;
	h->n = h->next->n;
	h->next->n = temp;
}
