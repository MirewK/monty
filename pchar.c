#include "monty.h"

/**
 * pchar_fun - prints the char at the top of the stack
 * @stack: pointer that points to the head of the stack
 * @line_number: line number
 *
 * Return: nothing
 */

void pchar_fun(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (!temp)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(data.file);
		free(data.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (temp->n > 127 || temp->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n",line_number);
		fclose(data.file);
		free(data.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", temp->n);
}
