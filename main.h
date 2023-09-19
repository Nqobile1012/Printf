#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* Flags */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* Sizes */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 * @fmt: It is the Format
 * @fn: Function associated
 */

struct fmt
{
	char fmt;

	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Struct op
 * @fmt: It is the Format
 * @fm_t: Function associated
 */

typedef struct fmt fmt_t;


int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
		va_list valist, char buffer[], int flags, int width,
		int precision, int size);

/***** Functions *****/

/* Functions to print strings and chars */
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size);


/* Functions to print numbers */
int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size);


int print_hexa(va_list types, char map_to[],
		char buffer[], int flags, char flag_ch, int width, int precision, int size);


/* Function that prints non printable chars */
int print_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size);


/* Function that prints mem address*/
int print_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size);


/* Functions that handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);


/* Function that prints a string in rev */
int print_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size);


/* Function that prints a string in rot 13 */
int print_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size);


/* Width Handler */
int handle_write_char(char c, char buffer[],
		int flags, int width, int precision, int size);
int write_pointer(char buffer[], int ind, int length, int width,
		int flags, char padd, char extra_c, int padd_start);
int write_num(int ind, char buffer[], int flags, int width,
		int precision, int length, char padd, char ectra_c);
int write_number(int is_positive, int ind, char buffer[],
		int flags, int width, int precision, int size);


int write_unsgnd(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size);


/***** Utils *****/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);


long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);


#endif /* MAIN_H */
