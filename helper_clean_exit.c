#include "monty.h"

/**
 * clean_exit - free the memory and exit with EXIT_FAILURE.
 */
void clean_exit(void)
{
	state.buff_line != NULL ? free(state.buff_line) : (void)0;
	state.stack != NULL ? stack_free(state.stack) : (void)0;
	exit(EXIT_FAILURE);
}
