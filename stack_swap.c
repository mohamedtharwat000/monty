#include "monty.h"

/**
 * stack_swap - swaps the top two elements of the stack.
 * @stack: Pointer to the pointer to the head of the stack.
 * @line_number: Line number (unused in this function).
 *
 * Return: void
 */
void stack_swap(stack_t **stack, unsigned int line_number)
{
	int last_n = 0;

	if (!(*stack) || !(*stack)->prev)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		clean_exit();
	}

	last_n = (*stack)->n;
	(*stack)->n = (*stack)->prev->n;
	(*stack)->prev->n = last_n;
}
