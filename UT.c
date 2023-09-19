#include "main.h"

/**
 * is_printable - It Evaluates if a char is printable
 * @c: char to evaluate
 * Return: 1 or 0
 */

int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - append asccii hexa code to buffer
 * @buffer: an array of chars
 * @i: start appending(index)
 * @ascii_code: Assci code
 * Return: 3
 */

int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	/* hexa format is always 2 digits long */

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - checks if a char is a digit
 * @c: char to be checked
 * Return: 1 or 0
 */

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - makes a number be a specific size
 * @num: number to be casted
 * @size: numb indicating type to be casted
 * Return: casted value or number
 */

long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);

	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - converts number to a specific size
 * @num: number to be converted
 * @size: numb indicating type to be casted
 * Return: casted value of number
 */

long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);

	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int) num);
}
