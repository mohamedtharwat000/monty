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

	if (state.stack_size == 0)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		clean_exit();
	}

	*stack = (*stack)->prev;
	if (*stack != NULL)
	{
		(*stack)->next = NULL;
	}

	free(tmp);
	state.stack_size -= 1;
}
