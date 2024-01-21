#include "monty.h"

/**
 * rotl_fun - rotates the stack to the top
 * @stack: pointer that points to the head of the stack
 * @line_number: line number of the element in the stack to rotate
 *
 * Return: nothing
 */

void rotl_fun(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp = *stack, *rotls;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	rotls = (*stack)->next;
	rotls->prev = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = temp;
	(*stack) = rotls;
}
