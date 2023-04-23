#include "main.h"

/** PRINT POINTER **/

/**
 * print_pointer - this prints the value of a pointer variable
 * @args: the list of arguments
 * @buffer: the buffer array to handle print
 * @flags: this calculates active flags
 * @wdth: this gets width
 * @prc: the precision specifier
 * @sz: the size of specifier
 * Return: value of a pointer variable
 */

int print_pointer(va_list args, char buffer[],
		int flags, int wdth, int prc, int sz)
{
char extra_c = 0, padd = ' ';
int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /** length=2, for '0x' **/

unsigned long num_addrs;
char map_to[] = "0123456789abcdef";
void *addrs =va_arg(args, void *);

UNUSED(wdth);
UNUSED(sz);

if (addrs == NULL)
	return (write(1, "(nil)", 5));

buffer[BUFF_SIZE - 1] = '\0';
UNUSED(prc);

num_addrs = (unsigned long) addrs;

while (num_addrs > 0)
{
buffer[ind--] = map_to[num_addrs % 16];
num_addrs /= 16;
length++;
}

if ((flags & F_ZERO) && !(flags & F_MINUS))
	padd = '0';
if (flags & F_PLUS)
	extra_c = '+', length++;

	else if (flags & F_SPACE)
	extra_c = ' ', length++;

	ind++;

	/** return (write (1, &buffer[i], BUFF_SIZE - i - 1)); **/

	return (write_pointer(buffer, ind, length,
				wdth, flags, padd, extra_c, padd_start));
}

/** PRINT NON PRINTABLE **/

/**
 * print_non_printable - this prints ascii codes in hexa of non printable chars
 * @args: the list of arguments
 * @buffer: the buffer array to handle print
 * @flags: this calculates active flags
 * @wdth: this gets width
 * @prc: the precision specifier
 * @sz: the size of specifier
 * Return: number of chars printed
 */

int print_non_pritable(va_list args, char buffer[],
		int flags, int wdth, int prc, int sz)
{
int i = 0, offset = 0;
char *str = va_arg(args, char *);

UNUSED(flags);
UNUSED(wdth);
UNUSED(prc);
UNUSED(sz);

if (str == NULL)
	return (write(1, "(null)", 6));

while (str[i] != '\0')
{
if (is_printable(str[i]))
	buffer[i + offset] = str[i];
else
	offset += append_hexa_code(str[i], buffer, i + offset);

i++;
}

buffer[i + offset] = '\0';

return (write(1, buffer, i + offset));
}

/** PRINT REVERSE **/

/**
 * print_reverse - this prints a string in reverse
 * @args: the list of arguments
 * @buffer: the buffer array to handle print
 * @flags: this calculates active flags
 * @wdth: this gets width
 * @prc: the precision specifier
 * @sz: the size of specifier
 * Return: number of chars printed
 */

int print_reverse(va_list args, char buffer[], int flags,
		int wdth, int prc, int sz)
{
char *str;
int i, count = 0;

UNUSED(buffer);
UNUSED(flags);
UNUSED(wdth);
UNUSED(sz);

str = va_arg(args, char *);

if (str == NULL)
{
UNUSED(prc);
str = ")Null(";

}
for (i = 0; str[i]; i++)
;

for (i = i - 1; i >= 0; i--)
{
char z = str[i];
write(1, &z, 1);
count++;
}
return (count);
}

/** PRINT A STRING IN ROT13 **/

/**
 * print_rot13string - this prints a string in ROT13 encoding
 * @args: the list of arguments
 * @buffer: the buffer array to handle print
 * @flags: this calculates active flags
 * @wdth: this gets width
 * @prc: the precision specifier
 * @sz: the size of specifier
 * Return: number of chars printed
 */

int print_rot13string(va_list args, char buffer[], int flags,
		int wdth, int prc, int sz)
{
char x;
char *str;
unsigned int i, f;
int count = 0;
char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

str = va_arg(args, char *);
UNUSED(buffer);
UNUSED(flags);
UNUSED(wdth);
UNUSED(prc);
UNUSED(sz);

if (str == NULL)
	str = "(AHYY)";

for (i = 0; str[i]; i++)
{
for (f = 0; in[f]; f++)
{
if (in[f] == str[i])
{
x = out[f];
write(1, &x, 1);
count++;

break;
}
}

if (!in[f])
{
x = str[i];
write(1, &x, 1);
count++;
}
}
return (count);

}
