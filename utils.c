#include "main.h"

/**
 * is_printable - this evaluate if a char is printable
 * @c: char to be evaluated
 * Return: 1 if c is printable, 0 otherwise
 */

int is_printable(char c)
{
return (c >= 32 && c < 127 ? 1 : 0);
}

/**
 * append_hexa_code - this appends ascii in hexadecimal code to buffer
 * @buffer: array of chars
 * @i: index at which to start appending
 * @ascii_code: ASCII code
 * Return: 3 always
 */

int append_hexa_code(char ascii_code, char buffer[], int i)
{
char map_to[] = "0123456789ABCDEF";
/** The hexa format code is always 2 digits long */

if (ascii_code < 0)
	ascii_code *= -1;

buffer[i++] = '\\';
buffer[i++] = 'x';

buffer[i++] = map_to[ascii_code / 16];
buffer[i] = map_to[ascii_code % 16];

return (3);
}

/**
 * is_digit - this verifies if a char is a digit
 * @c: char to be evaluated
 * Rturn: 1 if c is a digit, 0 otherwise
 */

int is_digit(char c)
{
return (c >= '0' && c <= '9' ? 1 : 0);
}

/**
 * convert_size_number - this casts a number to the specifer
 * @num: number to be casted
 * @size: number indicating the type to be casted
 * Return: casted value of num
 */

long int convert_size_number(long int num, int size)
{
return (size == S_LONG ? num : (size == S_short ? (short)num : (int)num));
}

/**
 * convert_size_unsgnd - this casts a number to the specified size
 * @num: number to be casted
 * @size: numberindicating the type to be casted
 * return: casted value of num
 */

long int convert_size_unsgnd(unsigned long int num, int size)
{
return (size == S_LONG ? num : (size == S_SHORT ? (unsigned short)num :
	(unsigned int)num));
}

/**
 * convert_size_unsgnd - casts a number to the specified size
 * @num: number to be casted
 * @size: number indicating the type to be casted
 * Return: casted value of num
 */

long int convert_size_unsgnd(unsigned long int num,
	int size)
{
return (size == S_LONG ? num : (size == S_SHORT ?
	(unsinged short)num : (unsigned int)num));
}

