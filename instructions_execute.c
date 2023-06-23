#include "monty.h"

/**
 * execute_instruction - Execute the instruction based on the opcode.
 * @stack_handle: Array of instruction_t structs
 *
 * This function executes the instruction based on the provided opcode.
 *
 */
void execute_instruction(instruction_t *stack_handle)
{
	size_t opcode_len = 0, i = 0;
	char *opcode = NULL;

	opcode = strtok(state.buff_line, " ");
	if (!opcode || strcmp(opcode, "\n") == 0 || strncmp(opcode, "#", 1) == 0)
	{
		return;
	}

	opcode_len = strlen(opcode);

	(opcode[opcode_len - 1] == '\n') ? (opcode[opcode_len - 1] = '\0') : 0;

	for (i = 0; stack_handle[i].opcode != NULL; i++)
	{
		if (strcmp(stack_handle[i].opcode, opcode) == 0)
		{
			stack_handle[i].f(&(state.stack), state.line_number);
			return;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", state.line_number, opcode);
		clean_exit();
}
