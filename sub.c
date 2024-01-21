#include "monty.h"

/**
 * sub_fun - substracts the top element of the stack from the second top element of the stack
 * @stack: pointer that points to the head of the stack
 * @line_number: line number of the element in the stack to be substracted
 *
 * Return: nothing
 */

void sub_fun(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int subs, nodes;

	temp = *stack;
	for (nodes = 0; temp != NULL; nodes++)
		temp = temp->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(data.file);
		free(data.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	subs = temp->next->n - temp->n;
	temp->next->n = subs;
	*stack = temp->next;
	free(temp);
}
