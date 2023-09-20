#include "main.h"

/****** Write handlers ******/

/**
 * handle_write_char - prints string
 * @c: char types
 * @buffer:  array to handle print
 * @flags: active flags
 * @width: width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of printed chars
 */

int handle_write_char(char c, char buffer[], int flags, int width,
		int precision, int size)
{
	int i = 0;

	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';

		for (i = 0 ; i < width - 1 ; i++)
			buffer[BUFF_SIZE - i - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_size - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}

/****** Write number ******/

/**
 * write_number - prints string
 * @is_negative: list of args
 * @ind: char types
 * @buffer: array to handle print
 * @flags: ative flags
 * @width: width
 * @precision: precision specification
 * @size: size specifiers
 * Return: number of printed chars
 */

int write_number(int is_negative, int ind, char buffer[], int flags,
		int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision, length,
				padd, extra_ch));
}

/**
 * write_num - write a number using a buffer
 * @ind: index at which the number starts on the buffer
 * @buffer: buffer
 * @flags: flags(active)
 * @width: width
 * @prec: precision specifier
 * @length: length of number
 * @padd: pading char
 * @extra_c: extra char
 * Return: number of chars printed
 */

int write_num(int ind, char buffer[], int flags, int width, int prec,
		int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)

		return (0);

	if (prec == 0 && ind == BUFF_SIZE - 2 && butter[ind] == '0')
		buffer[ind] = padd = ' ';

	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1 ; i < width - length + 1 ; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], i - padd_start) +
					write(1, &buffer[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)

	buffer[--ind] = extra_c;

	return (write(1, &buffer[ind],
			length));
}

/**
 * write_unsgnd - writes unsigned number
 * @is_negative: number that shows that a num is -tive
 * @ind: index at which the number starts in the buffer
 * @buffer: the array of chars
 * @flags: flags pecifiers
 * @width: width
 * @precision: precision specifier
 * @size: size specifier
 * Return: number of chars written
 */

int write_unsgnd(int is_negative, int ind, char buffer[], int flags, int width,
		int precision, int size)
{
	int length = BUFF_SIZE - ind - 1, i = 0;

	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);
	if (precision > 0 && precision < length)
		padd = ' ';
	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (width > length)
	{
		for (i = 0 ; i < width - length ; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
	}
	return (write(1, &buffer[ind], length));
}

/**
 * write_pointer - writes mem address
 * @buffer: buffer
 * @ind: index which the number starts in the buffers
 * @length: length of num
 * @width: width
 * @flags: flags specifier
 * @padd: char that represents the padding
 * @extra_c: char that represents the extra char
 * @padd_start: index which padding will start
 * Return: number of chars written
 */

int write_pointer(char buffer[], int ind, int length, int width, int flags,
		char padd, char extra_c, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3 ; i < width - length + 3 ; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) +
					write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';

	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
