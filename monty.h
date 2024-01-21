#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct data_d - a central data carrier, storing and transporting essential information
 * @val: character pointer used to store a value
 * @file: file pointer that points to the opened Monty bytecode file
 * @content: character pointer that holds the content of a line from Monty
 * @d_flag: integer flag used to control the behavior of the stack or queue
 *
 * Description: ensure data consistency and streamlining operations.
 */
typedef struct data_d
{
	char *val;
	FILE *file;
	char *content;
	int d_flag;
} data_d;
extern data_d data;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure for stack, queues, LIFO,FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int main(int argc, char *argv[]);
int execute(char *content, stack_t **head, unsigned int line_number, FILE *file);
void add_node(stack_t **head, int n);
void add_queue(stack_t **stack, int n);
void free_stack(stack_t *stack);
void push_fun(stack_t **head, unsigned int line_number);
void pall_fun(stack_t **stack, unsigned int line_number);
void pint_fun(stack_t **stack, unsigned int line_number);
void pop_fun(stack_t **stack, unsigned int line_number);
void swap_fun(stack_t **stack, unsigned int line_number);
void add_fun(stack_t **stack, unsigned int line_number);
void nop_fun(stack_t **stack, unsigned int line_number);
void stack_fun(stack_t **stack, unsigned int line_number);
void queue_fun(stack_t **stack, unsigned int line_number);
void sub_fun(stack_t **stack, unsigned int line_number);
void div_fun(stack_t **stack, unsigned int line_number);

#endif
