#include "monty.h"
/**
 * execute - executes the opcode
 * @content: a string containing the opcode or instruction to be executed
 * @head: a double pointer to the top of the stack
 * @line_number: the line number in the Monty file, likely used for error reporting
 * @file: a pointer to the opened Monty bytecode
 * Return: always 0
 */
int execute(char *content, stack_t **head, unsigned int line_number, FILE *file)
{
	instruction_t op_inst[] = {
		{"push", push_fun},
		{"pall", pall_fun},
		{"pint", pint_fun},
		{"pop", pop_fun},
		{"swap", swap_fun},
		{"add", add_fun},
		{NULL, NULL}
	};

	unsigned int i = 0;
	char *temp;

	temp = strtok(content, " \n\t");
	if (temp && temp[0] == '#')
		return (0);
	data.val = strtok(NULL, " \n\t");
	while (op_inst[i].opcode && temp)
	{
		if (strcmp(temp, op_inst[i].opcode) == 0)
		{
			op_inst[i].f(head, line_number);
			return (0);
		}
		i++;
	}
	if (temp && op_inst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, temp);
		fclose(file);
		free(content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	return (1);
}
