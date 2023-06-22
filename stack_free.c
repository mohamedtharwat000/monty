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

/**
 * clean_exit - free the memory and exit with EXIT_FAILURE.
 */
void clean_exit(void)
{
	state.buff_line != NULL ? free(state.buff_line) : (void)0;
	state.stack != NULL ? stack_free(state.stack) : (void)0;
	exit(EXIT_FAILURE);
}
