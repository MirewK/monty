#include "monty.h"

/**
 * pall_fun - prints the element of a stack, starting from the top
 * @stack: double pointer to the top of the stack
 * @line_number: the line number in the file
 */

void pall_fun(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
