/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 21:09:17 by astrole           #+#    #+#             */
/*   Updated: 2018/01/22 21:09:18 by astrole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper_functions.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		ft_putchar(str[i++]);
}

int		check_num(int nb)
{
	if (nb < 0 && nb != -2147483648)
	{
		nb *= -1;
		ft_putchar('-');
	}
	if (nb == 0)
		ft_putchar('0');
	else if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
		return (nb);
	return (0);
}

void	ft_putnbr(int nb)
{
	char	digits[11];
	int		i;

	nb = check_num(nb);
	if (nb != 0)
	{
		i = 0;
		while (nb > 0)
		{
			digits[i] = (nb % 10) + 48;
			nb /= 10;
			i++;
		}
		i -= 1;
		while (i >= 0)
		{
			write(1, &digits[i], 1);
			--i;
		}
	}
	ft_putchar('\n');
}

int		ft_atoi(char *str)
{
	int		res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if ((str[i] < 48 || str[i] > 57))
		return (0);
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
			res = res * 10 + str[i] - '0';
		else
			break ;
		++i;
	}
	return (res * sign);
}
