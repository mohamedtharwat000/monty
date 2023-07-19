#include "monty.h"

/**
 * stack_push - adds a new node at the end of a stack list.
 * @stack: Pointer to the address of the stack top node.
 * @line_number: line number.
 *
 * Return: void
 */
void stack_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;
	char *opcode_arg = NULL;
	size_t arg_last = 0;

	opcode_arg = strtok(NULL, " ");

	if (opcode_arg != NULL)
	{
		arg_last = strlen(opcode_arg) - 1;
		(opcode_arg[arg_last] == '\n') ? (opcode_arg[arg_last] = '\0') : 0;
	}

	if (opcode_arg == NULL || !isnumber(opcode_arg) || opcode_arg[0] == '\0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		clean_exit();
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		clean_exit();
	}

	if (state.stack_size == 0)
	{
		new_node->prev = NULL;
		new_node->next = NULL;
	}
	else
	{
		new_node->prev = *stack;
		(*stack)->next = new_node;
	}

	new_node->n = str_to_num(opcode_arg);
	*stack = new_node;
	state.stack_size += 1;
}
