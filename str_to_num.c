#include "monty.h"

/**
 * str_to_num - convert str to number
 * @str: The string to convert
 *
 * Return: Converted number
 */
int str_to_num(char *str)
{
	int result = 0;
	int sign = 1;

	if (str[0] == '-')
	{
		str++;
		sign *= -1;
	}

	result = atoi(str) * sign;

	return (result);
}
