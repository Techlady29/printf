#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/** PRINT UNSIGNED NUMBER **/

/**
 * print_unsigned - this prints an unsigned number
 * @args: the list of a arguments
 * @buffer: the buffer array to print
 * @flags: this calculates active flags
 * @wdth: this gets width
 * @prc: precision specifier
 * @sz: size of specifier
 * Return: unsigned numbers printed
 */

int print_unsigned(va_list args, char buffer[], int flags,
		int wdth, int prc, int sz)

{
int i = BUFF_SIZE - 2;

unsigned long int num = va_arg(args, unsigned long int);

num = convert_size_unsgnd(num, sz);

if (num == 0)
	buffer[i--] = '0';

buffer[BUFF_SIZE - 1] = '\0';

while (num > 0)
{
buffer[i--] = (num % 10) + '0';

num /= 10;
}

i++;

return (write_unsgnd(0, i, buffer, flags, wdth, prc, sz));
}

/** PRINT UNSIGNED NUMBER IN OCTAL **/

/**
 * print_octal - prints an unsigned number in octal notation
 * @args: the list of a arguments
 * @buffer: the buffer array to print
 * @flags: this calculates active flags
 * @wdth: this gets width
 * @prc: precision specifier
 * @sz: size of specifier
 * Return: unsigned numbers printed
 */

int print_octal(va_list args, char buffer[], int flags,
		int wdth, int prc, int sz)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(args, unsigned long int);
unsigned long int init_num = num;

UNUSED(wdth);

num = convert_size_unsgnd(num, sz);

if (num == 0)
	buffer[i--] = '0';

buffer[BUFF_SIZE - 1] = '\0';

while (num > 0)
{
buffer[i--] = (num % 8) + '0';
num /= 8;
}

if (flags & F_HASH && init_num != 0)
	buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, wdth, prc, sz));
}

/** PRINT UNSIGNED NUMBER IN HEXADECIMAL **/

/**
 * print_hexadecimal - this prints unsigned number in hexadecimal notation
 * @args: the list of a arguments
 * @buffer: the buffer array to print
 * @flags: this calculates active flags
 * @wdth: this gets width
 * @prc: precision specifier
 * @sz: size of specifier
 * Return: unsigned numbers printed
 */

int print_hexadecimal(va_list args, char buffer[], int flags,
	int wdth, int prc, int sz)

{
return (print_hexa(args, "0123456789abcdef", buffer, flags,
			'x', wdth, prc, sz));
}

/** PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **/

/**
 * print_hexa_upper - this prints unsigned number in upper hexadecimal notation
 * @args: the list of a arguments
 * @buffer: the buffer array to print
 * @flags: this calculates active flags
 * @wdth: this gets width
 * @prc: precision specifier
 * @sz: size of specifier
 * Return: unsigned numbers printed
 */

int print_hexa_upper(va_list args, char buffer[], int flags,
		int wdth, int prc, int sz)

{
return (print_hexa_upper(args, "0123456789ABCDEF", buffer, flags,
	'X', wdth, prc, sz));
}

/** PRINT HEXX NUM IN LOWER OR UPPER **/

/**
 * print_hexa - this prints hexadecimal number in lower or upper notation
 * @args: the list of a arguments
 * @buffer: the buffer array to print
 * @map_to: array of values to map the number to
 * @flags: this calculates active flags
 * @flag_ch: calculates active flags
 * @wdth: this gets width
 * @prc: precision specifier
 * @sz: size of specifier
 * Return: unsigned numbers printed
 */

int print_hexa(va_list args, char map_to[], char buffer[],
		int flags, char flag_ch, int wdth, int prc, int sz)

{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(args, unsigned long int);
unsigned long int init_num = num;

UNUSED(wdth);

num = convert_size_unsgnd(num, sz);

if (num == 0)
	buffer[i--] = '0';

buffer[BUFF_SIZE - 1] = '\0';

while (num > 0)
{
buffer[i--] = map_to[num % 16];
num /= 16;
}

if (flags & F_HASH && init_num != 0)
{
buffer[i--] = flag_ch;
buffer[i--] = '0';

}
i++;

return (write(0, i, buffer, flags, wdth, prc, sz));
}
