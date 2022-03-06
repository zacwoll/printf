#include "holberton.h"
#define BUF_SIZE 1024

/**
  * num_flags - counts number of flags total
  * @term: our format tag
  * Return: int, number of flags
  */
int num_flags(const char *term)
{
	const char *FLAGS = "+- 0123456789.#lh";
	int i = 0, j = 0;

	while (FLAGS[i])
	{
		if (FLAGS[i] == term[j])
		{
			i = 0;
			j++;
		}
		i++;
	}
	return (j);
}

/**
  * checkBuffer - checks if buffer is full
  * @buf_idx: buffer's index
  * @buffer: char * buffer to be printed
  * Return: idx if not full, 0 if full to be refilled
  */
int checkBuffer(int buf_idx, char *buffer)
{
	if (buf_idx == BUF_SIZE)
	{
		write(1, buffer, buf_idx);
		return (0);
	}
	return (buf_idx);
}

/**
  * _printf - our version of printf
  * @format: string of input, may have %tags that are replaced with args
  * Return: int, length of total chars
  */
int _printf(const char *format, ...)
{
	va_list ag;
	int buf_idx = 0, i = 0, j, count = 0;
	char *buffer, *temp;
	spec_t specs[] = {
		{'d', print_d},	{'i', print_d},	{'c', print_c},	{'s', print_s},
		{'S', print_S},	{'u', print_u}, {'\0', NULL}
	};

	if (!format)
		return (-1);
	buffer = malloc(sizeof(char) * BUF_SIZE);
	if (!buffer)
		return (-1);
	va_start(ag, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			buffer[buf_idx] = '%';
			buf_idx++;
			count++;
			buf_idx = checkBuffer(buf_idx, buffer);
			i++;
		}
		else if (format[i] == '%' && format[i + 1])
		{
			j = num_flags(format + i + 1);
			i += j + 1;
			for (j = 0; specs[j].s; j++)
			{
				if (format[i] == specs[j].s)
				{
					temp = specs[j].f(ag);
					break;
				}
			}
			if (!specs[j].s)
				return (-1);
			if (!temp)
				return (-1);
			for (j = 0; temp[j]; j++, buf_idx++)
			{
				buffer[buf_idx] = temp[j];
				count++;
				buf_idx = checkBuffer(buf_idx, buffer);
			}
		}
		else
		{
			buffer[buf_idx] = format[i];
			buf_idx++;
			count++;
			buf_idx = checkBuffer(buf_idx, buffer);
		}
		i++;
	}
	write(1, buffer, buf_idx);
	va_end(ag);
	free(buffer);
	return (count);
}
