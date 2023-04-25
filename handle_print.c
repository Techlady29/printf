#include "main.h"

/**
 * handle_print - this prints an argument based on its type
 * @fmt: formatted string in which to print the arguments
 * @list: list of arguments to be printed
 * @ind: ind
 * @buffer: buffer array to handle print
 * @flags: calculates flags
 * @wdth: width specifier
 * @prc: precision specifier
 * @sz: size specifier
 * Return: 1 or 2;
 */

int handle_print(const char *fmt, int *ind, va_list list,
	char buffer[], int flags, int wdth,
	int prc, int sz)
{
int i, unknown_len = 0, printed_chars = -1;

fmt_t fmt_types[] = {

	{'c', print_char}, {'s', print_string}, {'%', print_percent},
	{'i', print_int}, {'d', print_int}, {'b', print_binary},
	{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
	{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
	{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
};

for (i = 0; fmt_types[i].fmt != '\0'; i++)

if (fmt[*ind] == fmt_types[i].fmt)

return (fmt_types[i].fn(list, buffer, flags, wdth, prc, sz));

if (fmt_types[i].fmt == '\0')
{
if (fmt[*ind] == '\0')
return (-1);

unknown_len += write(1, "%%", 1);
if (fmt[*ind - 1] == ' ')

unknown_len += write(1, " ", 1);

else if (wdth)
{
--(*ind);
while (fmt[*ind] != ' ' && fmt[*ind] != '%')
--(*ind);
if (fmt[*ind] == ' ')
--(*ind);
return (1);
}
unknown_len += write(1, &fmt[*ind], 1);
return (unknown_len);
}
return (printed_chars);
}
