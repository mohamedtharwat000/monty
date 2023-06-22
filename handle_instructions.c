#include "monty.h"

/**
 * handle_instructions - Read and execute instructions from a file.
 * @file: Pointer to the file to read instructions from.
 *
 * This function reads instructions from a file line by line and executes
 * the corresponding operations based on the opcode. It uses a stack to
 * store and manipulate data.
 */
void handle_instructions(FILE *file)
{
	ssize_t i = 0, readed = 0;
	size_t size = 0;
	unsigned int line_number = 0;
	char *opcode = NULL;
	instruction_t stack_handle[] = {
		{"push", stack_push},
		{"pall", stack_pall},
		{"pint", stack_pint},
		{"pop", stack_pop},
		{NULL, NULL}
	};

	while ((readed = getline(&(state.buff_line), &size, file)) != -1)
	{
		line_number++;
		opcode = strtok(state.buff_line, " ");
		if (strcmp(opcode, "\n") == 0)
			continue;

		if (opcode[strlen(opcode) - 1] == '\n')
			opcode[strlen(opcode) - 1] = '\0';

		i = 0;
		while (stack_handle[i].opcode)
		{
			if (strcmp(stack_handle[i].opcode, opcode) == 0)
			{
				stack_handle[i].f(&(state.stack), line_number);
				break;
			}
			i++;
		}
		if (stack_handle[i].opcode == NULL)
		{
			dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n",
							line_number, opcode);
			clean_exit();
		}
	}
	state.buff_line != NULL ? free(state.buff_line) : (void)0;
	state.stack != NULL ? stack_free(state.stack) : (void)0;
}
