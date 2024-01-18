#include "monty.h"
/**
 * pop_fun - prints the top element of the stack
 * @stack: a pointer pointing to the head of a stack
 * @line_number: line number of the element of a stack to be printed
 *
 * Return: nothing
 */

void pop_fun(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(data.file);
		free(data.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = temp->next;
	free(temp);
}
