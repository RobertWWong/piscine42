/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:36:21 by rowong            #+#    #+#             */
/*   Updated: 2018/01/16 16:36:51 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_getlen(char *ptr)
{
	unsigned int	cnt;

	cnt = 0;
	while (*ptr++)
		cnt++;
	return (cnt);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char			*d;
	char			*s;
	unsigned int	n;
	unsigned int	dlen;

	d = dest;
	s = src;
	n = size;
	while (n-- != 0 && *d != 0)
		d++;
	dlen = d - dest;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_getlen(s));
	while (*s != 0)
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}
