#define  _POSIX_C_SOURCE 200809L
#include "monty.h"
#include <stdio.h>

bus_t bus = {NULL, NULL, NULL, 0};
/**
* main - main file
* @argc: argument count
* @argv: argument vector
* Return: 0
*/

int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t line = 1;
	stack_t *s = NULL;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (line > 0)
	{
		content = NULL;
		line = getline(&content, &size, file);
		bus.content = content;
		count++;
		if (line > 0)
		{
			exec(content, &s, count, file);
		}
		free(content);
	}
	stack_free(s);
	fclose(file);
	return (0);
}
