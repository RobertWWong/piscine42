#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_print_program_name(char *str)
{
	while (*str)
		ft_putchar(*str++);
	ft_putchar('\n');
}

int		ft_strcmp(char *s1, char *s2)
{
	char *s1a;
	char *s2b;

	s1a = s1;
	s2b = s2;
	while (*s1a || *s2b)
		if (*s1a++ != *s2b++)
			return (*--s1a - *--s2b);
	return (0);
}

void	ft_print(char *str)
{
	while (*str)
		ft_putchar(*str++);
	ft_putchar('\n');
}

void	ft_sort_params(char **arr, int a_size)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (i < a_size)
	{
		j = i + 1;
		while (j < a_size)
		{
			if (ft_strcmp(arr[i], arr[j]) > 0)
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	ft_sort_params(argv, argc);
	while (i < argc)
		ft_print(argv[i++]);
	return (0);
}
