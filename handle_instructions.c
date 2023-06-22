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
	char *opcode = NULL, *buff_line = NULL;
	stack_t *stack_top = NULL;
	instruction_t stack_handle[] = {
		{"push", stack_push},
		{"pall", stack_pall},
		{NULL, NULL}
	};

	while ((readed = getline(&buff_line, &size, file)) != -1)
	{
		line_number++;
		opcode = strtok(buff_line, " ");
		if (opcode == NULL)
			continue;

		if (opcode[strlen(opcode) - 1] == '\n')
		{
			opcode[strlen(opcode) - 1] = '\0';
		}
		i = 0;
		while (stack_handle[i].opcode)
		{
			if (strcmp(stack_handle[i].opcode, opcode) == 0)
			{
				stack_handle[i].f(&stack_top, line_number);
				break;
			}
			i++;
		}
		if (stack_handle[i].opcode == NULL)
		{
			dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n",
							line_number, opcode);
			free(buff_line);
			exit(EXIT_FAILURE);
		}
	}
	free(buff_line);
}
