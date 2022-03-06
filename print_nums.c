#include "holberton.h"
/**
  * print_d - print ints
  * @ag: variadic list
  * Return: char *
  */
char *print_d(va_list ag)
{
	/*declarations */
	int int_t, temp;
	char *s;
	int digits = 1, j, sign = 1, upper_b;

	int_t = va_arg(ag, int);
	temp = int_t;

	while (temp / 10)
	{
		digits++;
		temp /= 10;
	}
	upper_b = digits;
	if (int_t < 0)
	{
		sign = -1;
		upper_b++;
	}
	/* malloc for number */
	s = malloc(sizeof(char) * (upper_b + 1));
	if (s == NULL)
		return ("(null)");

	/* place our number in char *s */
	if (sign < 0)
		s[0] = '-';

	for (j = 0; j < digits; j++)
	{
		s[upper_b - j - 1] = int_t % 10 * sign + '0';
		int_t /= 10;
	}
	return (s);
}


/**
  * print_c - print characters
  * @ag: variadic list
  * Return: char *
  */
char *print_c(va_list ag)
{
	char c = va_arg(ag, int);
	char *s = malloc(sizeof(char) * (1 + 1));

	if (!s)
		return ("(null)");
	s[0] = c;
	s[1] = '\0';
	return (s);
}

/**
  * convert_to_hex - converts hex to dec, backwards
  * @dec: decimal number to be converted to hex
  * Return: char *
  */
char *convert_to_hex(int dec)
{
	char *s;
	int i, rem, temp = dec, digits = 0;

	while (temp)
	{
		digits++;
		temp /= 16;
	}

	s = malloc(sizeof(char) * (digits + 1));

	for (i = 0; i < digits; i++)
	{
		rem = dec % 16;
		if (rem < 10)
			s[i] = '0' + rem;
		else
			s[i] = 'A' + rem - 10;
		dec /= 16;
	}
	s[i] = '\0';

	return (s);
}


/**
  * print_u - print unsigned ints
  * @ag: variadic list
  * Return: char *
  */
char *print_u(va_list ag)
{
	unsigned int ui = va_arg(ag, unsigned int);
	char *s;
	unsigned int temp = ui;
	int i, digits = 0;

	while (temp)
	{
		digits++;
		temp /= 10;
	}

	/* malloc for number */
	s = malloc(sizeof(char) * (digits + 1));
	if (s == NULL)
		return ("(null)");

	/* place our number in char *s */

	for (i = 0; i < digits; i++)
	{
		s[digits - i - 1] = ui % 10 + '0';
		ui /= 10;
	}
	return (s);
}
