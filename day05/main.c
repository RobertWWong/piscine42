#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest); 
}

char	*ft_strstr(char *str, char *to_find)
{
	char *substr;
	char *origin;
	int idx;

	idx = 0;
	while (*str != '\0')
	{
		origin = str;
		substr = to_find;
		while (*str && *substr && *str == *substr)
		{
			str++;
			substr++;
		}
		if (!*substr)
			return (origin);
		str = origin + 1;
	}
	return (0);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2 )
		if (*s1++ != *s2++)
			return (*--s1 - *--s2);
	return (1);
}

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (n && *s1 && (*s1 == *s2))
	{
		++s1;
		++s2;
		--n;
	}
	if (!n)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

char	*ft_strupcase(char *str)
{
	int i;
	
	i = 0;
	while (*str)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

int		ft_atoi(char *str)
{
	int n;
	int i;
	int isnegative;

	n = 0;
	i = 0;
	isnegative = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		isnegative = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		n = 10 * n + (str[i] - '0');
		i++;
	}
	if (isnegative == 1)
		return (-n);
	return (n);
}

int main( )
{
	printf("%d\n", 's'-'a');
	char pt[] = "NOyes";
	char pt1[] = "NOyeas";
	printf("Is is the same = %d\n", ft_atoi(" asd w 23"));
	// printf("Is is the same = %s\n", ft_strupcase(pt));
   return 0;
}