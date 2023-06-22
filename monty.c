#include "monty.h"

state_t state = {NULL, NULL};

/**
 * main - Monty interpreter entry point
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv)
{
	FILE *file = NULL;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	handle_instructions(file);

	fclose(file);

	return (0);
}
