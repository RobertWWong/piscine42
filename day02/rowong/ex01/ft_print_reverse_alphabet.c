/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 13:34:43 by rowong            #+#    #+#             */
/*   Updated: 2018/01/10 15:57:28 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_reverse_alphabet(void)
{
	char chr;

	chr = 'z';
	while (chr >= 'a')
	{
		ft_putchar(chr);
		chr--;
	}
}
