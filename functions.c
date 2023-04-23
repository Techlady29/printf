#include "main.h"


/** PRINT CHAR **/

/**
 * print_char - prints a char
 * @args: the lists of arguments
 * @buff: the buffer array to handle print
 * @flags: this calculates active flags
 * @width: the width
 * @prc: precision specification
 * @sz: size specifier
 * Return: number of chars printed
 */

int print_char(va_list args, char buff[],
		int flags, int width, int prc, int sz)
{
char c = va_arg(args, int);
return (handle_write_char(c, buff, flags, width, prc, sz));

}

/** PRINT A STRING **/

/**
 * print_string - this prints a string
 * @args: the lists of arguments
 * @buff: the buffer array to handle print
 * @flags: this calculates active flags
 * @width: the width
 * @prc: precision specification
 * @sz: size specifier
 * Return: number of strings printed
 */

int print_string(va_list args, char buff[],
	int flags, int width, int prc, int sz)
{
int len = 0, i;
char *str = va_arg(args, char*);
UNUSED(buff);
UNUSED(flags);
UNUSED(width);
UNUSED(prc);
UNUSED(sz);
if (str == NULL)
{
str = "(null)";
if (prc >= 6)
	str = "";
}
while (str[len] != '\0')
len++;
if (prc >= 0 && prc < len)
	len = prc;
	if (width > len)
{
if (flags & F_MINUS)
{
write(1, &str[0], len);
for (i = width - len; i > 0; i--)
	write(1, "", 1);
write(1, &str[0], len);
return (width);
}
else
{
for (i = width - len; i > 0; i--)
	write(1, "", 1);
write(1, &str[0], len);
return (width);
}
}
return (write(1, str, len));

}

/** PRINT PERCENT SIGN **/

/**
 * print_percent - this prints a percent sign
 * @args: the list of arguments
 * @buff: the buffer array to handle print
 * @flags: this calculates active flags
 * @width: the width
 * @prc: the prcision specifier
 * @sz: size specifier
 * Return: number of chars printed
 */

int print_percent(va_list args, char buff[],
		int flags, int width, int prc, int sz)
{
UNUSED(args);
UNUSED(buff);
UNUSED(flags);
UNUSED(width);
UNUSED(prc);
UNUSED(sz);
return (write(1, "%%", 1));

}

/** PRINT INT **/

/**
 * print_int - print integer
 * @args: the lists of arguments
 * @buff: the buffer array to handle print
 * @flags: this calculates active flags
 * @width: the width
 * @prc: the prcision specifier
 * @sz: size specifier
 * Return: number of chars printed
 */

int print_int(va_list args, char buffer[],
	int flags, int width, int prc, int sz)
{
int i = BUFF_SIZE - 2;
int is_negative = 0;
long int n = va_arg(args, long int);
unsigned long int num;

n = convert_size_number(n, sz);

if (n == 0)
	buffer[i--] = '0';

buffer[BUFF_SIZE - 1] = '\0';
num = (unsigned long int)n;

if (n < 0)
{
num = (unsigned long int)((-1) * n);
is_negative = 1;
}

while (num > 0)
{
buffer[i--] = (num % 10) + '0';
num /= 10;
}

i++;

return (write_number(is_negative, i, buffer, flags, width, prc, sz));

}

/** PRINT BINARY **/

/**
 * print_binary - prints an unsigned number in binary
 * @args: the list of arguments
 * @buffer: the buffer array for print handling
 * @flags:  this Calculates active flags
 * @width: Width specifier
 * @prc: Precision specifier
 * @sz: Size specifier
 * Return: Number of characters printed
 */

int print_binary(va_list args, char buffer[],
	int flags, int width, int prc, int sz)
{
unsigned int n, m, i, sum;
unsigned int a[32];
int count;

UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(prc);
UNUSED(sz);

n = va_arg(args, unsigned int);
m = 2147483648; /* (2 ^ 31) */
a[0] = n / m;
for (i = 1; i < 32; i++)
{
m /= 2;
a[i] = (n / m) % 2;

}
for (i = 0, sum = 0, count = 0; i < 32; i++)
{
sum += a[i];
if (sum || i == 31)
{
char z = '0' + a[i];

write(1, &z, 1);
count++;
}
}
return (count);
}








