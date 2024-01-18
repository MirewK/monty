#include "monty.h"
/**
 * pint_fun - print the top element of the stack
 * @stack: pointer to the head of the stack
 * @line_number: the line number of the element to be displayed
 *
 * Return: nothing
 */
void pint_fun(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(data.file);
		free(data.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
