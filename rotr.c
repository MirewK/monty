#include "monty.h"

/**
 * rotr_fun - rotates the stack to the bottom
 * @stack: pointer that points to the head of the stack
 * @line_number: line number of the stack
 *
 * Return: nothing
 */

void rotr_fun(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if(*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}
