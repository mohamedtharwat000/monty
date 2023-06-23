#include "monty.h"

/* global state declaration */
state_t state = {0, 0, NULL, NULL, 0};

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
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	read_instructions(file);

	fclose(file);

	return (0);
}
