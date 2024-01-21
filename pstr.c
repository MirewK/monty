#include "monty.h"

/**
 * pstr_fun - prints the string starting at the top of the stack
 * @stack: pointer that points to the head of the stack
 * @line_number: line number no function
 *
 * Return: nothing
 */

void pstr_fun(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *stack;
	while (temp)
	{
		if (temp->n >127 || temp->n <= 0)
		{
			break;
		}
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
