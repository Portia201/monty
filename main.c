#include "monty.h"
#include <stdio.h> /* Include for getline */
#include <stdlib.h>

montyState_t montyState = {NULL, NULL};

/**
 * printError - this functoom prints the output
 * @message: the error message
 */
void printError(const char *message)
{
	fprintf(stderr, "Error: %s\n", message);
}

/**
 * executeMontyCode - read and execute Monty code
 * @file: executed
 */
void executeMontyCode(FILE *file)
{
	char *content;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		montyState.content = content;
		counter++;
		if (read_line > 0)
		{
			execute(content, &stack, counter, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
}

/**
 * main - entry point
 * @argc: argument count
 * @agrv: argument value
 * Return:  Eactime success return 0
 */
int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		printError("Usage: monty file");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	montyState.file = file;

	if (!file)
	{
		printError("Can't open the specified file");
		exit(EXIT_FAILURE);
	}

	executeMontyCode(file);

	return (0);
}
