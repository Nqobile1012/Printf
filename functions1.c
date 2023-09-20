#include "main.h"

/****** Print unsigned number ******/
/**
 * print_unsigned - prints unsigned number
 * @types: list of args
 * @buffer: array to handle print
 * @flags: active flags
 * @width: width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of printed chars
 */

int print_unsigned(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	int i = BUFF_SIZE - 2;

	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/****** Print unsigned number in octal ******/
/**
 * print_octal - prints an unsigned number in octal
 * @types: list of args
 * @buffer: array to handle print
 * @flags: active flags
 * @width: width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of chars printed
 */

int print_octal(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	int i = BUFF_SIZE - 2;

	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

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
	return (write unsgnd(0, i, buffer, flags, width, precision, size));
}

/****** Print unsigned number in hexadecimal ******/
/**
 * print_hexadecimal - prints an unsigned number in hexadecimal form
 * @types: list of args
 * @buffer: array to handle print
 * @flags: active flags
 * @width: width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of printed chars
 */

int print_hexadecimal(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
				flags, 'X', width, precision, size));
}

/****** Print unsigned number in upper hexadecimal ******/
/**
 * print_hexa_upper - prints unsigned number in upper hexadecimal form
 * @types: list of args
 * @buffer: array to handle print
 * @flags: active flags
 * @width: width
 * @precision: precision specification
 * @size: size specifiers
 * Return: number of printed chars
 */

int print_hexa_upper(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}

/****** Print hex num in upper of lower ******/
/**
 * print_hexa -prints hexadecimal number in upper or lower
 * @types: list of args
 * @map_to: array of values to map the umber to
 * @buffer: array to handle print
 * @flags: active flags
 * @flag_ch: calculates active flags
 * @width: width
 * @precision: precision specification
 * @size: size specifier
 * @size: size specification
 * Return: number of printed chars
 */

int print_hexa(va_list types, char map_to[], char buffer[], int flags,
		char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;

	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);
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
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
