/**
 * Copyright (c) 2011 Anup Patel.
 * All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * @file arm_stdio.c
 * @author Anup Patel (anup@brainfault.org)
 * @brief source file for common input/output functions
 */

#include <arm_board.h>
#include <arm_stdio.h>
#include <arm_math.h>

void arm_stdio_init(void)
{
	int rc;

	rc = arm_board_serial_init();
	if (rc) {
		while (1);
	}
}

bool arm_isprintable(char c)
{
	if (((31 < c) && (c < 127)) ||
	   (c == '\f') ||
	   (c == '\r') ||
	   (c == '\n') ||
	   (c == '\t')) {
		return TRUE;
	}
	return FALSE;
}

void arm_puts(const char * str)
{
	while (*str) {
		arm_board_serial_putc(*str);
		str++;
	}
}

void arm_gets(char *s, int maxwidth, char endchar)
{
	char *retval;
	char ch;
	retval = s;
	ch = arm_board_serial_getc();
	while (ch != endchar && maxwidth > 0) {
		*retval = ch;
		retval++;
		maxwidth--;
		if (maxwidth == 0)
			break;
		ch = arm_board_serial_getc();
	}
	*retval = '\0';
	return;
}

#define PAD_RIGHT	1
#define PAD_ZERO	2
#define PAD_ALTERNATE	4
#define PRINT_BUF_LEN	64

#define va_start(v,l)   	__builtin_va_start((v),l)
#define va_end          	__builtin_va_end
#define va_arg          	__builtin_va_arg
typedef __builtin_va_list	va_list;

static void printc(char **out, u32 *out_len, char ch)
{
	if (out) {
		if (*out) {
			if (out_len && (0 < *out_len)) {
				**out = ch;
				++(*out);
				(*out_len)--;
			} else {
				**out = ch;
				++(*out);
			}
		}
	} else {
		arm_board_serial_putc(ch);
	}
}

static int prints(char **out, u32 *out_len, const char *string, int width, int flags)
{
	int pc = 0;
	char padchar = ' ';

	if (width > 0) {
		int len = 0;
		const char *ptr;
		for (ptr = string; *ptr; ++ptr)
			++len;
		if (len >= width)
			width = 0;
		else
			width -= len;
		if (flags & PAD_ZERO)
			padchar = '0';
	}
	if (!(flags & PAD_RIGHT)) {
		for (; width > 0; --width) {
			printc(out, out_len, padchar);
			++pc;
		}
	}
	for (; *string; ++string) {
		printc(out, out_len, *string);
		++pc;
	}
	for (; width > 0; --width) {
		printc(out, out_len, padchar);
		++pc;
	}

	return pc;
}

static int printi(char **out, u32 *out_len, long long i, int b, int sg, 
		  int width, int flags, int letbase)
{
	char print_buf[PRINT_BUF_LEN];
	char *s;
	int neg = 0, pc = 0;
	u64 t;
	unsigned long long u = i;

	if (sg && b == 10 && i < 0) {
		neg = 1;
		u = -i;
	}

	s = print_buf + PRINT_BUF_LEN - 1;
	*s = '\0';

	if (!u) {
		*--s = '0';
	} else {
		while (u) {
                	u = do_udiv64(u, b, &t);
			if (t >= 10)
				t += letbase - '0' - 10;
			*--s = t + '0';
		}
	}

	if (flags & PAD_ALTERNATE) {
		if ((b == 16) && (letbase == 'A')) {
			*--s = 'X';
		} else if ((b == 16) && (letbase == 'a')) {
			*--s = 'x';
		}
		*--s = '0';
	}

	if (neg) {
		if (width && (flags & PAD_ZERO)) {
			printc(out, out_len, '-');
			++pc;
			--width;
		} else {
			*--s = '-';
		}
	}

	return pc + prints(out, out_len, s, width, flags);
}

