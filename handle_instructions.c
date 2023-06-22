#include "monty.h"

void execute_instruction(instruction_t *stack_handle);

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
	ssize_t readed = 0;
	size_t size = 0;
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

	while ((readed = getline(&(state.buff_line), &size, file)) != -1)
	{
		(state.line_number)++;
		execute_instruction(stack_handle);
	}
	free(state.buff_line);
	stack_free(state.stack);
}



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
	char *opcode = strtok(state.buff_line, " ");

	if (opcode == NULL)
		return;

	opcode_len = strlen(opcode);
	if (strcmp(opcode, "\n") == 0)
		return;

	if (opcode[opcode_len - 1] == '\n')
		opcode[opcode_len - 1] = '\0';

	while (stack_handle[i].opcode)
	{
		if (strcmp(stack_handle[i].opcode, opcode) == 0)
		{
			stack_handle[i].f(&(state.stack), state.line_number);
			break;
		}
		i++;
	}

	if (stack_handle[i].opcode == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n",
						state.line_number, opcode);
		clean_exit();
	}
}
