#include "main.h"

/**
 * get_flags - this calculates active flags
 * @format: formatted string in which to print the arguments
 * @i: takes a parameter
 * Return: flags
 */

int get_flags(const char *format, int *i)

{
int h, curr_i;
int flags = 0;
const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH,
	F_SPACE, 0};

for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
{
for (h = 0; FLAGS_CH[h] != '\0'; h++)
{
switch (format[curr_i])
{
	case '-':
	flags |= F_MINUS;
	break;
	case '+':
	flags |= F_PLUS;
	break;
	case '0':
	flags |= F_ZERO;
	break;
	case '#':
	flags |= F_HASH;
	break;
	case ' ':
	flags |= F_SPACE;
	break;
	default:
	break;
}
}
if (FLAGS_CH[h] == 0)
	break;
}
*i = curr_i - 1;

return (flags);
}
