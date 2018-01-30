/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 11:34:19 by rowong            #+#    #+#             */
/*   Updated: 2018/01/11 11:35:03 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_pairs(int first, int second)
{
	ft_putchar((first / 10) + '0');
	ft_putchar((first % 10) + '0');
	ft_putchar(' ');
	ft_putchar((second / 10) + '0');
	ft_putchar((second % 10) + '0');
	ft_putchar(',');
	ft_putchar(' ');
}

void	ft_print_comb2(void)
{
	int first;
	int second;

	first = 0;
	second = 0;
	while (first <= 98)
	{
		second = first + 1;
		while (second <= 99)
		{
			if (first <= 98 && second <= 99)
				ft_print_pairs(first, second);
			second++;
		}
		first++;
	}
}
