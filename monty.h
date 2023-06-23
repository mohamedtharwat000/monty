#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>


/**
 * struct stack_s - Doubly linked list representation of a stack (or queue)
 * @n: Integer value
 * @prev: Pointer to the previous element of the stack (or queue)
 * @next: Pointer to the next element of the stack (or queue)
 *
 * Description: Doubly linked list node structure for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Opcode and its function
 * @opcode: The opcode
 * @f: Function to handle the opcode
 *
 * Description: Opcode and its function for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct state_s - program state to store as global variable
 * @line_number: line_number.
 * @buff_line: Pointer to buff_line.
 * @stack: Pointer to stack.
 */
typedef struct state_s
{
	unsigned int line_number;
	size_t buff_size;
	char *buff_line;
	stack_t *stack;
} state_t;

/* global state variable */
extern state_t state;

/* functions to read and execute instructions */
void read_instructions(FILE *file);
void execute_instruction(instruction_t *stack_handle);

/* stack functions */
void stack_push(stack_t **stack, unsigned int line_number);
void stack_pop(stack_t **stack, unsigned int line_number);
void stack_pall(stack_t **stack, unsigned int line_number);
void stack_pint(stack_t **stack, unsigned int line_number);
void stack_swap(stack_t **stack, unsigned int line_number);
void stack_add(stack_t **stack, unsigned int line_number);
void stack_nop(stack_t **stack, unsigned int line_number);

/* helper functions */
void stack_free(stack_t *stack);
void clean_exit(void);
int isnumber(char *str);
int str_to_num(char *str);

#endif /* MONTY_H */
