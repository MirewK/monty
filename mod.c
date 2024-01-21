#include "monty.h"

/**
 * mod_fun - computes the rest of the division of the second top element of the stack by the top element of the stack
 * @stack: pointer that points to the head of the stack
 * @line_number: line number of elements of the stack to compute
 *
 * Return: nothing
 */

void mod_fun(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int len = 0, mods;

	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		fclose(data.file);
		free(data.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(data.file);
		free(data.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	mods = temp->next->n % temp->n;
	temp->next->n = mods;
	*stack = temp->next;
	free(temp);
}
