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
	stack_t *last1 = NULL, *last2 = NULL;

	if (!(*stack) || !(*stack)->prev)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_number);
		clean_exit();
	}

	last1 = state.stack;
	last2 = state.stack->prev;
	*stack = last2;
	(*stack)->next = NULL;
	(*stack)->prev = last1;
	(*stack)->prev->prev = last2->prev;
	(*stack)->prev->next = last2;
}
