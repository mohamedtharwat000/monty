#include "monty.h"

/**
 * stack_pop - removes the top element of the stack.
 * @stack: Pointer to the pointer to the head of the stack.
 * @line_number: Line number (unused in this function).
 *
 * Return: void
 */
void stack_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
		state.buff_line != NULL ? free(state.buff_line) : (void)0;
		state.stack != NULL ? stack_free(state.stack) : (void)0;
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->prev;
	if (*stack != NULL)
	{
		(*stack)->next = NULL;
	}

	free(tmp);
}
