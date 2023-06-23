#include "monty.h"

/**
 * stack_div - divides the second stack top by stack top.
 * @stack: Pointer to the pointer to the head of the stack.
 * @line_number: Line number (unused in this function).
 *
 * Return: void
 */
void stack_div(stack_t **stack, unsigned int line_number)
{
	int result = 0;

	if (state.stack_size < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		clean_exit();
	}

	if (state.stack->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		clean_exit();
	}

	result = (*stack)->prev->n / (*stack)->n;
	stack_pop(&(*stack), line_number);

	(*stack)->n = result;
}
