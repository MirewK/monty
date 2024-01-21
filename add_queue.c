#include "monty.h"
/**
 * add_queue - add a new node to the tail of the queue
 * @stack: pointer to the head of the queue
 * @n: line number of the queue that the new value will be added
 *
 * Return: nothing
 */

void add_queue(stack_t **stack, int n)
{
	stack_t *temp, *new_node;

	temp = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp->next = new_node;
		new_node->prev = temp;
	}
}
