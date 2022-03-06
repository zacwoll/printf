 #include "holberton.h"
/**
  * num_flag - counts number of flags total
  * @term: our format tag
  * Return: int, number of flags
  */
int num_flags(const char *term)
{
	const char *FLAGS = "+- 0123456789.#lh";
	int i = 0, j = 0;

	while(FLAGS[i])
	{
		if (FLAGS[i] == term[j])
		{
			putchar(FLAGS[i]);
			i = 0;
			j++;
		}
		i++;
	}
	putchar('\n');
	return j;
}

flags_t init_flags(flags_t flags)
{
	flags.flags = " +-0#";
	flags.values_size = 5;
	int i = 0;
	flags.width = 0;
	flags.prec = 0;
	flags.lng = 0;

	for (; i < flags.values_size; i++)
	{
		flags.values[i] = 0;
	}
	return (flags);
}


void set_flags(const char *term, int size, flags_t flags)
{
	char *OUTPUT = "0123456789";
	char *SIZE = "lh";
	char *type = "%bcdioprRsSuxX";
	int i, j, lower_bound;
	
	/* this section counts up the flags */
	/* if any flag int is 2 after this we need to throw an error */
	/* I haven't yet worked out input checking */
	for (i = 0; flags.flags[i]; i++)
	{
		if (flags.flags[i] == *term)
		{
			flags.values[i] += 1;
			i = 0;
			term++;
		}
	}
	for (i = 0; flags.flags[i]; i++)
	{
		if (flags.values[i] > 1)
			;/* stop, error time */
	}

	/* [width] */
	lower_bound = 1;
	while (*term >= lower_bound + '0' && *term <= '9')
	{
		flags.width *= 10;
		flags.width = *term++ - '0';
		lower_bound = 0;
	}
	/* [prec] */
	if (*term == '.')
	{
		term++;
		lower_bound = 1;
		while (*term >= lower_bound + '0' && *term <= '9')
		{
			flags.prec *= 10;
			flags.prec = *term++ - '0';
			lower_bound = 0;
		}
	}
	/* [length] */
	if (*term == 'l')
	{
		term++;
		flags.lng = 1;
	}
	else if (*term == 'h')
	{
		term++;
		flags.lng = -1;
	}
	for (i = 0; type[i]; i++)
	{
		if (type[i] == *term)
			break;
	}
	if (!type[i])
		printf("ERROR\n");/* error time */
}

int _printf(const char *format, ...)
{
	/* declarations */
	va_list ag;
	int buf_idx, i, j;
	char *buffer, *temp;
	spec_t specs[] = 
	{
		{'d', print_d},
		{'i', print_d},
		{'c', print_c},
		{'s', print_s},
		{'\0', NULL}
  	};
	flags_t flags;
	/* place characters into buffer one at a time */
	/* if we ever hit BUFSIZE this way, write buffer */
	int BUF_SIZE = 1024;

	/* input and malloc */
	if (!format)
		return (-1);
	else
		buffer = malloc(sizeof(char) * BUF_SIZE);
	if (!buffer)
		return (-1);

	/* begin looping through format string */
	va_start(ag, format);
	flags = init_flags(flags);
	buf_idx = 0;
	i = 0;
	while(format[i])
	{
		if (format[i] == '%')
		{
			/* It's a %tag, j is length to type */
			j = num_flags(format + i + 1);
			/* I changed setflags to void but i may need to chage it back to flags_t */
			set_flags(format + i + 1, j, flags);
			i += j + 1; /* format[i] needs to point to the type now */
			/* retrieve the converted string */
			for (j = 0; specs[j].s; j++)
			{
				if (format[i] == specs[j].s)
				{
					temp = specs[j].f(ag, flags);
					break;
				}
			}
			if (!specs[j].s)
				return (-1);
			/* put converted string into buffer */
			for (j = 0; temp[j]; j++, buf_idx++)
			{
				buffer[buf_idx] = temp[j];
				if (buf_idx == BUF_SIZE)
				{
					write(1, buffer, buf_idx);
					buf_idx = 0;
				}
			}
		}
		else
		{
			/* Not a %tag, add to buffer */
			buffer[buf_idx] = format[i];
			buf_idx++;
			/* if the buffer is full, print and flush it */
			if (buf_idx == BUF_SIZE)
			{
				write(1, buffer, buf_idx);
				buf_idx = 0;
			}
		}
		i++;
	}
	write(1, buffer, buf_idx);
}
