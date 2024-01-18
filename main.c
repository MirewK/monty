#define _GNU_SOURCE
#include "monty.h"
data_d data = {NULL, NULL, NULL, 0};
/**
 * main - responsible for orchestrating the program's overall logic and actions
 * @argc: integer representing the argument count
 * @argv: an array of character pointers
 *
 * Return: on success always 0
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *content;
	unsigned int line_number = 0;
	stack_t *head = NULL;
	size_t size = 0;
	ssize_t read_data = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	data.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_data > 0)
	{
		content = NULL;
		read_data = getline(&content, &size, file);
		data.content = content;
		line_number++;
		if (read_data > 0)
		{
			execute(content, &head, line_number, file);
		}
		free(content);
	}
	free_stack(head);
	fclose(file);
	return (0);
}
