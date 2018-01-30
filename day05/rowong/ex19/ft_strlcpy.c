/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 23:09:44 by rowong            #+#    #+#             */
/*   Updated: 2018/01/16 23:09:46 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	char			*d;
	char			*s;
	unsigned int	n;

	d = dest;
	s = src;
	n = size;
	if (n != 0 && --n != 0)
		while (n != 0)
		{
			if ((*d++ = *s++) == 0)
				break ;
			n--;
		}
	if (n == 0)
	{
		if (size != 0)
			*d = '\0';
		while (*s++)
			;
	}
	return (s - src - 1);
}
