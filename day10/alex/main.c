/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 19:06:11 by astrole           #+#    #+#             */
/*   Updated: 2018/01/22 19:06:12 by astrole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper_functions.h"

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while ((s1[i] != '\0') && (s2[i] != '\0'))
	{
		if (s1[i] == s2[i])
			i++;
		else
			break ;
	}
	if ((s1[i] == '\0') && (s2[i] == '\0'))
		return (0);
	return (s1[i] - s2[i]);
}

void	do_maths(char *str, int x, int y, int output)
{
	if (ft_strcmp(str, "+") == 0)
		output = x + y;
	else if (ft_strcmp(str, "-") == 0)
		output = x - y;
	else if (ft_strcmp(str, "*") == 0)
		output = x * y;
	else if (ft_strcmp(str, "/") == 0)
		if (x != 0 && y != 0)
			output = x / y;
		else
		{
			ft_putstr("Stop : division by zero\n");
			return ;
		}
	else if (ft_strcmp(str, "%") == 0)
	{
		if (x != 0 && y != 0)
			output = x % y;
		else
		{
			ft_putstr("Stop : modulo by zero\n");
			return ;
		}
	}
	ft_putnbr(output);
}

int		main(int argc, char **argv)
{
	int x;
	int y;
	int output;

	if (argc != 4)
		return (0);
	x = ft_atoi(argv[1]);
	y = ft_atoi(argv[3]);
	if ((argv[1][0] < 48 || argv[1][0] > 57))
	{
		if (argv[2][0] != '+' && argv[2][0] != '-')
		{
			ft_putstr("0\n");
			return (0);
		}
	}
	output = 0;
	do_maths(argv[2], x, y, output);
	return (0);
}
