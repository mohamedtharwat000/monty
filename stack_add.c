#include "monty.h"

/**
 * stack_add - adds the top two elements of the stack.
 * @stack: Pointer to the pointer to the head of the stack.
 * @line_number: Line number (unused in this function).
 *
 * Return: void
 */
void stack_add(stack_t **stack, unsigned int line_number)
{
	int result = 0;

	if (state.stack_size < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		clean_exit();
	}

	result = (*stack)->n + (*stack)->prev->n;
	stack_pop(stack, line_number);

	(*stack)->n = result;
}
