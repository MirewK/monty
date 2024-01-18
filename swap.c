#include "monty.h"
/**
 * swap_fun - swaps the top two elements of the stack
 * @stack: pointer that points to the head of the stack
 * @line_number: stack elements line number to be swaped
 *
 * Return: nothing
 */
void swap_fun(stack_t **stack, unsigned int line_number)
{
	int len = 0, num;
	stack_t *temp;

	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(data.file);
		free(data.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	num = temp->n;
	temp->n = temp->next->n;
	temp->next->n = num;
}
