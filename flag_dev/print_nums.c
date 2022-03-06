#include "holberton.h"

char *print_d(va_list ag)
{
	/*declarations */
	/* flags.values corresponds to " +-0#" */
	/* read-in integer / temporary holder of integer */
	int int_t, temp;
	/* output string */
	char *s;
	/* digits in num / iterator / sign of number / total size */
	int digits = 1, j, sign = 1, upper_b;
	/* maybe handle longs here */
	int_t = va_arg(ag, int);
	/* how many digits in number */
	temp = int_t;
	while (temp / 10)
	{
		digits++;
		temp /= 10;
	}
	upper_b = digits;
	/* number is negative */
	if (int_t < 0)
	{
		sign = -1;
		upper_b++;
	}     

	/* malloc for number */
	s = malloc(sizeof(char) * (upper_b + 1));
	if (s == NULL)
		return (NULL);

	/* place our number in char *s */
	
	/* sign */
	if (sign < 0)
		s[0] = '-';

	for (j = 0; j < digits; j++)
	{
		s[upper_b - j - 1] = int_t % 10 * sign + '0';
		int_t /= 10;
	}
	return (s);
}

char *print_s(va_list ag, flags_t flags)
{
	char *a = "LOL";

	return a;
}

char *print_c(va_list ag, flags_t flags)
{
	char *a = "LOL";

	return a;
}

