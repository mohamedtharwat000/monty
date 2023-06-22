#include "monty.h"

/**
 * isnumber - check if a string can be converted to a number
 * @str: The string to check
 *
 * Return: 1 if true, 0 if false
 */
int isnumber(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (!isdigit(str[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
