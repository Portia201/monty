#include "monty.h"

/**
 * mul - this multiplies the elements of stack top and bottom
 * @head: head of the stack
 * @counter: line number in the code
 *
 * Return: nothing to returm
 */
void mul(stack_t **head, unsigned int counter)
{
	stack_t *current = *head;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		close_file_and_exit(head);
	}

	current->next->n *= current->n;
	*head = current->next;
	free_node(current);
}
