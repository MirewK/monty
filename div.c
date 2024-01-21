#include "monty.h"

/**
 * div_fun - divides the second top element of the stack by the top element of the stack
 * @stack: pointer that points to the head of the stack
 * @line_number: line number of the elements to be divided
 *
 * Return: nothing
 */

void div_fun(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int len = 0, divs;

	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
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
	divs = temp->next->n / temp->n;
	temp->next->n = divs;
	*stack = temp->next;
	free(temp);
}
