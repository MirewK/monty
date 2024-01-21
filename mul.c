#include "monty.h"

/**
 * mul_fun - multiplies the second top element of the stack with the top element of the stack
 * @stack: pointer that points to the head of the stack
 * @line_number: line number of the elements of the stack to be multiplied
 *
 * Return: nothing
 */

void mul_fun(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int len = 0, mults;

	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(data.file);
		free(data.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	mults = temp->next->n * temp->n;
	temp->next->n = mults;
	*stack = temp->next;
	free(temp);
}
