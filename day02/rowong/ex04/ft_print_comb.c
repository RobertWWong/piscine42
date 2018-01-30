/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:35:37 by rowong            #+#    #+#             */
/*   Updated: 2018/01/10 16:35:39 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_it(char i, char j, char k)
{
	ft_putchar(i);
	ft_putchar(j);
	ft_putchar(k);
	if (i == '7' && j == '8' && k == '9')
		return ;
	ft_putchar(',');
	ft_putchar(' ');
}

void	ft_print_comb(void)
{
	char f;
	char s;
	char t;

	f = '0';
	s = '0';
	t = '0';
	while (f <= '7')
	{
		s = f + 1;
		while (s <= '8')
		{
			t = s + 1;
			while (t <= '9')
			{
				if (f <= '7' && s <= '8' && t <= '9')
					ft_print_it(f, s, t);
				t++;
			}
			s++;
		}
		f++;
	}
}
