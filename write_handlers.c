#include "main.h"

/** WRITE HANDLE **/

/**
 * handle_write_char - prints a string
 * @c: char types
 * @buffer: buffer aray to handle print
 * @flags: calculates active flags
 * @wdth: gets width
 * @prc: precision specifier
 * @sz: size specifier
 * Return: number of chars printed
 */

int handle_write_char(char c, char buffer[], int flags,
		int wdth, int prc, int sz)
{
int i = 0;
char padd = ' ';

UNUSED(prc);
UNUSED(sz);

if (flags & F_ZERO)
	padd = '0';

buffer[i++] = c;
buffer[i] = '\0';

if (wdth > 1)
{
buffer[BUFF_SIZE - 1] = '\0';
for (i = 0; i < wdth - 1; i++)
	buffer[BUFF_SIZE - i - 2] = padd;

if (flags & F_MINUS)
	return (write(1, &buffer[0], 1) +
			write(1, &buffer[BUFF_SIZE - i - 1], wdth - 1));
else
	return (write(1, &buffer[BUFF_SIZE - i - 1], wdth - 1) +
			write(1, &buffer[0], 1));
}
return (write(1, &buffer[0], 1));
}


/** WRITE NUMBER **/

/**
 * write_number - prints a string
 * @is_negative: lists arguments
 * @ind: char types
 * @buffer: buffer aray to handle print
 * @flags: calculates active flags
 * @wdth: gets width
 * @prc: precision specifier
 * @sz: size specifier
 * Return: number of chars printed
 */

int write_number(int is_negative, int ind, char buffer[], int flags,
		int wdth, int prc, int sz)
{
int length = BUFF_SIZE - ind - 1;
char padd = ' ', extra_ch = 0;

UNUSED(sz);

if ((flags & F_ZERO) && !(flags & F_MINUS))
	padd = '0';
if (is_negative)
	extra_ch = '-';
else if (flags & F_PLUS)
	extra_ch = '+';
else if (flags & F_SPACE)
	extra_ch = ' ';

return (write_num(ind, buffer, flags, wdth, prc,
			length, pad, extra_ch));
}


/**
 * write_num - write a number using a buffer
 * @ind: index at which the number starts on the buffer
 * @buffer: buffer aray
 * @flags: calculates active flags
 * @wdth: gets width
 * @prc: precision specifier
 * @length: number length
 * @padd: padding char
 * @extra_c: extra char
 * Return: number of chars printed
 */

int write_num(int ind, char buffer[], int flags,
		int wdth, int prc, int length,
		char padd, char extra_c)

{
int i, padd_start = 1;
int result = 0;

if (prc == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' &&
		wdth == 0)
	return (0);

return (0); /* printf(".0d", 0)  no char is printed */
	if (prc == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' '; /* width is displayed with padding ' ' */
	if (prc > 0 && pr < length)
		padd = ' ';

	switch (flags)
	{
		case F_MINUS:
			if (padd == ' ')
			{
			if (extra_c)
				buffer[--ind] = extra_c;
					result = write(1, &buffer[ind], length) +
					write(1, &buffer[1], wdth - length + 1);
			}
			break;
		case 0:
			if (padd == ' ')
			{
			if (extra_c)
				buffer[--ind] = extra_c;
			result = write(1, &buffer[1], wdth - length + 1)
				+ write(1, &buffer[ind], length);
			} else if (padd == '0')
			{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			result = write(1, &buffer[pad_start], wdth -
					padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start));
			}
			break;
		default:
			break;
	}

	if (extra_c)
		buffer[--ind] = extra_c;
	return (result);
}

/**
 * write_unsgnd - writes an unsigned number
 * @is_negative: number indicating if the number is negative
 * @ind: index at which the number starts on the buffer
 * @buffer: arrays of chars
 * @flags: flag specifiers
 * @wdth: width specifier
 * @prc: precision specifier
 * @sz: size specifier
 * Return: size specifier
 */

int write_unsgnd(int is_negative, int ind, char buffer[],
		int flags, int wdth, int prc, int size)
{
int length = BUFF_SIZE - ind - 1, i = 0;
char padd = ' ';

UNUSED(is_negative);
UNUSED(sz);

if (prc == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
	return (0); /* printf(".0d", 0) no char is printed */

if (prc > 0 && prc < length)
{
buffer[--ind] = '0';
length++;
}

switch (flags)
{
	case F_ZERO:
		if (!(flags & F_MINUS))
			padd = '0';
		break;
	case F_MINUS:
		/* Assign extra char to left of buffer [buffer > padd] */
		return (write(1, &buffer[ind], length) + write(1, &buffer[0], wdth - length));
	default:
		break;
}

if (wdth > length)
{
for (i = 0; i < wdth - length; i++)
	buffer[i] = padd;

buffer[i] = '\0';

if (flags & F_MINUS) /* Assign extra char to left of buffer [buffer > padd] */
{
return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
}

else /* Assign extra char to left of padding [padd > buffer] */

{
	return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
}
}
return (write(1, &buffer[ind], length));
}

/**
 * write_pointer - write a memory address
 * @buffer: arrays of chars
 * @ind: index at which the number starts in the buffer
 * @length: length of number
 * @wdth: width specifier
 * @flags: flags specifier
 * @padd: char representing the padding
 * @extra_c: char representingextra char
 * @padd_start: index at which padding should start
 * Return: number of written chars
 */

int write_pointers(char buffer[], int ind, int length, int wdth,
		int flags, char padd, char extra_c, int padd_start)

{
int i;
int result = 0;

if (wdth > length)
{
for (i = 3; i < wdth - length + 3; i++)
	buffer[i] = padd;
buffer[i] = '\0';
switch ((flags & F_MINUS) | (padd == '0' ? 2 : 0))
{
	case 0:/* extra char to the left of buffer */
		buffer[--ind] = 'x';
		buffer[--ind] = '0';
		if (extra_c)
			buffer[--ind] = extra_c;
		result = write(1, &buffer[3], i - 3) + write(1,
				&buffer[ind], length);
		break;
	case 1: /* extra char to the left of padding */
		if (extra_c)
			buffer[--padd_start] = extra_c;
		buffer[1] = '0';
		buffer[2] = 'x';
		result = write(1, &buffer[padd_start], i -
			       padd_start) + 
		write(1, &buffer[ind], length - (1 - padd_start) - 2);
	break;
	case 2: /* extra char to left of buffer */
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
	buffer[--ind] = extra_c;
result = write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3);
break;
	default:
break;

}
}
else
{
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
	buffer[--ind] = extra_c;
result = write(1, &buffer[ind], BUFF_SIZE - ind - 1);

}
return (result);
}
}
}
