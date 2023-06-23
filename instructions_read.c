#include "monty.h"

/**
 * read_instructions - Read instructions from a file.
 * @file: Pointer to the file to read instructions from.
 *
 * This function reads instructions from a file line by lin.
 * it executes the corresponding operations based on the opcode.
 */
void read_instructions(FILE *file)
{
	instruction_t stack_handle[] = {
		{"push", stack_push},
		{"pall", stack_pall},
		{"pint", stack_pint},
		{"swap", stack_swap},
		{"pop", stack_pop},
		{"add", stack_add},
		{"nop", stack_nop},
		{NULL, NULL}
	};

	while (getline(&(state.buff_line), &(state.buff_size), file) != -1)
	{
		state.line_number++;
		execute_instruction(stack_handle);
	}
	free(state.buff_line);
	stack_free(state.stack);
}
