#include "main.h"

/**
 * get_precision - calculates the precision for printing
 * @format: formatted string in which to print the arguments
 * @i: the list of arguments to be printed
 * @list: the list of arguements
 * Return: precision
 */

int get_precision(const char *format, int *i, va_list list)
{
int curr_i = *i + 1;
int prc = -1;

if (format[curr_i] != '.')
	return (prc);

prc = 0;

for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
{
	if (is_digit(format[curr_i]))
{
prc *= 10;
prc += format[curr_i] - '0';
}
else if
	(format[curr_i] == '*')
{
curr_i++;
prc = va_arg(list, int);
break;
}

if else
	break;

}

*i = curr_i - 1;

return (prc);
}
