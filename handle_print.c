#include "main.h"

/**
 * print_argument - this prints an argument based on its type
 * @format: formatted string in which to print the arguments
 * @index: index of the current char in the format string
 * @args: list of arguments to be printed
 * @buffer: buffer array to handle print
 * @flags: calculates flags
 * @wdth: width specifier
 * @prc: precision specifier
 * @sz: size specifier
 * Return: number of chars printed
 */

int print_argument(const char *format, int *index, va_list args,
		char buffer[],
		int flags, int wdth, int prc, int sz)
{
int i, unknown_len = 0, printed_chars = -1;

fmt_t fmt_types[] = {
	{'c', print_char}, {'s', print_string}, {'%', print_percent},
	{'i', print_int}, {'d', print_int}, {'b', print_binary},
	{'u', print_unsigned}, {'o', print_octal}, {'X', print_hexadecimal},
	{'X', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
};

for (i = 0; fmt_types[i].fmt != '\0'; i++)
{
if (format[*index] == fmt_types[i].fmt)
{
return (fmt_types[i].fn(args, buffer, flags, wdth, prc, sz));
}
}

if (fmt_types[i].fmt == '\0')

{
if (format[*index] == '\0')
{
return (-1);
}
unknown_len += write(1, "%%", 1);
if (format[*index - 1] == ' ')
{
unknown_len += write(1, " ", 1);
}
else if (wdth)
{
--(*index);
while (format[*index] != ' ' && format[*index] != '%')
{
--(*index);
}
if (format[*index] == ' ')
{
--(*index);
}
return (1);
}
return (printed_chars);
}
