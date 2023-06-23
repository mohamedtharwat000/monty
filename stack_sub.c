#include "monty.h"

/**
 * stack_sub - subtracts the stack top from the stack second top.
 * @stack: Pointer to the pointer to the head of the stack.
 * @line_number: Line number (unused in this function).
 *
 * Return: void
 */
void stack_sub(stack_t **stack, unsigned int line_number)
{
	int result = 0;

	if (state.stack_size < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		clean_exit();
	}

	result = (*stack)->prev->n - (*stack)->n;
	stack_pop(&(*stack), line_number);

	(*stack)->n = result;
}
