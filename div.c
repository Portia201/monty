#include "monty.h"

void free_stack(stack_t *head);
void free_node(stack_t *node);

/**
* close_file_and_exit - Closes the file and exits the program.
*/
void close_file_and_exit(void)
{
	if (bus.file)
		fclose(bus.file);

	if (bus.content)
		free(bus.content);

	if (*head)
		free_stack(*head);

	exit(EXIT_FAILURE);
}

/**
* custom_divide - divides the top two elements of the stack.
* @head: stack head
* @counter: line_number
* Return: no return
*/
void custom_divide(stack_t **head, unsigned int counter)
{
	stack_t *current;
	int length = 0, result;

	current = *head;

	while (current)
	{
		current = current->next;
		length++;
	}

	if (length < 2)
	{
		fprintf(stderr, "L%d: Unable to divide, stack is too short\n", counter);
		close_file_and_exit();
	}

	current = *head;

	if (current->n == 0)
	{
		fprintf(stderr, "L%d: Division by zero\n", counter);
		close_file_and_exit();
	}

	result = current->next->n / current->n;
	current->next->n = result;
	*head = current->next;
	free_node(current);
}
