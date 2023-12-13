#include "monty.h"

/**
 * _push - add node to the stack
 * @head: stack head
 * @counter: line count
*/

void _push(stack_t **head, unsigned int counter)
{
	int i = 0;
	int flag = 0;
	int n;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			i++;
		for (; bus.arg[i] != '\0'; i++)
		{
			if (bus.arg[i] > 57 || bus.arg[i] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			stack_free(*head);
			exit(EXIT_FAILURE); }}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		add_node(head, n);
	else
		add_queue(head, n);
}
