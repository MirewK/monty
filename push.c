#include "monty.h"

/**
 * push_fun - pushes an element onto the stack
 * @stack: double pointer to the top of the stack
 * @line_number: the line number in the file
 */
void push_fun(stack_t **stack, unsigned int line_number)
{
	int i, j = 0, flag = 0;

	if (data.val)
	{
		if (data.val[0] == '-')
			j++;
		for (; data.val[j] != '\0'; j++)
		{
			if (data.val[j] > 57 || data.val[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(data.file);
			free(data.content);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(data.file);
		free(data.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	i = atoi(data.val);
	if (data.d_flag == 0)
		add_node(stack, i);
	else
		add_node(stack, i);
}
