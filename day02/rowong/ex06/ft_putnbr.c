/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnpr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:37:56 by rowong            #+#    #+#             */
/*   Updated: 2018/01/11 13:53:38 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int		idx;
	int		was_neg;
	int		rem;
	char	str[12];

	idx = 0;
	was_neg = 0;
	if (nb < 0)
		was_neg = 1;
	if (was_neg == 1)
		nb *= -1;
	while (nb != 0)
	{
		rem = nb % 10;
		str[idx++] = rem + '0';
		nb /= 10;
	}
	if (was_neg)
		str[idx++] = '-';
	while (idx > 0)
		ft_putchar(str[--idx]);
}

int		main(void)
{
	ft_putnbr(42);
	return (0);
}
