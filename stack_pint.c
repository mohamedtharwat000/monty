#include "monty.h"

/**
 * stack_pint - prints the value at the top of the stack.
 * @stack: Pointer to the pointer to the head of the stack.
 * @line_number: Line number (unused in this function).
 *
 * Return: void
 */
void stack_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		state.buff_line != NULL ? free(state.buff_line) : (void)0;
		state.stack != NULL ? stack_free(state.stack) : (void)0;
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
