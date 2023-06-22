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
	char *opcode_argument = NULL;
	int opcode_argument_readed = 0;
	size_t opcode_argument_length = 0;

	opcode_argument = strtok(NULL, " ");
	if (opcode_argument)
	{
		opcode_argument_length = strlen(opcode_argument);
		if (opcode_argument[opcode_argument_length - 1] == '\n')
		{
			opcode_argument[opcode_argument_length - 1] = '\0';
		}
	}
	if (opcode_argument == NULL || !isnumber(opcode_argument))
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		state.buff_line != NULL ? free(state.buff_line) : (void)0;
		state.stack != NULL ? stack_free(state.stack) : (void)0;
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		state.buff_line != NULL ? free(state.buff_line) : (void)0;
		state.stack != NULL ? stack_free(state.stack) : (void)0;
		exit(EXIT_FAILURE);
	}
	if (*stack == NULL)
	{
		new_node->prev = NULL;
		new_node->next = NULL;
	}
	else
	{
		new_node->prev = *stack;
		(*stack)->next = new_node;
	}
	opcode_argument_readed = str_to_num(opcode_argument);
	new_node->n = opcode_argument_readed;
	*stack = new_node;
}
