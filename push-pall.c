#include "monty.h"

/**
 * f_push - pushes an element to the stack.
 * @head: Pointer to the head of the stack
 * @value: Integer value to push onto the stack
 */
void f_push(stack_t **head, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		close_file_and_exit(head);
	}

	new_node->n = value;
	new_node->next = *head;
	new_node->prev = NULL;

	if (*head)
		(*head)->prev = new_node;

	*head = new_node;
}

/**
 * f_pall - prints all the values on the stack
 * @head: Pointer to the head of the stack
 */
void f_pall(stack_t *head)
{
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
