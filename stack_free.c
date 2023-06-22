#include "monty.h"

/**
 * stack_free - free the stack.
 * @stack: Pointer to the top of the stack.
 *
 * Return: void
 */
void stack_free(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *tmp = NULL;

	while (current != NULL)
	{
		tmp = current->prev;
		free(current);
		current = tmp;
	}
}