static int print(char **out, u32 *out_len, const char *format, va_list args)
{
	int width, flags, acnt = 0;
	int pc = 0;
	char scr[2];
	unsigned long long tmp;

	for (; *format != 0; ++format) {
		if (*format == '%') {
			++format;
			width = flags = 0;
			if (*format == '\0')
				break;
			if (*format == '%')
				goto out;
			/* Get flags */
			if (*format == '-') {
				++format;
				flags = PAD_RIGHT;
			}
			if (*format == '#') {
				++format;
				flags |= PAD_ALTERNATE;
			}
			while (*format == '0') {
				++format;
				flags |= PAD_ZERO;
			}
			/* Get width */
			for (; *format >= '0' && *format <= '9'; ++format) {
				width *= 10;
				width += *format - '0';
			}
			if (*format == 's') {
				char *s = va_arg(args, char *);
				acnt += sizeof(char *);
				pc += prints(out, out_len, 
					     s ? s : "(null)", width, flags);
				continue;
			}
			if (*format == 'd') {
				pc += printi(out, out_len, 
					va_arg(args, int), 
					10, 1, width, flags, '0');
				acnt += sizeof(int);
				continue;
			}
			if (*format == 'x') {
				pc += printi(out, out_len, 
					va_arg(args, unsigned int), 
					16, 0, width, flags, 'a');
				acnt += sizeof(unsigned int);
				continue;
			}
			if (*format == 'X') {
				pc += printi(out, out_len, 
					va_arg(args, unsigned int), 
					16, 0, width, flags, 'A');
				acnt += sizeof(unsigned int);
				continue;
			}
			if (*format == 'u') {
				pc += printi(out, out_len, 
					va_arg(args, unsigned int), 
					10, 0, width, flags, 'a');
				acnt += sizeof(unsigned int);
				continue;
			}
			if (*format == 'p') {
				pc += printi(out, out_len, 
					va_arg(args, unsigned long),
					16, 0, width, flags, 'a');
				acnt += sizeof(unsigned long);
				continue;
			}
			if (*format == 'P') {
				pc += printi(out, out_len, 
					va_arg(args, unsigned long),
					16, 0, width, flags, 'A');
				acnt += sizeof(unsigned long);
				continue;
			}
			if (*format == 'l' && *(format + 1) == 'l') {
				while (acnt & (sizeof(unsigned long long)-1)) {
					va_arg(args, int);
					acnt += sizeof(int);
				}
				if (sizeof(unsigned long long) == 
						sizeof(unsigned long)) {
					tmp = va_arg(args, unsigned long long);
					acnt += sizeof(unsigned long long);
				} else {
					((unsigned long *)&tmp)[0] = 
						va_arg(args, unsigned long);
					((unsigned long *)&tmp)[1] = 
						va_arg(args, unsigned long);
					acnt += 2*sizeof(unsigned long);
				}
				if (*(format + 2) == 'u') {
					format += 2;
					pc += printi(out, out_len, tmp,
						10, 0, width, flags, 'a');
				} else if (*(format + 2) == 'x') {
					format += 2;
					pc += printi(out, out_len, tmp,
						16, 0, width, flags, 'a');
				} else if (*(format + 2) == 'X') {
					format += 2;
					pc += printi(out, out_len, tmp,
						16, 0, width, flags, 'A');
				} else {
					format += 1;
					pc += printi(out, out_len, tmp,
						10, 1, width, flags, '0');
				}
				continue;
			} else if (*format == 'l') {
				if (*(format + 1) == 'x') {
					format += 1;
					pc += printi(out, out_len, 
						va_arg(args, unsigned long),
						16, 0, width, flags, 'a');
					acnt += sizeof(unsigned long);
				} else if (*(format + 1) == 'X') {
					format += 1;
					pc += printi(out, out_len, 
						va_arg(args, unsigned long),
						16, 0, width, flags, 'A');
					acnt += sizeof(unsigned long);
				} else {
					pc += printi(out, out_len, 
						va_arg(args, long),
						10, 1, width, flags, '0');
					acnt += sizeof(long);
				}
			}
			if (*format == 'c') {
				/* char are converted to int then pushed on the stack */
				scr[0] = va_arg(args, int);
				scr[1] = '\0';
				pc += prints(out, out_len, scr, width, flags);
				acnt += sizeof(int);
				continue;
			}
		} else {
out:
			printc(out, out_len, *format);
			++pc;
		}
	}
	if (out)
		**out = '\0';
	return pc;
}

int arm_sprintf(char *out, const char *format, ...)
{
	va_list args;
	int retval;
	va_start(args, format);
	retval = print(&out, NULL, format, args);
	va_end(args);
	return retval;
}

int arm_snprintf(char *out, u32 out_sz, const char *format, ...)
{
	va_list args;
	int retval;
	va_start(args, format);
	retval = print(&out, &out_sz, format, args);
	va_end(args);
	return retval;
}

int arm_printf(const char *format, ...)
{
	va_list args;
	int retval;
	va_start(args, format);
	retval = print(NULL, NULL, format, args);
	va_end(args);
	return retval;
}

