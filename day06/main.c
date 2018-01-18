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

/*
**	Need to doo lo + 1 on ft_sort since our lo is + 1 past the argv, otherwise we get the file name
**
*/
int		ft_partition(char **arr, int lo, int hi)
{
	char	*piv;
	int		i;
	int		j;
	char	*swp;

	swp = arr[0];
	piv = arr[lo];
	i = lo - 1;
	j = hi + 1;

	while (1)
	{
		while ((ft_strcmp(arr[i], piv)) < 0)
			i += 1;
		while ((ft_strcmp(arr[j], piv)) > 0)
			j -= 1;
		if (i >= j)
			return (j);
		swp = arr[i];
		arr[i] = arr[j];
		arr[j] = arr[i];
	}
	return (0);
}

void	ft_sort_params(char **arr, int lo, int hi)
{
	int pivot;

	pivot = hi / 2;
	if (lo < hi)
	{
		ft_sort_params(arr, lo, pivot);
		ft_sort_params(arr, pivot + 1, hi);
	}
};


int		main(int argc, char *argv[])
{
    // ft_print_program_name(argv[0]);
    char *tmp;
    char *tmp2;

    printf("%s vs %s\n", argv[0], argv[1]);

    tmp = argv[0];
    argv[0] = argv[1];
    argv[1] = tmp;
    printf("%s vs %s\n", argv[0], argv[1]);

    ft_sort_params(argv, 1, argc - 1);

    printf("%s vs %s\n", argv[0], argv[1]);    

	return (0);
}
